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

int length(List* list) {
    if (list == NULL) return 0;
    int count = 0;
    Element* el = *list;
    while (el != NULL) {
        count++;
        el = el->next;
    }
    return count;
}

int is_empty(List* list) {
    if (list == NULL)
        return 0;
    if (*list == NULL)
        return 0;
    return 1;
}

int is_full(List* list) {
    return 0;
}

int prepend(List* list, struct person p) {
    if (list == NULL) return 0;
    Element* el = (Element*) malloc(sizeof(Element));
    if (el == NULL) return 0;
    el->data = p;
    el->prev = NULL;
    el->next = (*list);

    if (!is_empty(list))
        (*list)->prev = el;

    *list = el; // set el as the first element of the list
    return 1;
}


int append(List* list, struct person p) {
    if (list == NULL) return 0;
    Element* el = (Element*) malloc(sizeof(Element));
    if (el == NULL) return 0;
    el->data = p;
    el->next = NULL;

    if (is_empty(list)) {
        el->prev = NULL;
        *list = el;
    }
    else {
        Element* aux = *list;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = el;
        el->prev = aux;
    }
    return 1;
}

int ordered_insert(List* list, struct person p) {
    if (list == NULL) return 0;
    Element* el = (Element*) malloc(sizeof(Element));
    if (el == NULL) return 0;

    el->data = p;

    if (is_empty(list)) {
        el->prev = NULL;
        el->next = NULL;
        *list = el;
    }
    else {

        Element *previous, *current = *list;
        while (current != NULL && current->data.num < p.num) {
            previous = current;
            current = current->next;
        }

        if (current == *list) { //insert to begin
            el->prev = NULL;
            (*list)->prev = el;
            el->next = (*list);
            *list = el;
        } else {
            el->next = previous->next;
            el->prev = previous;
            previous->next = el;

            if (current != NULL)
                current->prev = el;
        }
    }
    return 1;
}

int delete(List* list, int num) {
    if (is_empty(list)) return 0;

    Element *current = *list;
    while (current != NULL && current->data.num == num)
        current = current->next;

    if (current == NULL) // not found
        return 0;

    if (current->prev == NULL) // the first element in the list
        *list = current->next;
    else
        current->prev->next = current->next;

    if (current->next != NULL) // not the last element in the list
        current->next->prev = current->prev;

    free(current);
    return 1;
}


int get(List* list, int pos, struct person *p) {
    if (list == NULL || pos <= 0) return 0;
    Element* el = *list;
    int i = 1;

    while (el != NULL && i < pos) {
        el = el->next;
        i++;
    }

    if (el == NULL)
        return 0;
    else
        *p = el->data;
    return 1;
}
