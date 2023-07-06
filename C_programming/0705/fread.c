#include <stdio.h>
#include <stdint.h>
#include<string.h>

int main() {
	/**
	FILE *fp = NULL;

	if (fopen_s(&fp, "file.txt", "rt") != NULL) {
		printf("ERROR");
		return -1;
	}
	
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);

	fseek(fp, 0, SEEK_SET);
	char read_file[1024] = "";
	fread(read_file, 1,size, fp);
	fclose(fp);
	int down, upper = 0;
	for (int i = 0; i < size; i++) {
		if (64 < (int)read_file[i] && (int)read_file[i] < 91) {
			down = (int)read_file[i] + 32;
			read_file[i] = (char)down;
		}
		else if (96 < (int)read_file[i] && (int)read_file[i] < 123)
		{
			upper = (int)read_file[i] - 32;
			read_file[i] = (char)upper;
		}
		printf("%c", read_file[i]);
	}
		**/
	/**
	FILE* fp = NULL;

	if (fopen_s(&fp, "file.txt", "a") != NULL) {
		printf("ERROR");
		return -1;
	}
	fputs("\t ABCDE", fp);
	fclose(fp);
	**/
	
	FILE* fp = NULL;

	if (fopen_s(&fp, "example.bin", "rb") != NULL) {
		printf("ERROR");
		return -1;
	}
	uint32_t read_example[10];
	fread(read_example, sizeof(read_example),1, fp);
	fclose(fp);
	for (int i =0 ; i<strlen(read_example); i++)
		printf("%x\n", read_example[i]);




	return 0;
}