#include <stdio.h>
#include <string.h>


void main() {
	int a = 0, sum = 0, j = 1, remain;
	printf("변환할 10진수 숫자 : ");
	scanf_s("%d", &a);

	for (int i = 0; i < a;) {
		remain = a % 2;		// 나머지값
		sum += remain * j;  //나머지는 끝단, 이후 값은 한칸씩 올림
		j *= 10;			// 단올리기
		a /= 2;				// 다음 단
	}
	printf("2진수의 값 :%d", sum);
}