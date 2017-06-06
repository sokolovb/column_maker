#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
** options:
** -c="int"
** -w="int"
** -b="int"
** -e="int"
** -r
** "input.txt"
** "output.txt"
*/

#define OPT(n, x) argv[n][0] == '-' && argv[n][1] == x

int main(int argc, char *argv[])
{	

	int col = 0, sym=0, r=0, txt_size = 0, in_size = 0, out_size = 0, start = 0, stop = INT_MAX;
	int i, j, k, l, f = 0;
	
	char c;
	char *file_out = NULL;
	char *file_in = NULL;
	
	char *txt, *intro, *outro;

	
	if (argc < 3) {
		printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
		return 0;
	}
	else {
		i = 1;
		
		while (i < argc) {
			
			if (OPT(i, 'c')) {
				
				if (strlen(argv[i]) >= 4) {
					for(j = 3; j < strlen(argv[i]); j++){
						col *= 10;
						col += argv[i][j] - '0';
					}
					i++;
					continue;
				} else {
					if (strlen(argv[i]) == 2) {
						i++;
						if (argv[i][0] == '=') {
							i++;
							for(j = 0; j < strlen(argv[i]); j++){
								col *= 10;
								col += argv[i][j] - '0';
							}
							i++;
							continue;
						}
						else {
							printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
							return 0;
						}
					} else {
						printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
						return 0;
					}
				}
			}
			
			if (OPT(i, 'w')) {
				if (strlen(argv[i]) >= 4) {
					for(j = 3; j < strlen(argv[i]); j++){
						sym *= 10;
						sym += argv[i][j] - '0';
					}
					i++;
					continue;
				} else {
					if (strlen(argv[i]) == 2) {
						i++;
						if (argv[i][0] == '=') {
							i++;
							for(j = 0; j < strlen(argv[i]); j++){
								sym *= 10;
								sym += argv[i][j] - '0';
							}
							i++;
							continue;
						}
						else {
							printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
							return 0;
						}
					} else {
						printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
						return 0;
					}
				}
			}
			
			if (OPT(i, 'b')) {
				if (strlen(argv[i]) >= 4) {
					for(j = 3; j < strlen(argv[i]); j++){
						start *= 10;
						start += argv[i][j] - '0';
					}
					i++;
					continue;
				} else {
					if (strlen(argv[i]) == 2) {
						i++;
						if (argv[i][0] == '=') {
							i++;
							for(j = 0; j < strlen(argv[i]); j++){
								start *= 10;
								start += argv[i][j] - '0';
							}
							i++;
							continue;
						}
						else {
							printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
							return 0;
						}
					} else {
						printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
						return 0;
					}
				}
			}
			
			if (OPT(i, 'e')) {
				if (strlen(argv[i]) >= 4) {
					stop = 0;
					for(j = 3; j < strlen(argv[i]); j++){
						stop *= 10;
						stop += argv[i][j] - '0';
					}
					i++;
					continue;
				} else {
					if (strlen(argv[i]) == 2) {
						i++;
						if (argv[i][0] == '=') {
							i++;
							stop = 0;
							for(j = 0; j < strlen(argv[i]); j++){
								stop *= 10;
								stop += argv[i][j] - '0';
							}
							i++;
							continue;
						}
						else {
							printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
							return 0;
						}
					} else {
						printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
						return 0;
					}
				}
			}
			
			if (OPT(i, 'r')) {
				r = 1; 
				i++;
				continue;
			}
			
			if (argv[i][0] != '-' && f == 0) {
				file_in = (char*) malloc ((strlen(argv[i]) + 1)*sizeof(char));
				strcpy(file_in, argv[i]);
				f++;
				i++;
				continue;
			}
			else if (argv[i][0] != '-' && f == 1) {
				file_out = (char*) malloc ((strlen(argv[i]) + 1)*sizeof(char));
				strcpy(file_out, argv[i]);
				f++;
				i++;
				continue;
			}
			else {
				printf ("Wrong options\nUsage:\n-c='number_of_columns' (required)\n-w='width_of_column' (required)\n-r (allow splits) \n-b='start row'\n-e='stop row'\n'input_filename.txt' \n'output_filename.txt'");
				return 0;
			}
		}
	}
	
	
	if (file_in != NULL) {
		FILE *in=fopen(file_in, "r");
		
		i = 0;
		fscanf(in, "%c", &c);
		while (!feof(in)){
			if (c == '\n') i++;
			if (i < start-1) {
				in_size++;
			} else if (i >= stop) {
				out_size++;
			} else {              
				txt_size++;
			}
			fscanf(in, "%c", &c);
		}
		
		fclose(in);
		in=fopen(file_in, "r");
		
		intro = (char*)calloc(in_size, sizeof(char));
		txt= (char*)calloc(txt_size, sizeof(char));
		outro = (char*)calloc(out_size, sizeof(char));
		
		i = 0;
		while (i < in_size){
			fscanf(in, "%c", &c);              //êîïèðóåì òåêñò
			intro[i++] = c;
		}
		
		i = 0;
		while (i < txt_size){
			fscanf(in, "%c", &c);
			if (c != '\n'){              //êîïèðóåì òåêñò
				txt[i++] = c;
			} else {
				txt[i++] = ' ';
			}
		}
		
		i = 0;
		while (i < out_size){
			fscanf(in, "%c", &c);              //êîïèðóåì òåêñò
			outro[i++] = c;
		}
	}
	else {
		txt_size = 1000;
		txt= (char*)calloc(txt_size, sizeof(char));
		i = 0;
		scanf ("%c", &c);
		while (c != '\n' && i < txt_size) {
			txt[i++] = c;
			scanf ("%c", &c);
		}
		txt_size = i;
	}
	
		
	if (file_out != NULL){
		FILE *out = freopen(file_out, "w", stdout);           		
		if (out == NULL)
			printf ("Failed to open file %s", file_out);
	}
	
	if (r == 1) {
		
		int col_size=txt_size/col; 
		int row_num=col_size/sym;  
		
		for (i = 0; i < in_size; i++)
			printf ("%c", intro[i]);
		printf ("\n");
		
		for (i=0; i<row_num; i++){
			for (j=0; j<col; j++){
				for (k=0; k<sym; k++){
					printf("%c", txt[j*col_size+i*sym+k]);
				}
				if (j == col-1){
					printf("\n");
				}
				else{
					printf(" | ");
				}
			}
		}
		
		printf ("\n");
		for (i = 0; i < out_size; i++)
			printf ("%c", outro[i]);
	}
	
	else {
		
		int str_num=2*txt_size/sym;
		char str[str_num][sym];
		for (i = 0; i < str_num; i++)
			for (j = 0; j < sym; j++)
				str[i][j] = ' ';
		char *word, *buf;
		i = 0;
		word = strtok (txt, " ");
		while (i < str_num && word){
			
			k = 0;
			if (sym < strlen(word)){
				buf = (char*) malloc((strlen(word))*sizeof(char));
				
				strcpy(buf, word);             
				for (j = 0; j < sym; j++){
					str[i][j] = buf[j];
				}
				
				word = (char*) malloc((strlen(buf) - sym)*sizeof(char));
				for (l = sym; l < strlen(buf); l++){
					word[l - sym] = buf[l];
				}
				i++;
				continue;
			}
			
			
			while (sym - k >= strlen(word)) {
				
				for (j = 0; j < strlen(word); j++){
					str[i][k] = word[j];
					k++;
				}
				
				if (k != sym) {
					str[i][k] = ' ';
					k++;
				}
				word = strtok(NULL, " ");
				if (!word) break;
			}
			while (k < sym){
				str[i][k] = ' ';
				k++;
			}
			i++;
		}
		
		int row_num = (i+1) / col; 
		
		for (i = 0; i < in_size; i++)
			printf ("%c", intro[i]);
		printf ("\n");
		
		for (i = 0; i < row_num; i++){
			for (j = 0; j < col; j++){
				for (l = 0; l < sym; l++)
					printf("%c", str[j*row_num + i][l]);
				if (j != col - 1){
					printf (" | ");
				} else {
					printf("\n");
				}
			}
		}
		
		printf ("\n");
		for (i = 0; i < out_size; i++)
			printf ("%c", outro[i]);
		
	}
	return 0;		
}
