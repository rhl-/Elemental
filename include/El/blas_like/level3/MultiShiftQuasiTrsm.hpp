/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_MULTISHIFT_QUASI_TRSM_HPP
#define EL_BLAS3_MULTISHIFT_QUASI_TRSM_HPP

namespace El {

// MultiShiftQuasiTrsm
// ===================
template<typename F>
void MultiShiftQuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  F alpha, const Matrix<F>& A, const Matrix<F>& shifts, Matrix<F>& B );
template<typename Real>
void MultiShiftQuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  Complex<Real> alpha,
  const Matrix<Real>& A,
  const Matrix<Complex<Real>>& shifts,
        Matrix<Real>& BReal, Matrix<Real>& BImag );
template<typename F>
void MultiShiftQuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  F alpha, const ElementalMatrix<F>& A, const ElementalMatrix<F>& shifts,
  ElementalMatrix<F>& B );
template<typename Real>
void MultiShiftQuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  Complex<Real> alpha,
  const ElementalMatrix<Real>& A,
  const ElementalMatrix<Complex<Real>>& shifts,
        ElementalMatrix<Real>& BReal, ElementalMatrix<Real>& BImag );

template<typename F>
void LocalMultiShiftQuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  F alpha, const DistMatrix<F,STAR,STAR>& A,
           const ElementalMatrix<F>& shifts,
                 ElementalMatrix<F>& X );
template<typename Real>
void LocalMultiShiftQuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  Complex<Real> alpha,
  const DistMatrix<Real,STAR,STAR>& A,
  const ElementalMatrix<Complex<Real>>& shifts,
        ElementalMatrix<Real>& XReal,
        ElementalMatrix<Real>& XImag );
} // end namespace El

#endif // EL_BLAS3_MULTISHIFT_QUASI_TRSM
