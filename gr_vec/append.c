#include "gr_vec.h"

int
gr_vec_append(gr_vec_t vec, gr_srcptr f, gr_ctx_t ctx)
{
    gr_vec_fit_length(vec, vec->length + 1, ctx);
    vec->length++;
    return gr_set(GR_ENTRY(vec->entries, vec->length - 1, ctx->sizeof_elem), f, ctx);
}
