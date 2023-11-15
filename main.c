#include <stdio.h>
#include "struct.h"
#include "cells.h"
#include "lists.h"
#include "timer.h"
#include "functions.h"
int main() {

    t_d_cell *cell1, *cell2, *cell3, *cell4, *cell5, *cell6, *cell7, *cell8;
    t_d_list *list;
     /*
    list = create_list(6);
    cell1 = create_cell(91,3);
    insert_cell(list, cell1);
    cell2 = create_cell(59,1);
    insert_cell(list, cell2);
    cell3 = create_cell(59, 5);
    insert_cell(list, cell3);
    cell4 = create_cell(56, 3);
    insert_cell(list, cell4);
    cell5 = create_cell(32, 5);
    insert_cell(list, cell5);
    cell6 = create_cell(31, 2);
    insert_cell(list, cell6);
    cell7 = create_cell(25, 1);
    insert_cell(list, cell7);
    cell8 = create_cell(18, 4);
    insert_cell(list, cell8);
    */
    list = create_special_list(4);
    display_all_levels(list);
    int search = classic_search(5, list);
    if (search != -1){
        printf("The value is at position %d\n", search+1);
    }
    int Hsearch = high_search(5, list);
    if (Hsearch != -1){
        printf("The value is at position %d\n", Hsearch);
    }
    return 0;
}
