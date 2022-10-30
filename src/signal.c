#include "dc_posix_xsi/dc_signal.h"


int dc_killpg(const struct dc_env *env, struct dc_error *err, pid_t pgrp, int sig)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = killpg(pgrp, sig);

    return ret_val;
}

int dc_sigaltstack(const struct dc_env *env, struct dc_error *err, const stack_t *restrict ss, stack_t *restrict oss)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigaltstack(ss, oss);

    return ret_val;
}

