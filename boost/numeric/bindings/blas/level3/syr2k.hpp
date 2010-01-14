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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL3_SYR2K_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL3_SYR2K_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/data_order.hpp>
#include <boost/numeric/bindings/data_side.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/trans_tag.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The BLAS-backend is selected by defining a pre-processor variable,
//  which can be one of
// * for CBLAS, define BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
// * for CUBLAS, define BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
// * netlib-compatible BLAS is the default
//
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
#include <boost/numeric/bindings/blas/detail/cblas.h>
#include <boost/numeric/bindings/blas/detail/cblas_option.hpp>
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
#include <boost/numeric/bindings/blas/detail/cublas.h>
#include <boost/numeric/bindings/blas/detail/blas_option.hpp>
#else
#include <boost/numeric/bindings/blas/detail/blas.h>
#include <boost/numeric/bindings/blas/detail/blas_option.hpp>
#endif

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end BLAS-routine.
//
namespace detail {

#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
//
// Overloaded function for dispatching to
// * CBLAS backend, and
// * float value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const int n, const int k,
        const float alpha, const float* a, const int lda, const float* b,
        const int ldb, const float beta, float* c, const int ldc ) {
    cblas_ssyr2k( cblas_option< Order >::value, cblas_option< UpLo >::value,
            cblas_option< Trans >::value, n, k, alpha, a, lda, b, ldb, beta,
            c, ldc );
}

//
// Overloaded function for dispatching to
// * CBLAS backend, and
// * double value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const int n, const int k,
        const double alpha, const double* a, const int lda, const double* b,
        const int ldb, const double beta, double* c, const int ldc ) {
    cblas_dsyr2k( cblas_option< Order >::value, cblas_option< UpLo >::value,
            cblas_option< Trans >::value, n, k, alpha, a, lda, b, ldb, beta,
            c, ldc );
}

//
// Overloaded function for dispatching to
// * CBLAS backend, and
// * complex<float> value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const int n, const int k,
        const std::complex<float> alpha, const std::complex<float>* a,
        const int lda, const std::complex<float>* b, const int ldb,
        const std::complex<float> beta, std::complex<float>* c,
        const int ldc ) {
    cblas_csyr2k( cblas_option< Order >::value, cblas_option< UpLo >::value,
            cblas_option< Trans >::value, n, k, &alpha, a, lda, b, ldb, &beta,
            c, ldc );
}

//
// Overloaded function for dispatching to
// * CBLAS backend, and
// * complex<double> value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const int n, const int k,
        const std::complex<double> alpha, const std::complex<double>* a,
        const int lda, const std::complex<double>* b, const int ldb,
        const std::complex<double> beta, std::complex<double>* c,
        const int ldc ) {
    cblas_zsyr2k( cblas_option< Order >::value, cblas_option< UpLo >::value,
            cblas_option< Trans >::value, n, k, &alpha, a, lda, b, ldb, &beta,
            c, ldc );
}

#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * float value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const int n, const int k,
        const float alpha, const float* a, const int lda, const float* b,
        const int ldb, const float beta, float* c, const int ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasSsyr2k( blas_option< UpLo >::value, blas_option< Trans >::value, n,
            k, alpha, a, lda, b, ldb, beta, c, ldc );
}

//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * double value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const int n, const int k,
        const double alpha, const double* a, const int lda, const double* b,
        const int ldb, const double beta, double* c, const int ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasDsyr2k( blas_option< UpLo >::value, blas_option< Trans >::value, n,
            k, alpha, a, lda, b, ldb, beta, c, ldc );
}

//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * complex<float> value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const int n, const int k,
        const std::complex<float> alpha, const std::complex<float>* a,
        const int lda, const std::complex<float>* b, const int ldb,
        const std::complex<float> beta, std::complex<float>* c,
        const int ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasCsyr2k( blas_option< UpLo >::value, blas_option< Trans >::value, n,
            k, alpha, a, lda, b, ldb, beta, c, ldc );
}

//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * complex<double> value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const int n, const int k,
        const std::complex<double> alpha, const std::complex<double>* a,
        const int lda, const std::complex<double>* b, const int ldb,
        const std::complex<double> beta, std::complex<double>* c,
        const int ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    // NOT FOUND();
}

