/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_MULTIPLY_HPP
#define EL_BLAS3_MULTIPLY_HPP

namespace El {

// Multiply
// ========
// NOTE: The following routine multiplies a sparse matrix by a set of vectors
//       and is obviously not a BLAS routine. However, it is a basic linear
//       algebra routine making use of Elemental's core data structures, and
//       so this is the natural placement
template<typename T>
void Multiply
( Orientation orientation,
  T alpha, const SparseMatrix<T>& A, const Matrix<T>& X,
  T beta,                                  Matrix<T>& Y );

template<typename T>
void Multiply
( Orientation orientation,
  T alpha,
  const DistSparseMatrix<T>& A,
  const DistMultiVec<T>& X,
  T beta,
        DistMultiVec<T>& Y );
template<typename T>
void Multiply
( Orientation orientation,
  T alpha,
  const DistSparseMatrix<T>& A,
  const AbstractDistMatrix<T>& X,
  T beta,
        AbstractDistMatrix<T>& Y );

} //end namespace El 

#endif // EL_BLAS3_MULTIPLY_HPP
