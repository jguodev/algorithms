#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    struct node *next;
    char obj[1024];
} qnode;

typedef struct {
    int size;
    qnode *head;
    qnode *tail;
} queue;

int enqueue(queue *q, char *obj);

char *dequeue(queue *q);

char *peek(queue *q);

#endif