#include "dc_posix_xsi/dc_unistd.h"


char *dc_crypt(const struct dc_env *env, struct dc_error *err, const char *key, const char *salt)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = crypt(key, salt);

    return ret_val;
}

void dc_encrypt(const struct dc_env *env, struct dc_error *err, char block[64], int edflag)
{
    DC_TRACE(env);
    errno = 0;
    encrypt(block, edflag);
}

long dc_gethostid(const struct dc_env *env, struct dc_error *err)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = gethostid();

    return ret_val;
}

int dc_lockf(const struct dc_env *env, struct dc_error *err, int fildes, int function, off_t size)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = lockf(fildes, function, size);

    return ret_val;
}

int dc_nice(const struct dc_env *env, struct dc_error *err, int value)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = nice(value);

    return ret_val;
}

int dc_setregid(const struct dc_env *env, struct dc_error *err, gid_t rgid, gid_t egid)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = setregid(rgid, egid);

    return ret_val;
}

int dc_setreuid(const struct dc_env *env, struct dc_error *err, uid_t ruid, uid_t euid)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = setreuid(ruid, euid);

    return ret_val;
}

void dc_swab(const struct dc_env *env, struct dc_error *err, const void *restrict src, void *restrict dest, ssize_t nbytes)
{
    DC_TRACE(env);
    errno = 0;
    swab(src, dest, nbytes);
}

void dc_sync(const struct dc_env *env, struct dc_error *err)
{
    DC_TRACE(env);
    errno = 0;
    sync();
}

