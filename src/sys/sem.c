#include "dc_posix_xsi/sys/dc_sem.h"


int dc_semctl(const struct dc_env *env, struct dc_error *err, int semid, int semnum, int cmd, ...)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    // TODO: can I even handle this?
    ret_val = semctl(semid, semnum, cmd, 0);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_semget(const struct dc_env *env, struct dc_error *err, key_t key, int nsems, int semflg)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = semget(key, nsems, semflg);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_semop(const struct dc_env *env, struct dc_error *err, int semid, struct sembuf *sops, size_t nsops)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = semop(semid, sops, nsops);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
