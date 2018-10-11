#include "stack.h"

void push(stack *s, char* pathname) {
    node *n = malloc(sizeof(node));
    strcpy(n -> pathname, pathname);
    n -> prev = (s -> head);
    if (s -> head != NULL) {
        (s -> head) -> next = n;
    }
    (s -> head) = n;
    (s -> size)++;
}

char* pop(stack *s) {
    if (s -> head == NULL) {
        return NULL;
    } else {
        node *n = s -> head;
        char *path = n -> pathname;
        (s -> head) = n -> prev;
        //head -> next = NULL;
        free(n);
        (s -> size)--;
        return path;
    }
}

char* peek(stack *s) {
    if (s -> head == NULL) {
        return NULL;
    } else {
        return (s -> head) -> pathname;
    }
}