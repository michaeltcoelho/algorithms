// linked_list_queue.c
#include <stdlib.h>

#include "linked_list_queue.h"

struct queue {
    struct element *head;
    struct element *tail;
    int qty;
};

struct element {
    struct person data;
    struct element *next;
};

typedef struct element Element;


Queue* create_queue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if (q != NULL) {
        q->tail = NULL;
        q->head = NULL;
    }
    return q;
}

void destroy(Queue *q) {
    if (q != NULL) {
        Element *el;
        while (q->head != NULL) {
            el = q->head;
            q->head = q->head->next;
            free(el);
        }
        free(q);
    }
}

int length(Queue *q) {
    if (q == NULL)
        return -1;
    return q->qty;
}

int is_full(Queue *p) {
    // memory capacity
    return 0;
}

int is_empty(Queue *q) {
    if (q == NULL) return 1;
    if (q->head == NULL)
        return 1;
    return 0;
}

int qput(Queue *q, struct person p) {
    if (q == NULL) return 0;
    Element* el = (Element*) malloc(sizeof(Element));
    if (el == NULL) return 0;
    el->data = p;
    el->next = NULL;

    if (q->tail == NULL)
        q->head = el;
    else
        q->tail->next = el;

    q->tail = el;
    return 1;
}

int qremove(Queue *q) {
    if (q == NULL) return 0;
    if (q->head == NULL)
        return 0;
    Element *el = q->head;
    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;
    free(el);
    return 1;
}

int get(Queue *q, struct person *p) {
    if (q == NULL || is_empty(q)) return 0;
    *p = q->head->data;
    return 1;
}
