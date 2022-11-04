#include "dc_posix_xsi/dc_search.h"


int dc_hcreate(const struct dc_env *env, struct dc_error *err, size_t nel)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = hcreate(nel);

    if(ret_val == 0)
    {
        // TODO: what?
    }

    return ret_val;
}

void dc_hdestroy(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    hdestroy();
}

ENTRY *dc_hsearch(const struct dc_env *env, struct dc_error *err, ENTRY item, ACTION action)
{
    ENTRY *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = hsearch(item, action);

    if(ret_val == 0)
    {
        // TODO: what?
    }

    return ret_val;
}

void dc_insque(const struct dc_env *env, void *element, void *pred)
{
    DC_TRACE(env);
    errno = 0;
    insque(element, pred);
}

void *dc_lfind(const struct dc_env *env, struct dc_error *err, const void *key, const void *base, size_t *nelp, size_t width, int (*compar)(const void *, const void *))
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = lfind(key, base, nelp, width, compar);

    if(ret_val == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

void *dc_lsearch(const struct dc_env *env, struct dc_error *err, const void *key, void *base, size_t *nelp, size_t width, int (*compar)(const void *, const void *))
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = lsearch(key, base, nelp, width, compar);

    if(ret_val == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

void dc_remque(const struct dc_env *env, void *element)
{
    DC_TRACE(env);
    errno = 0;
    remque(element);
}

void *dc_tdelete(const struct dc_env *env, const void *restrict key, void **restrict rootp, int(*compar)(const void *, const void *))
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = tdelete(key, rootp, compar);

    return ret_val;
}

void *dc_tfind(const struct dc_env *env, const void *key, void *const *rootp, int(*compar)(const void *, const void *))
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = tfind(key, rootp, compar);

    return ret_val;
}

void *dc_tsearch(const struct dc_env *env, struct dc_error *err, const void *key, void **rootp, int(*compar)(const void *, const void *))
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = tsearch(key, rootp, compar);

    if(ret_val == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

void dc_twalk(const struct dc_env *env, const void *root, void (*action)(const void *, VISIT, int))
{
    DC_TRACE(env);
    errno = 0;
    twalk(root, action);
}
