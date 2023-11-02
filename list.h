//
// Created by lzcst on 26/10/2023.
//

#ifndef PROJET_AGENDA_LIST_H
#define PROJET_AGENDA_LIST_H
#include "cell.h"

typedef struct s_d_list
{
    int max_levels;
    t_d_cell **head;
} t_d_list;
t_d_list *create_multi_level_list(int );
void insertion_en_tete(t_d_list *, t_d_cell *);
void display_cells_at_level(t_d_list *, int );
void display_all_levels(t_d_list *);
void insertion_en_ordre(t_d_list *, int , int );

#endif //PROJET_AGENDA_LIST_H
