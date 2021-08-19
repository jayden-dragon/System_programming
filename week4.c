#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <stdio.h>
#include <string.h>
int main() {
	char *buf[2];
	char tmp1[20], tmp2[20];
	ssize_t nr;
	struct iovec iov_write[2];
	int fd, i, pid, ppid;

	for (i = 0; i < 2; i++) {
		if (i == 0) {
			pid = getpid();
			sprintf(tmp1, "PID is %d\n", (int)pid);
			buf[i] = tmp1;
			printf("buf[%d] is %s\n",i, buf[i]);
		}
		else if (i == 1){
			ppid = getppid();
			sprintf(tmp2, "PPID is %d\n", (int)ppid);
			buf[i] = tmp2;
			printf("buf[%d] is %s\n",i, buf[i]);
		}
	}

	fd = creat("writev.txt", 0644);
	if (fd == -1) {
		printf("file open fail\n");
		return -1;
	}

	for (i = 0; i < 2; i++) {
		iov_write[i].iov_base = buf[i];
		iov_write[i].iov_len = strlen(buf[i]);
	}

	nr = writev(fd, iov_write, 2);

	if (nr == -1) {
		printf("writev func fail\n");
		return -1;
	}
	for (i = 0; i < 2; i++) {
		printf("buf[%d] size: %ld\n", i, strlen(buf[i]));
	}
	printf("wrote %ld bytes\n", nr);
	
	close (fd);
	
	return 0;
}
