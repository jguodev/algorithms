/*
 * Title: insertion_sort.c
 * Author: Jia Guo
 * Date: Sep 25, 2018
 * Description: Example of insertion sort.
 * Time: O(n^2) Space: O(1)
 */

#include "utility.h"

void insertion_sort(int * arr, int size);

int main(int argc, char const *argv[]) {
    int *arr;
    int size;
    if (argc != 2) {
        fprintf(stderr, "usage: %s %s\n", argv[0], "size");
        exit(1);
    } else {
        size = atoi(argv[1]);
    }
    arr = (int *)malloc(size * sizeof(int));
    init_arr(arr, size);
    printf("Before sorting:\n");
    print_arr(arr, size);
    insertion_sort(arr, size);
    printf("After sorting:\n");
    print_arr(arr, size);
    free(arr);
    return 0;
}

void insertion_sort(int * arr, int size) {
    int i, j, key;
    /* Insert arr[j] into the sorted sequence arr[0..j-1] */
    for (j = 1; j < size; j++) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}
