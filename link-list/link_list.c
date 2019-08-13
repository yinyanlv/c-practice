#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

int main (void) {
    Node *head, *p, *q;

    p = (Node *)malloc(sizeof(Node));
    p->data = 0;
    p->next = NULL;
    head = p;

    for (int i = 0; i < 4; i++) {
        q = (Node *)malloc(sizeof(Node));
        q->data = 10 * (i + 1);
        q->next = NULL;
        p->next = q;
        p = q;
    }

    p->next = NULL;

    printf("head address: %#x\n", head);

    for (Node *p = head; p != NULL; p = p->next) {
        printf("------------\n");
        printf("data: %d\n", p->data);
        printf("current address: %#x\n", p);
        printf("next address: %#x\n", p->next);
    }
}