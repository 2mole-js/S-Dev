#include <stdio.h>
#include <string.h>

int my_strcpy(char text1[], char text2[]) {
	for (int i = 0; text2[i]!=NULL; i++) {
		text1[i] = text2[i];
	}
	printf("복사된 변수 값 :%s", text1);
	printf("입력한 str  값 :%s", text2);
	return 0;
}

int main() {
	char text1[] = {0,};
	char text2[] = {0,};
	printf("복사할 str를 입력하세요 :");
	gets(text2);
	printf("입력받은 값: %s", text2);
	my_strcpy(text1, text2);

	return 0;
}