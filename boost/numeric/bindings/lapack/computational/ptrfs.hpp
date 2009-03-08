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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_PTRFS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_PTRFS_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void ptrfs( integer_t const n, integer_t const nrhs, float* d,
            float* e, float* df, float* ef, float* b, integer_t const ldb,
            float* x, integer_t const ldx, float* ferr, float* berr,
            float* work, integer_t& info ) {
        LAPACK_SPTRFS( &n, &nrhs, d, e, df, ef, b, &ldb, x, &ldx, ferr, berr,
                work, &info );
    }
    inline void ptrfs( integer_t const n, integer_t const nrhs, double* d,
            double* e, double* df, double* ef, double* b, integer_t const ldb,
            double* x, integer_t const ldx, double* ferr, double* berr,
            double* work, integer_t& info ) {
        LAPACK_DPTRFS( &n, &nrhs, d, e, df, ef, b, &ldb, x, &ldx, ferr, berr,
                work, &info );
    }
    inline void ptrfs( char const uplo, integer_t const n,
            integer_t const nrhs, float* d, traits::complex_f* e, float* df,
            traits::complex_f* ef, traits::complex_f* b, integer_t const ldb,
            traits::complex_f* x, integer_t const ldx, float* ferr,
            float* berr, traits::complex_f* work, float* rwork,
            integer_t& info ) {
        LAPACK_CPTRFS( &uplo, &n, &nrhs, d, traits::complex_ptr(e), df,
                traits::complex_ptr(ef), traits::complex_ptr(b), &ldb,
                traits::complex_ptr(x), &ldx, ferr, berr,
                traits::complex_ptr(work), rwork, &info );
    }
    inline void ptrfs( char const uplo, integer_t const n,
            integer_t const nrhs, double* d, traits::complex_d* e, double* df,
            traits::complex_d* ef, traits::complex_d* b, integer_t const ldb,
            traits::complex_d* x, integer_t const ldx, double* ferr,
            double* berr, traits::complex_d* work, double* rwork,
            integer_t& info ) {
        LAPACK_ZPTRFS( &uplo, &n, &nrhs, d, traits::complex_ptr(e), df,
                traits::complex_ptr(ef), traits::complex_ptr(b), &ldb,
                traits::complex_ptr(x), &ldx, ferr, berr,
                traits::complex_ptr(work), rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct ptrfs_impl{};

// real specialization
template< typename ValueType >
struct ptrfs_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorD, typename VectorE, typename VectorDF,
            typename VectorEF, typename MatrixB, typename MatrixX,
            typename VectorFERR, typename VectorBERR, typename WORK >
    static void compute( integer_t const n, VectorD& d, VectorE& e,
            VectorDF& df, VectorEF& ef, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorE >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorDF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorEF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorFERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
#ifndef NDEBUG
        assert( n >= 0 );
        assert( traits::matrix_size2(b) >= 0 );
        assert( traits::vector_size(d) >= n );
        assert( traits::vector_size(e) >= n-1 );
        assert( traits::vector_size(df) >= n );
        assert( traits::vector_size(ef) >= n-1 );
        assert( traits::leading_dimension(b) >= std::max(1,n) );
        assert( traits::leading_dimension(x) >= std::max(1,n) );
        assert( traits::vector_size(berr) >= traits::matrix_size2(b) );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                n )));
