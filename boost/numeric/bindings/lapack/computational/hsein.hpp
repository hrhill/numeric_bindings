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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_HSEIN_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_HSEIN_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for hsein is the netlib-compatible backend.
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
template< typename Side >
inline std::ptrdiff_t hsein( const Side side, const char eigsrc,
        const char initv, fortran_bool_t* select, const fortran_int_t n,
        const float* h, const fortran_int_t ldh, float* wr, const float* wi,
        float* vl, const fortran_int_t ldvl, float* vr,
        const fortran_int_t ldvr, const fortran_int_t mm, fortran_int_t& m,
        float* work, fortran_int_t* ifaill, fortran_int_t* ifailr ) {
    fortran_int_t info(0);
    LAPACK_SHSEIN( &lapack_option< Side >::value, &eigsrc, &initv, select, &n,
            h, &ldh, wr, wi, vl, &ldvl, vr, &ldvr, &mm, &m, work, ifaill,
            ifailr, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
template< typename Side >
inline std::ptrdiff_t hsein( const Side side, const char eigsrc,
        const char initv, fortran_bool_t* select, const fortran_int_t n,
        const double* h, const fortran_int_t ldh, double* wr,
        const double* wi, double* vl, const fortran_int_t ldvl, double* vr,
        const fortran_int_t ldvr, const fortran_int_t mm, fortran_int_t& m,
        double* work, fortran_int_t* ifaill, fortran_int_t* ifailr ) {
    fortran_int_t info(0);
    LAPACK_DHSEIN( &lapack_option< Side >::value, &eigsrc, &initv, select, &n,
            h, &ldh, wr, wi, vl, &ldvl, vr, &ldvr, &mm, &m, work, ifaill,
            ifailr, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
template< typename Side >
inline std::ptrdiff_t hsein( const Side side, const char eigsrc,
        const char initv, const fortran_bool_t* select, const fortran_int_t n,
        const std::complex<float>* h, const fortran_int_t ldh,
        std::complex<float>* w, std::complex<float>* vl,
        const fortran_int_t ldvl, std::complex<float>* vr,
        const fortran_int_t ldvr, const fortran_int_t mm, fortran_int_t& m,
        std::complex<float>* work, float* rwork, fortran_int_t* ifaill,
        fortran_int_t* ifailr ) {
    fortran_int_t info(0);
    LAPACK_CHSEIN( &lapack_option< Side >::value, &eigsrc, &initv, select, &n,
            h, &ldh, w, vl, &ldvl, vr, &ldvr, &mm, &m, work, rwork, ifaill,
            ifailr, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
template< typename Side >
inline std::ptrdiff_t hsein( const Side side, const char eigsrc,
        const char initv, const fortran_bool_t* select, const fortran_int_t n,
        const std::complex<double>* h, const fortran_int_t ldh,
        std::complex<double>* w, std::complex<double>* vl,
        const fortran_int_t ldvl, std::complex<double>* vr,
        const fortran_int_t ldvr, const fortran_int_t mm, fortran_int_t& m,
        std::complex<double>* work, double* rwork, fortran_int_t* ifaill,
        fortran_int_t* ifailr ) {
    fortran_int_t info(0);
    LAPACK_ZHSEIN( &lapack_option< Side >::value, &eigsrc, &initv, select, &n,
            h, &ldh, w, vl, &ldvl, vr, &ldvr, &mm, &m, work, rwork, ifaill,
            ifailr, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to hsein.
//
template< typename Value, typename Enable = void >
struct hsein_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct hsein_impl< Value, typename boost::enable_if< is_real< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename Side, typename VectorSELECT, typename MatrixH,
            typename VectorWR, typename VectorWI, typename MatrixVL,
            typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR,
            typename WORK >
    static std::ptrdiff_t invoke( const Side side, const char eigsrc,
            const char initv, VectorSELECT& select, const MatrixH& h,
            VectorWR& wr, const VectorWI& wi, MatrixVL& vl, MatrixVR& vr,
            const fortran_int_t mm, fortran_int_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, detail::workspace1<
            WORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixH >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixVL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixVR >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixH >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorWR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixH >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorWI >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixH >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixVL >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixH >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixVR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorIFAILL >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorIFAILR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorSELECT >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorWR >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixVL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixVR >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorIFAILL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorIFAILR >::value) );
        BOOST_ASSERT( bindings::size(select) >= bindings::size_column(h) );
        BOOST_ASSERT( bindings::size(wi) >= bindings::size_column(h) );
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_work( bindings::size_column(h) ));
        BOOST_ASSERT( bindings::size(wr) >= bindings::size_column(h) );
        BOOST_ASSERT( bindings::size_column(h) >= 0 );
        BOOST_ASSERT( bindings::size_minor(h) == 1 ||
                bindings::stride_minor(h) == 1 );
        BOOST_ASSERT( bindings::size_minor(vl) == 1 ||
                bindings::stride_minor(vl) == 1 );
        BOOST_ASSERT( bindings::size_minor(vr) == 1 ||
                bindings::stride_minor(vr) == 1 );
        BOOST_ASSERT( bindings::stride_major(h) >= std::max< std::ptrdiff_t >(1,
                bindings::size_column(h)) );
        BOOST_ASSERT( eigsrc == 'Q' || eigsrc == 'N' );
        BOOST_ASSERT( initv == 'N' || initv == 'U' );
        return detail::hsein( side, eigsrc, initv,
                bindings::begin_value(select), bindings::size_column(h),
                bindings::begin_value(h), bindings::stride_major(h),
                bindings::begin_value(wr), bindings::begin_value(wi),
                bindings::begin_value(vl), bindings::stride_major(vl),
                bindings::begin_value(vr), bindings::stride_major(vr), mm, m,
                bindings::begin_value(work.select(real_type())),
                bindings::begin_value(ifaill), bindings::begin_value(ifailr) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename Side, typename VectorSELECT, typename MatrixH,
            typename VectorWR, typename VectorWI, typename MatrixVL,
            typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR >
    static std::ptrdiff_t invoke( const Side side, const char eigsrc,
            const char initv, VectorSELECT& select, const MatrixH& h,
            VectorWR& wr, const VectorWI& wi, MatrixVL& vl, MatrixVR& vr,
            const fortran_int_t mm, fortran_int_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, minimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        bindings::detail::array< real_type > tmp_work( min_size_work(
                bindings::size_column(h) ) );
        return invoke( side, eigsrc, initv, select, h, wr, wi, vl, vr, mm, m,
                ifaill, ifailr, workspace( tmp_work ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename Side, typename VectorSELECT, typename MatrixH,
            typename VectorWR, typename VectorWI, typename MatrixVL,
            typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR >
    static std::ptrdiff_t invoke( const Side side, const char eigsrc,
            const char initv, VectorSELECT& select, const MatrixH& h,
            VectorWR& wr, const VectorWI& wi, MatrixVL& vl, MatrixVR& vr,
            const fortran_int_t mm, fortran_int_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, optimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( side, eigsrc, initv, select, h, wr, wi, vl, vr, mm, m,
                ifaill, ifailr, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return (n+2)*n;
    }
};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct hsein_impl< Value, typename boost::enable_if< is_complex< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename Side, typename VectorSELECT, typename MatrixH,
            typename VectorW, typename MatrixVL, typename MatrixVR,
            typename VectorIFAILL, typename VectorIFAILR, typename WORK,
            typename RWORK >
    static std::ptrdiff_t invoke( const Side side, const char eigsrc,
            const char initv, const VectorSELECT& select, const MatrixH& h,
            VectorW& w, MatrixVL& vl, MatrixVR& vr,
            const fortran_int_t mm, fortran_int_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, detail::workspace2<
            WORK, RWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixH >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixVL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_column_major< MatrixVR >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< VectorIFAILL >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorIFAILR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixH >::type >::type,
                typename remove_const< typename bindings::value_type<
                VectorW >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixH >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixVL >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixH >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixVR >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorW >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixVL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixVR >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorIFAILL >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< VectorIFAILR >::value) );
        BOOST_ASSERT( bindings::size(select) >= bindings::size_column(h) );
        BOOST_ASSERT( bindings::size(w) >= bindings::size_column(h) );
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_rwork( bindings::size_column(h) ));
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( bindings::size_column(h) ));
        BOOST_ASSERT( bindings::size_column(h) >= 0 );
        BOOST_ASSERT( bindings::size_minor(h) == 1 ||
                bindings::stride_minor(h) == 1 );
        BOOST_ASSERT( bindings::size_minor(vl) == 1 ||
                bindings::stride_minor(vl) == 1 );
        BOOST_ASSERT( bindings::size_minor(vr) == 1 ||
                bindings::stride_minor(vr) == 1 );
        BOOST_ASSERT( bindings::stride_major(h) >= std::max< std::ptrdiff_t >(1,
                bindings::size_column(h)) );
        BOOST_ASSERT( eigsrc == 'Q' || eigsrc == 'N' );
        BOOST_ASSERT( initv == 'N' || initv == 'U' );
        return detail::hsein( side, eigsrc, initv,
                bindings::begin_value(select), bindings::size_column(h),
                bindings::begin_value(h), bindings::stride_major(h),
                bindings::begin_value(w), bindings::begin_value(vl),
                bindings::stride_major(vl), bindings::begin_value(vr),
                bindings::stride_major(vr), mm, m,
                bindings::begin_value(work.select(value_type())),
                bindings::begin_value(work.select(real_type())),
                bindings::begin_value(ifaill), bindings::begin_value(ifailr) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename Side, typename VectorSELECT, typename MatrixH,
            typename VectorW, typename MatrixVL, typename MatrixVR,
            typename VectorIFAILL, typename VectorIFAILR >
    static std::ptrdiff_t invoke( const Side side, const char eigsrc,
            const char initv, const VectorSELECT& select, const MatrixH& h,
            VectorW& w, MatrixVL& vl, MatrixVR& vr,
            const fortran_int_t mm, fortran_int_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, minimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        bindings::detail::array< value_type > tmp_work( min_size_work(
                bindings::size_column(h) ) );
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork(
                bindings::size_column(h) ) );
        return invoke( side, eigsrc, initv, select, h, w, vl, vr, mm, m,
                ifaill, ifailr, workspace( tmp_work, tmp_rwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename Side, typename VectorSELECT, typename MatrixH,
            typename VectorW, typename MatrixVL, typename MatrixVR,
            typename VectorIFAILL, typename VectorIFAILR >
    static std::ptrdiff_t invoke( const Side side, const char eigsrc,
            const char initv, const VectorSELECT& select, const MatrixH& h,
            VectorW& w, MatrixVL& vl, MatrixVR& vr,
            const fortran_int_t mm, fortran_int_t& m,
            VectorIFAILL& ifaill, VectorIFAILR& ifailr, optimal_workspace ) {
        namespace bindings = ::boost::numeric::bindings;
        return invoke( side, eigsrc, initv, select, h, w, vl, vr, mm, m,
                ifaill, ifailr, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return n*n;
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
// Calls to these functions are passed to the hsein_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for hsein. Its overload differs for
// * MatrixVL&
// * MatrixVR&
// * User-defined workspace
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorWR, typename VectorWI, typename MatrixVL,
        typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        VectorSELECT& select, const MatrixH& h, VectorWR& wr,
        const VectorWI& wi, MatrixVL& vl, MatrixVR& vr,
        const fortran_int_t mm, fortran_int_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr, Workspace work ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, wr, wi,
            vl, vr, mm, m, ifaill, ifailr, work );
}

//
// Overloaded function for hsein. Its overload differs for
// * MatrixVL&
// * MatrixVR&
// * Default workspace-type (optimal)
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorWR, typename VectorWI, typename MatrixVL,
        typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR >
inline typename boost::disable_if< detail::is_workspace< VectorIFAILR >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        VectorSELECT& select, const MatrixH& h, VectorWR& wr,
        const VectorWI& wi, MatrixVL& vl, MatrixVR& vr,
        const fortran_int_t mm, fortran_int_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, wr, wi,
            vl, vr, mm, m, ifaill, ifailr, optimal_workspace() );
}

//
// Overloaded function for hsein. Its overload differs for
// * const MatrixVL&
// * MatrixVR&
// * User-defined workspace
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorWR, typename VectorWI, typename MatrixVL,
        typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        VectorSELECT& select, const MatrixH& h, VectorWR& wr,
        const VectorWI& wi, const MatrixVL& vl, MatrixVR& vr,
        const fortran_int_t mm, fortran_int_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr, Workspace work ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, wr, wi,
            vl, vr, mm, m, ifaill, ifailr, work );
}

//
// Overloaded function for hsein. Its overload differs for
// * const MatrixVL&
// * MatrixVR&
// * Default workspace-type (optimal)
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorWR, typename VectorWI, typename MatrixVL,
        typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR >
inline typename boost::disable_if< detail::is_workspace< VectorIFAILR >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        VectorSELECT& select, const MatrixH& h, VectorWR& wr,
        const VectorWI& wi, const MatrixVL& vl, MatrixVR& vr,
        const fortran_int_t mm, fortran_int_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, wr, wi,
            vl, vr, mm, m, ifaill, ifailr, optimal_workspace() );
}

//
// Overloaded function for hsein. Its overload differs for
// * MatrixVL&
// * const MatrixVR&
// * User-defined workspace
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorWR, typename VectorWI, typename MatrixVL,
        typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        VectorSELECT& select, const MatrixH& h, VectorWR& wr,
        const VectorWI& wi, MatrixVL& vl, const MatrixVR& vr,
        const fortran_int_t mm, fortran_int_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr, Workspace work ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, wr, wi,
            vl, vr, mm, m, ifaill, ifailr, work );
}

//
// Overloaded function for hsein. Its overload differs for
// * MatrixVL&
// * const MatrixVR&
// * Default workspace-type (optimal)
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorWR, typename VectorWI, typename MatrixVL,
        typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR >
inline typename boost::disable_if< detail::is_workspace< VectorIFAILR >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        VectorSELECT& select, const MatrixH& h, VectorWR& wr,
        const VectorWI& wi, MatrixVL& vl, const MatrixVR& vr,
        const fortran_int_t mm, fortran_int_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, wr, wi,
            vl, vr, mm, m, ifaill, ifailr, optimal_workspace() );
}

