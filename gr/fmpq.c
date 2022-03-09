#include "gr.h"

int
_gr_fmpq_init(fmpq_t x, const gr_ctx_t ctx)
{
    fmpq_init(x);
    return GR_SUCCESS;
}

int
_gr_fmpq_clear(fmpq_t x, const gr_ctx_t ctx)
{
    fmpq_clear(x);
    return GR_SUCCESS;
}

int
_gr_fmpq_swap(fmpq_t x, fmpq_t y, const gr_ctx_t ctx)
{
    fmpq_t t;
    *t = *x;
    *x = *y;
    *y = *t;
    return GR_SUCCESS;
}

/* todo: limits */
int
_gr_fmpq_randtest(fmpq_t res, flint_rand_t state, const void * options, const gr_ctx_t ctx)
{
    switch (n_randint(state, 4))
    {
        case 0:
            fmpq_randtest(res, state, 100);
            break;
        default:
            fmpq_randtest(res, state, 10);
    }

    return GR_SUCCESS;
}

int
_gr_fmpq_write(gr_stream_t out, const fmpq_t x, const gr_ctx_t ctx)
{
    gr_stream_write_fmpz(out, fmpq_numref(x));

    if (!fmpz_is_one(fmpq_denref(x)))
    {
        gr_stream_write(out, "/");
        gr_stream_write_fmpz(out, fmpq_denref(x));
    }

    return GR_SUCCESS;
}

int
_gr_fmpq_zero(fmpq_t x, const gr_ctx_t ctx)
{
    fmpq_zero(x);
    return GR_SUCCESS;
}

int
_gr_fmpq_one(fmpq_t x, const gr_ctx_t ctx)
{
    fmpq_one(x);
    return GR_SUCCESS;
}

int
_gr_fmpq_set_si(fmpq_t res, slong v, const gr_ctx_t ctx)
{
    fmpq_set_si(res, v, 1);
    return GR_SUCCESS;
}

int
_gr_fmpq_is_zero(int * res, const fmpq_t x, const gr_ctx_t ctx)
{
    res[0] = fmpq_is_zero(x);
    return GR_SUCCESS;
}

int
_gr_fmpq_is_one(int * res, const fmpq_t x, const gr_ctx_t ctx)
{
    res[0] = fmpq_is_one(x);
    return GR_SUCCESS;
}

int
_gr_fmpq_equal(int * res, const fmpq_t x, const fmpq_t y, const gr_ctx_t ctx)
{
    res[0] = fmpq_equal(x, y);
    return GR_SUCCESS;
}

int
_gr_fmpq_set(fmpq_t res, const fmpq_t x, const gr_ctx_t ctx)
{
    fmpq_set(res, x);
    return GR_SUCCESS;
}

int
_gr_fmpq_neg(fmpq_t res, const fmpq_t x, const gr_ctx_t ctx)
{
    fmpq_neg(res, x);
    return GR_SUCCESS;
}

