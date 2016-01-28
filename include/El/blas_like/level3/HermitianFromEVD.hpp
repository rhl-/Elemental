/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_HERMITIAN_FROM_EVD_HPP
#define EL_BLAS3_HERMITIAN_FROM_EVD_HPP

namespace El {

// Hermitian from EVD
// ==================
// A := Z diag(w) Z^H, where w is real
template<typename F>
void HermitianFromEVD
( UpperOrLower uplo,
        Matrix<F>& A,
  const Matrix<Base<F>>& w,
  const Matrix<F>& Z );
template<typename F>
void HermitianFromEVD
( UpperOrLower uplo,
        ElementalMatrix<F>& A,
  const ElementalMatrix<Base<F>>& w,
  const ElementalMatrix<F>& Z );

} //namespace El

#endif //EL_BLAS3_HERMITIAN_FROM_EVD
