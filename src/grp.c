#include "dc_posix_xsi/dc_grp.h"


void dc_endgrent(const struct dc_env *env, struct dc_error *err)
{
    DC_TRACE(env);
    errno = 0;
    endgrent();
}

struct group *dc_getgrent(const struct dc_env *env, struct dc_error *err)
{
    struct group *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getgrent();

    return ret_val;
}

void dc_setgrent(const struct dc_env *env, struct dc_error *err)
{
    DC_TRACE(env);
    errno = 0;
    setgrent();
}