int
_gr_fmpq_add(fmpq_t res, const fmpq_t x, const fmpq_t y, const gr_ctx_t ctx)
{
    fmpq_add(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpq_add_si(fmpq_t res, const fmpq_t x, slong y, const gr_ctx_t ctx)
{
    fmpq_add_si(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpq_sub(fmpq_t res, const fmpq_t x, const fmpq_t y, const gr_ctx_t ctx)
{
    fmpq_sub(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpq_mul(fmpq_t res, const fmpq_t x, const fmpq_t y, const gr_ctx_t ctx)
{
    fmpq_mul(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpq_mul_si(fmpq_t res, const fmpq_t x, slong y, const gr_ctx_t ctx)
{
    fmpq_mul_si(res, x, y);
    return GR_SUCCESS;
}

int
_gr_fmpq_inv(fmpq_t res, const fmpq_t x, const gr_ctx_t ctx)
{
    if (fmpq_is_zero(x))
    {
        return GR_DOMAIN;
    }
    else
    {
        fmpq_inv(res, x);
        return GR_SUCCESS;
    }
}

int
_gr_fmpq_div(fmpq_t res, const fmpq_t x, const fmpq_t y, const gr_ctx_t ctx)
{
    if (fmpq_is_zero(y))
    {
        return GR_DOMAIN;
    }
    else
    {
        fmpq_div(res, x, y);
        return GR_SUCCESS;
    }
}

int
_gr_fmpq_is_invertible(int * res, const fmpq_t x, const gr_ctx_t ctx)
{
    res[0] = !fmpq_is_zero(x);
    return GR_SUCCESS;
}

int
_gr_fmpq_pow_ui(fmpq_t res, const fmpq_t x, ulong exp, const gr_ctx_t ctx)
{
    if (exp > (ulong) WORD_MAX || exp >= ctx->size_limit)  /* todo: systematic size solution for test code */
    {
        return GR_UNABLE;
    }
    else
    {
        fmpq_pow_si(res, x, exp);
        return GR_SUCCESS;
    }
}

int _fmpq_methods2_initialized = 0;
gr_static_method_table _fmpq_static_table;
gr_method_tab_t _fmpq_methods2;

gr_method_tab_input fmpq_methods2[] =
{
    {GR_METHOD_INIT,            (gr_funcptr) _gr_fmpq_init},
    {GR_METHOD_CLEAR,           (gr_funcptr) _gr_fmpq_clear},
    {GR_METHOD_SWAP,            (gr_funcptr) _gr_fmpq_swap},
    {GR_METHOD_RANDTEST,        (gr_funcptr) _gr_fmpq_randtest},
    {GR_METHOD_WRITE,           (gr_funcptr) _gr_fmpq_write},
    {GR_METHOD_ZERO,            (gr_funcptr) _gr_fmpq_zero},
    {GR_METHOD_ONE,             (gr_funcptr) _gr_fmpq_one},
    {GR_METHOD_IS_ZERO,         (gr_funcptr) _gr_fmpq_is_zero},
    {GR_METHOD_IS_ONE,          (gr_funcptr) _gr_fmpq_is_one},
    {GR_METHOD_EQUAL,           (gr_funcptr) _gr_fmpq_equal},
    {GR_METHOD_SET,             (gr_funcptr) _gr_fmpq_set},
    {GR_METHOD_SET_SI,          (gr_funcptr) _gr_fmpq_set_si},
    {GR_METHOD_NEG,             (gr_funcptr) _gr_fmpq_neg},
    {GR_METHOD_ADD,             (gr_funcptr) _gr_fmpq_add},
    {GR_METHOD_ADD_SI,          (gr_funcptr) _gr_fmpq_add_si},
    {GR_METHOD_SUB,             (gr_funcptr) _gr_fmpq_sub},
    {GR_METHOD_MUL,             (gr_funcptr) _gr_fmpq_mul},
    {GR_METHOD_MUL_SI,          (gr_funcptr) _gr_fmpq_mul_si},
    {GR_METHOD_DIV,             (gr_funcptr) _gr_fmpq_div},
    {GR_METHOD_INV,             (gr_funcptr) _gr_fmpq_inv},
    {GR_METHOD_POW_UI,          (gr_funcptr) _gr_fmpq_pow_ui},
    {0,                         (gr_funcptr) NULL},
};

void
gr_ctx_init_fmpq(gr_ctx_t ctx)
{
    ctx->flags = GR_COMMUTATIVE_RING | GR_FIELD;
    ctx->sizeof_elem = sizeof(fmpq);
    ctx->elem_ctx = NULL;
    ctx->size_limit = WORD_MAX;

    if (!_fmpq_methods2_initialized)
    {
        gr_method_tab_init_static(&_fmpq_methods2, _fmpq_static_table, fmpq_methods2);
        _fmpq_methods2_initialized = 1;
    }

    ctx->methods2 = &_fmpq_methods2;
    ctx->debug_string = "fmpq ring";
}