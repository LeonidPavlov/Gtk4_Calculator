#include "engine.h"

const char * tests[] = 
{
    "2+2=",
    "3+3=",
    "12.3 / (23 + 13.5) =",
    "345.67/23 + 14 * 1.23  = ",
    "-2 - 3 * (-5 + 7)/2.5 = ",
    "2e3 + 3.4e3 = ",
    "-34.5E-1 + 34E-3 = ",
    "2.345e10 * (23.e3 - 344e-3) = "
};

int main()
{
    calculate_stack(tests, sizeof(tests)/ sizeof(char *));
    // calculate_stdin();
}