#include "dc_posix_xsi/dc_fmtmsg.h"
#include <fmtmsg.h>


int dc_fmtmsg(const struct dc_env *env, struct dc_error *err, long classification, const char *label, int severity, const char *text, const char *action, const char *tag)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fmtmsg(classification, label, severity, text, action, tag);

    if(ret_val != MM_OK)
    {
        // TODO: what?
    }

    return ret_val;
}
