// linear.c
#include <stdio.h>


int linear(int *V, int N, int elem) {
    for (int i = 0; i < N; i++)
        if (elem == V[i]) return i;
    return -1;
}

int main() {
    int v[10] = {-8, -5, 1, 4, 14, 21, 23, 54, 57, 90};
    if (linear(v, 10, 54) != -1)
        printf("OK!\n");
    else
        printf("NOT FOUND!\n");
    return 1;
}
