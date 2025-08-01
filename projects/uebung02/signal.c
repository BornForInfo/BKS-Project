#include <stdio.h>
#include <stdlib.h> //exit()
#include <signal.h> //signal()
#include <unistd.h> //sleep() system call
#include <stdbool.h> // true, false

volatile sig_atomic_t paused = 0;
volatile sig_atomic_t counter = 0;

void signal_pauser(int signum){
    paused = !paused;
    if (paused){
        printf("\nZähler pausiert!\n");
    }
    else {
    printf("\n");
    }
}

void signal_exit(int signum) {
    printf("Beendet nach %d Sekunden\n", counter);
    fflush(stdout);
    exit(0);
}

int main (){
    printf("PID: %d\n", getpid());
    signal(SIGINT, signal_pauser);
    signal(SIGTERM, signal_exit);
    while(1){
        if (!paused) {
            printf("Sekunde: %d\n",counter);
            fflush(stdout);
            counter++;
        }
        sleep(1);
    }
    return 0;
}
