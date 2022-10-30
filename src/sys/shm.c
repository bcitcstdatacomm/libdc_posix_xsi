#include "dc_posix_xsi/sys/dc_shm.h"


void *dc_shmat(const struct dc_env *env, struct dc_error *err, int shmid, const void *shmaddr, int shmflg)
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = shmat(shmid, shmaddr, shmflg);

    return ret_val;
}

int dc_shmctl(const struct dc_env *env, struct dc_error *err, int shmid, int cmd, struct shmid_ds *buf)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = shmctl(shmid, cmd, buf);

    return ret_val;
}

int dc_shmdt(const struct dc_env *env, struct dc_error *err, const void *shmaddr)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = shmdt(shmaddr);

    return ret_val;
}

int dc_shmget(const struct dc_env *env, struct dc_error *err, key_t key, size_t size, int shmflg)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = shmget(key, size, shmflg);

    return ret_val;
}

