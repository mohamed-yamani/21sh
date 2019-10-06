#include <stdio.h>
#include <memory.h>
#include <unistd.h>

/*int main( int argc, char ** argv )
{
	char buffer[BUFSIZ+1];
	printf("BUFSIZ = %d\n", BUFSIZ);

	// create the pipe 
	int fd[2];
	pipe(fd);

	// write into the pipe
	write(fd[1], "MADE IN CHINA", strlen("Hello World\n") + 1);

	// read the pipe and print the read value
	read(fd[0], buffer, BUFSIZ);
	printf("%s", buffer);
}*/

int		main(int argc, char **argv)
{
	//create the pipe ...
	int pfd[2];
	if (pipe(pfd) == -1)
	{
		printf("pipe failed\n");
		return 1;
	}
	//create the child ...
	int pid;
	if ((pid = fork()) < 0)
	{
		printf("fork failed\n");
		return 2;
	}
	if (pid == 0)
	{
		// child
		char buffer[BUFSIZ];
		close(pfd[0]); // close write side

		//while (read(pfd[0], buffer, BUFSIZ) != 0)
		//	printf("child reads %s", buffer);
		strcpy(buffer, "tst 1");
			write(pfd[1], buffer, strlen(buffer) + 1);
		close (pfd[1]);
	}
	else
	{
		char buffer[BUFSIZ];

		close(pfd[1]); // close read side
	
		while (read(pfd[0], buffer, BUFSIZ) != 0)
			printf("parent %s", buffer);
		//strcpy(buffer, " HelloWorld\n");
		//write(pfd[1], buffer , strlen(buffer) + 1);

		close(pfd[0]);
	}
	return (0);
}
