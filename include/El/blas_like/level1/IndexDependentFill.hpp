/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS_INDEXDEPENDENTFILL_HPP
#define EL_BLAS_INDEXDEPENDENTFILL_HPP

#include <functional>
#include <iosfwd>

#include "El/core.hpp"
#include "El/core/./DistMatrix/Abstract.hpp"
#include "El/core/Matrix.hpp"
#include "El/core/environment/decl.hpp"
#include "El/core/imports/mpi.hpp"

namespace El {

template<typename T>
void IndexDependentFill( Matrix<T>& A, function<T(Int,Int)> func )
{
    DEBUG_ONLY(CSE cse("IndexDependentFill"))
    const Int m = A.Height();
    const Int n = A.Width();
    for( Int j=0; j<n; ++j )
        for( Int i=0; i<m; ++i )
            A.Set( i, j, func(i,j) );
}

template<typename T>
void IndexDependentFill
( AbstractDistMatrix<T>& A, function<T(Int,Int)> func )
{
    DEBUG_ONLY(CSE cse("IndexDependentFill"))
    const Int mLoc = A.LocalHeight();
    const Int nLoc = A.LocalWidth();
    for( Int jLoc=0; jLoc<nLoc; ++jLoc )
    {
        const Int j = A.GlobalCol(jLoc);
        for( Int iLoc=0; iLoc<mLoc; ++iLoc )
        {
            const Int i = A.GlobalRow(iLoc);
            A.SetLocal( iLoc, jLoc, func(i,j) );
        }
    }
}

} // namespace El

#endif // ifndef EL_BLAS_INDEXDEPENDENTFILL_HPP
