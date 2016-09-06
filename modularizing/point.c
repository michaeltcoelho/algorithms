// point.c file

#include <stdlib.h>
#include <math.h>

#include "point.h"

struct point {
    float x;
    float y;
};

Point* pt_create(float x, float y) {
    Point* p = (Point*) malloc(sizeof(Point));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void pt_free(Point* p) {
    free(p);
}

void pt_get(Point* p, float* x, float* y) {
    *x = p->x;
    *y = p->y;
}

void pt_set(Point* p, float x, float y) {
    p->x = x;
    p->y = y;
}

float pt_distance(Point* p1, Point* p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}
