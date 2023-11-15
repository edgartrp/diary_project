//
// Created by edgar on 25/10/2023.
//

#ifndef UNTITLED5_LISTS_H
#define UNTITLED5_LISTS_H
#include "struct.h"
t_d_list* create_list(int max_levels);
void insert_cell(t_d_list* list, t_d_cell* cell);
void display_level(t_d_list* list, int level);
void display_all_levels(t_d_list* list);
void insert_sorted(t_d_list* list, t_d_cell* cell);
#endif //UNTITLED5_LISTS_H
