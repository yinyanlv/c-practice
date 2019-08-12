#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

int main (void) {
    Node *head, *p, *q, w;

    p = (Node *)malloc(sizeof(Node));
    p->data = 1;
    p->next = NULL;
    head = p;

    w.data = 2;
    w.next = NULL;

    printf("%d\n", p->data);
    printf("%d\n", p->next);
    printf("%d\n", w.data);
    printf("%d\n", w.next);
}