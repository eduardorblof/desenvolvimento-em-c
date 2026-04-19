#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 6

typedef struct {
    int data[CAPACITY];
    int head;   
    int tail;   
    int size;
} Queue;


void queue_init(Queue *q) {
    q->head = 0;
    q->tail = 0;
    q->size = 0;
}

bool queue_is_empty(const Queue *q) { return q->size == 0; }
bool queue_is_full (const Queue *q) { return q->size == CAPACITY; }

bool enqueue(Queue *q, int value) {
    if (queue_is_full(q)) {
        fprintf(stderr, "Queue cheia\n");
        return false;
    }
    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % CAPACITY;
    q->size++;
    return true;
}

bool dequeue(Queue *q, int *out) {
    if (queue_is_empty(q)) {
        fprintf(stderr, "Queue vazia\n");
        return false;
    }
    *out = q->data[q->head];
    q->head = (q->head + 1) % CAPACITY;
    q->size--;
    return true;
}

bool peek(const Queue *q, int *out) {
    if (queue_is_empty(q)) return false;
    *out = q->data[q->head];
    return true;
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count[2] = {0, 0};
    register int i = 0;

    for(int i =0; i< studentsSize; i++){
        if (students[i] == 0)
            count[0]++;
        
        else
            count[1]++;
        
    }

    for (int i = 0; i < sandwichesSize; i++) {
    int top = sandwiches[i];
    if (count[top] == 0)
        return sandwichesSize - i; 
    count[top]--;
    }   

    return (count[0] + count[1]);

}