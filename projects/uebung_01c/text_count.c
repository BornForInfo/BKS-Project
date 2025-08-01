#include <stdio.h>
#include <string.h>


void count(const char *text, int *vokale, int *leerzeichen, int *zeichen) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            (*vokale)++;
        }
        else if (text[i] == ' ') {
            (*leerzeichen)++;
        }
        (*zeichen)++;
    }

}


int main(){

    char text[1024];
    int zeichen = -1;
    int leerzeichen = 0;
    int vokale = 0;
    printf("gib ein text ein\n");
    fgets(text, sizeof(text), stdin);
    count(text, &vokale, &leerzeichen, &zeichen);
    printf("zeichen: %d\nleerzeichen: %d\nvokale: %d\n", zeichen, leerzeichen, vokale);
    return 0;
}
