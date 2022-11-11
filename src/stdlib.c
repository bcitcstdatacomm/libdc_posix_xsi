#include "dc_posix_xsi/dc_stdlib.h"
#include <stdlib.h>


long dc_a64l(const struct dc_env *env, const char *s)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = a64l(s);

    return ret_val;
}

int dc_grantpt(const struct dc_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = grantpt(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_initstate(const struct dc_env *env, struct dc_error *err, unsigned seed, char *state, size_t size)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = initstate(seed, state, size);

    if(ret_val == NULL)
    {
        // TODO: is this an error?
    }

    return ret_val;
}

char *dc_l64a(const struct dc_env *env, long value)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = l64a(value);

    return ret_val;
}

int dc_posix_openpt(const struct dc_env *env, struct dc_error *err, int oflag)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = posix_openpt(oflag);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_ptsname(const struct dc_env *env, struct dc_error *err, int fildes)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ptsname(fildes);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putenv(const struct dc_env *env, struct dc_error *err, char *string)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = putenv(string);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_realpath(const struct dc_env *env, struct dc_error *err, const char *restrict file_name, char *restrict resolved_name)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = realpath(file_name, resolved_name);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned short *dc_seed48(const struct dc_env *env, unsigned short seed16v[3])
{
    unsigned short *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = seed48(seed16v);

    return ret_val;
}

char *dc_setstate(const struct dc_env *env, struct dc_error *err, char *state)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = setstate(state);

    if(ret_val == NULL)
    {
        // TODO; is this an error?
    }

    return ret_val;
}

void dc_srand48(const struct dc_env *env, long seedval)
{
    DC_TRACE(env);
    errno = 0;
    srand48(seedval);
}

void dc_srandom(const struct dc_env *env, unsigned seed)
{
    DC_TRACE(env);
    errno = 0;
    srandom(seed);
}

int dc_unlockpt(const struct dc_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = unlockpt(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
