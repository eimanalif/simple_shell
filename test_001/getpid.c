#include"shell.h"





int main()
{
	pid_t pid;

	pid = getpid();

	write("pid = %d\n", pid);
	return (0);
}
