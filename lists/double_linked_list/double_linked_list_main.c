#include <stdio.h>
#include <assert.h>

#include "dynamic_double_chained_list.c"

List* list;

int main() {
    list = create_list();

    struct person p1;
    p1.num = 1;

    struct person p2;
    p2.num = 2;

    struct person p3;
    p3.num = 4;

    struct person p4;
    p4.num = 3;

    prepend(list, p1);
    append(list, p2);
    append(list, p3);
    ordered_insert(list, p4);

    print(list);

    delete(list, p3.num);

    print(list);

    lfree(list);
    return 0;
}
