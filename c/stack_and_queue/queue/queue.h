#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
typedef List Queue;

void queue_init(Queue *queue);
void queue_destroy(Queue *queue);
int queue_enqueue(Queue *queue, const dataType data);
int queue_dequeue(Queue *queue);
dataType queue_peek(const Queue *queue);
int queue_size(const Queue *queue);
void queue_print(const Queue *queue);
#endif