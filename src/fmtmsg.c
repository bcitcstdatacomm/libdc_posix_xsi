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
        const char *msg;

        if(ret_val == MM_NOTOK)
        {
            msg = "fmtmsg failed";
        }
        else if(ret_val == MM_NOMSG)
        {
            msg = "fmtmsg unable to generate a message on standard error";
        }
        else if(ret_val == MM_NOCON)
        {
            msg = "fmtmsg unable to generate a console message";
        }
        else
        {
            msg = "fmtmsg unknown error";
        }

        DC_ERROR_RAISE_SYSTEM(err, msg, ret_val);
    }

    return ret_val;
}