//
// Overloaded function for hsein. Its overload differs for
// * const MatrixVL&
// * const MatrixVR&
// * User-defined workspace
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorWR, typename VectorWI, typename MatrixVL,
        typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        VectorSELECT& select, const MatrixH& h, VectorWR& wr,
        const VectorWI& wi, const MatrixVL& vl, const MatrixVR& vr,
        const fortran_int_t mm, fortran_int_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr, Workspace work ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, wr, wi,
            vl, vr, mm, m, ifaill, ifailr, work );
}

//
// Overloaded function for hsein. Its overload differs for
// * const MatrixVL&
// * const MatrixVR&
// * Default workspace-type (optimal)
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorWR, typename VectorWI, typename MatrixVL,
        typename MatrixVR, typename VectorIFAILL, typename VectorIFAILR >
inline typename boost::disable_if< detail::is_workspace< VectorIFAILR >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        VectorSELECT& select, const MatrixH& h, VectorWR& wr,
        const VectorWI& wi, const MatrixVL& vl, const MatrixVR& vr,
        const fortran_int_t mm, fortran_int_t& m,
        VectorIFAILL& ifaill, VectorIFAILR& ifailr ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, wr, wi,
            vl, vr, mm, m, ifaill, ifailr, optimal_workspace() );
}
//
// Overloaded function for hsein. Its overload differs for
// * MatrixVL&
// * MatrixVR&
// * User-defined workspace
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorW, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        const VectorSELECT& select, const MatrixH& h, VectorW& w,
        MatrixVL& vl, MatrixVR& vr, const fortran_int_t mm,
        fortran_int_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr,
        Workspace work ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, w, vl,
            vr, mm, m, ifaill, ifailr, work );
}

