#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include "elf_header.h"
#define BUFF_SIZE 64

/**
 * errorExit - Display an error message and exit the
 *  program with exit code 98.
 * @message: The error message to display.
 */
void errorExit(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * readElfHeader - Read the ELF header from a file and store
 *  it in the provided header structure.
 * @filename: The name of the ELF file to read.
 * @header: Pointer to the ElfHeader structure to store the header information.
 */
void readElfHeader(const char *filename, ElfHeader *header)
{
	int fd;
	ssize_t bytesRead;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		errorExit(strerror(errno));

	bytesRead = read(fd, header, sizeof(ElfHeader));
	if (bytesRead == -1)
		errorExit(strerror(errno));

	close(fd);
}

/**
 * isElfFile - Check if the provided ElfHeader
 *  structure represents a valid ELF file.
 * @header: Pointer to the ElfHeader structure to check.
 *
 * Return: 1 if the header represents a valid ELF file, 0 otherwise.
 */
int isElfFile(ElfHeader *header)
{
	return (header->e_ident[0] == 0x7f &&
			strncmp((char *)&header->e_ident[1], "ELF", 3) == 0);
}

/**
 * displayElfHeader - Display the information stored
 *  in the ElfHeader structure.
 * @header: Pointer to the ElfHeader structure
 *  containing the header information.
 */
void displayElfHeader(ElfHeader *header)
{
	printf("Magic:   %02x %02x %02x %02x\n",
			header->e_ident[0], header->e_ident[1],
			header->e_ident[2], header->e_ident[3]);
	printf("Class:   %s bit\n",
			(header->e_ident[4] == 2) ? "64" : "32");
	printf("Data:    %s\n",
			(header->e_ident[5] == 1) ? "2's complement, little-endian" : "unknown");
	printf("Version: %d (current)\n", header->e_ident[6]);
	printf("OS/ABI:  %d\n", header->e_ident[7]);
	printf("ABI Ver: %d\n", header->e_ident[8]);
	printf("Type:    0x%x\n", header->e_type);
	printf("Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * main - Entry point for the program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, otherwise exits with code 98.
 */
int main(int argc, char *argv[])
{
	ElfHeader header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	memset(&header, 0, sizeof(ElfHeader));
	readElfHeader(argv[1], &header);

	if (!isElfFile(&header))
	{
		fprintf(stderr, "%s is not an ELF file\n", argv[1]);
		exit(98);
	}

	displayElfHeader(&header);
	return (0);
}
