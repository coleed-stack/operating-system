#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
        int pid, p1[2], p2[2];
        pipe(p1);
	pipe(p2);

        pid = fork();

        if (pid != 0) {
		// closing unneccessary ends of each pipe
		close(p1[0]);
		close(p2[1]);
		int ping = 1;

		clock_t start, end;

		start = clock();
		for (int i = 0; i < 50000; i++) {
			write(p1[1], &ping, 1);
			read(p2[0], &ping, 1);
		}
		end = clock();

		//waiting for child process and closing pipes
		wait(0);
		close(p1[1]);
		close(p2[0]);

		//calculating and printing ex per sec
		printf("exchanges per second: %ld times\n", (unsigned long)(1 / ((((double)(end-start))/CLOCKS_PER_SEC) / 50000)));
        }
        else {
		//closing unneccessary ends of each point
		close(p1[1]);
		close(p2[0]);
		int pong;

		//keeping child running and replying
		for (int j = 0; j < 50000; j++) {
			read(p1[0], &pong, 1);
			write(p2[1], &pong, 1);
		}

		//closing useful ends of the pipes
		close(p1[0]);
		close(p2[1]);
		exit(0);
        }
	return 0;
}
