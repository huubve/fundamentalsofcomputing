#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int	main( int argc, char * argv[]) {
	int	msgNr = 1;
	pid_t	childPid;

	srand(getpid());

	printf("msg %d/%d: I am process %d named '%s'. My parent process = %d.\n", getpid(), msgNr++, getpid(), argv[0], getppid());
	fflush(stdout);

	childPid = fork();
	if ( childPid == -1 ) {
		// fork() failed
		perror("fork() failed");
		exit(1);
	}
	if ( childPid > 0 ) {
		// in parent
		int	childExitStatus = 0;
		printf("msg %d/%d: I'm the parent. Fork told me my child's pid is %d\n", getpid(), msgNr++, childPid);
		fflush(stdout);
		sleep(1);
		printf("msg %d/%d: I'm the parent. I will wait for child to exit() now.\n", getpid(), msgNr++);
		fflush(stdout);
		wait(&childExitStatus);
		printf("msg %d/%d: I'm the parent. Child exited with value %d\n", getpid(), msgNr++, WEXITSTATUS(childExitStatus));
		fflush(stdout);

	} else {
		// in child
		int	exitValue = rand() % 128; // exit status is an int but can only use 8 bits
		printf("msg %d/%d: I'm the child. My pid is %d. My parent's pid is %d\n", getpid(), msgNr++, getpid(), getppid());
		printf("msg %d/%d: I'm the child. To show that my parent's wait(0 call get's my exit status,\n", getpid(), msgNr++);
		printf("msg %d/%d: I'm the child. I will exit with a different nr every time.\n", getpid(), msgNr++);
		fflush(stdout);
		sleep(2);
		printf("msg %d/%d: I'm the child. But first sleep a bit so my parent has the time to execute it's wait() call.\n", getpid(), msgNr++);
		fflush(stdout);
		sleep(2);
		printf("msg %d/%d: I'm the child. I will now exit with value %d.\n", getpid(), msgNr++, exitValue);
		fflush(stdout);
		exit(exitValue);
	}


	return EXIT_SUCCESS;
}

	
