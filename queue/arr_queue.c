#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

typedef struct queue {
    int arr[SIZE];
    int first;
    int last;
} Queue;

void init_queue(Queue *q) {
    q->first = 0;
    q->last = 0;
}

_Bool is_full(Queue *q) {

    return (q->last + 1) % SIZE == q->first;
}

bool is_empty(Queue *q) {
    return q->first == q->last;
}

void en_queue(Queue *q, int val) {
    if (is_full(q)) {
        printf("queue is full!\n");
        return;
    }

    q->arr[q->last] =  val;
    q->last = (q->last + 1) % SIZE;
}

int de_queue(Queue *q) {
    if (is_empty(q)) {
        printf("queue is empty!\n");
        return -1;
    }
    int result;
    result = q->arr[q->first];
    q->arr[q->first] = -1;
    q->first = (q->first + 1) / SIZE;
    return result;
}

int main(void) {
    int a[3] = {11};

    Queue q;
    init_queue(&q);
    en_queue(&q, 1);
    en_queue(&q, 2);
    en_queue(&q, 3);
    de_queue(&q);
    en_queue(&q, 4);

    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, q.arr[i]);
    }
}