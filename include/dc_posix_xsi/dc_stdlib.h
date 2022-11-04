#ifndef LIBDC_POSIX_XSI_DC_STDLIB_H
#define LIBDC_POSIX_XSI_DC_STDLIB_H


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


#ifdef __cplusplus
extern "C" {
#endif


long dc_a64l(const struct dc_env *env, const char *s);
double dc_drand48(const struct dc_env *env);
double dc_erand48(const struct dc_env *env, unsigned short xsubi[3]);
int dc_grantpt(const struct dc_env *env, struct dc_error *err, int fildes);
char *dc_initstate(const struct dc_env *env, struct dc_error *err, unsigned seed, char *state, size_t size);
long dc_jrand48(const struct dc_env *env, unsigned short xsubi[3]);
char *dc_l64a(const struct dc_env *env, long value);
void dc_lcong48(const struct dc_env *env, unsigned short param[7]);
long dc_lrand48(const struct dc_env *env);
long dc_mrand48(const struct dc_env *env);
long dc_nrand48(const struct dc_env *env, unsigned short xsubi[3]);
int dc_posix_openpt(const struct dc_env *env, struct dc_error *err, int oflag);
char *dc_ptsname(const struct dc_env *env, struct dc_error *err, int fildes);
int dc_putenv(const struct dc_env *env, struct dc_error *err, char *string);
long dc_random(const struct dc_env *env);
char *dc_realpath(const struct dc_env *env, struct dc_error *err, const char *restrict file_name, char *restrict resolved_name);
unsigned short *dc_seed48(const struct dc_env *env, unsigned short seed16v[3]);
char *dc_setstate(const struct dc_env *env, struct dc_error *err, char *state);
void dc_srand48(const struct dc_env *env, long seedval);
void dc_srandom(const struct dc_env *env, unsigned seed);
int dc_unlockpt(const struct dc_env *env, struct dc_error *err, int fildes);


#ifdef __cplusplus
}
#endif


// Not on FreeBSD
// void dc_setkey(const struct dc_env *env, struct dc_error *err, const char *key);



#endif // LIBDC_POSIX_XSI_DC_STDLIB_H
