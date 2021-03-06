#include "gr_poly.h"

int
gr_poly_set_fmpz_poly(gr_poly_t res, const fmpz_poly_t src, gr_ctx_t ctx)
{
    int status = GR_SUCCESS;
    slong sz = ctx->sizeof_elem;
    slong i, len = src->length;

    gr_poly_fit_length(res, len, ctx);

    for (i = 0; i < len; i++)
        status |= gr_set_fmpz(GR_ENTRY(res, i, sz), src->coeffs + i, ctx);

    _gr_poly_set_length(res, len, ctx);
    _gr_poly_normalise(res, ctx);

    return status;
}
