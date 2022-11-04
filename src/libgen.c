#include "dc_posix_xsi/dc_libgen.h"


char *dc_basename(const struct dc_env *env, char *path)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = basename(path);

    return ret_val;
}

char *dc_dirname(const struct dc_env *env, char *path)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dirname(path);

    return ret_val;
}
