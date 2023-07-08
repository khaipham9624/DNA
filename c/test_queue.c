#include "queue.h"

int main(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue_init(queue);
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 4);
    queue_enqueue(queue, 5);
    queue_print(queue);
    printf("peek = %d\n", queue_peek(queue));
    queue_dequeue(queue);
    queue_print(queue);
    printf("peek = %d\n", queue_peek(queue));
    queue_destroy(queue);
}