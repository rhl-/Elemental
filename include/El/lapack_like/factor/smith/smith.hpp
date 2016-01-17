//
// Created by Ryan H. Lewis on 1/16/16.
//
#pragma once
#ifndef ELEMENTAL_SMITH_HPP
#define ELEMENTAL_SMITH_HPP
#include <cstddef>
#include <El/core/imports/PrimeField.hpp>
#include <El/core/imports/PrimeField.hpp>
#include <El/core/SparseMatrix.hpp>

namespace El {
    namespace smith {

        template< std::size_t N>
        void reduce(SparseMatrix< PrimeField<N> > & A){ }

    } //end namespace Smith
} //end namespace El

#endif //ELEMENTAL_SMITH_HPP
