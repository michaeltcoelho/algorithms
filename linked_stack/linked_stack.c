// linked_stack.c
#include <stdlib.h>

#include "linked_stack.h"


struct element {
    struct person data;
    struct element *next;
};

typedef struct element Element;

Stack* create_stack() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s != NULL)
        *s = NULL;
    return s;
}

void destroy(Stack *s) {
    if (s != NULL) {
        Element *el;
        while ((*s) != NULL) {
            el = *s;
            *s = (*s)->next;
            free(el);
        }
        free(s);
    }
}

int length(Stack *s) {
    if (s == NULL) return -1;
    int count = 0;
    Element *el = *s;
    while (el != NULL) {
        count++;
        el = el->next;
    }
    return count;
}

int is_empty(Stack *s) {
    if (s == NULL) return 1;
    if (*s == NULL) return 1;
    return 0;
}

int qpush(Stack *s, struct person p) {
    if (s == NULL) return 0;
    Element *el = (Element*) malloc(sizeof(Element));
    if (el == NULL) return 0;
    el->data = p;
    el->next = (*s);
    *s = el;
    return 1;
}

int qpop(Stack *s) {
    if (is_empty(s)) return 0;
    Element *el = *s;
    *s = el->next;
    free(el);
    return 1;
}

int get(Stack *s, struct person *p) {
    if (is_empty(s)) return 0;
    *p = (*s)->data;
    return 1;
}
