#include "dc_posix_xsi/sys/dc_resource.h"


int dc_getpriority(const struct dc_env *env, struct dc_error *err, int which, id_t who)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getpriority(which, who);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getrlimit(const struct dc_env *env, struct dc_error *err, int resource, struct rlimit *rlp)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getrlimit(resource, rlp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getrusage(const struct dc_env *env, struct dc_error *err, int who, struct rusage *r_usage)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getrusage(who, r_usage);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setpriority(const struct dc_env *env, struct dc_error *err, int which, id_t who, int value)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = setpriority(which, who, value);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setrlimit(const struct dc_env *env, struct dc_error *err, int resource, const struct rlimit *rlp)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = setrlimit(resource, rlp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
