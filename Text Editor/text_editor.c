#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

// FILE fptr to be declared to interact with file 
// fptr = fopen("*file-to-open", "mode") : function used to open files, returns a pointer. eg : ptr = fopen("C:\\User\Anish\text.txt", "r") 
// fclose(fptr) : close a file which has been opened 

// MODES OF FILE OPENING
// r : read mode
// w : write  mode
// a : append mode
// r+ : read and write mode 
// w+ : read and write mode, if the file exists it is cleared out,  and if it doesnt then a new one is made.
// a+ : read and write/append mode, read the file from start, but write to file as apend.

// fscanf(fptr, "identifier", string_to_save_in) : to read a file, thus open file in read mode 
// fprintf(fptr, "identifier", string_to_print_from) : to write to a file, thus open file in write mode	
// fputc(char a, fptr) : writes a character to a file, returns EOF on failure
// fputs(char string, fptr) : writes a string to file, returns EOF on failure
// fgetc(fptr) : reads a character from a file, returns EOF on failure
// fgets(char string, int no_of_char, fptr) : reads a null terminated string from a file, returns EOF on failure  



int main(int const argc, char const *argv[])
{
	FILE *fptr = NULL;
	char buffer[256];
	int i, j;
	char ch;

	if(argc < 2)
	{
		printf("\nCommandline text editor  : \n");
		printf("[Syntax] : ./editor <filename.txt> <mode>\n\n");
		return 0;
	}

	fptr = fopen(argv[1], argv[2]);
	if(fptr == NULL) {
		printf("Error opening file\n");
	}

	

	if(strcmp(argv[2], "r") == 0) 
	{
		
		for(i = 0; ch != EOF; i++) 
		{
			j = 0;

			while(1) 
			{
				ch = fgetc(fptr);

				if(ch == '\n' || ch == EOF) 
				{
					break;
				}
				buffer[j] = ch;
				j++;
			}

			buffer[j] = '\0';
			printf("%3d. %s\n",i+1, buffer);
		}

		printf("The file has %d lines\n", i);
	}

	
	if(strcmp(argv[2], "w") == 0)
	{
		j = 1;
		printf("Enter the content : \n");
		while(1) 
		{
			printf("%3d. ", j);
			fgets(buffer, sizeof(buffer)-1, stdin);

			if( strcmp(buffer, ":q\n") == 0) 
			{
				break;
			}
			
			fputs(buffer, fptr);
			j++;
		}

	}

	printf("Closing file\n");
	fclose(fptr);

	return 0;
}