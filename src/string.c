#include "dc_posix_xsi/dc_string.h"


void *dc_memccpy(const struct dc_env *env, void *restrict s1, const void *restrict s2, int c, size_t n)
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = memccpy(s1, s2, c, n);

    return ret_val;
}
