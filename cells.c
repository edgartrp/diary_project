//
// Created by edgar on 25/10/2023.
//

#include "cells.h"



t_d_cell* create_cell(int value, int nbr_levels) {
    t_d_cell* cell = (t_d_cell*)malloc(sizeof(t_d_cell));
    if (cell != NULL) {
        cell->value = value;
        cell->nbr_levels = nbr_levels;
        cell->next = (t_d_cell**)malloc(nbr_levels * sizeof(t_d_cell*));
        for (int i = 0; i < nbr_levels; i++) {
            cell->next[i] = NULL;
        }
    }
    return cell;
}