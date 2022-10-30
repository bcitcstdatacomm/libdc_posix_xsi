#include "dc_posix_xsi/dc_time.h"


struct tm *dc_getdate(const struct dc_env *env, struct dc_error *err, const char *string)
{
    struct tm *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getdate(string);

    return ret_val;
}

char *dc_strptime(const struct dc_env *env, struct dc_error *err, const char *restrict buf, const char *restrict format, struct tm *restrict tm)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strptime(buf, format, tm);

    return ret_val;
}
