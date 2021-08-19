#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	int fdin, fdout;
	ssize_t nread;
	off_t size;
	char buf[1024] = {0};

	fdin = open("read.txt", O_RDONLY);
	fdout = creat("write.txt", 0644);

	if (fdin == -1 && fdout == -1) {
		printf("File open fail.\n");
		return -1;
	}

	while ((nread = read(fdin, buf, 1024)) > 0) {
		if (write (fdout, buf, nread) < nread) {
			printf("write failed.\n");
			close(fdin);
			close(fdout);
		}
	}
	
	printf("write.txt is %s", buf);

	size = lseek(fdout, 0, SEEK_END);

	if (size > 0) {
		printf("write.txt file size is : %d\n", size);
	}
	
	close(fdin);
	close(fdout);

	return 0;
}
