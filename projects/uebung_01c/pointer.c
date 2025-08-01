#include <stdio.h>

int zahl_summieren(int a, int b){
    if (a % 2 == 1) {
        printf("%d ist ungerade\n", a);
    }
    else if(b % 2 == 1) {
        printf("%d ist ungerade\n", b);
    }
    else {
        printf("%d%d\n", a, b);
    }
}


int main() {
    int age;
    float temp;
    char grade[64];
    int a;
    int b;
    printf("gibt 2 zahlen ein\n");
    scanf("%d %d", &a, &b);
    int combi = zahl_summieren(a, b);
    //printf("give age, temp, grade\n");
    //scanf("%d %f %s", &age, &temp, grade);
    //printf("your age: %d\nthe temp: %.1f\nyour grade: %s\n", age, temp, grade);
    return 0;
}
