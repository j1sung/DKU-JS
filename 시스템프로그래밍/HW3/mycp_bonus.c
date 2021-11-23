/* mycp program, by jisung. dalssagi00@gmail.com*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64

int main(int argc, char *argv[]){
        int fd1, fd2, read_size, info;
        char buff[MAX_BUF];
        struct stat s;                       // use stat

        if(argc != 3){                       // 3개의 인자인지 검사
                printf("USAGE: %s source_file destination_file\n", argv[0]);
                exit(-1);
        }
        fd1 = open(argv[1], O_RDONLY);
        info = stat(argv[1], &s);
        if(fd1<0){                           // error handling
                printf("Can't open %s\n", argv[1]);
                exit(-1);
        }

        fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, s.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));                                                          // 접근권한 정보를 복사
        if(fd2 < 0){                         // error handling
                printf("Can't create %s file with errno %d\n", argv[2], errno);
                exit(-1);
        }
        while(1){                            // read_size만큼 write 실행
                read_size = read(fd1, buff, MAX_BUF);
                if(read_size == 0)
                        break;
                write(fd2, buff, read_size);
        }
        close(fd1);
        close(fd2);
}