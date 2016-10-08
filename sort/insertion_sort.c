// insertion_sort.c

#include <assert.h>
#include <stdio.h>

/*
    Performance:
        Best Case: O(N)
        Worse Case: O(N ^ 2)

    Not recommended to a large set of data.
*/

void insertion_sort(int *V, int N) {
    int i, j, aux;
    // start looping over V from index 1
    for (i = 1; i < N; i++) {
        aux = V[i]; // aux = 3, j = 0
        // loop for the data greater than aux on left, moving them to a next pos
        for (j = i; (j > 0) && (aux < V[j - 1]); j--)
            V[j] = V[j - 1];
        V[j] = aux;
    }
}

int main() {
    int V[10] = {10, 5, 7, 8, 3, 4, -8, 2, 9, 6};
    int R[10] = {-8, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    insertion_sort(V, 10);
    for (int i = 0; i < 10; i++) {
        assert(V[i] == R[i]);
        printf("V[%d] = %d\n", i, V[i]);
    }
    return 1;
}
