/*
 * Title: merge_sort.c
 * Author: Jia Guo
 * Date: Sep 26, 2018
 * Description: Example of merge sort.
 * Time: O(nlgn) Space: O(n)
 */
#include "utility.h"

void merge_sort(int * arr, int p, int r);
void merge(int * arr, int p, int q, int r);

int main(int argc, char const *argv[]) {
    int *arr;
    int size;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s %s\n", argv[0], "size");
        exit(-1);
    } else {
        size = atoi(argv[1]);
    }
    arr = (int *)malloc(size * sizeof(int));
    init_arr(arr, size, false);
    printf("Before sorting:\n");
    print_arr(arr, size);
    merge_sort(arr, 0, size - 1);
    printf("After sorting:\n");
    print_arr(arr, size);
    free(arr);
    return 0;
}

void merge_sort(int * arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; // r - (r - q) / 2
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge(int * arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int * left = (int *)malloc((n1 + 1) * sizeof(int));
    int * right = (int *)malloc((n2 + 1) * sizeof(int));
    int i, j;
    for (i = 0; i < n1; i++) {
        left[i] = arr[p + i];
    }
    for (j = 0; j < n2; j++) {
        right[j] = arr[q + j + 1];
    }
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    i = 0;
    j = 0;
    int k;
    for (k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i += 1;
        } else {
            arr[k] = right[j];
            j += 1;
        }
    }
    free(left);
    free(right);
}
