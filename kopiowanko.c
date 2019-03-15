#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
* Kopiowanko, very simple program for copying two files which uses C library's functions.
*/ 
int main(int argc, char **argv) {
	if(argc == 1) {
		printf("Kopiowanko, program for copying two files\n");
		printf("Usage: kopiowanko source destination buffer_size\n"); 
		printf("Author: Sebastian Smolinski\n");
		
		return 0; 	
	}

	if(argc == 2) {
		if(strcmp(argv[1], "-v") == 0) {
			printf("Kopiowanko, version 1.0\n");
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

	FILE *source, *destination;

	source = fopen(argv[1], "r"); 

	if(source == NULL) {
		printf("Source file doesn't exist\n");
		return -1; 	
	}

	destination = fopen(argv[2], "w");

	if(destination == NULL) {
		fclose(source);
		printf("Destination path is invaild\n");
		return -1; 
	}

	char buffer[bufferSize];
	int counter = 0; 
	while((counter = fread(buffer, sizeof(char), bufferSize, source)) > 0) { 
		fwrite(buffer, sizeof(char), counter, destination);  
	}
	
	fclose(source);
	fclose(destination);

   	return 0;
}
