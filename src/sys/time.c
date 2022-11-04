#include "dc_posix_xsi/sys/dc_time.h"


int dc_utimes(const struct dc_env *env, struct dc_error *err, const char *path, const struct timeval times[2])
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = utimes(path, times);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

