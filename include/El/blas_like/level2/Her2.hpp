#pragma once
/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include <El/core.hpp>
#include <El/blas_like/level2/Syr.hpp>

namespace El {

template<typename T>
void Her2
( UpperOrLower uplo,
  T alpha, const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A )
{
    DEBUG_ONLY(CSE cse("Her2"))
    Syr2( uplo, T(alpha), x, y, A, true );
}

template<typename T>
void Her2
( UpperOrLower uplo,
  T alpha, const ElementalMatrix<T>& x, const ElementalMatrix<T>& y,
                 ElementalMatrix<T>& A )
{
    DEBUG_ONLY(CSE cse("Her2"))
    Syr2( uplo, T(alpha), x, y, A, true );
}

} // namespace El
