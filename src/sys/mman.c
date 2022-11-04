#include "dc_posix_xsi/sys/dc_mman.h"


int dc_msync(const struct dc_env *env, struct dc_error *err, void *addr, size_t len, int flags)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = msync(addr, len, flags);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
