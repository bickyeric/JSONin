#include<stdio.h>
#include<stdlib.h>

void skipWhitespace(char**pr){
    while(*(*pr) == ' ' || *(*pr) == '\n' || *(*pr) == '\t')
        (*pr)++;
}

char* getSubString(char* start, char* end){
    char* value;
    int length = end - start;
    value = (char*) malloc(length+1);
    for(int i=0; i<=length; i++){
        if(*(start+i) == '\\'){
            i++;
            switch(*(start+i)){
                case 'n':
                    value[i] = 'd';
                    break;
            }
        }else{
            value[i] = *(start+i);
        }
    }
    value[length+1] = '\0';
    return value;
}

char* getMatchPair(char* pr, char* name){
    skipWhitespace(&pr);
    char* pn = &name[0];
    if(*pr == '}')
        return 0;
    pr++; // "
    int seek = 0;
    while(*(pn+seek) != '\0' && *(pr+seek) != '\"' && (*(pr+seek) == *(pn+seek)) ){
        seek++;
    }
    if(*(pn+seek) == '\0' && *(pr+seek) == '\"'){
        pr+=seek;
        pr++; // "
        skipWhitespace(&pr);
        pr++; // :
        skipWhitespace(&pr);
        return pr;
    }else{
        pr+=seek;
        while( (*pr != '}') && (*pr != ',')){
            pr++;
        }
        if(*pr == '}')
            return 0;
        pr++;
        return getMatchPair(pr, name);
    }
}

char* JSONinGetStringValue(char* root, char* name){
    char* pr = &root[0];
    pr++; // {
    pr = getMatchPair(pr, name);
    if(pr == 0)
        return pr;

    if(*pr != '\"')
        printf("error 1");
    pr++; // "
    char *pEndValue = pr;
    while(*pEndValue != '\"'){
        if(*pEndValue == '\\'){
            pEndValue++;
        }
        pEndValue++;
    }
    char* value = getSubString(pr, pEndValue-1);
    return value;
}

int JSONinGetIntegerValue(char* root, char* name){
    return 0;
}
