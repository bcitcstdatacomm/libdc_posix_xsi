#include "dc_posix_xsi/dc_syslog.h"
#include <syslog.h>


void dc_closelog(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    closelog();
}

void dc_openlog(const struct dc_env *env, const char *ident, int logopt, int facility)
{
    DC_TRACE(env);
    errno = 0;
    openlog(ident, logopt, facility);
}

int dc_setlogmask(const struct dc_env *env, int maskpri)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = setlogmask(maskpri);

    return ret_val;
}
