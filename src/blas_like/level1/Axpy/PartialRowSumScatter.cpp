/*
   Copyright (c) 2009-2014, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"

namespace El {
namespace axpy {

template<typename T,Dist U,Dist V>
void PartialRowSumScatter
( T alpha,
  const DistMatrix<T,U,Partial<V>()>& A,
        DistMatrix<T,U,        V   >& B )
{
    DEBUG_ONLY(CallStackEntry cse("axpy::PartialRowSumScatter"))
    AssertSameGrids( A, B );
    if( A.Height() != B.Height() || A.Width() != B.Width() )
        LogicError("Matrix sizes did not match");
    if( !B.Participating() )
        return;

    if( B.RowAlign() % A.RowStride() == A.RowAlign() )
    {
        const Int rowStride = B.RowStride();
        const Int rowStridePart = B.PartialRowStride();
        const Int rowStrideUnion = B.PartialUnionRowStride();
        const Int rowRankPart = B.PartialRowRank();
        const Int rowAlign = B.RowAlign();
        const Int rowShiftOfA = A.RowShift();

        const Int height = B.Height();
        const Int width = B.Width();
        const Int localWidth = B.LocalWidth();
        const Int maxLocalWidth = MaxLength( width, rowStride );
        const Int recvSize = mpi::Pad( height*maxLocalWidth );
        const Int sendSize = rowStrideUnion*recvSize;

        // Pack
        std::vector<T> buffer( sendSize );
        EL_OUTER_PARALLEL_FOR
        for( Int k=0; k<rowStrideUnion; ++k )
        {
            const Int thisRank = rowRankPart+k*rowStridePart;
            const Int thisRowShift = Shift_( thisRank, rowAlign, rowStride );
            const Int thisRowOffset =
                (thisRowShift-rowShiftOfA) / rowStridePart;
            const Int thisLocalWidth =
                Length_( width, thisRowShift, rowStride );
            InterleaveMatrix
            ( height, thisLocalWidth,
              A.LockedBuffer(0,thisRowOffset), 1, rowStrideUnion*A.LDim(),
              &buffer[k*recvSize],             1, height );
        }

        // Communicate
        mpi::ReduceScatter( buffer.data(), recvSize, B.PartialUnionRowComm() );

        // Unpack our received data
        InterleaveMatrixUpdate
        ( alpha, height, B.LocalWidth(),
          buffer.data(), 1, height,
          B.Buffer(),    1, B.LDim() );
    }
    else
        LogicError("Unaligned axpy::PartialRowSumScatter not implemented");
}

#define PROTO_DIST(T,U,V) \
  template void PartialRowSumScatter \
  ( T alpha, \
    const DistMatrix<T,U,Partial<V>()>& A, \
          DistMatrix<T,U,        V   >& B );

#define PROTO(T) \
  PROTO_DIST(T,CIRC,CIRC) \
  PROTO_DIST(T,MC,  MR  ) \
  PROTO_DIST(T,MC,  STAR) \
  PROTO_DIST(T,MD,  STAR) \
  PROTO_DIST(T,MR,  MC  ) \
  PROTO_DIST(T,MR,  STAR) \
  PROTO_DIST(T,STAR,MC  ) \
  PROTO_DIST(T,STAR,MD  ) \
  PROTO_DIST(T,STAR,MR  ) \
  PROTO_DIST(T,STAR,STAR) \
  PROTO_DIST(T,STAR,VC  ) \
  PROTO_DIST(T,STAR,VR  ) \
  PROTO_DIST(T,VC,  STAR) \
  PROTO_DIST(T,VR,  STAR) 

#include "El/macros/Instantiate.h"

} // namespace axpy
} // namespace El