//
// Created by lzcst on 26/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
t_d_cell *create_multi_level_cell(int value, int level) {
    t_d_cell *cell = (t_d_cell *)malloc(sizeof(t_d_cell));
    if (cell == NULL) {
        // Gérer les erreurs de mémoire
        return NULL;
    }

    cell->value = value;
    cell->level = level;
    cell->next = (t_d_cell **)malloc(level * sizeof(t_d_cell *));
    if (cell->next == NULL) {
        // Gérer les erreurs de mémoire
        free(cell);
        return NULL;
    }

    for (int i = 0; i < level; i++) {
        cell->next[i] = NULL;
    }

    return cell;
}