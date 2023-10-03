#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024

void error_exit(int error_code, char *file_name, int fd);

/**
 * main - Copies the content of one file to another file.
 * @argc: The number of command-line arguments.
 * @argv: The command-line arguments.
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int file_in, file_out;
	ssize_t read_stat, write_stat;
	char buffer[MAXSIZE];

	if (argc != 3)
		error_exit(97, NULL, 0);

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		error_exit(98, argv[1], 0);

	file_out = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (file_out == -1)
		error_exit(99, argv[2], 0);

	while ((read_stat = read(file_in, buffer, MAXSIZE)) > 0)
	{
		write_stat = write(file_out, buffer, read_stat);
		if (write_stat != read_stat)
			error_exit(99, argv[2], 0);
	}

	if (read_stat == -1)
		error_exit(98, argv[1], 0);

	if (close(file_in) == -1)
		error_exit(100, NULL, file_in);

	if (close(file_out) == -1)
		error_exit(100, NULL, file_out);

	return (0);
}

/**
 * error_exit - Handle errors by printing appropriate
 *  error messages and exiting.
 * @error_code: The error code that determines the error message.
 * @file_name: The file name that the error refers to.
 * @fd: The file descriptor that the error refers to.
 */

void error_exit(int error_code, char *file_name, int fd)
{
	switch (error_code)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
			break;
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
			break;
		default:
			return;
	}
	exit(error_code);
}
