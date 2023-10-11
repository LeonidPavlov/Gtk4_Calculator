#include "stack.h"

void test_new_stack()
{
    puts("test 'Stack * new_stack(int type_size, const char * print_format)");
    Stack * st = new_stack(sizeof(long), 10, "%ld");
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
    Stack * st = new_stack(sizeof(short), 20, "%s");
    printf("count %d\n", st->count);
    int huy = 34;
    printf("before push value %d\n", huy);
    push(st, (int *) &huy);
    printf("count %d\n", st->count);
    puts("\ntest pop");
    int * ptr = pop(st);
    printf("poped -> %d, \n", *ptr);
    free_memory(st);
    puts("end test push\n");
}

void capacity_test()
{
}

int main()
{
    test_new_stack();
    test_push();
}
