#include <stdio.h>
#include <stdlib.h>

#include "point.c"

int main() {
    float d;
    Point *p, *q;

    p = pt_create(10, 21);
    q = pt_create(7, 25);

    d = pt_distance(p, q);

    pt_free(p);
    pt_free(q);

    printf("%f", d);
}
