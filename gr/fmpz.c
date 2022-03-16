#include "gr.h"

int
_gr_fmpz_ctx_write(gr_stream_t out, gr_ctx_t ctx)
{
    gr_stream_write(out, "Integer ring (fmpz)");
    return GR_SUCCESS;
}

int
_gr_fmpz_init(fmpz_t x, const gr_ctx_t ctx)
{
    fmpz_init(x);
    return GR_SUCCESS;
}

int
_gr_fmpz_clear(fmpz_t x, const gr_ctx_t ctx)
{
    fmpz_clear(x);
    return GR_SUCCESS;
}

int
_gr_fmpz_swap(fmpz_t x, fmpz_t y, const gr_ctx_t ctx)
{
    fmpz_t t;
    *t = *x;
    *x = *y;
    *y = *t;
    return GR_SUCCESS;
}

/* todo: limits */
int
_gr_fmpz_randtest(fmpz_t res, flint_rand_t state, const void * options, const gr_ctx_t ctx)
{
    switch (n_randint(state, 4))
    {
        case 0:
            fmpz_randtest(res, state, 100);
            break;
        default:
            fmpz_randtest(res, state, 10);
    }

    return GR_SUCCESS;
}

int
_gr_fmpz_write(gr_stream_t out, const fmpz_t x, const gr_ctx_t ctx)
{
    gr_stream_write_fmpz(out, x);
    return GR_SUCCESS;
}

int
_gr_fmpz_zero(fmpz_t x, const gr_ctx_t ctx)
{
    fmpz_zero(x);
    return GR_SUCCESS;
}

int
_gr_fmpz_one(fmpz_t x, const gr_ctx_t ctx)
{
    fmpz_one(x);
    return GR_SUCCESS;
}

int
_gr_fmpz_set_si(fmpz_t res, slong v, const gr_ctx_t ctx)
{
    fmpz_set_si(res, v);
    return GR_SUCCESS;
}

int
_gr_fmpz_set_ui(fmpz_t res, ulong v, const gr_ctx_t ctx)
{
    fmpz_set_ui(res, v);
    return GR_SUCCESS;
}

int
_gr_fmpz_set_fmpz(fmpz_t res, const fmpz_t v, const gr_ctx_t ctx)
{
    fmpz_set(res, v);
    return GR_SUCCESS;
}

int
_gr_fmpz_set_fmpq(fmpz_t res, const fmpq_t v, const gr_ctx_t ctx)
{
    if (fmpz_is_one(fmpq_denref(v)))
    {
        fmpz_set(res, fmpq_numref(v));
        return GR_SUCCESS;
    }
    else
    {
        return GR_DOMAIN;
    }
}

int
_gr_fmpz_is_zero(int * res, const fmpz_t x, const gr_ctx_t ctx)
{
    res[0] = fmpz_is_zero(x);
    return GR_SUCCESS;
}

int
_gr_fmpz_is_one(int * res, const fmpz_t x, const gr_ctx_t ctx)
{
    res[0] = fmpz_is_one(x);
    return GR_SUCCESS;
}

int
_gr_fmpz_is_neg_one(int * res, const fmpz_t x, const gr_ctx_t ctx)
{
    res[0] = (*x == -1);
    return GR_SUCCESS;
}

int
_gr_fmpz_equal(int * res, const fmpz_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    res[0] = fmpz_equal(x, y);
    return GR_SUCCESS;
}

int
_gr_fmpz_set(fmpz_t res, const fmpz_t x, const gr_ctx_t ctx)
{
    fmpz_set(res, x);
    return GR_SUCCESS;
}

int
_gr_fmpz_neg(fmpz_t res, const fmpz_t x, const gr_ctx_t ctx)
{
    fmpz_neg(res, x);
    return GR_SUCCESS;
}

