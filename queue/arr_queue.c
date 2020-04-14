#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct queue {
    int arr[SIZE];
    int first;
    int next;
    int count;
} Queue;

void init_queue(Queue *q) {
    q->first = 0;
    q->next = 0;
    q->count = 0;
}

bool is_empty(Queue *q) {
    return q->count == 0;
}

bool is_full(Queue *q) {
    return q->count == SIZE;
}

void en_queue(Queue *q, int val) {
    if (is_full(q)) {
        return;
    }

    q->arr[q->next] = val;
    q->next = (q->next + 1) % SIZE;
    q->count++;
}

int de_queue(Queue *q) {
    if (is_empty(q)) {
        printf("queue is empty!\n");
        return -1;
    }
    int result;
    result = q->arr[q->first];
    q->arr[q->first] = -1;
    q->first = (q->first + 1) % SIZE;
    q->count--;
    return result;
}

int main(void) {
    Queue q;
    init_queue(&q);
    en_queue(&q, 1);
    en_queue(&q, 2);
    en_queue(&q, 3);
    de_queue(&q);
    en_queue(&q, 4);
    de_queue(&q);
    en_queue(&q, 5);
    en_queue(&q, 6);
    en_queue(&q, 7);

    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, q.arr[i]);
    }
}