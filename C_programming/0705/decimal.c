#include <stdio.h>

int my_decimal(int a) {
	int b = 0;
	for (int i = 2; i < a; i++) {
		if (a & i == 0)	b++; break;
	}
	return b;
}

int main() {
	int a = 0;
	printf("값을 입력해주세요:");
	scanf_s("%d", &a);
	if (my_decimal(a) == 1) printf("입력하신 %d는 소수입니다", a);
	else printf("입력하신 %d는 소수가 아닙니다.", a);
}