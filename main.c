#include <stdio.h>
#include "list.h"
#include "cell.h"
#include "timer.h"
#include <stdlib.h>

int main() {
    printf("Hello, World!\n");
    int max_levels = 5;
    t_d_list *list = create_multi_level_list(max_levels);
    t_d_cell *cell = create_multi_level_cell(1, 5);
    insertion_en_tete(list,cell);
    display_all_levels(list);
    // Niveau 0
   /*
    insertion_en_ordre(list,0,18);
    insertion_en_ordre(list,0,25);
    insertion_en_ordre(list,0,31);
    insertion_en_ordre(list,0,32);
    insertion_en_ordre(list,0,56);
    insertion_en_ordre(list,0,59);
    insertion_en_ordre(list,0,59);
    insertion_en_ordre(list,0,91);

    // Niveau 1
    insertion_en_ordre(list,1,18);
    insertion_en_ordre(list,1,31);
    insertion_en_ordre(list,1,32);
    insertion_en_ordre(list,1,56);
    insertion_en_ordre(list,1,59);
    insertion_en_ordre(list,1,91);

    //Niveau 2
    insertion_en_ordre(list,2,18);
    insertion_en_ordre(list,2,32);
    insertion_en_ordre(list,2,56);
    insertion_en_ordre(list,2,59);
    insertion_en_ordre(list,2,91);

    //Niveau 3
    insertion_en_ordre(list,3,18);
    insertion_en_ordre(list,3,32);
    insertion_en_ordre(list,3,59);

    //Niveau 4
    insertion_en_ordre(list,4,32);
    insertion_en_ordre(list,4,59);
    display_all_levels(list);
    cell = recherche_du_plus_haut(list, 25);
/*

        /*
         cell = recherche_0(list, 18);
         */
        printf("%d", cell->value);
         /*
        /*
        printf("\n");
        t_d_cell *cell1 = create_multi_level_cell(2, 4);
        insertion_en_tete(list,cell1);
        display_all_levels(list);
        */
    int initialLevel = 7;
    int finalLevel = 15;

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Boucle sur tous les niveaux à tester
    for (int currentLevel = initialLevel; currentLevel <= finalLevel; currentLevel++) {
        printf("Niveau testé: %d\n", currentLevel);

        // Création de la liste à niveaux
        t_d_list *nv = create_multi_level_list(currentLevel);

        // Démarrage du timer pour la recherche au niveau 0
        startTimer();
        for (int i = 0; i < 10000; i++) {  // 10 000 recherches au hasard
            int randomValue = rand() % (currentLevel * 10);
            recherche_0(list, randomValue);
        }
        stopTimer();
        printf("Search time at level 0: %s\n", getTimeAsString());

        // Démarrage du timer pour la recherche multi-niveaux
        startTimer();
        for (int i = 0; i < 10000; i++) {  // 10 000 recherches au hasard
            int randomValue = rand() % (currentLevel * 10);
            recherche_du_plus_haut(list, randomValue);
        }
        stopTimer();
        printf("Search time at multi-levels: %s\n", getTimeAsString());

        // Libération de la mémoire de la liste
        // (vous devrez implémenter cette fonction)
        // free_multi_level_list(list);
    }

    return 0;
}
