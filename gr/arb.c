#include "arb.h"
#include "gr.h"

typedef struct
{
    slong prec;
}
gr_arb_ctx;

#define ARB_CTX_PREC(ring_ctx) (((gr_arb_ctx *)((ring_ctx)->elem_ctx))->prec)

int
_gr_arb_ctx_write(gr_stream_t out, gr_ctx_t ctx)
{
    gr_stream_write(out, "Real numbers (arb, prec = ");
    gr_stream_write_si(out, ARB_CTX_PREC(ctx));
    gr_stream_write(out, ")");
    return GR_SUCCESS;
}

void
_gr_arb_init(arb_t x, const gr_ctx_t ctx)
{
    arb_init(x);
}

void
_gr_arb_clear(arb_t x, const gr_ctx_t ctx)
{
    arb_clear(x);
}

void
_gr_arb_swap(arb_t x, arb_t y, const gr_ctx_t ctx)
{
    arb_t t;
    *t = *x;
    *x = *y;
    *y = *t;
}

/* todo: limits */
int
_gr_arb_randtest(arb_t res, flint_rand_t state, const void * options, const gr_ctx_t ctx)
{
    arb_randtest(res, state, ARB_CTX_PREC(ctx), 10);
    return GR_SUCCESS;
}

/* todo */
int
_gr_arb_write(gr_stream_t out, const arb_t x, const gr_ctx_t ctx)
{
    gr_stream_write_free(out, arb_get_str(x, ARB_CTX_PREC(ctx) * 0.30102999566398 + 1, 0));
    return GR_SUCCESS;
}

int
_gr_arb_zero(arb_t x, const gr_ctx_t ctx)
{
    arb_zero(x);
    return GR_SUCCESS;
}

int
_gr_arb_one(arb_t x, const gr_ctx_t ctx)
{
    arb_one(x);
    return GR_SUCCESS;
}

