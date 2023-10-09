#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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
int is_full();
Token next_token(FILE * input);
void print_token(Token token);

void calculate_stdin();
void calculate_file_content(const char * filename);
void calculate();

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
#endif
