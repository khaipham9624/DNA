#include "list.h"

typedef List Stack;
void stack_init(Stack *stack);
void stack_destroy(Stack *stack);
int stack_push(Stack *stack, dataType data);
int stack_pop(Stack *stack, dataType data);
dataType stack_peek(const Stack *stack);
int stack_size(const Stack *stack);
