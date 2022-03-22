#ifndef GR_POLY_H
#define GR_POLY_H

#ifdef GR_POLY_INLINES_C
#define GR_POLY_INLINE FLINT_DLL
#else
#define GR_POLY_INLINE static __inline__
#endif

#include "flint/fmpz_poly.h"
#include "gr.h"

#ifdef __cplusplus
 extern "C" {
#endif

typedef struct
{
    gr_ptr coeffs;
    slong length;
    slong alloc;
}
gr_poly_struct;

typedef gr_poly_struct gr_poly_t[1];

int gr_poly_init(gr_poly_t poly, gr_ctx_t ctx);
int gr_poly_init2(gr_poly_t poly, slong len, gr_ctx_t ctx);
int gr_poly_clear(gr_poly_t poly, gr_ctx_t ctx);

GR_POLY_INLINE gr_ptr
gr_poly_entry_ptr(gr_poly_t poly, slong i, gr_ctx_t ctx)
{
    return GR_ENTRY(poly->coeffs, i, ctx->sizeof_elem);
}

GR_POLY_INLINE slong gr_poly_length(const gr_poly_t poly, gr_ctx_t ctx)
{
    return poly->length;
}

GR_POLY_INLINE int
gr_poly_swap(gr_poly_t poly1, gr_poly_t poly2, gr_ctx_t ctx)
{
    gr_poly_struct t = *poly1;
    *poly1 = *poly2;
    *poly2 = t;
    return GR_SUCCESS;
}

int gr_poly_fit_length(gr_poly_t poly, slong len, gr_ctx_t ctx);
int _gr_poly_set_length(gr_poly_t poly, slong len, gr_ctx_t ctx);
int _gr_poly_normalise(gr_poly_t poly, gr_ctx_t ctx);

int gr_poly_set(gr_poly_t res, const gr_poly_t src, gr_ctx_t ctx);

int _gr_poly_reverse(gr_ptr res, gr_srcptr poly, slong len, slong n, gr_ctx_t ctx);
int gr_poly_reverse(gr_poly_t res, const gr_poly_t poly, slong n, gr_ctx_t ctx);

GR_POLY_INLINE int
gr_poly_zero(gr_poly_t poly, gr_ctx_t ctx)
{
    _gr_poly_set_length(poly, 0, ctx);
    return GR_SUCCESS;
}

int gr_poly_one(gr_poly_t poly, gr_ctx_t ctx);
int gr_poly_neg_one(gr_poly_t poly, gr_ctx_t ctx);

int gr_poly_write(gr_stream_t out, const gr_poly_t poly, gr_ctx_t ctx);
int gr_poly_print(const gr_poly_t poly, gr_ctx_t ctx);

int gr_poly_randtest(gr_poly_t poly, flint_rand_t state, slong len, gr_ctx_t ctx);

int _gr_poly_equal(int * res, gr_srcptr poly1, slong len1, gr_srcptr poly2, slong len2, gr_ctx_t ctx);
int gr_poly_equal(int * res, const gr_poly_t poly1, const gr_poly_t poly2, gr_ctx_t ctx);

int gr_poly_neg(gr_poly_t res, const gr_poly_t src, gr_ctx_t ctx);

int _gr_poly_add(gr_ptr res, gr_srcptr poly1, slong len1, gr_srcptr poly2, slong len2, gr_ctx_t ctx);
int gr_poly_add(gr_poly_t res, const gr_poly_t poly1, const gr_poly_t poly2, gr_ctx_t ctx);

int _gr_poly_sub(gr_ptr res, gr_srcptr poly1, slong len1, gr_srcptr poly2, slong len2, gr_ctx_t ctx);
int gr_poly_sub(gr_poly_t res, const gr_poly_t poly1, const gr_poly_t poly2, gr_ctx_t ctx);

int _gr_poly_mul(gr_ptr res, gr_srcptr poly1, slong len1, gr_srcptr poly2, slong len2, gr_ctx_t ctx);
int gr_poly_mul(gr_poly_t res, const gr_poly_t poly1, const gr_poly_t poly2, gr_ctx_t ctx);

int _gr_poly_mullow(gr_ptr res, gr_srcptr poly1, slong len1, gr_srcptr poly2, slong len2, slong n, gr_ctx_t ctx);
int gr_poly_mullow(gr_poly_t res, const gr_poly_t poly1, const gr_poly_t poly2, slong n, gr_ctx_t ctx);

#ifdef __cplusplus
}
#endif

#endif