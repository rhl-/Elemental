/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/

#include <El/blas_like/level2/QuasiTrsv.hpp>

namespace El {

#define PROTO(F) \
  template void QuasiTrsv \
  ( UpperOrLower uplo, Orientation orientation, \
    const Matrix<F>& A, Matrix<F>& x, bool checkIfSingular ); \
  template void QuasiTrsv \
  ( UpperOrLower uplo, Orientation orientation, \
    const ElementalMatrix<F>& A, ElementalMatrix<F>& x, \
    bool checkIfSingular );

#define EL_NO_INT_PROTO
#define EL_ENABLE_DOUBLEDOUBLE
#define EL_ENABLE_QUADDOUBLE
#define EL_ENABLE_QUAD
#define EL_ENABLE_BIGFLOAT
#include "El/macros/Instantiate.h"

} // namespace El
