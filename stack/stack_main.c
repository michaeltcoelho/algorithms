// stack_main.c
#include <assert.h>

#include "stack.c"

Stack* st;

int main() {
    st = create_stack();

    assert(length(st) == 0);
    assert(is_full(st) == 0);
    assert(is_empty(st) == 1);

    struct person p1;
    p1.num = 1;

    struct person p2;
    p2.num = 2;

    assert(push(st, p2) == 1);
    assert(push(st, p1) == 1);

    assert(pop(st) == 1);
    assert(length(st) == 1);

    struct person p3;
    assert(get(st, &p3) == 1);
    assert(p3.num == 2);

    destroy(st);

    return 1;
}
