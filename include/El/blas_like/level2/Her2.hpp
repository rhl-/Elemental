#ifndef EL_BLASLIKE_LEVEL2_HER2_HPP
#define EL_BLASLIKE_LEVEL2_HER2_HPP

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

#ifdef EL_INSTANTIATE_BLAS_LEVEL2
# define EL_EXTERN
#else
# define EL_EXTERN extern
#endif


#define PROTO(T) \
  EL_EXTERN template void Her2 \
  ( UpperOrLower uplo, T alpha, \
    const Matrix<T>& x, const Matrix<T>& y, Matrix<T>& A ); \
  EL_EXTERN template void Her2 \
  ( UpperOrLower uplo, T alpha, \
    const ElementalMatrix<T>& x, const ElementalMatrix<T>& y, \
          ElementalMatrix<T>& A );

#define EL_ENABLE_DOUBLEDOUBLE
#define EL_ENABLE_QUADDOUBLE
#define EL_ENABLE_QUAD
#define EL_ENABLE_BIGINT
#define EL_ENABLE_BIGFLOAT
#include "El/macros/Instantiate.h"

#undef EL_EXTERN

} // namespace El

#endif /* HER2_HPP */
