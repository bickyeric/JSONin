#include <stdio.h>
#include <stdlib.h>
#include "JSONin.h"

char* readFile(char* filename){
    FILE *f = fopen(filename, "r");
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* buffer = malloc(length);
    fread(buffer, 1, length, f);
    fclose(f);
    return buffer;
}

int main(){
    char* JSON = readFile("schema.json");
    char* string = JSONinGetStringValue(JSON, "custom");

    if(string){
        printf("%s", string);
    }else{
        printf("tidak ditemukan");
    }

    return 0;
}
