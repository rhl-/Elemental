/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS_LIKE_LEVEL_2_HEMV_HPP
#define EL_BLAS_LIKE_LEVEL_2_HEMV_HPP

#include <El/blas_like/level2/Symv.hpp>

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

} // namespace El

#endif //EL_BLAS_LIKE_LEVEL_2_HEMV_HPP
