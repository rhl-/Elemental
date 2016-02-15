/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS_UPDATEDIAGONAL_HPP
#define EL_BLAS_UPDATEDIAGONAL_HPP

#include <functional>
#include <iosfwd>

#include "El/core.hpp"
#include "El/core/./DistMatrix/Element.hpp"
#include "El/core/Element/decl.hpp"
#include "El/core/Element/impl.hpp"
#include "El/core/Matrix.hpp"
#include "El/core/environment/decl.hpp"
#include "El/core/imports/mpi.hpp"
#include "El/core/types.hpp"

namespace El {

template <typename T> class DistMultiVec;
template <typename T> class DistSparseMatrix;
template <typename T> class SparseMatrix;

template<typename T>
void UpdateDiagonal( Matrix<T>& A, T alpha, const Matrix<T>& d, Int offset )
{
    DEBUG_ONLY(CSE cse("UpdateDiagonal"))
    function<void(T&,T)> func
    ( [alpha]( T& beta, T gamma ) { beta += alpha*gamma; } );
    UpdateMappedDiagonal( A, d, func, offset );
}

template<typename T>
void UpdateRealPartOfDiagonal
( Matrix<T>& A, Base<T> alpha, const Matrix<Base<T>>& d, Int offset )
{
    DEBUG_ONLY(CSE cse("UpdateRealPartOfDiagonal"))
    function<void(T&,Base<T>)> func
    ( [alpha]( T& beta, Base<T> gamma ) { UpdateRealPart(beta,alpha*gamma); } );
    UpdateMappedDiagonal( A, d, func, offset );
}

template<typename T>
void UpdateImagPartOfDiagonal
( Matrix<T>& A, Base<T> alpha, const Matrix<Base<T>>& d, Int offset )
{
    DEBUG_ONLY(CSE cse("UpdateImagPartOfDiagonal"))
    function<void(T&,Base<T>)> func
    ( [alpha]( T& beta, Base<T> gamma ) { UpdateImagPart(beta,alpha*gamma); } );
    UpdateMappedDiagonal( A, d, func, offset );
}

template<typename T,Dist U,Dist V>
void UpdateDiagonal
( DistMatrix<T,U,V>& A, T alpha, const ElementalMatrix<T>& d, Int offset )
{
    DEBUG_ONLY(CSE cse("UpdateDiagonal"))
    function<void(T&,T)> func
    ( [alpha]( T& beta, T gamma ) { beta += alpha*gamma; } );
    UpdateMappedDiagonal( A, d, func, offset );
}

template<typename T,Dist U,Dist V>
void UpdateRealPartOfDiagonal
( DistMatrix<T,U,V>& A, Base<T> alpha, const ElementalMatrix<Base<T>>& d, 
  Int offset )
{
    DEBUG_ONLY(CSE cse("UpdateRealPartOfDiagonal"))
    function<void(T&,Base<T>)> func
    ( [alpha]( T& beta, Base<T> gamma ) { UpdateRealPart(beta,alpha*gamma); } );
    UpdateMappedDiagonal( A, d, func, offset );
}

template<typename T,Dist U,Dist V>
void UpdateImagPartOfDiagonal
( DistMatrix<T,U,V>& A, Base<T> alpha, const ElementalMatrix<Base<T>>& d, 
  Int offset )
{
    DEBUG_ONLY(CSE cse("UpdateImagPartOfDiagonal"))
    function<void(T&,Base<T>)> func
    ( [alpha]( T& beta, Base<T> gamma ) { UpdateImagPart(beta,alpha*gamma); } );
    UpdateMappedDiagonal( A, d, func, offset );
}

template<typename T>
void UpdateDiagonal
( SparseMatrix<T>& A, T alpha, const Matrix<T>& d, Int offset, 
  bool diagExists )
{
    DEBUG_ONLY(CSE cse("UpdateDiagonal"))
    function<void(T&,T)> func
    ( [alpha]( T& beta, T gamma ) { beta += alpha*gamma; } );
    UpdateMappedDiagonal( A, d, func, offset, diagExists );
}

template<typename T>
void UpdateRealPartOfDiagonal
( SparseMatrix<T>& A, Base<T> alpha, const Matrix<Base<T>>& d, Int offset, 
  bool diagExists )
{
    DEBUG_ONLY(CSE cse("UpdateRealPartOfDiagonal"))
    function<void(T&,Base<T>)> func
    ( [alpha]( T& beta, Base<T> gamma ) { UpdateRealPart(beta,alpha*gamma); } );
    UpdateMappedDiagonal( A, d, func, offset, diagExists );
}

template<typename T>
void UpdateImagPartOfDiagonal
( SparseMatrix<T>& A, Base<T> alpha, const Matrix<Base<T>>& d, Int offset,
  bool diagExists )
{
    DEBUG_ONLY(CSE cse("UpdateImagPartOfDiagonal"))
    function<void(T&,Base<T>)> func
    ( [alpha]( T& beta, Base<T> gamma ) { UpdateImagPart(beta,alpha*gamma); } );
    UpdateMappedDiagonal( A, d, func, offset, diagExists );
}

template<typename T>
void UpdateDiagonal
( DistSparseMatrix<T>& A, T alpha, const DistMultiVec<T>& d, Int offset,
  bool diagExists )
{
    DEBUG_ONLY(CSE cse("UpdateDiagonal"))
    function<void(T&,T)> func
    ( [alpha]( T& beta, T gamma ) { beta += alpha*gamma; } );
    UpdateMappedDiagonal( A, d, func, offset, diagExists );
}

template<typename T>
void UpdateRealPartOfDiagonal
( DistSparseMatrix<T>& A, Base<T> alpha, 
  const DistMultiVec<Base<T>>& d, Int offset, bool diagExists )
{
    DEBUG_ONLY(CSE cse("UpdateRealPartOfDiagonal"))
    function<void(T&,Base<T>)> func
    ( [alpha]( T& beta, Base<T> gamma ) { UpdateRealPart(beta,alpha*gamma); } );
    UpdateMappedDiagonal( A, d, func, offset, diagExists );
}

template<typename T>
void UpdateImagPartOfDiagonal
( DistSparseMatrix<T>& A, Base<T> alpha, 
  const DistMultiVec<Base<T>>& d, Int offset, bool diagExists )
{
    DEBUG_ONLY(CSE cse("UpdateImagPartOfDiagonal"))
    function<void(T&,Base<T>)> func
    ( [alpha]( T& beta, Base<T> gamma ) { UpdateImagPart(beta,alpha*gamma); } );
    UpdateMappedDiagonal( A, d, func, offset, diagExists );
}

} // namespace El

#endif // ifndef EL_BLAS_UPDATEDIAGONAL_HPP
