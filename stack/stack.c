#include "stack.h"

Stack * new_stack(int type_size, int capacity, const char * print_format)
{
    Stack * stack = malloc(sizeof(Stack));
    stack->type_size = type_size;
    stack->print_format = print_format;
    stack->count = -1;
    stack->capacity = capacity;
    stack->items = calloc(type_size, capacity * type_size);
    return stack;
}

bool push(Stack * st, const void * aspirant)
{
    if (is_full(st)) 
    {
        st->capacity += st->capacity/2;
        st->items = realloc(st->items, st->capacity);
    }
    st->count++;
    void * target = st->items + st->count * st->type_size;
    memcpy(target, aspirant, sizeof(aspirant));
    if (target != NULL) return true;
    else return false;
}

bool free_memory(Stack * stack)
{
    if(stack->items != NULL)
    {
        free(stack->items);
        if (stack != NULL) 
        {
            free(stack);
            return true;
        }
    } 
    else
    {
        puts("attempt to free empty memory");
        return false;
    }
}

void * pop(Stack * st)
{
    if (is_empty(st))
    {
        puts("an attempt to acquire empty stack");
        return NULL; 
    }
    else 
    {
        void * target = st->items + st->count * st->type_size;
        st->count--;
        return target;
    }
}
