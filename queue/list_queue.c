#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;

struct node {
    int value;
    Node *next;
};

typedef struct queue {
    Node* first;
    Node* last;
    int count;
} Queue;


void en_queue(Queue *q, int value) {

    Node *n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;

    if (q->first == NULL) {
       q->first = n;
       q->last = n;
       q->count++;

       return;
    }

    q->last->next = n;
    q->count++;
}

int de_queue(Queue *q) {
    printf("a::%d\n", q->count);
    if (q->count == 0) {
         printf("queue is empty!\n");
         return -1;
    }

    Node* n = q->first;
    int temp = n->value;

    q->first = q->first->next;
    q->count--;
    free(n);
    return temp;
}

void init_queue(Queue *q) {
    q->first = NULL;
    q->last = NULL;
    q->count = 0;
}


int main(void) {
    Queue q;

    init_queue(&q);

    en_queue(&q, 1);
    en_queue(&q, 2);
    de_queue(&q);
    de_queue(&q);
    de_queue(&q);
    Node *head;

    for (head = q.first; head != NULL; head = head->next) {
        printf("%d\n", head->value);
    }
}
