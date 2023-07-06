#include <stdio.h>
#include <string.h>
char password[5] = "qw12";

int main() {
	printf("%s\n", password);
	int num = 0;
	char result[5] = {0};
	for (int num = 0; num < 5; num++) {
		//printf("%s", password[num]);
		for (int j = 48; j <= 57; j++) {
			if (password[num] == j) {
				//printf("%c", j);
				char temp2[2] = { (char)j, '\0' };
				strcat(result, temp2);
			}
		}
		for (int i = 97; i <= 122; i++) {
			//printf("%c", (char)i);
			if (password[num] == (char)i) {
				char temp[2] = { (char)i, '\0' };
				strcat(result, temp);
				//char result[num] = {(char)i};
			}
		}
		
	}
	printf("%s", result);
}

