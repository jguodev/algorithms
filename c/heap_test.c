#include <assert.h>
#include "heap.h"

int main(int argc, char **argv) {
  min_heap * heap;
  heap = malloc(sizeof(min_heap));
  heap->capacity = 10;
  heap->size = 0;
  heap->arr = malloc(sizeof(int) * heap->capacity);

  insert_key(15, heap);
  insert_key(12, heap);
  insert_key(9, heap);
  insert_key(13, heap);
  insert_key(11, heap);

  assert(get_min(heap) == 9);
  extract_min(heap);
  assert(get_min(heap) == 11);
  extract_min(heap);
  assert(get_min(heap) == 12);

  free(heap->arr);
  free(heap);
  return 0;
}
