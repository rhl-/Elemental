#ifndef EL_BLASLIKE_LEVEL2_TRMV_HPP
#define EL_BLASLIKE_LEVEL2_TRMV_HPP

/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include <El/matrices.hpp>


namespace El {

template<typename T>
void Trmv
( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag,
  const Matrix<T>& A, Matrix<T>& x )
{
    DEBUG_ONLY(
        CSE cse("Trmv");
        if( x.Height() != 1 && x.Width() != 1 )
            LogicError("x must be a vector");
        if( A.Height() != A.Width() )
            LogicError("A must be square");
        const Int xLength = ( x.Width()==1 ? x.Height() : x.Width() );
        if( xLength != A.Height() )
            LogicError("x must conform with A");
    )
    const char uploChar = UpperOrLowerToChar( uplo );
    const char transChar = OrientationToChar( orientation );
    const char diagChar = UnitOrNonUnitToChar( diag );
    const Int m = A.Height();
    const Int incx = ( x.Width()==1 ? 1 : x.LDim() );
    blas::Trmv
    ( uploChar, transChar, diagChar, m,
      A.LockedBuffer(), A.LDim(), x.Buffer(), incx );
}

// TODO: Implement distributed version
#ifdef EL_INSTANTIATE_BLAS_LEVEL2
# define EL_EXTERN
#else
# define EL_EXTERN extern
#endif


#define PROTO(T) \
  EL_EXTERN template void Trmv \
  ( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, \
    const Matrix<T>& A, Matrix<T>& x );

#define EL_ENABLE_DOUBLEDOUBLE
#define EL_ENABLE_QUADDOUBLE
#define EL_ENABLE_QUAD
#define EL_ENABLE_BIGINT
#define EL_ENABLE_BIGFLOAT
#include "El/macros/Instantiate.h"

#undef EL_EXTERN

} // namespace El

#endif /* TRMV_HPP */
