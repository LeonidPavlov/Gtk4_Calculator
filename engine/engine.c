#include "engine.h"

static FILE * input;
static Buffer buffer = {0};

int (*ptr_to_get)(FILE * file) = NULL;
int (*ptr_to_ungetc)(int ch, FILE * file) = NULL;

void calculate_stdin()
{
    puts("\nCALCULATE FROM SDIN");
    input = stdin;
    ptr_to_get = getc;
    ptr_to_ungetc = ungetc;
    while (1)
    {
        printf(" %le\n", expression());
        Token t = unset_buffer();
    }
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
    else if (t.symbol == '+') return primary();
    else if (t.symbol == '-') return  - primary();
    else 
    {
        fprintf(stderr, "END PRIMARY METHOD BAD INPUT\n");
        exit(1);
    }
}

double extract_double_literal(char start_char, FILE * input)
{
    char temp[50] = {0};
    double result = 0;
    if ( isdigit(start_char) || start_char == '.'  )
    {
        char ch = start_char;
        int j = 0;
        while(isdigit(ch) || ch == '.')
        {
            temp[j++] = ch;
            ch = (*ptr_to_get)(input);
        }
        add_exponent_tail(ch, input, temp, j);
    }
    sscanf(temp, "%lf", &result);
    return result;
}

void add_exponent_tail(char start_char, FILE * input, char * char_array, int index)
{
    char ch = start_char;
    char next = 0;
    char next_next = 0;
    int j = index;
    if (ch == 'e' || ch == 'E')
    {
        next = (*ptr_to_get)(input);
        next_next = (*ptr_to_get)(input);
        if ( (next == '-' || next == '+') && isdigit(next_next))
        {
            char_array[j++] = ch;
            char_array[j++] = next;
            do {
                char_array[j++] = next_next;
                next_next = (*ptr_to_get)(input);
            } while (isdigit(next_next));
            (*ptr_to_ungetc)(next_next, input);   
        }
        else if (isdigit(next))
        {
            (*ptr_to_ungetc)(next_next, input);
            char_array[j++] = ch;
            do {
                char_array[j++] = next;
                next = (*ptr_to_get)(input);
            } while (isdigit(next));
            (*ptr_to_ungetc)(next, input);   
        }
        else
        {
            fprintf(stderr, "WRONG EXPONENT REPRESENTATION\n");
        }
    }
    else (*ptr_to_ungetc)(ch, input);    
}

char next_acceptable_symbol(FILE * input)
{
    char result = 0;
    char ch = 0;
    do {
        ch = (*ptr_to_get)(input);
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

int full() { return buffer.fullness; }

void print_token(Token token) 
    { printf("symbol %c value %lf\n", token.symbol, token.value); }

Token next_token(FILE * input) 
{
    Token token;
    if (full())
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

static Stack * st;
void calculate_stack(const char * tests[], int size)
{
    puts("\nCALCULATE FROM STACK");
    input = NULL;
    ptr_to_get = read_symbol_from_stack;
    ptr_to_ungetc = put_symbol_to_stack;
    for (int j = 0; j < size; j++)
    {
        st = set_char_literal_into_stack(tests[j]);
        printf("%s", tests[j]);
        printf(" %le\n", expression());
        Token t = unset_buffer();       
        free_memory(st);
    }
}

int read_symbol_from_stack(FILE * input)
{
    char * letter = pop(st);
    return *letter;
}

static int put_symbol_to_stack(int ch, FILE * input)
{
    int chr = ch;
    push(st,(char *)&chr);
}
