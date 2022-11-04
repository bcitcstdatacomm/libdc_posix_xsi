#include "dc_posix_xsi/dc_pwd.h"


void dc_endpwent(const struct dc_env *env, struct dc_error *err)
{
    DC_TRACE(env);
    errno = 0;
    endpwent();

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }
}

struct passwd *dc_getpwent(const struct dc_env *env, struct dc_error *err)
{
    struct passwd *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getpwent();

    if(ret_val == NULL && errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_setpwent(const struct dc_env *env, struct dc_error *err)
{
    DC_TRACE(env);
    errno = 0;
    setpwent();

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }
}
