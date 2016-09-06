// file point.h

typedef struct point Point;

Point* pt_create(float x, float y);

void pt_free(Point* p);

void pt_get(Point* p, float* x, float* y);

void pt_set(Point* p, float x, float y);

float pt_distance(Point* p1, Point* p2);
