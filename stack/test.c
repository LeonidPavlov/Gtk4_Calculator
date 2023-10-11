#include "stack.h"

void test_new_stack()
{
    puts("test 'Stack * new_stack(int type_size, const char * print_format)");
    Stack * st = new_stack(sizeof(long));
    printf("stack->type_size %d\n", st->type_size);
    printf("stack->capacity %d\n", capacity(st));
    printf("stack count -> %d\n", count(st));
    printf("is empty -> %d\n", is_empty(st));
    free_memory(st);
    puts("ent test 'Stack * new_stack(int type_size, const char * print_format)'");
}

void test_push()
{
    puts("\ntest push");
    Stack * st = new_stack(sizeof(short));
    printf("count %d\n", st->count);
    int huy = 34;
    printf("before push value %d\n", huy);
    push(st, (int *) &huy);
    printf("count %d\n", st->count);
    puts("\ntest pop");
    int * ptr = pop(st);
    printf("poped -> %d, \n", *ptr);
    free_memory(st);
    puts("end test pop\n");
}

void capacity_test()
{
    puts("capacity test");
    Stack * st = new_stack(sizeof(unsigned));
    for (unsigned j = 0; j < 20; j++)
    {
        int * ptr = &j;
        bool pu = push(st,(void*)ptr);
    }
    puts("pop");
    while(!is_empty(st)) 
    {
        unsigned * ptr = pop(st);
        printf("%u ", *ptr);
    }
    puts("");
    printf("capacity -> %d\n", st->capacity);
    puts("end capacity test\n");

    puts("peek test");
    unsigned t = 23;
    if (is_empty(st)) push(st, (void*) &t);
    unsigned * pt = peek(st);
    printf("peek -> %u\n", *pt);
    puts("end peek test\n");
    free_memory(st);
}

void test_utility_method()
{
    puts("utility test");
    Stack * st = set_char_literal_into_stack("ebat colotit");
    while(!is_empty(st)) 
    {
        char * ch = pop(st);
        printf("%c", *ch);
    }
    puts("");
    free_memory(st);
    puts("end utility test");
}

int main()
{
    test_new_stack();
    test_push();
    capacity_test();
    test_utility_method();
}

