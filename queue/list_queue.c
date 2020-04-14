#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;

struct node {
    int value;
    Node *prev;
    Node *next;
};

typedef struct queue {
    Node* first;
    Node* last;
    int count;
} Queue;


void en_queue(Queue *q, int value) {

    if (q->first == NULL) {
       Node *n = (Node *)malloc(sizeof(Node));
       n->value = value;
       n->prev = NULL;
       n->next = NULL;
       q->first = n;
       q->last = n;
       q->count++;

       return;
    }

    Node *n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->prev = q->last;
    n->next = NULL;
    q->last = n;
    q->count++;
}

int de_queue(Queue *q) {
    if (q->count == 0) {
         printf("queue is empty!\n");
         return -1;
    }

    return 1;
}


int main(void) {
    Queue q;
    q.first = NULL;

    en_queue(&q, 1);
    en_queue(&q, 2);
    Node *head;

    for (head = q.first; head != NULL; head = head->next) {
        printf("%d\n", head->value);
    }
}
