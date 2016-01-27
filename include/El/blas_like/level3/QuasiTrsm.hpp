/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_QUASITRSM_HPP
#define EL_BLAS3_QUASITRSM_HPP

namespace El {

// QuasiTrsm
// =========
template<typename F>
void QuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  F alpha, const Matrix<F>& A, Matrix<F>& B,
  bool checkIfSingular=false );
template<typename F>
void QuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  F alpha, const ElementalMatrix<F>& A, ElementalMatrix<F>& B,
  bool checkIfSingular=false );

template<typename F>
void LocalQuasiTrsm
( LeftOrRight side, UpperOrLower uplo, Orientation orientation,
  F alpha, const DistMatrix<F,STAR,STAR>& A, ElementalMatrix<F>& X,
  bool checkIfSingular=false );

} //end namespace El

#endif //EL_BLAS3_QUASITRSM_HPP
