// stack.c
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"


struct stack {
    int qty;
    struct person data[MAX];
};


Stack* create_stack() {
    Stack* st = (Stack*) malloc(sizeof(struct stack));
    if (st != NULL)
        st->qty = 0;
    return st;
}

void destroy(Stack *s) {
    free(s);
}

int length(Stack *s) {
    if (s == NULL) return -1;
    return s->qty;
}

int is_full(Stack *s) {
    if (s == NULL) return -1;
    return (s->qty == MAX);
}

int is_empty(Stack *s) {
    if (s == NULL) return -1;
    return (s->qty == 0);
}

int push(Stack *s, struct person p) {
    if (s == NULL || is_full(s)) return 0;
    s->data[s->qty] = p;
    s->qty++;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL || is_empty(s)) return 0;
    s->qty--;
    return 1;
}

int get(Stack *s, struct person *p) {
    if (s == NULL || is_empty(s)) return 0;
    *p = s->data[s->qty - 1];
    s->qty--;
    return 1;
}
