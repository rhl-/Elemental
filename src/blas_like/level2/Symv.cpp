/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"

#include <El/blas_like/level2/Symv.hpp>

namespace El {

#define PROTO(T) \
  template void Symv \
  ( UpperOrLower uplo, \
    T alpha, \
    const Matrix<T>& A, \
    const Matrix<T>& x, \
    T beta, \
         Matrix<T>& y, \
    bool conjugate ); \
  template void Symv \
  ( UpperOrLower uplo, \
    T alpha, \
    const ElementalMatrix<T>& A, \
    const ElementalMatrix<T>& x, \
    T beta, \
          ElementalMatrix<T>& y, \
    bool conjugate, \
    const SymvCtrl<T>& ctrl ); \
  template void symv::LocalColAccumulate \
  ( UpperOrLower uplo, \
    T alpha, \
    const DistMatrix<T>& A, \
    const DistMatrix<T,MC,STAR>& x_MC_STAR, \
    const DistMatrix<T,MR,STAR>& x_MR_STAR, \
          DistMatrix<T,MC,STAR>& z_MC_STAR, \
          DistMatrix<T,MR,STAR>& z_MR_STAR, bool conjugate, \
    const SymvCtrl<T>& ctrl ); \
  template void symv::LocalRowAccumulate \
  ( UpperOrLower uplo, \
    T alpha, \
    const DistMatrix<T>& A, \
    const DistMatrix<T,STAR,MC>& x_STAR_MC, \
    const DistMatrix<T,STAR,MR>& x_STAR_MR, \
          DistMatrix<T,STAR,MC>& z_STAR_MC, \
          DistMatrix<T,STAR,MR>& z_STAR_MR, bool conjugate, \
    const SymvCtrl<T>& ctrl );

#define EL_ENABLE_DOUBLEDOUBLE
#define EL_ENABLE_QUADDOUBLE
#define EL_ENABLE_QUAD
#define EL_ENABLE_BIGINT
#define EL_ENABLE_BIGFLOAT
#include "El/macros/Instantiate.h"

} // namespace El
