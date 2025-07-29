#include <stdio.h> //perror
#include <unistd.h> //read, write, close
#include <fcntl.h> //open


#define BUFFER_SIZE 1024
void cat_from_fd(int fd){
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0){
        write(1, buffer, bytes_read);
    }
}

void cat_from_file(char *filename) {

    int fd = open(filename, 0);
    if (fd > 0) {
        cat_from_fd(fd);
    }

}

int main(int argc, char *argv[]){
    if (argc == 1) {
        cat_from_fd(0);
    }
    else{
        for (int i = 1; i < argc; i++){
            cat_from_file(argv[i]);
        }
    }
    return 0;
}

