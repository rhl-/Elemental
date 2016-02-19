#ifndef EL_BLASLIKE_LEVEL2_HEMV_HPP
#define EL_BLASLIKE_LEVEL2_HEMV_HPP

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
void Hemv
( UpperOrLower uplo,
  T alpha, const Matrix<T>& A, const Matrix<T>& x, T beta, Matrix<T>& y )
{
    DEBUG_ONLY(CSE cse("Hemv"))
    Symv( uplo, alpha, A, x, beta, y, true );
}

template<typename T>
void Hemv
( UpperOrLower uplo,
  T alpha, const ElementalMatrix<T>& A,
           const ElementalMatrix<T>& x,
  T beta,        ElementalMatrix<T>& y,
  const SymvCtrl<T>& ctrl )
{
    DEBUG_ONLY(CSE cse("Hemv"))
    Symv( uplo, alpha, A, x, beta, y, true, ctrl );
}

#ifdef EL_INSTANTIATE_BLAS_LEVEL2
# define EL_EXTERN
#else
# define EL_EXTERN extern
#endif


#define PROTO(T) \
  EL_EXTERN template void Hemv \
  ( UpperOrLower uplo, T alpha, \
    const Matrix<T>& A, const Matrix<T>& x, T beta, Matrix<T>& y ); \
  EL_EXTERN template void Hemv \
  ( UpperOrLower uplo, T alpha, \
    const ElementalMatrix<T>& A, const ElementalMatrix<T>& x, \
    T beta, ElementalMatrix<T>& y, \
    const SymvCtrl<T>& ctrl );

#define EL_ENABLE_DOUBLEDOUBLE
#define EL_ENABLE_QUADDOUBLE
#define EL_ENABLE_QUAD
#define EL_ENABLE_BIGINT
#define EL_ENABLE_BIGFLOAT
#include "El/macros/Instantiate.h"

#undef EL_EXTERN

} // namespace El

#endif /* HEMV_HPP */
