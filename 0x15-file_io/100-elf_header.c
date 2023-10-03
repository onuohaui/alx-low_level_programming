#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error - Prints the error message and exits the program
 * @msg: The error message to be printed
 */
void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * display_magic - Displays the magic bytes of the ELF header
 * @header: Pointer to the ELF header
 */
void display_magic(const Elf64_Ehdr *header)
{
	printf("Magic: %c%c%c%c\n",
			header->e_ident[EI_MAG0],
			header->e_ident[EI_MAG1],
			header->e_ident[EI_MAG2],
			header->e_ident[EI_MAG3]);
}

/**
 * display_class - Displays the ELF class (32-bit or 64-bit)
 * @header: Pointer to the ELF header
 */
void display_class(const Elf64_Ehdr *header)
{
	printf("Class: %s\n", (header->e_ident[EI_CLASS] ==
				ELFCLASS64) ? "ELF64" : "ELF32");
}

/**
 * display_elf_header - Displays the information in the ELF header
 * @filename: The name of the ELF file
 */
void display_elf_header(const char *filename)
{
	int fd;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		print_error("Failed to open the file");
	}

	if (read(fd, &header, sizeof(Elf64_Ehdr)) !=
			sizeof(Elf64_Ehdr))
	{
		print_error("Failed to read ELF header");
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Not an ELF file");
	}

	display_magic(&header);
	display_class(&header);

	close(fd);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Reads an ELF file specified by the user
 *  and prints its header information.
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	display_elf_header(argv[1]);

	return (0);
}
