#include <stdio.h>
#include <stdlib.h> //exit()
#include <unistd.h> //fork()
#include <sys/wait.h> //wait()
#include <time.h>  //

int ist_gerade(int time){
    int ungerade = 0;

    if((time % 2) == 0){
        ungerade = 1;
    }
    return ungerade;
}

int main(){
    pid_t pid;
    int status;
    int gerade = 0;
    int ungerade = 0;
    srand(time(NULL));

    printf("Elternprozess PID:%d\n", getpid());
    for(int i = 0; i < 3; i++) {
        pid = fork();
        if (pid == 0) {
            srandom(getpid());
            int wait_time = (rand() % 5) + 1;
            if(ist_gerade(wait_time)){
                printf("Kindprocess mit PID %d hat Exit-Code 0, arbeitzeit %d\n", getpid(), wait_time);
                sleep(wait_time);
                exit(0);
            }
            else{
                printf("Kindprocess mit PID %d hat Exit-Code 1, arbeitzeit %d\n", getpid(), wait_time);
                sleep(wait_time);
                exit(1);
            }
        }
        else if (pid < 0) {
            perror("fork fehlgeschlagen");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < 3; i++){
        wait(&status);
        if(WIFEXITED(status)){
            int code = WEXITSTATUS(status);
            if (code == 0){
                gerade++;
            }
            else{
                ungerade++;
            }
        }
    }

    printf("Gerade Wartezeiten: %d\nUngerade Wartezeiten: %d\n", gerade, ungerade);
    return 0;
}