//
// Overloaded function for hsein. Its overload differs for
// * MatrixVL&
// * MatrixVR&
// * Default workspace-type (optimal)
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorW, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR >
inline typename boost::disable_if< detail::is_workspace< VectorIFAILR >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        const VectorSELECT& select, const MatrixH& h, VectorW& w,
        MatrixVL& vl, MatrixVR& vr, const fortran_int_t mm,
        fortran_int_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, w, vl,
            vr, mm, m, ifaill, ifailr, optimal_workspace() );
}

//
// Overloaded function for hsein. Its overload differs for
// * const MatrixVL&
// * MatrixVR&
// * User-defined workspace
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorW, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        const VectorSELECT& select, const MatrixH& h, VectorW& w,
        const MatrixVL& vl, MatrixVR& vr, const fortran_int_t mm,
        fortran_int_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr,
        Workspace work ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, w, vl,
            vr, mm, m, ifaill, ifailr, work );
}

//
// Overloaded function for hsein. Its overload differs for
// * const MatrixVL&
// * MatrixVR&
// * Default workspace-type (optimal)
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorW, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR >
inline typename boost::disable_if< detail::is_workspace< VectorIFAILR >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        const VectorSELECT& select, const MatrixH& h, VectorW& w,
        const MatrixVL& vl, MatrixVR& vr, const fortran_int_t mm,
        fortran_int_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, w, vl,
            vr, mm, m, ifaill, ifailr, optimal_workspace() );
}

