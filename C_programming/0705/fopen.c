/*
fopen함수는 file pointer를 반환하고, fopen_s 함수는 일반 정수형을 반환한다 (통상적으로 errno_t 라는 예약어를 사용하기도 한다)
fopen 함수는 반환값이 NULL일 경우, 정상 실행 되지 않은 상태
fopen_s 함수는 반환값이 NULL이 아닐 경우, 정상 실행 되지 않은 상태
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* fp = fopen("file.txt", "wt");

	//open 한 파일의 존재값 검사
	if (fp == NULL) {
		printf("file.txt is existence");
	}
	else {
		fprintf(fp, "Hello KISIA");
	}
		fclose(fp);
	return 0;

	/*
	// case 1
	int ret = 0;
	FILE *fp = NULL;

	ret = fopn_s(&fp, filename, "r");

	if (ret != NULL){
		printf("FILE cannot opn");
		retrun -1;
		}
	fprintf(fp, "%s", buf);

	//case 2
	FILE *fp = NULL;


	if (fopen_s(fp,filename,"r") != NULL){
		//error
		}

		fprintf(fp,"%s",buf);
	*/
}
