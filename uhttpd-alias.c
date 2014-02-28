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

#include "uhttpd-alias.h"
#include <libubox/blobmsg.h>

static LIST_HEAD(aliases);

struct url_alias {
	struct list_head list;
	const char *from;
	int from_l;
	const char *to;
	int to_l;
};

void uh_alias_add(const char *from, const char *to) {
	struct url_alias *alias = malloc(sizeof(struct url_alias));
	alias->from = strdup(from);
	alias->from_l = strlen(from);
	alias->to = strdup(to);
	alias->to_l = strlen(to);

	list_add_tail(&alias->list, &aliases);
}

bool uh_alias_transform(const char *url, char *dest, int dest_l) {
	struct url_alias *alias;

	list_for_each_entry(alias, &aliases, list) {
		if (strncmp(url, alias->from, alias->from_l) == 0) {
			snprintf(dest, dest_l, alias->to, url + alias->from_l);
			dest[dest_l-1] = 0;
			return true;
		}
	}

	// The URL doesn't match any alias, copy as is
	strncpy(dest, url, dest_l);
	dest[dest_l-1] = 0;
	return false;
}

