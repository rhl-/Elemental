/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_GEMM_HPP
#define EL_BLAS3_GEMM_HPP

namespace El {

// Gemm
// ====
namespace GemmAlgorithmNS {
enum GemmAlgorithm {
  GEMM_DEFAULT,
  GEMM_SUMMA_A,
  GEMM_SUMMA_B,
  GEMM_SUMMA_C,
  GEMM_SUMMA_DOT,
  GEMM_CANNON
};
}
using namespace GemmAlgorithmNS;

template<typename T>
void Gemm
( Orientation orientA, Orientation orientB,
  T alpha, const Matrix<T>& A, const Matrix<T>& B, T beta, Matrix<T>& C );

template<typename T>
void Gemm
( Orientation orientA, Orientation orientB,
  T alpha, const Matrix<T>& A, const Matrix<T>& B, Matrix<T>& C );

template<typename T>
void Gemm
( Orientation orientA, Orientation orientB,
  T alpha, const ElementalMatrix<T>& A, const ElementalMatrix<T>& B,
  T beta,        ElementalMatrix<T>& C, GemmAlgorithm alg=GEMM_DEFAULT );

template<typename T>
void Gemm
( Orientation orientA, Orientation orientB,
  T alpha, const ElementalMatrix<T>& A, const ElementalMatrix<T>& B,
                 ElementalMatrix<T>& C, GemmAlgorithm alg=GEMM_DEFAULT );

template<typename T>
void LocalGemm
( Orientation orientA, Orientation orientB,
  T alpha, const ElementalMatrix<T>& A,
           const ElementalMatrix<T>& B,
  T beta,        ElementalMatrix<T>& C );
template<typename T>
void LocalGemm
( Orientation orientA, Orientation orientB,
  T alpha, const ElementalMatrix<T>& A,
           const ElementalMatrix<T>& B,
                 ElementalMatrix<T>& C );

} // namespace El

#endif // ifndef EL_BLAS3_GEMM
