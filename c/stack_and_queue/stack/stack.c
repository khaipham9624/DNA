#include "stack.h"

void stack_init(Stack *stack){
    stack->size = 0;
    stack->head = NULL;
    stack->tail = NULL;
}

void stack_destroy(Stack *stack){
    while (stack->size > 0)
    {
        stack_pop(stack, NULL);
    }
}

int stack_push(Stack *stack, dataType data){
    list_ins_next(stack, NULL, data);
}

int stack_pop(Stack *stack){
    list_rem_next(stack, NULL);
}

dataType stack_peek(const Stack *stack){

}
int stack_size(const Stack *stack){

}
