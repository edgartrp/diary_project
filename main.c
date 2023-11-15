#include <stdio.h>
#include "struct.h"
#include "cells.h"
#include "lists.h"
#include "timer.h"
#include "functions.h"
int main() {

    t_d_list *list;
    list = create_special_list(5);
    display_all_levels(list);
    /*
    int search = classic_search(4, list);
    if (search != -1){
        printf("The value is in the list\n");
    }
    else{
        printf("Nothing here\n");
    }
     */
    int Hsearch = high_search(31, list);
    if (Hsearch != -1){
        printf("The value is in the list\n");
    }
    else{
        printf("Nothing here\n");
    }
    return 0;
}
