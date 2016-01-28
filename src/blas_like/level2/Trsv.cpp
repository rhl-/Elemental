/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"

#include <El/blas_like/level2/Trsv.hpp>

namespace El {

#define PROTO(F) \
  template void Trsv \
  ( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, \
    const Matrix<F>& A, Matrix<F>& x ); \
  template void Trsv \
  ( UpperOrLower uplo, Orientation orientation, UnitOrNonUnit diag, \
    const AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& x );

#define EL_NO_INT_PROTO
#define EL_ENABLE_DOUBLEDOUBLE
#define EL_ENABLE_QUADDOUBLE
#define EL_ENABLE_QUAD
#define EL_ENABLE_BIGFLOAT
#include "El/macros/Instantiate.h"

} // namespace El
