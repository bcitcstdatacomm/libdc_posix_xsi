#include "dc_posix_xsi/dc_stdlib.h"


long dc_a64l(const struct dc_env *env, struct dc_error *err, const char *s)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = a64l(s);

    return ret_val;
}

double dc_drand48(const struct dc_env *env, struct dc_error *err)
{
    double ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = drand48();

    return ret_val;
}

double dc_erand48(const struct dc_env *env, struct dc_error *err, unsigned short xsubi[3])
{
    double ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = erand48(xsubi);

    return ret_val;
}

int dc_grantpt(const struct dc_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = grantpt(fildes);

    return ret_val;
}

char *dc_initstate(const struct dc_env *env, struct dc_error *err, unsigned seed, char *state, size_t size)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = initstate(seed, state, size);

    return ret_val;
}

long dc_jrand48(const struct dc_env *env, struct dc_error *err, unsigned short xsubi[3])
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = jrand48(xsubi);

    return ret_val;
}

char *dc_l64a(const struct dc_env *env, struct dc_error *err, long value)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = l64a(value);

    return ret_val;
}

void dc_lcong48(const struct dc_env *env, struct dc_error *err, unsigned short param[7])
{
    DC_TRACE(env);
    errno = 0;
    lcong48(param);
}

long dc_lrand48(const struct dc_env *env, struct dc_error *err)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = lrand48();

    return ret_val;
}

long dc_mrand48(const struct dc_env *env, struct dc_error *err)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = mrand48();

    return ret_val;
}

long dc_nrand48(const struct dc_env *env, struct dc_error *err, unsigned short xsubi[3])
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = nrand48(xsubi);

    return ret_val;
}

int dc_posix_openpt(const struct dc_env *env, struct dc_error *err, int oflag)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = posix_openpt(oflag);

    return ret_val;
}

char *dc_ptsname(const struct dc_env *env, struct dc_error *err, int fildes)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ptsname(fildes);

    return ret_val;
}

int dc_putenv(const struct dc_env *env, struct dc_error *err, char *string)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = putenv(string);

    return ret_val;
}

long dc_random(const struct dc_env *env, struct dc_error *err)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = random();

    return ret_val;
}

char *dc_realpath(const struct dc_env *env, struct dc_error *err, const char *restrict file_name, char *restrict resolved_name)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = realpath(file_name, resolved_name);

    return ret_val;
}

unsigned short *dc_seed48(const struct dc_env *env, struct dc_error *err, unsigned short seed16v[3])
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

    return ret_val;
}

void dc_srand48(const struct dc_env *env, struct dc_error *err, long seedval)
{
    DC_TRACE(env);
    errno = 0;
    srand48(seedval);
}

void dc_srandom(const struct dc_env *env, struct dc_error *err, unsigned seed)
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

    return ret_val;
}
