#include <stdio.h>

#ifndef STACK_LNP_H
#define STACK_LNP_H

typedef void * type;

void push(type elem);
type pop();
int is_empty();
int is_full();

/*
    return element at the given position
*/
type peek(unsigned position);
/*
    amount of elements
*/
unsigned count();
/*
    change element at a given position
*/
void change(type elem, unsigned position);
/*
    display all elements
*/
void display();

void* init_stack_body(unsigned size, void * type);

#endif
