//
// Copyright (c) 2002--2010
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_LACGV_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_LACGV_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for lacgv is the netlib-compatible backend.
//
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end LAPACK-routine.
//
namespace detail {

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
inline std::ptrdiff_t lacgv( const fortran_int_t n, std::complex<float>* x,
        const fortran_int_t incx ) {
    fortran_int_t info(0);
    LAPACK_CLACGV( &n, x, &incx );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
inline std::ptrdiff_t lacgv( const fortran_int_t n, std::complex<double>* x,
        const fortran_int_t incx ) {
    fortran_int_t info(0);
    LAPACK_ZLACGV( &n, x, &incx );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to lacgv.
//
template< typename Value >
struct lacgv_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename VectorX >
    static std::ptrdiff_t invoke( const fortran_int_t n, VectorX& x,
            const fortran_int_t incx ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorX >::value) );
        BOOST_ASSERT( n >= 0 );
        return detail::lacgv( n, bindings::begin_value(x), incx );
    }

};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the lacgv_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for lacgv. Its overload differs for
// * VectorX&
//
template< typename VectorX >
inline std::ptrdiff_t lacgv( const fortran_int_t n, VectorX& x,
        const fortran_int_t incx ) {
    return lacgv_impl< typename value< VectorX >::type >::invoke( n, x,
            incx );
}

//
// Overloaded function for lacgv. Its overload differs for
// * const VectorX&
//
template< typename VectorX >
inline std::ptrdiff_t lacgv( const fortran_int_t n, const VectorX& x,
        const fortran_int_t incx ) {
    return lacgv_impl< typename value< VectorX >::type >::invoke( n, x,
            incx );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