#endif
        detail::ptrfs( n, traits::matrix_size2(b), traits::vector_storage(d),
                traits::vector_storage(e), traits::vector_storage(df),
                traits::vector_storage(ef), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::matrix_storage(x),
                traits::leading_dimension(x), traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename VectorD, typename VectorE, typename VectorDF,
            typename VectorEF, typename MatrixB, typename MatrixX,
            typename VectorFERR, typename VectorBERR >
    static void compute( integer_t const n, VectorD& d, VectorE& e,
            VectorDF& df, VectorEF& ef, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        compute( n, d, e, df, ef, b, x, ferr, berr, info,
                workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename VectorD, typename VectorE, typename VectorDF,
            typename VectorEF, typename MatrixB, typename MatrixX,
            typename VectorFERR, typename VectorBERR >
    static void compute( integer_t const n, VectorD& d, VectorE& e,
            VectorDF& df, VectorEF& ef, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        compute( n, d, e, df, ef, b, x, ferr, berr, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 2*n;
    }
};

// complex specialization
template< typename ValueType >
struct ptrfs_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorD, typename VectorE, typename VectorDF,
            typename VectorEF, typename MatrixB, typename MatrixX,
            typename VectorFERR, typename VectorBERR, typename WORK,
            typename RWORK >
    static void compute( char const uplo, integer_t const n, VectorD& d,
            VectorE& e, VectorDF& df, VectorEF& ef, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorDF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorFERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorE >::value_type, typename traits::vector_traits<
                VectorEF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorE >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorE >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
#ifndef NDEBUG
        assert( uplo == 'U' || uplo == 'L' );
        assert( n >= 0 );
        assert( traits::matrix_size2(b) >= 0 );
        assert( traits::vector_size(d) >= n );
        assert( traits::vector_size(e) >= n-1 );
        assert( traits::vector_size(df) >= n );
        assert( traits::vector_size(ef) >= n-1 );
        assert( traits::leading_dimension(b) >= std::max(1,n) );
        assert( traits::leading_dimension(x) >= std::max(1,n) );
        assert( traits::vector_size(berr) >= traits::matrix_size2(b) );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( n )));
        assert( traits::vector_size(work.select(real_type()) >=
                min_size_rwork( n )));
#endif
        detail::ptrfs( uplo, n, traits::matrix_size2(b),
                traits::vector_storage(d), traits::vector_storage(e),
                traits::vector_storage(df), traits::vector_storage(ef),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                traits::vector_storage(ferr), traits::vector_storage(berr),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename VectorD, typename VectorE, typename VectorDF,
            typename VectorEF, typename MatrixB, typename MatrixX,
            typename VectorFERR, typename VectorBERR >
    static void compute( char const uplo, integer_t const n, VectorD& d,
            VectorE& e, VectorDF& df, VectorEF& ef, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        compute( uplo, n, d, e, df, ef, b, x, ferr, berr, info,
                workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename VectorD, typename VectorE, typename VectorDF,
            typename VectorEF, typename MatrixB, typename MatrixX,
            typename VectorFERR, typename VectorBERR >
    static void compute( char const uplo, integer_t const n, VectorD& d,
            VectorE& e, VectorDF& df, VectorEF& ef, MatrixB& b, MatrixX& x,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        compute( uplo, n, d, e, df, ef, b, x, ferr, berr, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return n;
    }
};


// template function to call ptrfs
template< typename VectorD, typename VectorE, typename VectorDF,
        typename VectorEF, typename MatrixB, typename MatrixX,
        typename VectorFERR, typename VectorBERR, typename Workspace >
inline integer_t ptrfs( integer_t const n, VectorD& d, VectorE& e,
        VectorDF& df, VectorEF& ef, MatrixB& b, MatrixX& x, VectorFERR& ferr,
        VectorBERR& berr, Workspace work = optimal_workspace() ) {
    typedef typename traits::vector_traits< VectorD >::value_type value_type;
    integer_t info(0);
    ptrfs_impl< value_type >::compute( n, d, e, df, ef, b, x, ferr, berr,
            info, work );
    return info;
}
// template function to call ptrfs
template< typename VectorD, typename VectorE, typename VectorDF,
        typename VectorEF, typename MatrixB, typename MatrixX,
        typename VectorFERR, typename VectorBERR, typename Workspace >
inline integer_t ptrfs( char const uplo, integer_t const n, VectorD& d,
        VectorE& e, VectorDF& df, VectorEF& ef, MatrixB& b, MatrixX& x,
        VectorFERR& ferr, VectorBERR& berr,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::vector_traits< VectorD >::value_type value_type;
    integer_t info(0);
    ptrfs_impl< value_type >::compute( uplo, n, d, e, df, ef, b, x, ferr,
            berr, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif