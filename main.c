#include <stdio.h>
#include "list.h"
#include "cell.h"

int main() {
    printf("Hello, World!\n");
    int max_levels = 5;
    t_d_list *list = create_multi_level_list(max_levels);
    t_d_cell *cell = create_multi_level_cell(5, 5);

    insertion_en_tete(list,cell);


    display_all_levels(list);
    return 0;

}