#else
//
// Overloaded function for dispatching to
// * netlib-compatible BLAS backend (the default), and
// * float value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const fortran_int_t n,
        const fortran_int_t k, const float alpha, const float* a,
        const fortran_int_t lda, const float* b, const fortran_int_t ldb,
        const float beta, float* c, const fortran_int_t ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    BLAS_SSYR2K( &blas_option< UpLo >::value, &blas_option< Trans >::value,
            &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc );
}

//
// Overloaded function for dispatching to
// * netlib-compatible BLAS backend (the default), and
// * double value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const fortran_int_t n,
        const fortran_int_t k, const double alpha, const double* a,
        const fortran_int_t lda, const double* b, const fortran_int_t ldb,
        const double beta, double* c, const fortran_int_t ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    BLAS_DSYR2K( &blas_option< UpLo >::value, &blas_option< Trans >::value,
            &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc );
}

//
// Overloaded function for dispatching to
// * netlib-compatible BLAS backend (the default), and
// * complex<float> value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const fortran_int_t n,
        const fortran_int_t k, const std::complex<float> alpha,
        const std::complex<float>* a, const fortran_int_t lda,
        const std::complex<float>* b, const fortran_int_t ldb,
        const std::complex<float> beta, std::complex<float>* c,
        const fortran_int_t ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    BLAS_CSYR2K( &blas_option< UpLo >::value, &blas_option< Trans >::value,
            &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc );
}

//
// Overloaded function for dispatching to
// * netlib-compatible BLAS backend (the default), and
// * complex<double> value-type.
//
template< typename Order, typename UpLo, typename Trans >
inline void syr2k( Order, UpLo, Trans, const fortran_int_t n,
        const fortran_int_t k, const std::complex<double> alpha,
        const std::complex<double>* a, const fortran_int_t lda,
        const std::complex<double>* b, const fortran_int_t ldb,
        const std::complex<double> beta, std::complex<double>* c,
        const fortran_int_t ldc ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    BLAS_ZSYR2K( &blas_option< UpLo >::value, &blas_option< Trans >::value,
            &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc );
}

#endif

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to syr2k.
//
template< typename Value >
struct syr2k_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef void return_type;

    //
    // Static member function that
    // * Deduces the required arguments for dispatching to BLAS, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename MatrixC >
    static return_type invoke( const value_type alpha, const MatrixA& a,
            const MatrixB& b, const value_type beta, MatrixC& c ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::data_order< MatrixB >::type order;
        typedef typename result_of::data_side< MatrixC >::type uplo;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        BOOST_STATIC_ASSERT( (is_same< typename remove_const< typename value<
                MatrixA >::type >::type, typename remove_const<
                typename value< MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (is_same< typename remove_const< typename value<
                MatrixA >::type >::type, typename remove_const<
                typename value< MatrixC >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixC >::value) );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_minor(c) == 1 ||
                bindings::stride_minor(c) == 1 );
        detail::syr2k( order(), uplo(), trans(),
                bindings::size_column(c), bindings::size_column(a), alpha,
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(b), bindings::stride_major(b), beta,
                bindings::begin_value(c), bindings::stride_major(c) );
    }
};

//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. Calls
// to these functions are passed to the syr2k_impl classes. In the 
// documentation, the const-overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for syr2k. Its overload differs for
// * MatrixC&
//
template< typename MatrixA, typename MatrixB, typename MatrixC >
inline typename syr2k_impl< typename value< MatrixA >::type >::return_type
syr2k( const typename value< MatrixA >::type alpha, const MatrixA& a,
        const MatrixB& b, const typename value< MatrixA >::type beta,
        MatrixC& c ) {
    syr2k_impl< typename value< MatrixA >::type >::invoke( alpha, a, b,
            beta, c );
}

//
// Overloaded function for syr2k. Its overload differs for
// * const MatrixC&
//
template< typename MatrixA, typename MatrixB, typename MatrixC >
inline typename syr2k_impl< typename value< MatrixA >::type >::return_type
syr2k( const typename value< MatrixA >::type alpha, const MatrixA& a,
        const MatrixB& b, const typename value< MatrixA >::type beta,
        const MatrixC& c ) {
    syr2k_impl< typename value< MatrixA >::type >::invoke( alpha, a, b,
            beta, c );
}

} // namespace blas
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
