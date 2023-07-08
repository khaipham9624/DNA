#include "stack.h"
const dataType unusedValue = -999999;

void stack_init(Stack *stack){
    list_init(stack);
}

void stack_destroy(Stack *stack){
    list_destroy(stack);
}

int stack_push(Stack *stack, dataType data){
    return list_ins_next(stack, NULL, data);
}

int stack_pop(Stack *stack){
    return list_rem_next(stack, NULL);
}

dataType stack_peek(const Stack *stack){
    if (stack->size > 0) {
        return list_data(stack, stack->head);
    }
    return unusedValue;
}
int stack_size(const Stack *stack){
    return list_size(stack);
}

void stack_print(const Stack* stack){
    list_print(stack);
}