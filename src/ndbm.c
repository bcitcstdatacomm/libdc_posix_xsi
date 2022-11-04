#include "dc_posix_xsi/dc_ndbm.h"


int dc_dbm_clearerr(const struct dc_env *env, struct dc_error *err, DBM *db)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    dbm_clearerr(db);

    if(dc_dbm_error(env, db))
    {
        // TODO: what?
    }

    return ret_val;
}

void dc_dbm_close(const struct dc_env *env, DBM *db)
{
    DC_TRACE(env);
    errno = 0;
    dbm_close(db);
}

int dc_dbm_delete(const struct dc_env *env, struct dc_error *err, DBM *db, datum key)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dbm_delete(db, key);

    if(ret_val < 0)
    {
        // TODO: what?
    }

    return ret_val;
}

int dc_dbm_error(const struct dc_env *env, DBM *db)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dbm_error(db);

    return ret_val;
}

datum dc_dbm_fetch(const struct dc_env *env, struct dc_error *err, DBM *db, datum key)
{
    datum ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dbm_fetch(db, key);

    if(ret_val.dptr == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

datum dc_dbm_firstkey(const struct dc_env *env, struct dc_error *err, DBM *db)
{
    datum ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dbm_firstkey(db);

    if(ret_val.dptr == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

datum dc_dbm_nextkey(const struct dc_env *env, struct dc_error *err, DBM *db)
{
    datum ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dbm_nextkey(db);

    if(ret_val.dptr == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

DBM *dc_dbm_open(const struct dc_env *env, struct dc_error *err, const char *file, int open_flags, mode_t file_mode)
{
    DBM *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dbm_open(file, open_flags, file_mode);

    if(ret_val  == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

int dc_dbm_store(const struct dc_env *env, struct dc_error *err, DBM *db, datum key, datum content, int store_mode)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dbm_store(db, key, content, store_mode);

    if(ret_val < 0)
    {
        // TODO: what?
    }

    return ret_val;
}