int
_gr_arb_set_si(arb_t res, slong v, const gr_ctx_t ctx)
{
    arb_set_si(res, v);
    arb_set_round(res, res, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_set_ui(arb_t res, ulong v, const gr_ctx_t ctx)
{
    arb_set_ui(res, v);
    arb_set_round(res, res, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_set_fmpz(arb_t res, const fmpz_t v, const gr_ctx_t ctx)
{
    arb_set_round_fmpz(res, v, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_set_fmpq(arb_t res, const fmpq_t v, const gr_ctx_t ctx)
{
    arb_set_fmpq(res, v, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

truth_t
_gr_arb_is_zero(const arb_t x, const gr_ctx_t ctx)
{
    if (arb_is_zero(x))
        return T_TRUE;

    if (arb_contains_zero(x))
        return T_UNKNOWN;

    return T_FALSE;
}

truth_t
_gr_arb_is_one(const arb_t x, const gr_ctx_t ctx)
{
    if (arb_is_one(x))
        return T_TRUE;

    if (arb_contains_si(x, 1))
        return T_UNKNOWN;

    return T_FALSE;
}

truth_t
_gr_arb_is_neg_one(const arb_t x, const gr_ctx_t ctx)
{
    if (arb_equal_si(x, -1))
        return T_TRUE;

    if (arb_contains_si(x, -1))
        return T_UNKNOWN;

    return T_FALSE;
}

truth_t
_gr_arb_equal(const arb_t x, const arb_t y, const gr_ctx_t ctx)
{
    if (arb_is_exact(x) && arb_equal(x, y))
        return T_TRUE;

    if (arb_overlaps(x, y))
        return T_UNKNOWN;

    return T_FALSE;
}

int
_gr_arb_set(arb_t res, const arb_t x, const gr_ctx_t ctx)
{
    arb_set(res, x);
    return GR_SUCCESS;
}

int
_gr_arb_neg(arb_t res, const arb_t x, const gr_ctx_t ctx)
{
    arb_neg(res, x);
    return GR_SUCCESS;
}

int
_gr_arb_add(arb_t res, const arb_t x, const arb_t y, const gr_ctx_t ctx)
{
    arb_add(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_add_si(arb_t res, const arb_t x, slong y, const gr_ctx_t ctx)
{
    arb_add_si(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_add_ui(arb_t res, const arb_t x, ulong y, const gr_ctx_t ctx)
{
    arb_add_ui(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_add_fmpz(arb_t res, const arb_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    arb_add_fmpz(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_sub(arb_t res, const arb_t x, const arb_t y, const gr_ctx_t ctx)
{
    arb_sub(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_sub_si(arb_t res, const arb_t x, slong y, const gr_ctx_t ctx)
{
    arb_sub_si(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_sub_ui(arb_t res, const arb_t x, ulong y, const gr_ctx_t ctx)
{
    arb_sub_ui(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_sub_fmpz(arb_t res, const arb_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    arb_sub_fmpz(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_mul(arb_t res, const arb_t x, const arb_t y, const gr_ctx_t ctx)
{
    arb_mul(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_mul_si(arb_t res, const arb_t x, slong y, const gr_ctx_t ctx)
{
    arb_mul_si(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_mul_ui(arb_t res, const arb_t x, ulong y, const gr_ctx_t ctx)
{
    arb_mul_ui(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_mul_fmpz(arb_t res, const arb_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    arb_mul_fmpz(res, x, y, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_inv(arb_t res, const arb_t x, const gr_ctx_t ctx)
{
    if (arb_is_zero(x))
    {
        return GR_DOMAIN;
    }
    else
    {
        arb_inv(res, x, ARB_CTX_PREC(ctx));
        if (arb_is_finite(res))
            return GR_SUCCESS;
        else
            return GR_UNABLE;
    }
}

int
_gr_arb_div(arb_t res, const arb_t x, const arb_t y, const gr_ctx_t ctx)
{
    if (arb_is_zero(y))
    {
        return GR_DOMAIN;
    }
    else
    {
        arb_div(res, x, y, ARB_CTX_PREC(ctx));

        if (arb_is_finite(res))
            return GR_SUCCESS;
        else
            return GR_UNABLE;
    }
}

int
_gr_arb_div_si(arb_t res, const arb_t x, slong y, const gr_ctx_t ctx)
{
    if (y == 0)
    {
        return GR_DOMAIN;
    }
    else
    {
        arb_div_si(res, x, y, ARB_CTX_PREC(ctx));
        return GR_SUCCESS;
    }
}

int
_gr_arb_div_ui(arb_t res, const arb_t x, ulong y, const gr_ctx_t ctx)
{
    if (y == 0)
    {
        return GR_DOMAIN;
    }
    else
    {
        arb_div_ui(res, x, y, ARB_CTX_PREC(ctx));
        return GR_SUCCESS;
    }
}

int
_gr_arb_div_fmpz(arb_t res, const arb_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    if (fmpz_is_zero(y))
    {
        return GR_DOMAIN;
    }
    else
    {
        arb_div_fmpz(res, x, y, ARB_CTX_PREC(ctx));
        return GR_SUCCESS;
    }
}

truth_t
_gr_arb_is_invertible(const arb_t x, const gr_ctx_t ctx)
{
    if (arb_is_zero(x))
        return T_FALSE;

    if (arb_contains_zero(x))
        return T_UNKNOWN;

    return T_TRUE;
}

int
_gr_arb_pow_ui(arb_t res, const arb_t x, ulong exp, const gr_ctx_t ctx)
{
    arb_pow_ui(res, x, exp, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_pow_si(arb_t res, const arb_t x, slong exp, const gr_ctx_t ctx)
{
    if (exp < 0 && arb_is_zero(x))
    {
        return GR_DOMAIN;
    }
    else if (exp < 0 && arb_contains_zero(x))
    {
        return GR_UNABLE;
    }
    else
    {
        fmpz_t t;
        fmpz_init_set_si(t, exp);
        arb_pow_fmpz(res, x, t, ARB_CTX_PREC(ctx));
        fmpz_clear(t);
        return GR_SUCCESS;
    }
}

int
_gr_arb_pow_fmpz(arb_t res, const arb_t x, const fmpz_t exp, const gr_ctx_t ctx)
{
    if (fmpz_sgn(exp) < 0 && arb_is_zero(x))
    {
        return GR_DOMAIN;
    }
    else if (fmpz_sgn(exp) < 0 && arb_contains_zero(x))
    {
        return GR_UNABLE;
    }
    else
    {
        arb_pow_fmpz(res, x, exp, ARB_CTX_PREC(ctx));
        return GR_SUCCESS;
    }
}

int
_gr_arb_pow_fmpq(arb_t res, const arb_t x, const fmpq_t exp, const gr_ctx_t ctx)
{
    if (fmpq_sgn(exp) < 0 && arb_is_zero(x))
    {
        return GR_DOMAIN;
    }
    else if (fmpq_sgn(exp) < 0 && arb_contains_zero(x))
    {
        return GR_UNABLE;
    }
    else
    {
        if (fmpz_is_one(fmpq_denref(exp)) || arb_is_nonnegative(x))
        {
            arb_pow_fmpq(res, x, exp, ARB_CTX_PREC(ctx));
            return GR_SUCCESS;
        }
        else if (arb_is_negative(x))
        {
            return GR_DOMAIN;
        }
        else
        {
            return GR_UNABLE;
        }
    }
}

int
_gr_arb_pow(arb_t res, const arb_t x, const arb_t exp, const gr_ctx_t ctx)
{
    if (arb_is_int(exp))
    {
        if (arf_sgn(arb_midref(exp)) < 0)
        {
            if (arb_is_zero(x))
                return GR_DOMAIN;

            if (arb_contains_zero(x))
                return GR_UNABLE;
        }

        arb_pow(res, x, exp, ARB_CTX_PREC(ctx));
        return GR_SUCCESS;
    }
    else if (arb_is_positive(x) || (arb_is_nonnegative(x) && arb_is_nonnegative(exp)))
    {
        arb_pow(res, x, exp, ARB_CTX_PREC(ctx));
        return GR_SUCCESS;
    }
    else if (arb_is_negative(x) && !arb_contains_int(exp))
    {
        return GR_DOMAIN;
    }
    else
    {
        return GR_UNABLE;
    }
}

truth_t
_gr_arb_is_square(const arb_t x, const gr_ctx_t ctx)
{
    return T_TRUE;
}

int
_gr_arb_sqrt(arb_t res, const arb_t x, const gr_ctx_t ctx)
{
    if (arb_is_nonnegative(x))
    {
        arb_sqrt(res, x, ARB_CTX_PREC(ctx));
        return GR_SUCCESS;
    }
    else if (arb_is_negative(x))
    {
        return GR_DOMAIN;
    }
    else
    {
        return GR_UNABLE;
    }
}

int
_gr_arb_rsqrt(arb_t res, const arb_t x, const gr_ctx_t ctx)
{
    if (arb_is_positive(x))
    {
        arb_rsqrt(res, x, ARB_CTX_PREC(ctx));
        return GR_SUCCESS;
    }
    else if (arb_is_nonpositive(x))
    {
        return GR_DOMAIN;
    }
    else
    {
        return GR_UNABLE;
    }
}

int
_gr_arb_vec_dot(arb_t res, const arb_t initial, int subtract, arb_srcptr vec1, arb_srcptr vec2, slong len, gr_ctx_t ctx)
{
    arb_dot(res, initial, subtract, vec1, 1, vec2, 1, len, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_vec_dot_rev(arb_t res, const arb_t initial, int subtract, arb_srcptr vec1, arb_srcptr vec2, slong len, gr_ctx_t ctx)
{
    arb_dot(res, initial, subtract, vec1, 1, vec2 + len - 1, -1, len, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_poly_mullow(arb_ptr res,
    arb_srcptr poly1, slong len1,
    arb_srcptr poly2, slong len2, slong n, gr_ctx_t ctx)
{
    _arb_poly_mullow(res, poly1, len1, poly2, len2, n, ARB_CTX_PREC(ctx));
    return GR_SUCCESS;
}

int
_gr_arb_ctx_clear(gr_ctx_t ctx)
{
    flint_free(ctx->elem_ctx);
    return GR_SUCCESS;
}

int _arb_methods2_initialized = 0;
gr_static_method_table _arb_static_table;
gr_method_tab_t _arb_methods2;

gr_method_tab_input arb_methods2[] =
{
    {GR_METHOD_CTX_CLEAR,       (gr_funcptr) _gr_arb_ctx_clear},
    {GR_METHOD_CTX_WRITE,       (gr_funcptr) _gr_arb_ctx_write},
    {GR_METHOD_INIT,            (gr_funcptr) _gr_arb_init},
    {GR_METHOD_CLEAR,           (gr_funcptr) _gr_arb_clear},
    {GR_METHOD_SWAP,            (gr_funcptr) _gr_arb_swap},
    {GR_METHOD_RANDTEST,        (gr_funcptr) _gr_arb_randtest},
    {GR_METHOD_WRITE,           (gr_funcptr) _gr_arb_write},
    {GR_METHOD_ZERO,            (gr_funcptr) _gr_arb_zero},
    {GR_METHOD_ONE,             (gr_funcptr) _gr_arb_one},
    {GR_METHOD_IS_ZERO,         (gr_funcptr) _gr_arb_is_zero},
    {GR_METHOD_IS_ONE,          (gr_funcptr) _gr_arb_is_one},
    {GR_METHOD_IS_NEG_ONE,      (gr_funcptr) _gr_arb_is_neg_one},
    {GR_METHOD_EQUAL,           (gr_funcptr) _gr_arb_equal},
    {GR_METHOD_SET,             (gr_funcptr) _gr_arb_set},
    {GR_METHOD_SET_SI,          (gr_funcptr) _gr_arb_set_si},
    {GR_METHOD_SET_UI,          (gr_funcptr) _gr_arb_set_ui},
    {GR_METHOD_SET_FMPZ,        (gr_funcptr) _gr_arb_set_fmpz},
    {GR_METHOD_SET_FMPQ,        (gr_funcptr) _gr_arb_set_fmpq},
    {GR_METHOD_NEG,             (gr_funcptr) _gr_arb_neg},
    {GR_METHOD_ADD,             (gr_funcptr) _gr_arb_add},
    {GR_METHOD_ADD_UI,          (gr_funcptr) _gr_arb_add_ui},
    {GR_METHOD_ADD_SI,          (gr_funcptr) _gr_arb_add_si},
    {GR_METHOD_ADD_FMPZ,        (gr_funcptr) _gr_arb_add_fmpz},
    {GR_METHOD_SUB,             (gr_funcptr) _gr_arb_sub},
    {GR_METHOD_SUB_UI,          (gr_funcptr) _gr_arb_sub_ui},
    {GR_METHOD_SUB_SI,          (gr_funcptr) _gr_arb_sub_si},
    {GR_METHOD_SUB_FMPZ,        (gr_funcptr) _gr_arb_sub_fmpz},
    {GR_METHOD_MUL,             (gr_funcptr) _gr_arb_mul},
    {GR_METHOD_MUL_UI,          (gr_funcptr) _gr_arb_mul_ui},
    {GR_METHOD_MUL_SI,          (gr_funcptr) _gr_arb_mul_si},
    {GR_METHOD_MUL_FMPZ,        (gr_funcptr) _gr_arb_mul_fmpz},
    {GR_METHOD_DIV,             (gr_funcptr) _gr_arb_div},
    {GR_METHOD_DIV_UI,          (gr_funcptr) _gr_arb_div_ui},
    {GR_METHOD_DIV_SI,          (gr_funcptr) _gr_arb_div_si},
    {GR_METHOD_DIV_FMPZ,        (gr_funcptr) _gr_arb_div_fmpz},
    {GR_METHOD_INV,             (gr_funcptr) _gr_arb_inv},
    {GR_METHOD_POW,             (gr_funcptr) _gr_arb_pow},
    {GR_METHOD_POW_UI,          (gr_funcptr) _gr_arb_pow_ui},
    {GR_METHOD_POW_SI,          (gr_funcptr) _gr_arb_pow_si},
    {GR_METHOD_POW_FMPZ,        (gr_funcptr) _gr_arb_pow_fmpz},
    {GR_METHOD_POW_FMPQ,        (gr_funcptr) _gr_arb_pow_fmpq},
    {GR_METHOD_IS_SQUARE,       (gr_funcptr) _gr_arb_is_square},
    {GR_METHOD_SQRT,            (gr_funcptr) _gr_arb_sqrt},
    {GR_METHOD_RSQRT,           (gr_funcptr) _gr_arb_rsqrt},
    {GR_METHOD_VEC_DOT,         (gr_funcptr) _gr_arb_vec_dot},
    {GR_METHOD_VEC_DOT_REV,     (gr_funcptr) _gr_arb_vec_dot_rev},
    {GR_METHOD_POLY_MULLOW,     (gr_funcptr) _gr_arb_poly_mullow},
    {0,                         (gr_funcptr) NULL},
};

void
gr_ctx_init_real_arb(gr_ctx_t ctx, slong prec)
{
    ctx->flags = GR_COMMUTATIVE_RING | GR_FIELD;
    ctx->sizeof_elem = sizeof(arb_struct);
    ctx->elem_ctx = flint_malloc(sizeof(gr_arb_ctx));
    ctx->size_limit = WORD_MAX;

    if (prec < 2 || prec > WORD_MAX / 4)
        abort();

    ARB_CTX_PREC(ctx) = prec;

    if (!_arb_methods2_initialized)
    {
        gr_method_tab_init_static(&_arb_methods2, _arb_static_table, arb_methods2);
        _arb_methods2_initialized = 1;
    }

    ctx->methods2 = &_arb_methods2;
}