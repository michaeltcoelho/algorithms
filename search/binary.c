// binary.c
#include <stdio.h>


int binary(int *V, int N, int elem) {
    int start, middle, end;
    start = 0;
    end = N - 1;
    while (start <= end) {
        middle = (start + end) / 2;
        if (elem < V[middle]) {
            end = middle - 1;
        } else {
            if (elem > V[middle]) {
                start = middle + 1;
            } else {
                return middle;
            }
        }
    }
    return -1;
}

int main() {
    int v[10] = {-8, -5, 1, 4, 14, 21, 23, 54, 57, 90};
    if (binary(v, 10, 54) != -1)
        printf("OK!\n");
    else
        printf("NOT FOUND!\n");
    return 1;
}