int
_gr_fmpz_add(fmpz_t res, const fmpz_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    fmpz_add(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpz_add_si(fmpz_t res, const fmpz_t x, slong y, const gr_ctx_t ctx)
{
    fmpz_add_si(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpz_add_ui(fmpz_t res, const fmpz_t x, ulong y, const gr_ctx_t ctx)
{
    fmpz_add_ui(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpz_sub(fmpz_t res, const fmpz_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    fmpz_sub(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpz_mul(fmpz_t res, const fmpz_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    fmpz_mul(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpz_mul_si(fmpz_t res, const fmpz_t x, slong y, const gr_ctx_t ctx)
{
    fmpz_mul_si(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpz_inv(fmpz_t res, const fmpz_t x, const gr_ctx_t ctx)
{
    if (fmpz_is_pm1(x))
    {
        fmpz_set(res, x);
        return GR_SUCCESS;
    }
    else
    {
        return GR_DOMAIN;
    }
}

int
_gr_fmpz_div(fmpz_t res, const fmpz_t x, const fmpz_t y, const gr_ctx_t ctx)
{
    if (fmpz_is_zero(y))
    {
        return GR_DOMAIN;
    }
    else
    {
        if (fmpz_divides(res, x, y))
            return GR_SUCCESS;
        else
            return GR_DOMAIN;
    }
}

int
_gr_fmpz_is_invertible(int * res, const fmpz_t x, const gr_ctx_t ctx)
{
    res[0] = fmpz_is_pm1(x);
    return GR_SUCCESS;
}

/* todo: overload pow_fmpz? */

int
_gr_fmpz_pow_ui(fmpz_t res, const fmpz_t x, ulong exp, const gr_ctx_t ctx)
{
    if (exp > (ulong) WORD_MAX || exp >= ctx->size_limit)  /* todo: systematic size solution for test code */
    {
        return GR_UNABLE;
    }
    else
    {
        fmpz_pow_ui(res, x, exp);
        return GR_SUCCESS;
    }
}

int
_gr_fmpz_is_square(int * res, const fmpz_t x, const gr_ctx_t ctx)
{
    res[0] = fmpz_is_square(x);
    return GR_SUCCESS;
}

int
_gr_fmpz_sqrt(fmpz_t res, const fmpz_t x, const gr_ctx_t ctx)
{
    if (fmpz_sgn(x) < 0)
        return GR_DOMAIN;

    if (fmpz_root(res, x, 2))
    {
        return GR_SUCCESS;
    }
    else
    {
        return GR_DOMAIN;
    }
}

int
_gr_fmpz_rsqrt(fmpz_t res, const fmpz_t x, const gr_ctx_t ctx)
{
    if (fmpz_is_one(x))
    {
        fmpz_one(res);
        return GR_SUCCESS;
    }
    else
    {
        return GR_DOMAIN;
    }
}

int _fmpz_methods2_initialized = 0;
gr_static_method_table _fmpz_static_table;
gr_method_tab_t _fmpz_methods2;

gr_method_tab_input fmpz_methods2[] =
{
    {GR_METHOD_CTX_WRITE,       (gr_funcptr) _gr_fmpz_ctx_write},
    {GR_METHOD_INIT,            (gr_funcptr) _gr_fmpz_init},
    {GR_METHOD_CLEAR,           (gr_funcptr) _gr_fmpz_clear},
    {GR_METHOD_SWAP,            (gr_funcptr) _gr_fmpz_swap},
    {GR_METHOD_RANDTEST,        (gr_funcptr) _gr_fmpz_randtest},
    {GR_METHOD_WRITE,           (gr_funcptr) _gr_fmpz_write},
    {GR_METHOD_ZERO,            (gr_funcptr) _gr_fmpz_zero},
    {GR_METHOD_ONE,             (gr_funcptr) _gr_fmpz_one},
    {GR_METHOD_IS_ZERO,         (gr_funcptr) _gr_fmpz_is_zero},
    {GR_METHOD_IS_ONE,          (gr_funcptr) _gr_fmpz_is_one},
    {GR_METHOD_IS_NEG_ONE,      (gr_funcptr) _gr_fmpz_is_neg_one},
    {GR_METHOD_EQUAL,           (gr_funcptr) _gr_fmpz_equal},
    {GR_METHOD_SET,             (gr_funcptr) _gr_fmpz_set},
    {GR_METHOD_SET_SI,          (gr_funcptr) _gr_fmpz_set_si},
    {GR_METHOD_SET_UI,          (gr_funcptr) _gr_fmpz_set_ui},
    {GR_METHOD_SET_FMPZ,        (gr_funcptr) _gr_fmpz_set_fmpz},
    {GR_METHOD_SET_FMPQ,        (gr_funcptr) _gr_fmpz_set_fmpq},
    {GR_METHOD_NEG,             (gr_funcptr) _gr_fmpz_neg},
    {GR_METHOD_ADD,             (gr_funcptr) _gr_fmpz_add},
    {GR_METHOD_ADD_UI,          (gr_funcptr) _gr_fmpz_add_ui},
    {GR_METHOD_ADD_SI,          (gr_funcptr) _gr_fmpz_add_si},
    {GR_METHOD_SUB,             (gr_funcptr) _gr_fmpz_sub},
    {GR_METHOD_MUL,             (gr_funcptr) _gr_fmpz_mul},
    {GR_METHOD_MUL_SI,          (gr_funcptr) _gr_fmpz_mul_si},
    {GR_METHOD_DIV,             (gr_funcptr) _gr_fmpz_div},
    {GR_METHOD_INV,             (gr_funcptr) _gr_fmpz_inv},
    {GR_METHOD_POW_UI,          (gr_funcptr) _gr_fmpz_pow_ui},
    {GR_METHOD_IS_SQUARE,       (gr_funcptr) _gr_fmpz_is_square},
    {GR_METHOD_SQRT,            (gr_funcptr) _gr_fmpz_sqrt},
    {GR_METHOD_RSQRT,           (gr_funcptr) _gr_fmpz_rsqrt},
    {0,                         (gr_funcptr) NULL},
};

void
gr_ctx_init_fmpz(gr_ctx_t ctx)
{
    ctx->flags = GR_COMMUTATIVE_RING;
    ctx->sizeof_elem = sizeof(fmpz);
    ctx->elem_ctx = NULL;
    ctx->size_limit = WORD_MAX;

    if (!_fmpz_methods2_initialized)
    {
        gr_method_tab_init_static(&_fmpz_methods2, _fmpz_static_table, fmpz_methods2);
        _fmpz_methods2_initialized = 1;
    }

    ctx->methods2 = &_fmpz_methods2;
}