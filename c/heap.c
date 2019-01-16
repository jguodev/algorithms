#include "heap.h"

void swap(int *m, int *n) {
  int temp = *m;
  *n = *m;
  *m = temp;
}

int parent(int i) {return (i - 1) / 2;}

int left(int i) {return 2 * i + 1;}

int right(int i) {return 2 * i;}

int get_min(min_heap * heap) {return heap->arr[0];}

int extract_min(min_heap * heap) {
  if (heap->size <= 0) {
    fprintf(stderr, "%s\n", "the heap is empty.");
    exit(-1);
  }

  // save the current root
  int root = heap->arr[0];
  // move the last element to root
  heap->arr[0] = heap->arr[heap->size - 1];
  heap->size--;
  // heapify to maintain the heap from the root
  min_heapify(0, heap);
  return root;
}

void insert_key(int key, min_heap * heap) {
  if (heap->size == heap->capacity) {
    fprintf(stderr, "%s\n", "Overflow: Could not insert key.");
    exit(-1);
  }

  // insert the new key at the end
  heap->size++;
  int i = heap->size - 1;
  heap->arr[i] = key;

  // maintain the minheap
  while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) {
    swap(&heap->arr[i], &heap->arr[parent(i)]);
    i = parent(i);
  }
}

void min_heapify(int i, min_heap * heap) {
  int l = left(i);
  int r = right(i);
  int min = i;

  // compare parent with min
  if (l < heap->size && heap->arr[l] < heap->arr[i]) {
    min = l;
  }
  if (r < heap->size && heap->arr[r] < heap->arr[min]) {
    min = r;
  }

  if (min != i) {
    swap(&heap->arr[i], &heap->arr[min]);
    // recursively heapify the subtree
    min_heapify(min, heap);
  }
}
//
// void delete_key(min_heap * heap) {
//
// }
