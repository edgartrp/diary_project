//
// Created by edgar on 04/11/2023.
//

#ifndef UNTITLED5_FUNCTIONS_H
#define UNTITLED5_FUNCTIONS_H
#include "struct.h"
void free_cell(t_d_cell* cell);
void free_list(t_d_list* list);
t_d_list* create_special_list(int n);
int classic_search(int value, t_d_list *list);
int high_search(int value, t_d_list *list);
#endif //UNTITLED5_FUNCTIONS_H
