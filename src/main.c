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

#include "link_list.h"

int main(int argc, char *argv[]) {
    link_list_t *list;
    person_t *bonnie;
    person_t *clyde;

    bonnie = malloc(sizeof(person_t));
    bonnie->name = strdup("Bonnie");
    bonnie->age = 24;

    clyde = malloc(sizeof(person_t));
    clyde->name = strdup("Clyde");
    clyde->age = 23;

    list = link_list_alloc();
    link_list_append(list, bonnie);
    link_list_append(list, clyde);

    printf("%zu\n", link_list_count(list));

    link_list_free(list);
    free((void *)clyde);
    free((void *)bonnie);
}
