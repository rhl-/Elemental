/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_NORMAL_FROM_EVD_HPP
#define EL_BLAS3_NORMAL_FROM_EVD_HPP

namespace El {

// Normal from EVD
// ===============
// A := Z diag(w) Z^H, where w is complex
template<typename Real>
void NormalFromEVD
(       Matrix<Complex<Real>>& A,
  const Matrix<Complex<Real>>& w,
  const Matrix<Complex<Real>>& Z );
template<typename Real>
void NormalFromEVD
(       ElementalMatrix<Complex<Real>>& A,
  const ElementalMatrix<Complex<Real>>& w,
  const ElementalMatrix<Complex<Real>>& Z );

} //namespace El

#endif //EL_BLAS3_NORMAL_FROM_EVD
