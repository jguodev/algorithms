/*
 * Title: insertion_sort.c
 * Author: Jia Guo
 * Date: Sep 25, 2018
 * Description: Example of insertion sort.
 * Time: O(n^2) Space: O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int * arr, int size);
void print_arr(int * arr, int size);
void insertion_sort(int * arr, int size);

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int *arr;
    int size = 10;
    arr = (int *)malloc(size * sizeof(int));
    init(arr, size);
    printf("Before sorting:\n");
    print_arr(arr, size);
    insertion_sort(arr, size);
    printf("After sorting:\n");
    print_arr(arr, size);
    free(arr);
    return 0;
}

void init(int * arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
}

void print_arr(int * arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
