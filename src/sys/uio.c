#include "dc_posix_xsi/sys/dc_uio.h"


ssize_t dc_readv(const struct dc_env *env, struct dc_error *err, int fildes, const struct iovec *iov, int iovcnt)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = readv(fildes, iov, iovcnt);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_writev(const struct dc_env *env, struct dc_error *err, int fildes, const struct iovec *iov, int iovcnt)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = writev(fildes, iov, iovcnt);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
