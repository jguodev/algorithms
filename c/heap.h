#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct heap_node_t {
  int key;
  struct heap_node_t * left;
  struct heap_node_t * right;
} heap_node;

typedef struct {
  int capacity;
  int size;
  int * arr;
  // heap_node * root;
} min_heap;

// get the parent index of the current node
int parent(int);

// get the left child index of the current node
int left(int);

// get the right child index of the current node
int right(int);

// remove the minimum element from the min_heap
int extract_min(min_heap *);

// returns the minimum element of the min_heap
int get_min(min_heap *);

// insert a new key to the heap
void insert_key(int, min_heap *);

// delete a key from the heap
void delete_key(int, min_heap *);

// heapify a subtree with the root at given index
void min_heapify(int, min_heap *);

#endif
