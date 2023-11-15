//
// Created by lzcst on 26/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
t_d_list *create_multi_level_list(int max_levels) {
    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    if (list == NULL) {
        // Gérer les erreurs de mémoire
        return NULL;
    }

    list->max_levels = max_levels;
    list->head = (t_d_cell **)malloc(max_levels * sizeof(t_d_cell *));
    if (list->head == NULL) {
        // Gérer les erreurs de mémoire
        free(list);
        return NULL;
    }

    // Initialiser les têtes de chaque niveau

    for (int i = 0; i < max_levels; i++) {
        list->head[i] = create_multi_level_cell(0, i + 1); // 0 est la valeur de la cellule de base
    }

    return list;
}

void insertion_en_tete(t_d_list *list, t_d_cell *cell) {
    int levels;

    if (cell->level <= list->max_levels) {
        levels = cell->level;
    } else {
        levels = list->max_levels;
    }
    for (int i = 0; i < levels; i++) {
        cell->next[i] = list->head[i]->next[i];
        list->head[i]->next[i] = cell;
    }
}
void display_cells_at_level(t_d_list *list, int level) {
    if (level < 0 || level >= list->max_levels) {
        // niveau invalide
        return;
    }

    printf("Cellules au niveau %d : ", level);

    t_d_cell *courant = list->head[level]->next[level];
    while (courant != NULL) {
        printf("%d ", courant->value);
        courant = courant->next[level];
    }

    printf("\n");
}
void display_all_levels(t_d_list *list) {
    for (int level = 0; level < list->max_levels; level++) {
        printf("[list head_%d @-]", level);

        t_d_cell *courant = list->head[level]->next[level];
        t_d_cell *niv_premier = list->head[0]->next[0]; // On initialise un pointeur qui pointe sur le niveau 0

        // Traitement pour le niveau 0
        if (level == 0) {
            while (courant != NULL) {
                printf("-->[ %d|@-]", courant->value);
                courant = courant->next[level]; // On passe à la cellule suivante du niveau courant
            }
        }
        else { // Traitement pour les niveaux supérieurs
            while (niv_premier != NULL) { // Parcourir le niveau de base
                if (courant != NULL && courant->value == niv_premier->value) {
                    printf("-->[ %d|@-]", courant->value);
                    courant = courant->next[level]; // On passe à la cellule suivante du niveau courant
                } else {
                    printf("-----------"); // Espace pour cellule manquante
                }
                niv_premier = niv_premier->next[0]; // On next dans le premier niveau
            }
        }
        printf("-->NULL\n");
    }
}


void insertion_en_ordre(t_d_list *list, int level, int value) {
    // Créez une nouvelle cellule à insérer
    t_d_cell *newCell = create_multi_level_cell(value, level);

    // Initialisez la recherche au niveau demandé
    t_d_cell *current = list->head[level];

    while (current->next[level] != NULL && current->next[level]->value < value) {
        current = current->next[level];
    }

    newCell->next[level] = current->next[level];
    current->next[level] = newCell;
}