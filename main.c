#include <stdio.h>
#include "list.h"
#include "cell.h"

int main() {
    printf("Hello, World!\n");
    int max_levels = 5;
    t_d_list *list = create_multi_level_list(max_levels);
    //t_d_cell *cell = create_multi_level_cell(1, 5);
    //insertion_en_tete(list,cell);
    //display_all_levels(list);
    // Niveau 0
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
    /*
    printf("\n");
    t_d_cell *cell1 = create_multi_level_cell(2, 4);
    insertion_en_tete(list,cell1);
    display_all_levels(list);
    */
    return 0;

}