#include <stdio.h>
#include <string.h>


void main() {
	int a = 0, sum = 0, j = 1, remain;
	printf("��ȯ�� 10���� ���� : ");
	scanf_s("%d", &a);

	for (int i = 0; i < a;) {
		remain = a % 2;		// ��������
		sum += remain * j;  //�������� ����, ���� ���� ��ĭ�� �ø�
		j *= 10;			// �ܿø���
		a /= 2;				// ���� ��
	}
	printf("2������ �� :%d", sum);
}