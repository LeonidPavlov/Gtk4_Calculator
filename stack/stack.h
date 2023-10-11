#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef STACK_LNP_H
#define STACK_LNP_H

typedef struct stack
{
    int type_size;
    int count;
    int capacity;
    void * items;
    const char * print_format;
} Stack;


/*
    return stack without capacity
*/
Stack * new_stack(int type_size, int capacity, const char * print_format);
bool free_memory(Stack * stack);

static inline bool is_empty(Stack * stack) { return stack->count == -1 ? true : false; }
static inline bool is_full(Stack * stack) 
                { return stack->count == stack->capacity - 1 ? true : false; }
bool push(Stack * stack, const void * aspirant);

/* need to free memory */
void * pop(Stack * stack);

static inline int count(Stack * stack) { return stack->count; }

static inline int capacity(Stack * stack) { return stack->capacity; }

/* need to free memory */
void peek(Stack * stack, int position);

// push():  If the stack is full then the overflow condition occurs.
// pop():If the stack is empty means that no element exists in the stack, this state is known as an underflow state.
// isEmpty(): It determines whether the stack is empty or not.
// isFull(): It determines whether the stack is full or not.'
// peek(): It returns the element at the given position.
// count(): It returns the total number of elements available in a stack.
// change(): It changes the element at the given position.
// display(): It prints all the elements available in the stack.

#endif
