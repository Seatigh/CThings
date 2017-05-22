#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

int debug = 0;

int main (int argc, char ** argv) {
	initscr();
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-d") == 0) {
			debug = 1;
		}
	}
	printf("debug = %d\n", debug);
	char * sim [3] = {".  ", ".. ", "..."};
	int key;
	for (int i = 0;; i++) {
		if (debug) {
			key = getch();
		}
		if (key == 32) {
			printf("\rLoading%s", sim[i%(sizeof(sim)/sizeof(sim[0]))]);
			fflush(stdout);
		}
		usleep(500*1000);
	}
	printf("\rCompleted\n");
	return 1;
}
