#include "dc_posix_xsi/dc_utmpx.h"


void dc_endutxent(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    endutxent();
}

struct utmpx *dc_getutxent(const struct dc_env *env)
{
    struct utmpx *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getutxent();

    return ret_val;
}

struct utmpx *dc_getutxid(const struct dc_env *env, const struct utmpx *id)
{
    struct utmpx *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getutxid(id);

    return ret_val;
}

struct utmpx *dc_getutxline(const struct dc_env *env, const struct utmpx *line)
{
    struct utmpx *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getutxline(line);

    return ret_val;
}

struct utmpx *dc_pututxline(const struct dc_env *env, struct dc_error *err, const struct utmpx *utmpx)
{
    struct utmpx *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = pututxline(utmpx);

    if(ret_val == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

void dc_setutxent(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    setutxent();
}
