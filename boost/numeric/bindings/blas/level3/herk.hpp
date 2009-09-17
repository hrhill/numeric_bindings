//
// Copyright (c) 2003--2009
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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL3_HERK_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL3_HERK_HPP

#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/blas/detail/blas.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {
namespace level3 {

// overloaded functions to call blas
namespace detail {
    inline void herk( const char uplo, const char trans, const integer_t n,
            const integer_t k, const float alpha, const traits::complex_f* a,
            const integer_t lda, const float beta, traits::complex_f* c,
            const integer_t ldc ) {
        BLAS_CHERK( &uplo, &trans, &n, &k, &alpha, traits::complex_ptr(a),
                &lda, &beta, traits::complex_ptr(c), &ldc );
    }
    inline void herk( const char uplo, const char trans, const integer_t n,
            const integer_t k, const double alpha, const traits::complex_d* a,
            const integer_t lda, const double beta, traits::complex_d* c,
            const integer_t ldc ) {
        BLAS_ZHERK( &uplo, &trans, &n, &k, &alpha, traits::complex_ptr(a),
                &lda, &beta, traits::complex_ptr(c), &ldc );
    }
}

// value-type based template
template< typename ValueType >
struct herk_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef void return_type;

    // templated specialization
    template< typename MatrixA, typename MatrixC >
    static return_type invoke( const char trans, const integer_t k,
            const real_type alpha, const MatrixA& a, const real_type beta,
            MatrixC& c ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixC >::value_type >::value) );
        detail::herk( traits::matrix_uplo_tag(c), trans,
                traits::matrix_num_columns(c), k, alpha,
                traits::matrix_storage(a), traits::leading_dimension(a), beta,
                traits::matrix_storage(c), traits::leading_dimension(c) );
    }
};

// low-level template function for direct calls to level3::herk
template< typename MatrixA, typename MatrixC >
inline typename herk_impl< typename traits::matrix_traits<
        MatrixA >::value_type >::return_type
herk( const char trans, const integer_t k,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixA >::value_type >::real_type alpha, const MatrixA& a,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixA >::value_type >::real_type beta, MatrixC& c ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    herk_impl< value_type >::invoke( trans, k, alpha, a, beta, c );
}

}}}}} // namespace boost::numeric::bindings::blas::level3

#endif
