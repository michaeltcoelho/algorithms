// queue_main.c
#include <stdio.h>
#include <assert.h>

#include "queue.c"

Queue* q;

int main() {

    struct person p1;
    p1.num = 1;

    struct person p2;
    p2.num = 1;

    q = create_queue();

    qput(q, p1);
    qput(q, p2);

    assert(length(q) == 2);

    qremove(q);

    assert(length(q) == 1);

    qput(q, p2);

    assert(length(q) == 2);

    struct person p3;

    get(q, &p3);

    assert(p3.num == 1);

    destroy(q);

    return 1;
}
