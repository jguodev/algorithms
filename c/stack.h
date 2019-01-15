#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char obj[1024];
    struct Node *next;
    struct Node *prev;
} node;

typedef struct {
    node *head;
    int size;
} stack;

void push(stack *s, char* obj);

char* pop(stack *s);

char* peek(stack *s);

#endif