// queue.c
#include <stdlib.h>

#include "queue.h"

struct queue {
    int head, tail, qty;
    struct person data[MAX];
};

Queue* create_queue() {
    Queue *q = (Queue*) malloc(sizeof(struct queue));
    if (q != NULL) {
        q->head = 0;
        q->tail = 0;
        q->qty = 0;
    }
    return q;
}

void destroy(Queue *q) {
    free(q);
}

int length(Queue *q) {
    if (q == NULL)
        return -1;
    return q->qty;
}

int is_full(Queue *q) {
    if (q == NULL) return -1;
    if (q->qty == MAX)
        return 1;
    return 0;
}

int is_empty(Queue *q) {
    if (q == NULL) return -1;
    if (q->qty == 0)
        return 1;
    return 0;
}

int qput(Queue *q, struct person p) {
    if (q == NULL || is_full(q)) return 0;
    q->data[q->tail] = p;
    q->tail = (q->tail + 1) % MAX;
    q->qty++;
    return 1;
}

int qremove(Queue *q) {
    if (q == NULL || is_empty(q)) return 0;
    q->head = (q->head + 1) % MAX;
    q->qty--;
    return 1;
}

int get(Queue *q, struct person *p) {
    if (q == NULL || is_empty(q)) return 0;
    *p = q->data[q->head];
    return 1;
}
