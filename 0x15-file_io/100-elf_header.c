#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_magic - prints the magic numbers
 * @header: the ELF header
 */
void print_magic(Elf64_Ehdr header)
{
	printf("Magic:   %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n",
			header.e_ident[EI_MAG0], header.e_ident[EI_MAG1],
			header.e_ident[EI_MAG2], header.e_ident[EI_MAG3],
			header.e_ident[EI_CLASS], header.e_ident[EI_DATA],
			header.e_ident[EI_VERSION], header.e_ident[EI_OSABI],
			header.e_ident[EI_ABIVERSION], header.e_ident[EI_PAD],
			header.e_ident[9], header.e_ident[10], header.e_ident[11],
			header.e_ident[12], header.e_ident[13], header.e_ident[15]);
}

/**
 * is_elf_file - checks if file is an ELF file
 * @header: the ELF header
 * @filename: name of the file
 *
 * Return: 1 if is ELF, 0 otherwise.
 */
int is_elf_file(Elf64_Ehdr header, char *filename)
{
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: %s is not an ELF file\n", filename);
		return (0);
	}
	return (1);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument values
 *
 * Return: 0 on success, or exit with status code 98 on error.
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		fprintf(stderr, "Error: Can't read ELF header of %s\n", argv[1]);
		close(fd);
		exit(98);
	}
	close(fd);

	if (!is_elf_file(header, argv[1]))
		exit(98);

	print_magic(header);
	/* ... Similarly, print other header fields using helper functions ... */

	return (0);
}
