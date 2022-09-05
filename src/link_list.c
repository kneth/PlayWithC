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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "link_list.h"

link_list_element_t *link_list_element_alloc() {
    link_list_element_t *element;

    element = malloc(sizeof(link_list_element_t));
    if (element == NULL) {
        printf("Cannot allocate link_list_element");
        exit(0);
    }

    element->next = NULL;
    element->payload = NULL;

    return element;
}

void link_list_element_free(link_list_element_t *element) {
    free((void *)element);
}

link_list_t *link_list_alloc() {
    link_list_t *list = malloc(sizeof(link_list_t));

    if (!list) {
        printf("Cannot allocate list.");
        exit(-1);
    }

    list->first = NULL;
    list->last = NULL;
    return list;
}

void link_list_free(link_list_t *list) {
    link_list_element_t *iter;

    iter = list->first;
    while (iter != NULL) {
        link_list_element_t *next = iter->next;
        link_list_element_free(iter);
        iter = next;
    }

    free((void *)list);
}

void link_list_append(link_list_t *list, person_t *person) {
    link_list_element_t *element;
    link_list_element_t *last;

    element = link_list_element_alloc();
    element->payload = person;
    element->next = NULL;

    if (list->first == NULL) {
        list->first = element;
        list->last = element;
    }

    last = list->last;
    list->last = element;
    last->next = element;
}

size_t link_list_count(link_list_t *list) {
    size_t count = 0;
    link_list_element_t *iter = list->first;
    while (iter != NULL) {
        count++;
        iter = iter->next;
    }
    return count;
}