/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include <El/blas_like/level2/Gemv.hpp>

namespace El {

#define PROTO(T) \
  template void Gemv \
  ( Orientation orientation, \
    T alpha, const Matrix<T>& A, \
             const Matrix<T>& x, \
    T beta,        Matrix<T>& y ); \
  template void Gemv \
  ( Orientation orientation, \
    T alpha, const Matrix<T>& A, \
             const Matrix<T>& x, \
                   Matrix<T>& y ); \
  template void Gemv \
  ( Orientation orientation, \
    T alpha, const ElementalMatrix<T>& A, \
             const ElementalMatrix<T>& x, \
    T beta,        ElementalMatrix<T>& y ); \
  template void Gemv \
  ( Orientation orientation, \
    T alpha, const ElementalMatrix<T>& A, \
             const ElementalMatrix<T>& x, \
                   ElementalMatrix<T>& y ); \
  template void Gemv \
  ( Orientation orientation, \
    T alpha, const DistMatrix<T,MC,MR,BLOCK>& A, \
             const DistMatrix<T,MC,MR,BLOCK>& x, \
    T beta,        DistMatrix<T,MC,MR,BLOCK>& y ); \
  template void Gemv \
  ( Orientation orientation, \
    T alpha, const DistMatrix<T,MC,MR,BLOCK>& A, \
             const DistMatrix<T,MC,MR,BLOCK>& x, \
                   DistMatrix<T,MC,MR,BLOCK>& y ); \
  template void LocalGemv \
  ( Orientation orientation, \
    T alpha, const ElementalMatrix<T>& A, \
             const ElementalMatrix<T>& x, \
    T beta,        ElementalMatrix<T>& y );

#define EL_ENABLE_DOUBLEDOUBLE
#define EL_ENABLE_QUADDOUBLE
#define EL_ENABLE_QUAD
#define EL_ENABLE_BIGINT
#define EL_ENABLE_BIGFLOAT
#include "El/macros/Instantiate.h"

} // namespace El
