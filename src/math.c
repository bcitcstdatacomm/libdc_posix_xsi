#include "dc_posix_xsi/dc_math.h"
#include <math.h>


double dc_j0(const struct dc_env *env, struct dc_error *err, double x)
{
    double ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = j0(x);

    return ret_val;
}

double dc_j1(const struct dc_env *env, struct dc_error *err, double x)
{
    double ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = j1(x);

    return ret_val;
}

double dc_jn(const struct dc_env *env, struct dc_error *err, int n, double x)
{
    double ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = jn(n, x);

    return ret_val;
}

double dc_y0(const struct dc_env *env, struct dc_error *err, double x)
{
    double ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = y0(x);

    return ret_val;
}

double dc_y1(const struct dc_env *env, struct dc_error *err, double x)
{
    double ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = y1(x);

    return ret_val;
}

double dc_yn(const struct dc_env *env, struct dc_error *err, int n, double x)
{
    double ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = yn(n, x);

    return ret_val;
}
