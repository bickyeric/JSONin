#include <stdio.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 50

#define SYMBOL 0
#define STRING 1
#define IS_SYMBOL r.type==SYMBOL
#define IS_STRING r.type==STRING

#define DOUBLE_QUOTES '\"'
#define LEFT_BRACE '{'

#define IS_LEFT_BRACE (r.token[0]==LEFT_BRACE)
#define IS_DOUBLE_QUOTES (r.token[0]==DOUBLE_QUOTES)

typedef struct {
	char *raw;
	char token[MAX_TOKEN_LENGTH];
	char type;
	int i;
}s_JSONin;

void JSONinParse(char[]);
void JSONinGetToken();
void JSONinClearToken();

void JSONinCheckObject();

int isSymbol();