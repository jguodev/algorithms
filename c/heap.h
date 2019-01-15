#ifndef _HEAP_H
#define _HEAP_H

typedef struct {
    int key;
    heap_node * left;
    heap_node * right;
} heap_node;

typedef struct {
    heap_node * root;
} heap;

void heapify();

int insert();

int remove();
