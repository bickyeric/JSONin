#include "JSONin.h"

s_JSONin r;

char symbols[] = "{}";

void printToken(){
	printf("\n%s -> %d\n", r.token, r.type);
	// printf("%c\n", r.token[0]);
}

void JSONinParse(char JSON[]){
	r.raw = JSON;
	r.i = 0;
	
	JSONinCheckObject();
}

void JSONinCheckObject(){

	JSONinGetToken();
	if (!IS_LEFT_BRACE){
		printf("expected '{'");
	}

	JSONinGetToken();
	if (!IS_DOUBLE_QUOTES){
		printf("expected '\"'");
	}

	JSONinGetToken();
	printToken();
}

void JSONinGetToken(){
	JSONinClearToken();

	for (int i = 0; i < MAX_TOKEN_LENGTH; ++i){
		if (i==0){
			switch(r.raw[r.i]){
				case LEFT_BRACE:
					r.token[i] = r.raw[r.i];
					r.type = SYMBOL;
					r.i++;
					return;

				case DOUBLE_QUOTES:
					r.token[i] = r.raw[r.i];
					r.type = SYMBOL;
					r.i++;
					return;

				default:
					r.token[i] = r.raw[r.i];
					r.type = STRING;
					break;
			}
		}else{
			r.token[i] = r.raw[r.i];
		}

		r.i++;
	}
}

void JSONinClearToken(){
	for (int i = 0; i < MAX_TOKEN_LENGTH; ++i){
		r.token[i]='\0';
	}
}