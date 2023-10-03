#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * open_files - Opens source and destination files.
 * @file_from: Pointer to the source file name.
 * @file_to: Pointer to the destination file name.
 * Return: File descriptor of the source file or -1 on error.
 */
int open_files(char *file_from, char *file_to);

/**
 * copy_content - Copies content from one file to another.
 * @fd_from: Source file descriptor.
 * @fd_to: Destination file descriptor.
 * Return: 0 on success, -1 on failure.
 */
ssize_t copy_content(int fd_from, int fd_to);

/**
 * close_files - Closes the source and destination file descriptors.
 * @fd_from: Source file descriptor.
 * @fd_to: Destination file descriptor.
 */
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

	fd_from = open_files(argv[1], argv[2]);
	if (fd_from == -1)
	{
		exit(98);
	}

	fd_to = open_files(argv[1], argv[2]);
	if (fd_to == -1)
	{
		close(fd_from);
		exit(99);
	}

	if (copy_content(fd_from, fd_to) == -1)
	{
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	close_files(fd_from, fd_to);

	return (0);
}

/**
 * open_files - Opens source and destination files.
 * @file_from: Pointer to the source file name.
 * @file_to: Pointer to the destination file name.
 * Return: File descriptor of the source file or -1 on error.
 */

int open_files(char *file_from, char *file_to)
{
	int fd_from, fd_to;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		perror("Error opening source file");
		return (-1);
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		close(fd_from);
		perror("Error opening destination file");
		return (-1);
	}

	return (fd_from);
}

/**
 * copy_content - Copies content from fd_from to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * Return: 0 on success or -1 on failure
 */

ssize_t copy_content(int fd_from, int fd_to)
{
	ssize_t read_bytes, write_bytes;
	char buffer[BUFFER_SIZE];

	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
		{
			return (-1);
		}
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
		perror("Error closing source file");
	}

	if (close(fd_to) == -1)
	{
		perror("Error closing destination file");
	}
}
