/*
fopen�Լ��� file pointer�� ��ȯ�ϰ�, fopen_s �Լ��� �Ϲ� �������� ��ȯ�Ѵ� (��������� errno_t ��� ���� ����ϱ⵵ �Ѵ�)
fopen �Լ��� ��ȯ���� NULL�� ���, ���� ���� ���� ���� ����
fopen_s �Լ��� ��ȯ���� NULL�� �ƴ� ���, ���� ���� ���� ���� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* fp = fopen("file.txt", "wt");

	//open �� ������ ���簪 �˻�
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
