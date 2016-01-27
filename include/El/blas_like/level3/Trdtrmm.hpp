/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS3_TRDTRMM_HPP
#define EL_BLAS3_TRDTRMM_HPP

namespace El {

// Trdtrmm
// =======
template<typename F>
void Trdtrmm( UpperOrLower uplo, Matrix<F>& A, bool conjugate=false );
template<typename F>
void Trdtrmm
( UpperOrLower uplo, Matrix<F>& A, const Matrix<F>& dOff, 
  bool conjugate=false );

template<typename F>
void Trdtrmm
( UpperOrLower uplo, ElementalMatrix<F>& A, bool conjugate=false );
template<typename F>
void Trdtrmm
( UpperOrLower uplo,
  ElementalMatrix<F>& A, const ElementalMatrix<F>& dOff, 
  bool conjugate=false );

template<typename F>
void Trdtrmm
( UpperOrLower uplo, DistMatrix<F,STAR,STAR>& A, bool conjugate=false );
template<typename F>
void Trdtrmm
( UpperOrLower uplo,
  DistMatrix<F,STAR,STAR>& A, const DistMatrix<F,STAR,STAR>& dOff,
  bool conjugate=false );


} // namespace El

#endif // ifndef EL_BLAS3_TRDTRMM_HPP
