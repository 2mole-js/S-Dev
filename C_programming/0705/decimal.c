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
	printf("���� �Է����ּ���:");
	scanf_s("%d", &a);
	if (my_decimal(a) == 1) printf("�Է��Ͻ� %d�� �Ҽ��Դϴ�", a);
	else printf("�Է��Ͻ� %d�� �Ҽ��� �ƴմϴ�.", a);
}