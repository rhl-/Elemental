/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_HERK2_HPP
#define EL_BLAS3_HERK2_HPP

namespace El {

// Her2k
// =====
template<typename T>
void Her2k
( UpperOrLower uplo, Orientation orientation,
  T alpha,       const Matrix<T>& A, const Matrix<T>& B, 
  Base<T> beta,        Matrix<T>& C );

template<typename T>
void Her2k
( UpperOrLower uplo, Orientation orientation,
  T alpha, const Matrix<T>& A, const Matrix<T>& B, Matrix<T>& C );

template<typename T>
void Her2k
( UpperOrLower uplo, Orientation orientation,
  T alpha,      const ElementalMatrix<T>& A, const ElementalMatrix<T>& B,
  Base<T> beta,       ElementalMatrix<T>& C );

template<typename T>
void Her2k
( UpperOrLower uplo, Orientation orientation,
  T alpha, const ElementalMatrix<T>& A, const ElementalMatrix<T>& B,
                 ElementalMatrix<T>& C );
} //end namespace El
#endif // EL_BLAS3_HERK2_HPP
