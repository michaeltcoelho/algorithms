#include <stdio.h>

#include "linear_static_list.h"

/*
    GOODS:
        - Fast access to the elements;
        - The same time spend to access an element;
        - Easiness when changing informations;

    BADS:
        - Fixed length;
        - Difficulty when inserting/deleting an element:
          it's necessary move each element on insert/delete op;
*/


struct list {
    int qty;
    struct person data[MAX];
};

List* create_list() {
    List* li = (List*) malloc(sizeof(struct list));
    if (li != NULL)
        li->qty = 0;
    return li;
}

void set_list_free(List* li) {
    free(li);
}

int list_size(List* li) {
    if (li == null)
        return -1;
    return li->qty;
}

int is_full(List* li) {
    if (li == null)
        return -1;
    return (li->qty == MAX);
}

int is_empty(List* li) {
    if (li == NULL)
        return -1;
    return (li->qty == 0);
}

int append(List* li, struct person p) {
    if (li == NULL)
        return 0;
    if is_full(li)
        return 0;
    li->data[li->qty] = p;
    li->qty++;
    return 1;
}

int prepend(List* li, struct person p) {
    if (li == NULL)
        return 0;
    if is_full(li)
        return 0;

    int i = li->qty - 1;
    for (; i >= 0; i--) {
        li->data[i + 1] = li->data[i];
    }
    li->data[0] = p;
    li->qty++;
    return 1;
}

int ordered_insert(List* li, struct person p) {
    if (li == NULL)
        return 0;
    if is_full(li)
        return 0;

    int i = 0;
    while ((i < li->qty) && (li->data[i].num < p->num))
        i++;

    int k = li->qty - 1;
    for (; k >= i; k--)
        li->data[k + 1] = li->data[k];

    li->data[i] = p;
    li->qty++;
    return 1;
}

int remove_last(List* li) {
    if (li == NULL)
        return 0;
    if is_empty()
        return 0;
    li->qty--;
    return 1;
}

int remove_first(List* li) {
    if (li == NULL)
        return 0;
    if is_empty()
        return 0;

    for (int i = 0; i < li->qty - 1, i++)
        li->data[i] = li->data[i + 1];

    li->qty--;
    return 1;
}

int search_pos(list* li, int pos, struct person *p) {
    if (li == NULL || pos <= 0 || pos > li->qty)
        return 0;
    *p = li->data[pos - 1];
    return 1;
}

int search(List* list, int num, struct person *p) {
    if (li == NULL)
        return 0;

    int i = 0;
    while((i < li->qty) && (li->data[i].num != num))
        i++;

    if (i == li->qty)
        return 0;

    *p = li->data[i];
    return 1;
}
