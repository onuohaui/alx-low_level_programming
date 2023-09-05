#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void print_elf_header(Elf64_Ehdr *hdr);

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Reads an ELF file specified by the user and prints its header information.
 *
 * Return: 0 on success, 98 on failure
 */

int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr hdr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		perror("open");
		exit(98);
	}

	if (read(fd, &hdr, sizeof(hdr)) != sizeof(hdr))
	{
		perror("read");
		exit(98);
	}

	if (memcmp(hdr.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Not an ELF file\n");
		exit(98);
	}

	print_elf_header(&hdr);

	close(fd);
	return (0);
}

/**
 * print_elf_header - Prints the information in the ELF header
 * @hdr: Pointer to the ELF header structure
 *
 * This function takes a pointer to an ELF64 header structure
 * and prints its details in the format specified.
 */

void print_elf_header(Elf64_Ehdr *hdr)
{
	int i;

	printf("Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", hdr->e_ident[i]);
	}
	printf("\n");

	printf("Class:                             ");
	printf("%s\n", hdr->e_ident[EI_CLASS] == ELFCLASS32 ?
			"ELF32" : "ELF64");

	printf("Data:                              ");
	printf("%s\n", hdr->e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" :
			"2's complement, big endian");

	printf("Version:                           ");
	printf("%d (current)\n", hdr->e_ident[EI_VERSION]);

	printf("OS/ABI:                            ");
	printf("UNIX - System V\n");

	printf("ABI Version:                       ");
	printf("%d\n", hdr->e_ident[EI_ABIVERSION]);

	printf("Type:                              ");
	switch (hdr->e_type)
	{
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		default:
			printf("Unknown (%x)\n", hdr->e_type);
	}

	printf("Entry point address:               ");
	printf("0x%lx\n", hdr->e_entry);
}
