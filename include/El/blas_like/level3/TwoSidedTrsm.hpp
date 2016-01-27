/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_TWOSIDEDTRSM_HPP
#define EL_BLAS3_TWOSIDEDTRSM_HPP

namespace El {

// TwoSidedTrsm
// ============
template<typename F>
void TwoSidedTrsm
( UpperOrLower uplo, UnitOrNonUnit diag, 
  Matrix<F>& A, const Matrix<F>& B );
template<typename F>
void TwoSidedTrsm
( UpperOrLower uplo, UnitOrNonUnit diag,
  ElementalMatrix<F>& A, const ElementalMatrix<F>& B );
template<typename F>
void TwoSidedTrsm
( UpperOrLower uplo, UnitOrNonUnit diag,
  DistMatrix<F,MC,MR,BLOCK>& A, const DistMatrix<F,MC,MR,BLOCK>& B );
template<typename F>
void TwoSidedTrsm
( UpperOrLower uplo, UnitOrNonUnit diag,
  DistMatrix<F,STAR,STAR>& A, const DistMatrix<F,STAR,STAR>& B );



} // namespace El

#endif // ifndef EL_BLAS3_TWOSIDEDTRSM_HPP
