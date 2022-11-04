#ifndef LIBDC_POSIX_XSI_DC_UNISTD_H
#define LIBDC_POSIX_XSI_DC_UNISTD_H


/*
 * Copyright 2022-2022 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <dc_env/env.h>
#include <unistd.h>


#ifdef __cplusplus
extern "C" {
#endif


char *dc_crypt(const struct dc_env *env, struct dc_error *err, const char *key, const char *salt);
long dc_gethostid(const struct dc_env *env);
int dc_lockf(const struct dc_env *env, struct dc_error *err, int fildes, int function, off_t size);
int dc_nice(const struct dc_env *env, struct dc_error *err, int value);
int dc_setregid(const struct dc_env *env, struct dc_error *err, gid_t rgid, gid_t egid);
int dc_setreuid(const struct dc_env *env, struct dc_error *err, uid_t ruid, uid_t euid);
void dc_swab(const struct dc_env *env, const void *restrict src, void *restrict dest, ssize_t nbytes);
void dc_sync(const struct dc_env *env);


#ifdef __cplusplus
}
#endif


// Not on FreeBSD
// void dc_encrypt(const struct dc_env *env, struct dc_error *err, char block[64], int edflag);


#endif // LIBDC_POSIX_XSI_DC_UNISTD_H
