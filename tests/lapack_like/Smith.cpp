/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"
#include <unordered_map>

using namespace El;

template< std::size_t N> 
void TestCorrectness( const SparseMatrix<PrimeField< N>>& AOrig){}

template< std::size_t N, typename SimplicialChainComplex>
SparseMatrix< PrimeField< N>>
create_boundary( const SimplicialChainComplex& M)  {
    typedef typename SimplicialChainComplex::key_type Simplex;
    typedef typename Simplex::value_type Vertex_type; //we assume Vertex_type is equivalent to std::size_t else this makes no sense.

    SparseMatrix< PrimeField< N>> BD;
    BD.Resize( M.size(), M.size());
    for( auto& pair : M){
        std::size_t i = pair.second;
        const Simplex& sigma = pair.first;
        if( sigma.size() > 1) {
            Vertex_type removed = sigma.front();
            Simplex tau( sigma.begin()+1, sigma.end());
            int coefficient = 1;
            for (auto& vtx: tau){
                auto tau_ptr = M.find( tau);
                if( tau_ptr == M.end()){ throw std::invalid_argument( "Input SC must be closed under face relation"); }
                std::size_t j = tau_ptr->second;
                BD.QueueUpdate(i,j, coefficient);
                coefficient *= -1;
                std::swap( vtx, removed);
            }
        }
    }
    BD.ProcessQueues();
    return BD;
}

template< typename T>
inline std::size_t pjw_hash( const T & key){
    std::size_t h, g;
    h = 0;
    for( auto i : key){
      h = (h << 4) + i;
      if ((g = h & 0xf0000000)) {
	h = h^(g >> 24);
	h = h^g;
      }
    }
   return h;
} 


namespace std {
template<>
struct hash< std::vector< std::size_t>>{
	std::size_t operator()( const std::vector<std::size_t> & key) const{
		return pjw_hash( key);	
	}
}
; 
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
     
     C.emplace( std::vector< std::size_t>{1,2,3}, 6 );
     C.emplace( std::vector< std::size_t>{2,3}, 5 );
     C.emplace( std::vector< std::size_t>{1,3}, 4 );
     C.emplace( std::vector< std::size_t>{1,3}, 3 );
     C.emplace( std::vector< std::size_t>{1}, 2 );
     C.emplace( std::vector< std::size_t>{2}, 1 );
     C.emplace( std::vector< std::size_t>{3}, 0 );

     SparseMatrix M = create_boundary< 3>( C);
     El::Display( M, "Boundary Matrix");
     El::smith::reduce( M);
    }
    catch( exception& e ) { ReportException(e); }

    return 0;
}
