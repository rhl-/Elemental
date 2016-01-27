/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_MULTISHIFT_TRSM_HPP
#define EL_BLAS3_MULTISHIFT_TRSM_HPP

namespace El {


// MultiShiftTrsm
// ==============
template<typename F>
void MultiShiftTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  F alpha, Matrix<F>& U, const Matrix<F>& shifts, Matrix<F>& X );
template<typename F>
void MultiShiftTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  F alpha, const ElementalMatrix<F>& U, const ElementalMatrix<F>& shifts,
  ElementalMatrix<F>& X );

} //end namespace El

#endif // EL_BLAS3_MULTISHIFT_TRSM_HPP
