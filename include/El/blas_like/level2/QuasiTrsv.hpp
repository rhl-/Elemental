#ifndef EL_BLASLIKE_LEVEL2_QUASITRSV_HPP
#define EL_BLASLIKE_LEVEL2_QUASITRSV_HPP

/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/

#include <El/matrices.hpp>

#include <El/blas_like/level2/QuasiTrsv/LN.hpp>
#include <El/blas_like/level2/QuasiTrsv/LT.hpp>
#include <El/blas_like/level2/QuasiTrsv/UN.hpp>
#include <El/blas_like/level2/QuasiTrsv/UT.hpp>

namespace El {

template<typename F>
void QuasiTrsv
( UpperOrLower uplo, Orientation orientation, const Matrix<F>& A, Matrix<F>& x, 
  bool checkIfSingular )
{
    DEBUG_ONLY(CSE cse("QuasiTrsv"))
    if( uplo == LOWER )
    {
        if( orientation == NORMAL )
            quasitrsv::LN( A, x, checkIfSingular );
        else
            quasitrsv::LT( orientation, A, x, checkIfSingular );
    }
    else
    {
        if( orientation == NORMAL )
            quasitrsv::UN( A, x, checkIfSingular );
        else
            quasitrsv::UT( orientation, A, x, checkIfSingular );
    }
}

template<typename F>
void QuasiTrsv
( UpperOrLower uplo, Orientation orientation, 
  const ElementalMatrix<F>& A, ElementalMatrix<F>& x, 
  bool checkIfSingular )
{
    DEBUG_ONLY(CSE cse("QuasiTrsv"))
    if( uplo == LOWER )
    {
        if( orientation == NORMAL )
            quasitrsv::LN( A, x, checkIfSingular );
        else
            quasitrsv::LT( orientation, A, x, checkIfSingular );
    }
    else
    {
        if( orientation == NORMAL )
            quasitrsv::UN( A, x, checkIfSingular );
        else
            quasitrsv::UT( orientation, A, x, checkIfSingular );
    }
}

#ifdef EL_INSTANTIATE_BLAS_LEVEL2
# define EL_EXTERN
#else
# define EL_EXTERN extern
#endif


#define PROTO(F) \
  EL_EXTERN template void QuasiTrsv \
  ( UpperOrLower uplo, Orientation orientation, \
    const Matrix<F>& A, Matrix<F>& x, bool checkIfSingular ); \
  EL_EXTERN template void QuasiTrsv \
  ( UpperOrLower uplo, Orientation orientation, \
    const ElementalMatrix<F>& A, ElementalMatrix<F>& x, \
    bool checkIfSingular );

#define EL_NO_INT_PROTO
#define EL_ENABLE_DOUBLEDOUBLE
#define EL_ENABLE_QUADDOUBLE
#define EL_ENABLE_QUAD
#define EL_ENABLE_BIGFLOAT
#include "El/macros/Instantiate.h"

#undef EL_EXTERN

} // namespace El

#endif /* QUASITRSV_HPP */
