#include <stdio.h>

#include "dynamic_double_chained_list.h"

List* list;

int main() {
    list = create_list();
    lfree(list);
    return 0;
}
