#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void checker(int a){
    if(a == -1){
        printf("Failed\n");
        exit(1);
    }
}

int main(){
    int bruh;
    char buf[13];
    bruh = open("bruh.txt", O_WRONLY | O_APPEND);
    checker(bruh);
    write(bruh, "Bruh moaent\n", 12);
    close(bruh);

    bruh = open("bruh.txt", O_RDONLY);
    checker(bruh);
    read(bruh, buf, 12);

    buf[12] = '\0';

    printf("Buffer: %s\n", buf); 

    close(bruh);

    return 0;
}