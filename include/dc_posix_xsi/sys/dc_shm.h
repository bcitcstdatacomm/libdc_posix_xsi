#ifndef LIBDC_POSIX_XSI_SYS_DC_SHM_H
#define LIBDC_POSIX_XSI_SYS_DC_SHM_H


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
#include <sys/shm.h>


#ifdef __cplusplus
extern "C" {
#endif


void *dc_shmat(const struct dc_env *env, struct dc_error *err, int shmid, const void *shmaddr, int shmflg);
int dc_shmctl(const struct dc_env *env, struct dc_error *err, int shmid, int cmd, struct shmid_ds *buf);
int dc_shmdt(const struct dc_env *env, struct dc_error *err, const void *shmaddr);
int dc_shmget(const struct dc_env *env, struct dc_error *err, key_t key, size_t size, int shmflg);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_XSI_SYS_DC_SHM_H
