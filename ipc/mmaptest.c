/*
** mmapdemo.c -- demonstrates memory mapped files lamely.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd, 		// id del archivo cargado en memoria
		offset;		// de donde vamos a empezar a leer el archivo (numero de char)
	char *data;
	struct stat sbuf;

	if (argc != 2) {
		fprintf(stderr, "usage: mmaptest offset\n");
		exit(1);
	}

	// Cargamos archivo a memoria con syscall open()
	if ((fd = open("mmaptest.c", O_RDONLY)) == -1) {
		perror("open error");
		exit(1);
	}

	// Saca estadisticas de archivo con stat() y la guardara a &sbuf
	if (stat("mmaptest.c", &sbuf) == -1) {
		perror("stat");
		exit(1);
	}

	offset = atoi(argv[1]);
	if (offset < 0 || offset > sbuf.st_size-1) {
		fprintf(stderr, "mmaptest: offset must be in the range 0-%ld\n", sbuf.st_size-1);
		exit(1);
	}
	
	// Funcion mmap() creara una direccion de memoria y la inicializara con el archivo
	// Bandera MAP_SHARED especifica que sera un archivo compartido, solo habra un archivo
	// fd (el archivo) se pone en la direccion de memoria
	if ((data = mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0)) == (caddr_t)(-1)) {
		perror("mmap");
		exit(1);
	}

	printf("byte at offset %d is '%c'\n", offset, data[offset]);

	return 0;
}