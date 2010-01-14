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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_PBCON_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_PBCON_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/bandwidth.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/data_side.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for pbcon is the netlib-compatible backend.
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
// * float value-type.
//
inline std::ptrdiff_t pbcon( const char uplo, const fortran_int_t n,
        const fortran_int_t kd, const float* ab, const fortran_int_t ldab,
        const float anorm, float& rcond, float* work, fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_SPBCON( &uplo, &n, &kd, ab, &ldab, &anorm, &rcond, work, iwork,
            &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t pbcon( const char uplo, const fortran_int_t n,
        const fortran_int_t kd, const double* ab, const fortran_int_t ldab,
        const double anorm, double& rcond, double* work,
        fortran_int_t* iwork ) {
    fortran_int_t info(0);
    LAPACK_DPBCON( &uplo, &n, &kd, ab, &ldab, &anorm, &rcond, work, iwork,
            &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
inline std::ptrdiff_t pbcon( const char uplo, const fortran_int_t n,
        const fortran_int_t kd, const std::complex<float>* ab,
        const fortran_int_t ldab, const float anorm, float& rcond,
        std::complex<float>* work, float* rwork ) {
    fortran_int_t info(0);
    LAPACK_CPBCON( &uplo, &n, &kd, ab, &ldab, &anorm, &rcond, work, rwork,
            &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
inline std::ptrdiff_t pbcon( const char uplo, const fortran_int_t n,
        const fortran_int_t kd, const std::complex<double>* ab,
        const fortran_int_t ldab, const double anorm, double& rcond,
        std::complex<double>* work, double* rwork ) {
    fortran_int_t info(0);
    LAPACK_ZPBCON( &uplo, &n, &kd, ab, &ldab, &anorm, &rcond, work, rwork,
            &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to pbcon.
//
template< typename Value, typename Enable = void >
struct pbcon_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct pbcon_impl< Value, typename boost::enable_if< is_real< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixAB, typename WORK, typename IWORK >
    static std::ptrdiff_t invoke( const char uplo, const MatrixAB& ab,
            const real_type anorm, real_type& rcond, detail::workspace2< WORK,
            IWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_ASSERT( bindings::bandwidth(ab, uplo()) >= 0 );
        BOOST_ASSERT( bindings::size(work.select(fortran_int_t())) >=
                min_size_iwork( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_work( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size_column(ab) >= 0 );
        BOOST_ASSERT( bindings::size_minor(ab) == 1 ||
                bindings::stride_minor(ab) == 1 );
        BOOST_ASSERT( bindings::stride_major(ab) >= bindings::bandwidth(ab,
                uplo())+1 );
        return detail::pbcon( uplo, bindings::size_column(ab),
                bindings::bandwidth(ab, uplo()), bindings::begin_value(ab),
                bindings::stride_major(ab), anorm, rcond,
                bindings::begin_value(work.select(real_type())),
                bindings::begin_value(work.select(fortran_int_t())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixAB >
    static std::ptrdiff_t invoke( const char uplo, const MatrixAB& ab,
            const real_type anorm, real_type& rcond, minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        bindings::detail::array< real_type > tmp_work( min_size_work(
                bindings::size_column(ab) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( bindings::size_column(ab) ) );
        return invoke( uplo, ab, anorm, rcond, workspace( tmp_work,
                tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixAB >
    static std::ptrdiff_t invoke( const char uplo, const MatrixAB& ab,
            const real_type anorm, real_type& rcond, optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( uplo, ab, anorm, rcond, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return 3*n;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t n ) {
        return n;
    }
};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct pbcon_impl< Value, typename boost::enable_if< is_complex< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixAB, typename WORK, typename RWORK >
    static std::ptrdiff_t invoke( const char uplo, const MatrixAB& ab,
            const real_type anorm, real_type& rcond, detail::workspace2< WORK,
            RWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_ASSERT( bindings::bandwidth_upper(ab) >= 0 );
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_rwork( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size_column(ab) >= 0 );
        BOOST_ASSERT( bindings::size_minor(ab) == 1 ||
                bindings::stride_minor(ab) == 1 );
        BOOST_ASSERT( bindings::stride_major(ab) >=
                bindings::bandwidth_upper(ab)+1 );
        return detail::pbcon( uplo, bindings::size_column(ab),
                bindings::bandwidth_upper(ab), bindings::begin_value(ab),
                bindings::stride_major(ab), anorm, rcond,
                bindings::begin_value(work.select(value_type())),
                bindings::begin_value(work.select(real_type())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixAB >
    static std::ptrdiff_t invoke( const char uplo, const MatrixAB& ab,
            const real_type anorm, real_type& rcond, minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        bindings::detail::array< value_type > tmp_work( min_size_work(
                bindings::size_column(ab) ) );
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork(
                bindings::size_column(ab) ) );
        return invoke( uplo, ab, anorm, rcond, workspace( tmp_work,
                tmp_rwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixAB >
    static std::ptrdiff_t invoke( const char uplo, const MatrixAB& ab,
            const real_type anorm, real_type& rcond, optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( uplo, ab, anorm, rcond, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return 2*n;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array rwork.
    //
    static std::ptrdiff_t min_size_rwork( const std::ptrdiff_t n ) {
        return n;
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the pbcon_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for pbcon. Its overload differs for
// * User-defined workspace
//
template< typename MatrixAB, typename Workspace >
inline std::ptrdiff_t pbcon( const char uplo, const MatrixAB& ab,
        const typename remove_imaginary< typename value<
        MatrixAB >::type >::type anorm, typename remove_imaginary<
        typename value< MatrixAB >::type >::type& rcond, Workspace work ) {
    return pbcon_impl< typename value< MatrixAB >::type >::invoke( uplo,
            ab, anorm, rcond, work );
}

//
// Overloaded function for pbcon. Its overload differs for
// * Default workspace-type (optimal)
//
template< typename MatrixAB >
inline std::ptrdiff_t pbcon( const char uplo, const MatrixAB& ab,
        const typename remove_imaginary< typename value<
        MatrixAB >::type >::type anorm, typename remove_imaginary<
        typename value< MatrixAB >::type >::type& rcond ) {
    return pbcon_impl< typename value< MatrixAB >::type >::invoke( uplo,
            ab, anorm, rcond, optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
