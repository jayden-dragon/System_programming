#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#define NR_OPEN 1024

int main() {
	pid_t pid;
	int i, ret;

	pid = fork();

	if (pid == -1) {
		return -1;
	}
	else if (pid != 0) {
		printf("child pid is %d\n", pid);
		exit(0);
	}

	if (pid == 0) {
		printf("daemon pid is %d\n", getpid());
	}

	if (setsid() == -1) {
		return -1;
	}

	if (chdir("/") == -1) {
		return -1;
	}

	for (i = 0; i < NR_OPEN; i++) {
		close(i);
	}

	open ("/dev/null", O_RDWR);
	dup(0);	
	dup(0); 

	while(1) {
		ret = getpriority(PRIO_PROCESS, 0);
		printf("nice value is currently %d\n", ret);
		sleep(1);
	}
}