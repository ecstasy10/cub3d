#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../cub3d.h"

struct Stack {
    int top;
    int capacity;
    char **array;
};

struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char**)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, char *item)
{
    if (isFull(stack))
        return;
    stack->array[stack->top] = item;
    stack->top++;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    // can be broken, or poppin segmentation fault
    return *stack->array[stack->top];
}

char **peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array;
}