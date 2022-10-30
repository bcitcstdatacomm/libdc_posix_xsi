#ifndef LIBDC_POSIX_XSI_DC_RESOURCE_H
#define LIBDC_POSIX_XSI_DC_RESOURCE_H


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
#include <sys/resource.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_getpriority(const struct dc_env *env, struct dc_error *err, int which, id_t who);
int dc_getrlimit(const struct dc_env *env, struct dc_error *err, int resource, struct rlimit *rlp);
int dc_getrusage(const struct dc_env *env, struct dc_error *err, int who, struct rusage *r_usage);
int dc_setpriority(const struct dc_env *env, struct dc_error *err, int which, id_t who, int value);
int dc_setrlimit(const struct dc_env *env, struct dc_error *err, int resource, const struct rlimit *rlp);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_XSI_DC_RESOURCE_H
