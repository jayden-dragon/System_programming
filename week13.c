#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int count = 0;

void alarmHandler(int signal) {
        count ++;
        printf("Count : %d\n" ,count);
        if (count < 5) {
                alarm(2);
        }
        else {
                printf("Count : %d.. TIME OUT\n", count);
                exit(0);
        }
}
int main() {
        void (*hand)(int);
        hand = signal(SIGALRM, alarmHandler);
        if (hand == SIG_ERR) {
                printf("sig func fail\n");
                return -1;
        }
        alarm(2);
        while(1) {
                printf("Running\n");
                sleep(1);
        }
        return 0;
}