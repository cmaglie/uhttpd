/*
 * uhttpd - Tiny single-threaded httpd - Alias handler
 *
 *   Copyright (C) 2014 Cristian Maglie <c.maglie@bug.st>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef _UHTTPD_ALIAS_
#define _UHTTPD_ALIAS_

#include "uhttpd.h"

void uh_alias_add(const char *from, const char *to);

bool uh_alias_transform(const char *url, char *dest, int dest_l);

#endif

