#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/*
* Kopiowanko2, second version of Kopiowanko which uses unix functions. 
*/
int main(int argc, char **argv) {
	if(argc == 1) {
		printf("Kopiowanko2, program for copying two files\n");
		printf("Usage: kopiowanko2 source destination buffer_size\n");
		printf("Author: Sebastian Smolinski\n");

		return 0; 
	}

	if(argc == 2) {
		if(strcmp(argv[1], "-v") == 0) {
			printf("Kopiowanko2, version 1.0\n");
			return 0;
		}
	}

	if(argc != 4) {
		printf("Error: invaild number of arguments\n");
		return -1; 
	}

	char *endptr; 
	long bufferSize = strtol(argv[3], &endptr, 10);
	
	if(endptr == argv[3]) {
		printf("Third argument should be a number\n");
		return -1; 
	} else if (*endptr != '\0') {
		printf("Third argument should be a number\n"); 
		return -1; 
	}

	int source, destination; 
	
	source = open(argv[1], O_RDONLY);
	if(source < 0) {
		printf("Error: Could not open source file\n");
		return -1; 
	}	

	destination = open(argv[2], O_WRONLY | O_CREAT, 0666); 
	if(destination < 0) {
		printf("Error: Could not open destination file\n");
		close(source); 
		return -1; 
	}

	char buffer[bufferSize];
	int counter = 0; 
	while((counter = read(source, buffer, sizeof buffer)) > 0) {
		write(destination, buffer, counter);
	}	

	close(source);
	close(destination);

	return 0;
}
