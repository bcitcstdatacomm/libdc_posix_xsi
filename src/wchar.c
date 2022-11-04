#include "dc_posix_xsi/dc_wchar.h"


int dc_wcswidth(const struct dc_env *env, const wchar_t *pwcs, size_t n)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = wcswidth(pwcs, n);

    return ret_val;
}

int dc_wcwidth(const struct dc_env *env, wchar_t wc)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = wcwidth(wc);

    return ret_val;
}
