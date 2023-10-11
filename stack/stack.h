#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef STACK_LNP_H
#define STACK_LNP_H

#define INITAL_CAPACITY 128

typedef struct stack
{
    int type_size;
    int count;
    int capacity;
    void * items;
    const char * print_format;
} Stack;


/*
    return pointer to stack with initial capacity
*/
Stack * new_stack(int type_size);


bool free_memory(Stack * stack);

static inline bool is_empty(Stack * stack) { return stack->count == -1 ? true : false; }
static inline bool is_full(Stack * stack) 
                { return stack->count == stack->capacity - 1 ? true : false; }

bool push(Stack * stack, const void * aspirant);
/*
    if empty return NULL !!!
*/
void * pop(Stack * stack);

/* count + 1 = amount element */
static inline int count(Stack * stack) { return stack->count; }

/* current size of stack */
static inline int capacity(Stack * stack) { return stack->capacity; }

/* 
    return pointer on top element without ejecting from stack 
    if stack is empty return NULL !!!
*/
void * peek(Stack * stack);

/*
    METHODS FOR CALCULATOR PROGRAMS
*/

/*
    set string in stack to imitate hand input
    return function peek() result -> first character
    return pointer to Stack instance need to free memory 
    with free_memory(...) function
*/
Stack * set_char_literal_into_stack(const char * str);


#endif
