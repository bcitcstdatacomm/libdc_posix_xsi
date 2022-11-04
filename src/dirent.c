#include "dc_posix_xsi/dc_dirent.h"


void dc_seekdir(const struct dc_env *env, DIR *dirp, long loc)
{
    DC_TRACE(env);
    errno = 0;
    seekdir(dirp, loc);
}

long dc_telldir(const struct dc_env *env, DIR *dirp)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = telldir(dirp);

    return ret_val;
}
