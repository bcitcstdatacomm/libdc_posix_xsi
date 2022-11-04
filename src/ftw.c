#include "dc_posix_xsi/dc_ftw.h"


int dc_nftw(const struct dc_env *env, struct dc_error *err, const char *path, int (*fn)(const char *, const struct stat *, int, struct FTW *), int fd_limit, int flags)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = nftw(path, fn, fd_limit, flags);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
