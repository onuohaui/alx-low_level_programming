#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int open_files(char *file_from, char *file_to, int *fd_from, int *fd_to);
ssize_t copy_content(int fd_from, int fd_to);
void close_files(int fd_from, int fd_to);

/**
 * main - function to copy content
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, error code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	if (open_files(argv[1], argv[2], &fd_from, &fd_to) == -1)
		return (1);

	if (copy_content(fd_from, fd_to) == -1)
	{
		close_files(fd_from, fd_to);
		exit(98);
	}

	close_files(fd_from, fd_to);

	return (0);
}

/**
 * open_files - Open source/destination files
 * @file_from: source file
 * @file_to: destination file
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * Return: Combined file descriptors or -1
 */
int open_files(char *file_from, char *file_to, int *fd_from, int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	*fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(*fd_from);
		exit(99);
	}

	return (0);
}

/**
 * copy_content - Copies content from fd_from to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * Return: 0 on success or -1 on failure
 */
ssize_t copy_content(int fd_from, int fd_to)
{
	ssize_t read_count, write_count;
	char buffer[1024];

	while ((read_count = read(fd_from, buffer, 1024)) > 0)
	{
		write_count = write(fd_to, buffer, read_count);
		if (write_count != read_count)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to\n");
			return (-1);
		}
	}

	if (read_count == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from\n");
		return (-1);
	}

	return (0);
}

/**
 * close_files - Closes the file descriptors
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}
