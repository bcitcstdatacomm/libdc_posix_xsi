#include "dc_posix_xsi/sys/dc_ipc.h"


key_t dc_ftok(const struct dc_env *env, struct dc_error *err, const char *path, int id)
{
    key_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ftok(path, id);

    return ret_val;
}
