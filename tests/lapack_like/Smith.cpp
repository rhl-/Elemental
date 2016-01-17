/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"
using namespace El;
template< std::size_t N> 
void TestCorrectness( const SparseMatrix<PrimeField< N>>& AOrig){}

template< std::size_t N, typename SimplicialChainComplex>
SparseMatrix< PrimeField< N>>
create_boundary( const SimplicialChainComplex& M) const {
    typedef SimplicialChainComplex::key_type Simplex;
    typedef Simplex::value_type Vertex_type; //we assume Vertex_type is equivalent to std::size_t else this makes no sense.

    SparseMatrix< PrimeField< N>> BD;
    BD.Resize( M.size(), M.size());
    for( auto& pair : M){
        std::size_t i = pair.second;
        const Simplex& sigma = pair.first;
        if( sigma.size() > 1) {
            Vertex_type removed = sigma.front();
            Simplex tau( sigma.begin()+1, sigma.end());
            coefficient = 1;
            for (auto& vtx: tau){
                auto tau_ptr = M.find( tau);
                if( tau_ptr == M.end()){ throw std::illegal_argument_exception( "Input SC must be closed under face relation"); }
                std::size_t j = tau_ptr->second;
                BD.QueueUpdate(i,j, coefficient);
                coefficient *= -1;
                std::swap( *vtx, removed);
            }
        }
    }
    BD.ProcessQueues();
    return BD;
}

int
main( int argc, char* argv[] )
{
    Environment env( argc, argv );
    mpi::Comm comm = mpi::COMM_WORLD;
    const Int commRank = mpi::Rank( comm );
    const Int commSize = mpi::Size( comm );

    try
    {
     typedef SparseMatrix< PrimeField<3> > SparseMatrix;
     typedef std::unordered_map< std::vector< std::size_t>, std::size_t> SimplicialChainComplex;
     SimplicialChainComplex C;
     C.emplace( {{1,2,3}, 6 });
     C.emplace( {{2,3}, 5 });
     C.emplace( {{1,3}, 4 });
     C.emplace( {{1,3}, 3 });
     C.emplace( {{1}, 2 });
     C.emplace( {{2}, 1 });
     C.emplace( {{3}, 0 });

     SparseMatrix M = create_boundary( C);
     El::Display( M, "Boundary Matrix");
     reduce( M);
    }
    catch( exception& e ) { ReportException(e); }

    return 0;
}
