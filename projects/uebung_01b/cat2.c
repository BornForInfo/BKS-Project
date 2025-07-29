#include <stdio.h> //perror()
#include <unistd.h>
#include <fcntl.h>

#define BUFFERSIZE 1024
void cat_fd(int fd){
    ssize_t bytes_read;
    char buffer[BUFFERSIZE];
    while((bytes_read = read(fd, buffer, BUFFERSIZE) > 0)) { //read 0 keyboard input
        write(1, buffer, bytes_read); //write always 1
    }
}

void cat_num(char *filename) {
    int fd = open(filename, 0); // fd = 3 read .txt
    if (fd > 0) {
        cat_fd(fd);
    }
}


int main(int argc, char *argv[]) { //int argc is input counter, argv list of saved input
    if (argc == 1) {
        cat_fd(0);
    }
    else {
        for(int i = 1; i < argc; i++){
            cat_num(argv[i]);
        }
    }
    return 0;
}
