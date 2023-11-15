//
// Created by edgar on 04/11/2023.
//

#include "functions.h"
#include "struct.h"
#include "lists.h"
#include "cells.h"

void free_cell(t_d_cell* cell) {
    if (cell != NULL) {
        free(cell->next);
        free(cell);
    }
}
void free_list(t_d_list* list) {
    if (list != NULL) {
        for (int level = 0; level < list->max_levels; level++) {
            t_d_cell* current = list->head[level];
            while (current != NULL) {
                t_d_cell* temp = current;
                current = current->next[level];
                free_cell(temp);
            }
        }
    }
    free(list);
}
t_d_list* create_special_list(int n){
    t_d_list *list = create_list(n);
    t_d_cell *newCell;
    int arr[(int) (pow(2, n) - 1)];
    for (int i = 0; i < pow(2, n)-1; i++) {
        arr[i] = 1;
    }
    for (int j = 1; j < n; j++){
        for (int i = (int) pow(2, j)-1; i < pow(2, n)-1; i += (int) pow(2, j)){
            arr[i]++;
        }
    }
    for (int i = 0; i <= pow(2, n)-1; i++) {
        newCell = create_cell((int) (pow(2, n)-1)-i, arr[i]);
        insert_cell(list, newCell);
    }
    return list;
}

int classic_search(int value, t_d_list *list){
    t_d_cell *current = list->head[0];
    int cpt = 0;
    while (current != NULL){
        if (value == current->value){
            return cpt;
        }
        current = current->next[0];
        cpt++;
    }
    return -1;
}

int igh_search(int value, t_d_list *list){
    int current_lvl = list->max_levels-1, pos;
    t_d_cell *current = list->head[current_lvl];
    while (current_lvl >= 0){
        while (current != NULL){
            if (value == current->value){
                return 1;
            }
            if (value > current->value){

            }
            current = current->next[current_lvl];
        }
        current_lvl--;
        current = list->head[current_lvl];
    }
    return -1;
}

int high_search(int value, t_d_list *list){
    int current_lvl = list->max_levels;
    t_d_cell *current = list->head[current_lvl-1];
    while (value != current->value && current_lvl >= 0){
        current_lvl -= 1;
        if (value > current->value){
            current = current->next[current_lvl];
        }
        else{
            current = list->head[current_lvl];
        }
    }
    if (value == current->value){
        return value;
    }
    else{
        return -1;
    }

}