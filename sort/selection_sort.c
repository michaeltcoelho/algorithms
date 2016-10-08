// selection_sort.c

#include <assert.h>
#include <stdio.h>

/*
    Performance:
        Best Case: O(N ^ 2)
        Worse Case: O(N ^ 2)

    Not recommended to a large set of data. Not stable in the most case...

    Will loop over entire array picking the lowest value, placing it into the beginning of the array.
*/

void selection_sort(int *V, int N) {
    int i, j, lowest, shift;
    for (i = 0; i < N - 1; i++) {
        lowest = i;
        for (j = i + 1; j < N; j++) {
            if (V[j] < V[lowest])
                lowest = j;
        }

        if (i != lowest) {
            shift = V[i];
            V[i] = V[lowest];
            V[lowest] = shift;
        }
    }
}

int main() {
    int V[10] = {10, 5, 7, 8, 3, 4, -8, 2, 9, 6};
    int R[10] = {-8, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    selection_sort(V, 10);
    for (int i = 0; i < 10; i++) {
        printf("V[%d] = %d\n", i, V[i]);
        assert(V[i] == R[i]);
    }
    return 1;
}
