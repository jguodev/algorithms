#include "utility.h"

typedef struct {
    int left;
    int right;
    int sum;
} subarr;

subarr find_max_crossing_subarr(int *arr, int low, int mid, int high);
subarr find_max_subarr(int *arr, int low, int high);

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
    init_arr(arr, size, true);
    print_arr(arr, size);

    subarr max = find_max_subarr(arr, 0, size - 1);
    printf("subarr [%d, %d] (0 indexed) has the max sum: %d\n", max.left, max.right, max.sum);
    free(arr);
    return 0;
}


subarr find_max_crossing_subarr(int *arr, int low, int mid, int high) {
    subarr max_crossing_subarr;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    // find the left max
    for (int i = mid, sum = 0; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_crossing_subarr.left = i;
        }
    }
    // find the right max
    for (int i = mid + 1, sum = 0; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_crossing_subarr.right = i;
        }
    }
    max_crossing_subarr.sum = left_sum + right_sum;
    return max_crossing_subarr;
}

subarr find_max_subarr(int *arr, int low, int high) {
    subarr max_subarr;
    if (high == low) {
        max_subarr.left = low;
        max_subarr.right = high;
        max_subarr.sum = arr[low];
    } else {
        int mid = low + (high - low) / 2;
        subarr max_left_subarr = find_max_subarr(arr, low, mid);
        subarr max_right_subarr = find_max_subarr(arr, mid + 1, high);
        subarr max_crossing_subarr = find_max_crossing_subarr(arr, low, mid, high);
        if (max_left_subarr.sum >= max_right_subarr.sum
            && max_left_subarr.sum >= max_crossing_subarr.sum) {
            max_subarr.left = max_left_subarr.left;
            max_subarr.right = max_left_subarr.right;
            max_subarr.sum = max_left_subarr.sum;
        } else if (max_right_subarr.sum >= max_left_subarr.sum
            && max_right_subarr.sum >= max_crossing_subarr.sum) {
            max_subarr.left = max_right_subarr.left;
            max_subarr.right = max_right_subarr.right;
            max_subarr.sum = max_right_subarr.sum;
        } else {
            max_subarr.left = max_crossing_subarr.left;
            max_subarr.right = max_crossing_subarr.right;
            max_subarr.sum = max_crossing_subarr.sum;
        }
    }
    return max_subarr;
}
