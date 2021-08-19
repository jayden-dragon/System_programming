#include unistd.h
#include stdio.h
#include stdlib.h
void childfunc() {
	char data1[] = {binecho, hello, NULL};
	printf(Child pid is %dn, getpid());
	execv(binecho, data1);
	printf(execv failn);
}
void parentfunc(pid_t pid_c) {
	printf(Parent pid is %d and th pid of my child is %d.n, getpid(), pid_c);
	exit(0);
}
int main() {
	pid_t ret;
	ret = fork();
	if (ret == -1) {
		printf(fork failn);
		return -1;
	}
	if (ret == 0) {
		childfunc();
	}
	else {
		parentfunc(ret);
	}

	printf(shouldn't reach heren);

	return 0;
}