//
// Overloaded function for hsein. Its overload differs for
// * MatrixVL&
// * const MatrixVR&
// * User-defined workspace
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorW, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        const VectorSELECT& select, const MatrixH& h, VectorW& w,
        MatrixVL& vl, const MatrixVR& vr, const fortran_int_t mm,
        fortran_int_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr,
        Workspace work ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, w, vl,
            vr, mm, m, ifaill, ifailr, work );
}

//
// Overloaded function for hsein. Its overload differs for
// * MatrixVL&
// * const MatrixVR&
// * Default workspace-type (optimal)
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorW, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR >
inline typename boost::disable_if< detail::is_workspace< VectorIFAILR >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        const VectorSELECT& select, const MatrixH& h, VectorW& w,
        MatrixVL& vl, const MatrixVR& vr, const fortran_int_t mm,
        fortran_int_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, w, vl,
            vr, mm, m, ifaill, ifailr, optimal_workspace() );
}

//
// Overloaded function for hsein. Its overload differs for
// * const MatrixVL&
// * const MatrixVR&
// * User-defined workspace
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorW, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        const VectorSELECT& select, const MatrixH& h, VectorW& w,
        const MatrixVL& vl, const MatrixVR& vr, const fortran_int_t mm,
        fortran_int_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr,
        Workspace work ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, w, vl,
            vr, mm, m, ifaill, ifailr, work );
}

//
// Overloaded function for hsein. Its overload differs for
// * const MatrixVL&
// * const MatrixVR&
// * Default workspace-type (optimal)
//
template< typename Side, typename VectorSELECT, typename MatrixH,
        typename VectorW, typename MatrixVL, typename MatrixVR,
        typename VectorIFAILL, typename VectorIFAILR >
inline typename boost::disable_if< detail::is_workspace< VectorIFAILR >,
        std::ptrdiff_t >::type
hsein( const Side side, const char eigsrc, const char initv,
        const VectorSELECT& select, const MatrixH& h, VectorW& w,
        const MatrixVL& vl, const MatrixVR& vr, const fortran_int_t mm,
        fortran_int_t& m, VectorIFAILL& ifaill, VectorIFAILR& ifailr ) {
    return hsein_impl< typename bindings::value_type<
            MatrixH >::type >::invoke( side, eigsrc, initv, select, h, w, vl,
            vr, mm, m, ifaill, ifailr, optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
