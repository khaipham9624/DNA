#include "stack.h"

int main(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);
    stack_print(stack);
    printf("peek = %d\n", stack_peek(stack));
    stack_print(stack);
    stack_pop(stack);
    stack_print(stack);
    stack_destroy(stack);
}