#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int	sigIntHandled = 0;

// This is a signal handler.
// signal handlers should not do complex shit like file I/O etc.
void sigint_handler(int signal) {
	sigInthandled = 1;
	return;
}
	
int	main( int argc, char * argv[]) {

	// after this call to signal(3)
	// the process will not die from receiving SIGINT
	// but instead function sigint_handler will be called
	// see: https://man7.org/linux/man-pages/man3/signal.3p.html
	signal(SIGINT, sigint_handler);

	print("%s: on Linux, typing <ctrl>c will make the terminal device driver send signal SIGINT. Try it.\n", argv[0]);
	for (int i=0; i<20; i++) {
		printf("i=%d SIGINT handled=%d\n", i, sigIntHandled);
		sleep(1);
	}
	return EXIT_SUCCESS;
}
