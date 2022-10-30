#include "dc_posix_xsi/dc_strings.h"


int dc_ffs(const struct dc_env *env, struct dc_error *err, int i)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ffs(i);

    return ret_val;
}
