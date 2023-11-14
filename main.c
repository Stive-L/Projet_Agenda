#include <stdio.h>
#include "list.h"
#include "cell.h"

int main() {
    printf("Hello, World!\n");
    int max_levels = 5;
    t_d_list *list = create_multi_level_list(max_levels);
    t_d_cell *cell = create_multi_level_cell(5, 5);

    insertion_en_tete(list,cell);
    //display_all_levels(list);
    insertion_en_ordre(list,2,3);
    insertion_en_ordre(list,4,6);
    insertion_en_ordre(list,1,7);
    insertion_en_ordre(list,1,1000);
    //display_cells_at_level(list,2);
    display_all_levels(list);
    printf("\n");
    t_d_cell *cell1 = create_multi_level_cell(2, 4);
    insertion_en_tete(list,cell1);
    display_all_levels(list);
    return 0;

}
