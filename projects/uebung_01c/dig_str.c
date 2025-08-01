#include <stdio.h>
#include <string.h>
#include <ctype.h>


int is_digit(const char *text){
    int digit = 1;
    for (int i = 0; i < strlen(text); i++) {
        if (isdigit(text[i]) == 0) {
            digit = 0;
        }
    }
    return digit;
}

int main(int argc, char *argv[]){
    for (int i = 1; i < argc; i++) {
        if(is_digit(argv[i])){
            printf("%s: zahl\n", argv[i]);
        }
        else{
            printf("%s: wort\n", argv[i]);
        }
    }
    return 0;
}
