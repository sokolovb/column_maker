#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
** options:
** -c="int"
** -w="int"
** -r
** -f="ghgh1.txt"
*/

#define OPT(n, x) argv[n][0] == '-' && argv[n][1] == x

int main(int argc, char *argv[])
{	

	int col = 0, sym=0, r=0, txt_size = 0;
	int i, j, k, l;
	char c;
	char *file_out = NULL;
	
	FILE *in=fopen("input.txt", "r");
	
	
	fscanf(in, "%c", &c);
	while (!feof(in)){
		if (c != '\n')              
			txt_size++;
		fscanf(in, "%c", &c);
	}
	
	fclose(in);
	in=fopen("input.txt", "r");
	
	char *txt= (char*)calloc(txt_size, sizeof(char));
	
	while (i < txt_size){
		fscanf(in, "%c", &c);
		if (c != '\n'){              //êîïèðóåì òåêñò
			txt[i++] = c;
		}
	}

	if (argc == 1){
		col = 1;
		sym = 50;
		r = 0;
	}
	else if (argc == 2){
		if (OPT(1, 'c')) {
			for(i = 3; i < strlen(argv[1]); i++){
				col *= 10;
				col += argv[1][i] - '0';
			}
			sym = 50;
			r = 0;
		}
		else if (OPT(1, 'w')) {
			for(i = 3; i < strlen(argv[1]); i++){
				sym *= 10;
				sym += argv[1][i] - '0';
			}
			col = 1;
			r = 0;
		}
		else if (OPT(1, 'r')){ 
			col = 1;
			sym = 50;	
			r = 1;
		}
		else if (OPT(1, 'f')) {
			col = 1;
			sym = 50;
			r = 0;
			file_out = (char*) malloc ((strlen(argv[1]) - 3) * sizeof (char));
			for (i = 3; i < strlen(argv[1]); i++){
				file_out[i-3] = argv[1][i];
			}
		}
		else {
			printf ("Wrong options\nUsage: -c='number_of_column' -w='width_of_column' -r (allow splits) -f='output_filename.txt'");
			return 0;
		}
	}
	else if (argc == 3) {
		if (OPT(1, 'c') && OPT(2, 'w')){
			for(i = 3; i < strlen(argv[1]); i++){
				col *= 10;
				col += argv[1][i] - '0';
			}
			for(i = 3; i < strlen(argv[2]); i++){
				sym *= 10;
				sym += argv[2][i] - '0';
			}
			r = 0;
		}
		else if (OPT(1, 'c') && OPT(2, 'r')) {
			for(i = 3; i < strlen(argv[1]); i++){
				col *= 10;
				col += argv[1][i] - '0';
			}
			sym = 50;
			r = 1;
		}
		else if (OPT(1, 'c') && OPT(2, 'f')) {
			for(i = 3; i < strlen(argv[1]); i++){
				col *= 10;
				col += argv[1][i] - '0';
			}
			sym = 50;
			r = 0;
			file_out = (char*) malloc ((strlen(argv[1]) - 3) * sizeof (char));
			for (i = 3; i < strlen(argv[2]); i++){
				file_out[i-3] = argv[2][i];
			}
		}
		else if (OPT(1, 'w') && OPT(2, 'r')) {
			col = 1;
			for(i = 3; i < strlen(argv[1]); i++){
				sym *= 10;
				sym += argv[1][i] - '0';
			}
			r = 1;
		}
		else if (OPT(1, 'w') && OPT(2, 'f')) {
			col = 1;
			for(i = 3; i < strlen(argv[1]); i++){
				sym *= 10;
				sym += argv[1][i] - '0';
			}
			r = 0;
			file_out = (char*) malloc ((strlen(argv[1]) - 3) * sizeof (char));
			for (i = 3; i < strlen(argv[2]); i++){
				file_out[i-3] = argv[2][i];
			}
		}
		else if (OPT(1, 'r') && OPT(2, 'f')) {
			col = 1;
			sym = 50;
			r = 1;
			file_out = (char*) malloc ((strlen(argv[1]) - 3) * sizeof (char));
			for (i = 3; i < strlen(argv[2]); i++){
				file_out[i-3] = argv[2][i];
			}
		}
		else {
			printf ("Wrong options\nUsage: -c='number_of_column' -w='width_of_column' -r (allow splits) -f='output_filename.txt'");
			return 0;
		}
	}
	else if (argc == 4) {
		if (OPT(1, 'w') && OPT(2, 'r') && OPT(3, 'f')){
			col = 1;
			for(i = 3; i < strlen(argv[1]); i++){
				sym *= 10;
				sym += argv[1][i] - '0';
			}
			r = 1;
			file_out = (char*) malloc ((strlen(argv[1]) - 3) * sizeof (char));
			for (i = 3; i < strlen(argv[3]); i++){
				file_out[i-3] = argv[3][i];
			}
		}
		else if (OPT(1, 'c') && OPT(2, 'r') && OPT(3, 'f')) {
			for(i = 3; i < strlen(argv[1]); i++){
				col *= 10;
				col += argv[1][i] - '0';
			}
			sym = 50;
			r = 1;
			file_out = (char*) malloc ((strlen(argv[1]) - 3) * sizeof (char));
			for (i = 3; i < strlen(argv[3]); i++){
				file_out[i-3] = argv[3][i];
			}
		}
		else if (OPT(1, 'c') && OPT(2, 'w') && OPT(3, 'f')){
			for(i = 3; i < strlen(argv[1]); i++){
				col *= 10;
				col += argv[1][i] - '0';
			}
			for(i = 3; i < strlen(argv[2]); i++){
				sym *= 10;
				sym += argv[2][i] - '0';
			}
			r = 0;
			file_out = (char*) malloc ((strlen(argv[1]) - 3) * sizeof (char));
			for (i = 3; i < strlen(argv[3]); i++){
				file_out[i-3] = argv[3][i];
			}
		}
		else if (OPT(1, 'c') && OPT(2, 'w') && OPT(3, 'r')){
			for(i = 3; i < strlen(argv[1]); i++){
				col *= 10;
				col += argv[1][i] - '0';
			}
			for(i = 3; i < strlen(argv[2]); i++){
				sym *= 10;
				sym += argv[2][i] - '0';
			}
			r = 1;
		}
		else {
			printf ("Wrong options\nUsage: -c='number_of_column' -w='width_of_column' -r (allow splits) -f='output_filename.txt'");
			return 0;
		}
	}
	else if (argc == 5) {
		if (OPT(1, 'c') && OPT(2, 'w') && OPT(3, 'r') && OPT(4, 'f')){
			for(i = 3; i < strlen(argv[1]); i++){
				col *= 10;
				col += argv[1][i] - '0';
			}
			for(i = 3; i < strlen(argv[2]); i++){
				sym *= 10;
				sym += argv[2][i] - '0';
			}
			r = 1;
			file_out = (char*) malloc ((strlen(argv[1]) - 3) * sizeof (char));
			for (i = 3; i < strlen(argv[4]); i++){
				file_out[i-3] = argv[4][i];
			}
		}
		else {
			printf ("Wrong options\nUsage: -c='number_of_column' -w='width_of_column' -r (allow splits) -f='output_filename.txt'");
			return 0;
		}
	}
	else {
		printf ("Wrong options\nUsage: -c='number_of_column' -w='width_of_column' -r (allow splits) -f='output_filename.txt'");
		return 0;
	}
		
	if (file_out != NULL){
		FILE *out = freopen(file_out, "w", stdout);           		
		if (out == NULL)
			printf ("Failed to open file %s", file_out);
	}
	
	if (r == 1) {
		
		int col_size=txt_size/col; 
		int row_num=col_size/sym;  
		
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
				strcpy(buf, word);             
				for (j = 0; j < sym; j++){
					str[i][j] = buf[j];
				}
				
				word = (char*) malloc((strlen(buf) - sym)*sizeof(char));
				for (l = sym; l < strlen(buf); l++){
					word[l - sym] = buf[l];
				}
				break;
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
		
	}
	return 0;		
}

