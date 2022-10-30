#ifndef LIBDC_POSIX_XSI_DC_SEARCH_H
#define LIBDC_POSIX_XSI_DC_SEARCH_H


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
#include <search.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_hcreate(const struct dc_env *env, struct dc_error *err, size_t nel);
void dc_hdestroy(const struct dc_env *env, struct dc_error *err);
ENTRY *dc_hsearch(const struct dc_env *env, struct dc_error *err, ENTRY item, ACTION action);
void dc_insque(const struct dc_env *env, struct dc_error *err, void *element, void *pred);
void *dc_lfind(const struct dc_env *env, struct dc_error *err, const void *key, const void *base, size_t *nelp, size_t width, int (*compar)(const void *, const void *));
void *dc_lsearch(const struct dc_env *env, struct dc_error *err, const void *key, void *base, size_t *nelp, size_t width, int (*compar)(const void *, const void *));
void dc_remque(const struct dc_env *env, struct dc_error *err, void *element);
void *dc_tdelete(const struct dc_env *env, struct dc_error *err, const void *restrict key, void **restrict rootp, int(*compar)(const void *, const void *));
void *dc_tfind(const struct dc_env *env, struct dc_error *err, const void *key, void *const *rootp, int(*compar)(const void *, const void *));
void *dc_tsearch(const struct dc_env *env, struct dc_error *err, const void *key, void **rootp, int(*compar)(const void *, const void *));
void dc_twalk(const struct dc_env *env, struct dc_error *err, const void *root, void (*action)(const void *, VISIT, int));


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_XSI_DC_SEARCH_H
