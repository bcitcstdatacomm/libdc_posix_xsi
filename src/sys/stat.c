#include "dc_posix_xsi/sys/dc_stat.h"


int dc_mknod(const struct dc_env *env, struct dc_error *err, const char *path, mode_t mode, dev_t dev)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = mknod(path, mode, dev);

    return ret_val;
}
