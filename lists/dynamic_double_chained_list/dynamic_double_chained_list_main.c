#include <stdio.h>
#include <assert.h>

#include "dynamic_double_chained_list.c"

List* list;

int main() {
    list = create_list();

    struct person p1;
    p1.num = 123;

    struct person p2;
    p1.num = 456;

    prepend(list, p1);
    prepend(list, p2);
    append(list, p1);
    append(list, p2);

    assert(4 == length(list));

    lfree(list);
    return 0;
}
