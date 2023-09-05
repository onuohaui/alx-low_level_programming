#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void display_magic(unsigned char *e_ident);
void display_class(unsigned char e_class);
void display_data(unsigned char e_data);
void display_version(unsigned char e_version);
void display_osabi(unsigned char e_osabi);
void display_abi_version(unsigned char e_abi_version);
void display_type(uint16_t e_type);
void display_entry(uint64_t e_entry);

/**
 * main - Entry point for the program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t n;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(98);
	}

	n = read(fd, &header, sizeof(header));
	if (n != sizeof(header))
	{
		fprintf(stderr, "Could not read ELF header\n");
		close(fd);
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Not an ELF file\n");
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	display_magic(header.e_ident);
	display_class(header.e_ident[EI_CLASS]);
	display_data(header.e_ident[EI_DATA]);
	display_version(header.e_ident[EI_VERSION]);
	display_osabi(header.e_ident[EI_OSABI]);
	display_abi_version(header.e_ident[EI_ABIVERSION]);
	display_type(header.e_type);
	display_entry(header.e_entry);

	close(fd);
	return (0);
}
/**
 * display_magic - Display the magic bytes of ELF header
 * @e_ident: The magic bytes
 */

void display_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * display_class - Display the class of ELF file
 * @e_class: The class identifier
 */

void display_class(unsigned char e_class)
{
	printf("  Class:                             ");
	printf(e_class == ELFCLASS32 ? "ELF32\n" : "ELF64\n");
}

/**
 * display_data - Display the data encoding of ELF file
 * @e_data: The data encoding identifier
 */

void display_data(unsigned char e_data)
{
	printf("  Data:                              ");
	printf(e_data == ELFDATA2LSB ? "2's complement, little endian\n" :
			"2's complement, big endian\n");
}

/**
 * display_version - Display the version of ELF file
 * @e_version: The version identifier
 */

void display_version(unsigned char e_version)
{
	printf("  Version:                           ");
	printf(e_version == EV_CURRENT ? "1 (current)\n" : "<unknown>\n");
}

/**
 * display_osabi - Display the OS/ABI of ELF file
 * @e_osabi: The OS/ABI identifier
 */

void display_osabi(unsigned char e_osabi)
{
	printf("  OS/ABI:                            ");
	switch (e_osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %x>\n", e_osabi);
			break;
	}
}

/**
 * display_abi_version - Display the ABI Version of ELF file
 * @e_abi_version: The ABI version
 */

void display_abi_version(unsigned char e_abi_version)
{
	printf("  ABI Version:                       ");
	printf("%d\n", e_abi_version);
}

/**
 * display_type - Display the type of ELF file
 * @e_type: The type of ELF file
 */

void display_type(uint16_t e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
			break;
	}
}

/**
 * display_entry - Display the entry point of ELF file
 * @e_entry: The entry point
 */

void display_entry(uint64_t e_entry)
{
	printf("  Entry point address:               ");
	printf("0x%lx\n", e_entry);
}
