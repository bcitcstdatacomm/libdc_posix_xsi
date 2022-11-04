#include "dc_posix_xsi/sys/dc_msg.h"


int dc_msgctl(const struct dc_env *env, struct dc_error *err, int msqid, int cmd, struct msqid_ds *buf)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = msgctl(msqid, cmd, buf);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_msgget(const struct dc_env *env, struct dc_error *err, key_t key, int msgflg)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = msgget(key, msgflg);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_msgrcv(const struct dc_env *env, struct dc_error *err, int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = msgrcv(msqid, msgp, msgsz, msgtyp, msgflg);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_msgsnd(const struct dc_env *env, struct dc_error *err, int msqid, const void *msgp, size_t msgsz, int msgflg)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = msgsnd(msqid, msgp, msgsz, msgflg);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
