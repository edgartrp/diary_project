//
// Created by edgar on 25/10/2023.
//

#include "lists.h"
#include "struct.h"



t_d_list* create_list(int max_levels) {
    t_d_list* list = (t_d_list*)malloc(sizeof(t_d_list));

    if (list != NULL) {
        list->max_levels = max_levels;
        list->head = (t_d_cell**)malloc(max_levels * sizeof(t_d_cell*));

        for (int i = 0; i < max_levels; i++) {
            list->head[i] = NULL;
        }
    }

    return list;
}


void insert_cell(t_d_list* list, t_d_cell* cell) {
    for (int i = 0; i < cell->nbr_levels; i++) {
        cell->next[i] = list->head[i];
        list->head[i] = cell;
    }
}


void display_level(t_d_list* list, int level) {
    int tmp_lvl[50], nbr_elements = 0, j = 0;
    if (level != 0){
        t_d_cell* tmp = list->head[0];
        while (tmp != NULL){
            tmp_lvl[nbr_elements] = tmp->value;
            nbr_elements++;
            tmp = tmp->next[0];
        }
    }
    t_d_cell* current = list->head[level];
    printf("[list head_%d @-]", level);
    while (current != NULL) {
        if (level != 0 && current->value != tmp_lvl[j]){
            printf("----------");
        }
        else{
            printf("-->[ %d|@ ]", current->value);
            current = current->next[level];
        }
        j++;
    }
    if (j<nbr_elements){
        for (int k = 0; k < nbr_elements-j; k++){
            printf("----------");
        }
    }
    printf("-->NULL");
    printf("\n");
}

void display_all_levels(t_d_list* list) {
    if (list == NULL) {
        return;
    }
    display_level(list, 0);
    for (int i = 1; i < list->max_levels; i++) {
        display_level(list, i);
    }
}

void insert_sorted(t_d_list* list, t_d_cell* cell) {
    if (list == NULL || cell == NULL) {
        return;
    }
    int nbr_levels = cell->nbr_levels;

    if (nbr_levels > list->max_levels) {
        return;
    }

    for (int level = 0; level < nbr_levels; level++) {
        if (list->head[level] == NULL || (list->head[level])->value >= cell->value) {
            cell->next[level] = list->head[level];
            list->head[level] = cell;
        } else {
            t_d_cell* current = list->head[level];
            while (current->next[level] != NULL && current->next[level]->value < cell->value) {
                current = current->next[level];
            }
            cell->next[level] = current->next[level];
            current->next[level] = cell;
        }
    }
}
