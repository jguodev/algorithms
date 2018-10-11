#include "queue.h"

int enqueue(queue *q, char* obj) {
    qnode *n = malloc(sizeof(qnode));
    strcpy(n -> obj, obj);

    n -> prev = NULL;
    n -> next = q -> tail;

    if (q -> tail != NULL) {
        q -> tail -> prev = n;
    } else {
        q -> head = n;
    }
    q -> tail = n;
    q -> size++;
    return 0;
}

char* dequeue(queue *q) {
    if (q -> head == NULL) {
        return NULL;
    } else {
        qnode *n = q -> head;
        char *obj = n -> obj;

        q -> head = n -> prev;
        if (q -> head != NULL) {
            q -> head -> next = NULL;
        }

        free(n);
        q -> size--;
        return obj;
    }
}

char* peek(queue *q) {
    if (q -> head == NULL) {
        return NULL;
    } else {
        return q -> head -> obj;
    }
}