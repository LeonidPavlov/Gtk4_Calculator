#include "stack.h"

Stack * new_stack(int type_size)
{
    Stack * stack = malloc(sizeof(Stack));
    stack->type_size = type_size;
    stack->count = -1;
    stack->capacity = INITAL_CAPACITY;
    stack->items = calloc(type_size, INITAL_CAPACITY * type_size);
    return stack;
}

bool push(Stack * st, const void * aspirant)
{
    if (is_full(st)) 
    {
        st->capacity += st->capacity;
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

void * peek(Stack * st)
{
    if (is_empty(st))
    {
        fprintf(stderr, "acquire empty stack\n");
        return NULL;
    }
    else
    {
        void * result = st->items + st->count * st->type_size;
        return result;
    }
}

Stack * set_char_literal_into_stack(const char * str)
{
    int length = (int) strlen(str);
    Stack * st = new_stack(sizeof(char));
    char ch = EOF; push(st, (char*)&ch);
    for (int j = length - 1; j >= 0; j--) push(st, (char*)&str[j]);
    return st;
}


