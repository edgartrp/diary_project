#ifndef UNTITLED5_STRUCT_H
#define UNTITLED5_STRUCT_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

// cell structure
typedef struct s_d_cell{
    int value;
    int nbr_levels;
    struct s_d_cell** next;
} t_d_cell;

// list structure
typedef struct s_d_list{
    int max_levels;
    t_d_cell **head;
} t_d_list;

// timer structure
typedef struct s_timer{
    clock_t _start; // start time
    clock_t _end;   // end time
    double _msecs;  // duration in milliseconds
} t_timer;

#endif //UNTITLED5_STRUCT_H
