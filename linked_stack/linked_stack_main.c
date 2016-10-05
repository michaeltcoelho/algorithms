// linked_stack_main.c
#include <stdio.h>
#include <assert.h>

#include "linked_stack.c"

Stack *st;

int main() {
    st = create_stack();

    assert(length(st) == 0);
    assert(is_empty(st) == 1);

    struct person p1;
    p1.num = 1;
    struct person p2;
    p2.num = 2;

    assert(qpush(st, p2) == 1);
    assert(qpush(st, p1) == 1);

    assert(length(st) == 2);
    assert(is_empty(st) == 0);

    assert(qpop(st) == 1);
    assert(length(st) == 1);

    struct person p3;

    assert(get(st, &p3) == 1);

    assert(p3.num == 2);

    destroy(st);

    return 1;
}
