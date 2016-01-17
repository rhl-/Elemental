/*
   Copyright (c) 2009-2016, Ryan H. Lewis
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#pragma once
#ifndef EL_IMPORTS_PRIME_FIELDS_HPP
#define EL_IMPORTS_PRIME_FIELDS_HPP
#include <cstddef>
#include <type_traits>
namespace El {

namespace detail {
 //Extended Euclidean Algorithm
 inline std::size_t inverse(const std::size_t a, const std::size_t prime) noexcept {
     if (a == 0) { return (std::size_t) 0; }
     std::size_t b = prime - 2;
     std::size_t x = 1, y = a;
     while (b > 0) {
         if (b % 2 == 1) {
             x = (x * y);
             if (x > prime) { x %= prime; }
         }
         y = (y * y);
         if (y > prime) { y %= prime; }
         b /= 2;
     }
     return x;
 }
 //TODO: Use these to enfornce that PrimeField is instantiated with a prime..
 constexpr bool any_factors( std::size_t target, std::size_t start, std::size_t step) {
     return
             !(start*start*36 > target)
             &&
             (
                     ( (step==1)
                       && (
                               (target%(start*6+1) == 0)
                               || (target%(start*6+5) == 0)
                       )
                     )
                     ||
                     ( (step > 1)
                       &&
                       (
                               any_factors( target, start, step/2 )
                               || any_factors( target, start+step/2, step/2 )
                       )
                     )
             );
 }
 constexpr bool is_prime( std::size_t target ) {
     // handle 2, 3 and 5 explicitly:
     return
             (target == 2 || target == 3 || target == 5)
             ||
             (
                     target != 0
                     && target != 1
                     && target%2 != 0
                     && target%3 != 0
                     && target%5 != 0
                     && !any_factors( target, 1, target/6 + 1 ) // can make that upper bound a bit tighter, but I don't care
             );
 }

} //end namespace detail


template< std::size_t _prime> //requires is_prime(_prime)
class PrimeField{
private:
    typedef PrimeField< _prime> Self;
public:
    static constexpr std::size_t prime = _prime;

    PrimeField(){}

    template< typename T>
    PrimeField( const T n): x( mod( n) ){}

    //mod avoid branch when possible.
    template <typename T>
    typename std::enable_if< std::is_unsigned<T>::value, std::size_t>::type
    mod(T n) const { return n%_prime; }

    template <typename T>
    typename std::enable_if< !std::is_unsigned<T>::value, std::size_t>::type
    mod(T n) const { return (n>=0)? (n % _prime) : (_prime-((-1*n)%_prime)); }

    //given an arbitrary number get a number between [0, prime)
    template< typename T>
    std::size_t get_number_data(const T & rhs) const { return mod( rhs); }

    std::size_t get_number_data( const Self& rhs) const { return mod( rhs.x); }

    template< typename T>
    Self& operator=( const T& from){
        x = get_number_data( from);
        return *this;
    }

    template< typename T>
    Self operator+( const T& rhs) const { return Self( x+get_number_data(rhs)); }

    template< typename T>
    Self& operator+=( const T& rhs){
        x+=get_number_data( rhs);
        x=mod( x);
        return *this;
    }

    template< typename T>
    Self operator-( const T& rhs) const {
        const std::size_t lhs = x  + (_prime - get_number_data(rhs));
        return Self( lhs);
    }
    template< typename T>
    Self& operator-=( const T& rhs){
        x = mod(x  + (_prime - get_number_data(rhs)));
        return *this;
    }

    template< typename T>
    Self operator*( const T& rhs) const { return Self( x*get_number_data(rhs)); }
    template< typename T>
    Self& operator*=( const T& rhs){
        x*=get_number_data(rhs);
        x = mod(x);
        return *this;
    }

    template< typename T>
    bool operator==( const T& rhs) const { return (x == get_number_data( rhs)); }

    template< typename T>
    bool operator!=( const T& rhs) const { return (x != get_number_data( rhs)); }

    template< typename T>
    Self operator/(const T& rhs) const{ return *this*inverse( rhs, _prime); }

    template< typename T>
    Self& operator/=(const T& rhs){
        *this = detail::inverse( rhs, _prime);
        return *this;
    }

    //TODO: Casting Operators?
    //(What would you even do?)
private:
    std::size_t x;
}; //class PrimeField


template< typename Stream, std::size_t N>
Stream& operator<<( Stream & out, const PrimeField< N> & x ){
    int value = x.get_number_data( x);
    if( N >2 && value >= N/2.0){ value = -1*(N -value); }
    out << value;
    return out;
}

template< typename Stream, std::size_t N>
Stream& operator<<( Stream & out, const PrimeField< N> && x ){
    out << x;
    return out;
}

} // namespace El

template<typename T, std::size_t N>
El::PrimeField< N> operator* (T k, const El::PrimeField< N> &m) { return m * k; }


#endif // ifndef EL_IMPORTS_PRIME_FIELDS_HPP
