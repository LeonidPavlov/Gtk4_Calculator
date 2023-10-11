#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../stack/stack.h"


#ifndef CALCULATOR_ENGINE_H
#define CALCULATOR_ENGINE_H

typedef struct Token {
    char symbol;
    double value;
} Token;

typedef struct Buffer {
    int fullness;
    Token token;
} Buffer;

int set_buffer(Token token);
Token unset_buffer();
int full();
Token next_token(FILE * input);
void print_token(Token token);


double expression();
double term();
double primary();

/*
    extract double literal from input stream
    arguments: 
        1. start character of double literal
        2. file input 
    return sucess: double value of number literal
    return error: 0.0
*/
double extract_double_literal(char start_char, FILE * input);
/*
    skip spaces and tabs
    return symbol if it is number or symbol acceptable for calculator
    return EOF if wrong symbol 
*/
char next_acceptable_symbol(FILE * input);

void calculate_stdin();

void calculate_stack(const char * tests[], int size);

static int read_symbol_from_stack(FILE * input);

static int put_symbol_to_stack(int ch, FILE * input);

#endif
