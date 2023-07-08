#include "queue.h"
const dataType unusedValue = -999999;

void queue_init(Queue *queue){
    list_init(queue);
}
void queue_destroy(Queue *queue){
    list_destroy(queue);
}
int queue_enqueue(Queue *queue, const dataType data){
    return list_ins_next(queue, list_tail(queue), data);
}
int queue_dequeue(Queue *queue){
    return list_rem_next(queue, NULL);
}
dataType queue_peek(const Queue *queue){
    if (queue->size > 0) {
        return list_data(queue, queue->head);
    }
    return unusedValue;
}
int queue_size(const Queue *queue){
    return list_size(queue);
}
void queue_print(const Queue *queue){
    list_print(queue);
}