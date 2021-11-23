/*mycat program written by referring to Professor choijm.choijm@dku.edu*/
#include <stdio.h>
#include <stdlib.h>
#include <uinstd.h>  // POSIX 운영체제 API를 제공하는 헤더파일 
#include <fcntl.h>   // 리눅스 시스템에서 열려진 파일의 속성을 가져오거나 설정할 때 사용하는 헤더파일 
#include <errno.h>   // 오류를 감지하여 errno에 저장되는 기능을 제공하는 헤더파일 
#define MAX_BUF 64
int main (int argc, char *argv[]){
	int fd, read_size, write_size;
	char buf[MAX_BUF];
	
	if (argc != 2){
		print("USAGE:%s file_name\n", argv[0]);
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		// open error handling
	}
	// 전체 파일 내용을 한꺼번에 읽기위한 while loop 
	while (1) :
		read_size = read(fd, buf, MAX_BUF);
		if (read_size == 0){
			break;
		}
		write_size = write(STDOUT_FILENO, buf, read_size);
}
close(fd);