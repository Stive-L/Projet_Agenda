#include <stdio.h>
#include "list.h"
#include "cell.h"
#include <math.h>
#include "timer.h"
#include <stdlib.h>

int main() {

    int niv_actu = 7;
    int niv_final = 16;

    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;
    srand(time(NULL));

    // Boucle pour calculer le temps d'éxution
    while (niv_actu <= niv_final){

        printf("Le niveau courant est %d\n", niv_actu);

        int nbr_cell = pow(2,niv_actu)-1;
        int tab_levels[nbr_cell];
        t_d_list *list_p2 = create_multi_level_list(niv_final);
        // Init les éléments du tab à 0
        for (int i = 0; i < nbr_cell;i++){
            tab_levels[i] = 0;
        }

        // On remplit le tableau en suivant la méthode de Mr.Fasque
        for (int step = 2; step <= nbr_cell; step *= 2) {
            int temp = step-1;
            while (temp <=nbr_cell-1){
                tab_levels[temp] += 1;
                temp += step;
            }

        }
        // On insère les éléments dans la liste de niveaux
        for (int i = 0;i < nbr_cell;i++){
            insertion_en_ordre(list_p2,tab_levels[i],i+1);
        }


        startTimer();
        for (int i = 0; i < 10000; i++){
            int nbr_aleatoire = (rand() % nbr_cell) + 1;
            int temp_niv0 = recherche_0(*list_p2,nbr_aleatoire);
        }
        stopTimer();
        time_lvl0 = getTimeAsString(); // fonction du module timer
        printf("Le temps de recherche au niveau 0 est %s\n", getTimeAsString());

        startTimer();
        for (int i = 0; i < 10000; i++){
            int nbr_aleatoire = (rand() % nbr_cell) + 1;
            int temp_niv0 = recherche_du_plus_haut(*list_p2,nbr_aleatoire);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        fprintf(log_file,format,niv_actu,time_lvl0, time_all_levels);
        printf("Le temps de recherche pour du multi_niveaux est %s\n", getTimeAsString());

        niv_actu += 1;
    }
    fclose(log_file);


    // Partie 2 (test)
    /*
    int n = 7;
    int nbr_cell = pow(2,n)-1;
    int tab_levels[nbr_cell];
    t_d_list *list_p2 = create_multi_level_list(n);
    for (int i = 0; i < nbr_cell;i++){
        tab_levels[i] = 0;
        //printf("%d",tab_levels[i]);
    }
    printf("\n");
    // Remplir le tableau
    for (int step = 2; step <= nbr_cell; step *= 2) {
        int temp = step-1;
        while (temp <=nbr_cell-1){
            tab_levels[temp] += 1;
            temp += step;
        }

    }

    for (int i = 0; i < nbr_cell;i++){
        printf("%d",tab_levels[i]);
    }

    //display_all_levels(*list_p2);
    for (int i = 0;i < nbr_cell;i++){
        insertion_en_ordre(list_p2,tab_levels[i],i+1);
    }
    //display_all_levels(*list_p2);
    */


    // Partie 1 (test)
    /*
    int max_levels = 5;
    t_d_list *list = create_multi_level_list(max_levels);
    t_d_cell *cell = create_multi_level_cell(1, 5);
    insertion_en_tete(list,cell);
    //display_all_levels(*list);
    // Niveau 0

    insertion_en_ordre(list,0,25);
    insertion_en_ordre(list,0,59);

    // Niveau 1
    insertion_en_ordre(list,1,31);


    //Niveau 2
    insertion_en_ordre(list,2,56);
    insertion_en_ordre(list,2,91);

    //Niveau 3
    insertion_en_ordre(list,3,18);

    //Niveau 4
    insertion_en_ordre(list,4,32);
    insertion_en_ordre(list,4,59);

    display_all_levels(*list);
    display_cells_at_level(*list,1);

    int test_recherche_0 = recherche_0(*list,20);
    printf("Recherche niveau 0 : %d\n", test_recherche_0);
    int test_recherche_haut = recherche_du_plus_haut(*list,20);
    printf("Recherche niveau_plus_haut : %d", test_recherche_haut);
    */
    return 0;
}