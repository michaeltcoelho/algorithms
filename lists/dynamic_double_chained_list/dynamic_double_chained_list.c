#include <stdlib.h>
#include <stdio.h>

#include "dynamic_double_chained_list.h"

/*
    GOODS:
        - Better memory usage;
        - Not shifting elements when insert/delete;
    BADS:
        - Expensive memory access: needs to loop over the list to access an element;
*/

struct element {
    struct element* prev;
    struct person data;
    struct element* next;
};

typedef struct element Element;

List* create_list() {
    List* list = (List*) malloc(sizeof(List));
    if (list != NULL)
        *list = NULL;
    return list;
}

void lfree(List* list) {
    if (list != NULL) {
        Element* el;
        while ((*list) != NULL) {
            el = *list;
            *list = (*list)->next;
            free(el);
        }
        free(list);
    }
}
