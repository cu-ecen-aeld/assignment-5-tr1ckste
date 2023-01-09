#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include <string.h>

void writeToFile(int fd, char *string) {
    int length = strlen(string);
    ssize_t nr;
    nr = write(fd, string, length);
    if (nr == -1) {
        perror("write");
    }
}

int main (int argc, char *argv[]) {
    if (argc != 3) {
        printf("2 arguments needed, provided: %d\n", argc - 1);
        return 1;
    }
    int fd;
    char *writefile = argv[1];
    char *writestr = argv[2];

    fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
    }
    if (fd != -1) {
        writeToFile(fd, writestr);
    }
    return 0;
}

