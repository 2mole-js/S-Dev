#include <stdio.h>
#include <string.h>

int my_strcpy(char text1[], char text2[]) {
	for (int i = 0; text2[i]!=NULL; i++) {
		text1[i] = text2[i];
	}
	printf("����� ���� �� :%s", text1);
	printf("�Է��� str  �� :%s", text2);
	return 0;
}

int main() {
	char text1[] = {0,};
	char text2[] = {0,};
	printf("������ str�� �Է��ϼ��� :");
	gets(text2);
	printf("�Է¹��� ��: %s", text2);
	my_strcpy(text1, text2);

	return 0;
}