/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_BLAS_HPP
#define EL_BLAS_HPP

#include <El/core/Element/decl.hpp>
#include <El/core/imports/mpc.hpp>

// Tuning parameters
// =================

namespace El {
//
//template<typename T> void SetLocalTrrkBlocksize( Int blocksize );
//template<> void SetLocalTrrkBlocksize<Int>( Int blocksize );
//template<> void SetLocalTrrkBlocksize<float>( Int blocksize );
//template<> void SetLocalTrrkBlocksize<double>( Int blocksize );
//template<> void SetLocalTrrkBlocksize<Complex<float>>( Int blocksize );
//template<> void SetLocalTrrkBlocksize<Complex<double>>( Int blocksize );
//#ifdef EL_HAVE_QD
//template<> void SetLocalTrrkBlocksize<DoubleDouble>( Int blocksize );
//template<> void SetLocalTrrkBlocksize<QuadDouble>( Int blocksize );
//#endif
//#ifdef EL_HAVE_QUAD
//template<> void SetLocalTrrkBlocksize<Quad>( Int blocksize );
//template<> void SetLocalTrrkBlocksize<Complex<Quad>>( Int blocksize );
//#endif
//#ifdef EL_HAVE_MPC
//template<> void SetLocalTrrkBlocksize<BigInt>( Int blocksize );
//template<> void SetLocalTrrkBlocksize<BigFloat>( Int blocksize );
//#endif
//
//template<typename T> void SetLocalTrr2kBlocksize( Int blocksize );
//template<> void SetLocalTrr2kBlocksize<Int>( Int blocksize );
//template<> void SetLocalTrr2kBlocksize<float>( Int blocksize );
//template<> void SetLocalTrr2kBlocksize<double>( Int blocksize );
//template<> void SetLocalTrr2kBlocksize<Complex<float>>( Int blocksize );
//template<> void SetLocalTrr2kBlocksize<Complex<double>>( Int blocksize );
//#ifdef EL_HAVE_QD
//template<> void SetLocalTrr2kBlocksize<DoubleDouble>( Int blocksize );
//template<> void SetLocalTrr2kBlocksize<QuadDouble>( Int blocksize );
//#endif
//#ifdef EL_HAVE_QUAD
//template<> void SetLocalTrr2kBlocksize<Quad>( Int blocksize );
//template<> void SetLocalTrr2kBlocksize<Complex<Quad>>( Int blocksize );
//#endif
//#ifdef EL_HAVE_MPC
//template<> void SetLocalTrr2kBlocksize<BigInt>( Int blocksize );
//template<> void SetLocalTrr2kBlocksize<BigFloat>( Int blocksize );
//#endif
//
//
//template<typename T> Int LocalTrrkBlocksize();
//template<> Int LocalTrrkBlocksize<Int>();
//template<> Int LocalTrrkBlocksize<float>();
//template<> Int LocalTrrkBlocksize<double>();
//template<> Int LocalTrrkBlocksize<Complex<float>>();
//template<> Int LocalTrrkBlocksize<Complex<double>>();
//#ifdef EL_HAVE_QD
//template<> Int LocalTrrkBlocksize<DoubleDouble>();
//template<> Int LocalTrrkBlocksize<QuadDouble>();
//#endif
//#ifdef EL_HAVE_QUAD
//template<> Int LocalTrrkBlocksize<Quad>();
//template<> Int LocalTrrkBlocksize<Complex<Quad>>();
//#endif
//#ifdef EL_HAVE_MPC
//template<> Int LocalTrrkBlocksize<BigInt>();
//template<> Int LocalTrrkBlocksize<BigFloat>();
//#endif
//
//template<typename T> Int LocalTrr2kBlocksize();
//template<> Int LocalTrr2kBlocksize<Int>();
//template<> Int LocalTrr2kBlocksize<float>();
//template<> Int LocalTrr2kBlocksize<double>();
//template<> Int LocalTrr2kBlocksize<Complex<float>>();
//template<> Int LocalTrr2kBlocksize<Complex<double>>();
//#ifdef EL_HAVE_QD
//template<> Int LocalTrr2kBlocksize<DoubleDouble>();
//template<> Int LocalTrr2kBlocksize<QuadDouble>();
//#endif
//#ifdef EL_HAVE_QUAD
//template<> Int LocalTrr2kBlocksize<Quad>();
//template<> Int LocalTrr2kBlocksize<Complex<Quad>>();
//#endif
//#ifdef EL_HAVE_MPC
//template<> Int LocalTrr2kBlocksize<BigInt>();
//template<> Int LocalTrr2kBlocksize<BigFloat>();
//#endif

} // namespace El

#include <El/blas_like/level1.hpp>
#include <El/blas_like/level2.hpp>
#include <El/blas_like/level3.hpp>

#endif // ifndef EL_BLAS_HPP
