/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_TWOSIDEDTRMM_HPP
#define EL_BLAS3_TWOSIDEDTRMM_HPP

namespace El {

// TwoSidedTrmm
// ============
template<typename T>
void TwoSidedTrmm
( UpperOrLower uplo, UnitOrNonUnit diag, 
  Matrix<T>& A, const Matrix<T>& B );
template<typename T>
void TwoSidedTrmm
( UpperOrLower uplo, UnitOrNonUnit diag, 
  ElementalMatrix<T>& A, const ElementalMatrix<T>& B );
template<typename T>
void TwoSidedTrmm
( UpperOrLower uplo, UnitOrNonUnit diag,
  DistMatrix<T,MC,MR,BLOCK>& A, const DistMatrix<T,MC,MR,BLOCK>& B );
template<typename T>
void LocalTwoSidedTrmm
( UpperOrLower uplo, UnitOrNonUnit diag,
  DistMatrix<T,STAR,STAR>& A, const DistMatrix<T,STAR,STAR>& B );

} // namespace El

#endif // ifndef EL_BLAS3_TWOSIDEDTRMM_HPP
