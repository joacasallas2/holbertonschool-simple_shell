#include "shell.h"

/**
 * get_pid - PID
 *
 * Return: PID.
 */
int get_pid(void)
{
	pid_t child;
	pid_t parent;

	child = getpid();
	parent = getppid();
	printf("parent %u\n", parent);
	printf("child %u\n", child);
	return (parent);
}
