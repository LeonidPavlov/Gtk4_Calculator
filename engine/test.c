#include "engine.h"

const char * tests[] = 
{
    "2+2=",
    "3+3=",
    "12.3 / (23 + 13.5) =",
    "345.67/23 + 14 * 1.23  = "
};

int main()
{
    // calculate_stdin();
    calculate_stack(tests, sizeof(tests)/ sizeof(char *));
}
