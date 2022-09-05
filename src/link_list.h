/*
 * PlayWithC
 * Copyright (C) 2022 by Kenneth Geisshirt <geisshirt@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stddef.h>

#ifndef _LINK_LIST
#define _LINK_LIST

typedef struct _person {
    char *name;
    int age;
} person_t;

typedef struct _link_list_element {
    struct _link_list_element *next;
    person_t *payload;
} link_list_element_t;

typedef struct _link_list {
    link_list_element_t *first;
    link_list_element_t *last;
} link_list_t;

extern link_list_element_t *link_list_element_alloc();
extern void link_list_element_free(link_list_element_t *);
extern link_list_t *link_list_alloc();
extern void link_list_free(link_list_t *);
extern void link_list_append(link_list_t *, person_t *);
extern size_t link_list_count(link_list_t *);

#endif