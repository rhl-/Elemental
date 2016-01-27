/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_TRSM_HPP
#define EL_BLAS3_TRSM_HPP

namespace El {

// Trsm
// ====
namespace TrsmAlgorithmNS {
enum TrsmAlgorithm {
  TRSM_DEFAULT,
  TRSM_LARGE,
  TRSM_MEDIUM,
  TRSM_SMALL
};
}
using namespace TrsmAlgorithmNS;

template<typename F>
void Trsm
( LeftOrRight side, UpperOrLower uplo,
  Orientation orientation, UnitOrNonUnit diag,
  F alpha, const Matrix<F>& A, Matrix<F>& B,
  bool checkIfSingular=false );
template<typename F>
void Trsm
( LeftOrRight side, UpperOrLower uplo,
  Orientation orientation, UnitOrNonUnit diag,
  F alpha,
  const AbstractDistMatrix<F>& A,
        AbstractDistMatrix<F>& B,
  bool checkIfSingular=false, TrsmAlgorithm alg=TRSM_DEFAULT );

template<typename F>
void LocalTrsm
( LeftOrRight side, UpperOrLower uplo,
  Orientation orientation, UnitOrNonUnit diag,
  F alpha,
  const DistMatrix<F,STAR,STAR>& A,
        AbstractDistMatrix<F>& X,
  bool checkIfSingular=false );


} // namespace El

#endif // ifndef EL_BLAS3_TRSM_HPP
