// dynamic_chained_list_main.c
#include <stdlib.h>
#include <stdio.h>

#include "dynamic_chained_list.c"

List* list;

int main() {
    list = create_list();

    struct person p1;
    p1.num = 123;

    int a = prepend(list, p1);

    printf("---> %d \n", length(list));

    lfree(list);

    return 0;
}
