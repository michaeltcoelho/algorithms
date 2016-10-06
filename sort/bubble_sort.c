// buble_sort.c
#include <stdio.h>

/*
    Performance:
        Best Case: O(N)
        Worse Case: O(N ^ 2)

    Not recommended to a large set of data.
*/

void bubble_sort(int *V, int N) {
    int flag, i;
    do
    {
        flag = 0;
        for (i = 0; i < N - 1; i++) {
            if (V[i] > V[i + 1]) {
                int n = V[i];
                V[i] = V[i + 1];
                V[i + 1] = n;
                flag = 1;
            }
        }
        N--;
    } while(flag);
}


int main() {
    int v[10] = {10, 7, 8, 9, 6, 5, 4, 3, 2, 1};
    bubble_sort(v, 10);
    for (int i = 0; i < 11; i++) {
        printf("%d ", i);
    }
    return 1;
}
