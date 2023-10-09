#include "engine.h"

static FILE * input;
static Buffer buffer = {0};

void calculate_stdin()
{
        input = stdin;
        calculate();  
}

void calculate_file_content(const char * filename)
{
    input = fopen(filename, "r");
    if (input == NULL) 
    {
        fprintf(stderr, "can't open %s file\n",filename);
        exit(1);
    }
    calculate();
    if (input != NULL) fclose(input);
}

void calculate()
{
    printf(" = %lf\n", expression());
    Token t = unset_buffer();
}   

double expression()
{
    double left = term();
    Token t = next_token(input);
    while(1)
    {
        if (t.symbol == '+')
        {
            left += term();
            t = next_token(input);
        }
        else if (t.symbol == '-')
        {
            left -= term();
            t = next_token(input);
        }
        else 
        {
            set_buffer(t);
            return left;
        }
    }
}

double term()
{
    double left = primary();
    Token t = next_token(input);
    while(1)
    {   
        if (t.symbol == '*')
        {
            left *= primary();
            t = next_token(input);
        }
        else if (t.symbol == '/')
        {
            double d = primary();
            left /= d;
            t = next_token(input);
        }
        else 
        {
            set_buffer(t);
            return left;
        }
    }
}

double primary()
{
    Token t = next_token(input);
    if (t.symbol == 'n') return t.value;
    else if (t.symbol == '(')
    {
        double d = expression();
        t = next_token(input);
        if (t.symbol != ')') 
        {
            fprintf(stderr, "EXPECTED ) symbol\n");
            exit(1);
        }
        return d;
    } 
    else fprintf(stderr, "END PRIMARY METHOD\n");
}

double extract_double_literal(char start_char, FILE * input)
{
    char temp[50] = {0};
    double result = 0;
    if ( isdigit(start_char) || start_char == '.' )
    {
        char ch = start_char;
        int j = 0;
        while(isdigit(ch) || ch == '.')
        {
            temp[j++] = ch;
            ch = getc(input);
        }
        temp[j] = '\0';
        ungetc(ch,input);
    }
    sscanf(temp, "%lf", &result);
    return result;
}

char next_acceptable_symbol(FILE * input)
{
    char result = 0;
    char ch = 0;
    do {
        ch = getc(input);
    } while(ch == ' ' || ch == '\t' || ch == '\n');
    if (ch >= '(' && ch <= '9') result = ch;
    else if (ch == '=' || ch == EOF) result = ch;
    else
    {
        fprintf(stderr, "unacceptable symbol %c int value %d\n", ch, ch);
        result = EOF;
    }
    return result;
}

int set_buffer(Token token)
{
    if (buffer.fullness == 1) 
            printf("ACHTUNG: atemption to insert in full buffer\n");
    buffer.fullness = 1;
    buffer.token = token;
}

Token unset_buffer()
{
    if (buffer.fullness == 0) 
            printf("ACHTUNG: atemption to extract from empty buffer\n");
    buffer.fullness = 0;
    return buffer.token;
}

int is_full() { return buffer.fullness; }

void print_token(Token token) 
    { printf("symbol %c value %lf\n", token.symbol, token.value); }

Token next_token(FILE * input) 
{
    Token token;
    if (is_full())
    {
        token = unset_buffer();
        return token;
    }
    else
    {
        char ch = next_acceptable_symbol(input);
        double d;
        if (ch >= '0' && ch <= '9' || ch == '.') 
        {
                token.symbol = 'n';
                token.value = extract_double_literal(ch, input);
        }    
        else
        {
            token.symbol = ch;
            token.value = 0.0;
        }
        return token;
    } 
}
