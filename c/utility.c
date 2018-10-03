#include "utility.h"

// randomly fill the arr with unique numbers within the range of [1, size]
void init_arr(int * arr, int size, _Bool sign) {
    srand(time(NULL));
    int i;
    int j;
    // lib is initialized with values from 1 to size in order
    int *lib = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        lib[i] = i + 1;
    }
    // find unused values using randomly generated index
    for (i = 0; i < size; i++) {
        do {
            j = rand() % size;
        } while (lib[j] == 0);
        arr[i] = lib[j];
        if (sign && rand() % 2 == 1) {
            arr[i] = -arr[i];
        }
        // set used number to 0
        lib[j] = 0;
    }

    free(lib);
}

void print_arr(int * arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
