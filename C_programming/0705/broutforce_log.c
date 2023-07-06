#define _CRT_SECURE_NO_WARNINGS         //fopen ���� ������
#define MAX_LENGTH 1024                 //�ִ� ���̷� ����� ���� ���� ����

#include <stdio.h>
#include <string.h>

// ����ü�� ��ü ���̴� 20���� ����
// �� �������� ��Ȯ�� characters ũ��� �����Ϸ��� ������ �̻��ϰ� ��Ȯ�� charactersũ��� ������ ���
// ����ü �ȿ� �Է��Ҷ� �ٸ� �迭�� ���� ���� �ԷµǴ� ������ �־�
// date, time, result char ���� +1 �� �־� �ذ��Ͽ��� => ���� ��..
typedef struct Logtace {
    char date[11];
    char time[9];
    char user_name[20];
    char try_password[20];
    char result[8];
} Logtace;
// � ������ ����ü�� ũ�� ����
Logtace logs[MAX_LENGTH];

int main() {
    // File �� �������� �� ���� ���� Ȯ��
    FILE* fp = NULL;
    if ((fp = fopen("log.txt", "rt")) == NULL) {
        printf("ERROR, file is not exist\n");
        return -1;
    }
    char dump[MAX_LENGTH] = "";
    char succes_attack[MAX_LENGTH] = "";
    int i = 0, log_index = 0;
    // ������ ���� ���� �޾ƿͼ� dump�� �����ϴµ� �ݺ��ϴ� Ƚ���� MAX_LENGTH���� �ݺ��ϰų�,���� ���� ������(NULL)����
    while (fgets(dump, sizeof(dump), fp) != NULL && log_index < MAX_LENGTH) {
        char *token = strtok(dump, " ");                    //�޾ƿ� ���ڿ����� ���鰪 ����
        int token_index = 0;
        //������ ���ŵǾ� �и��Ǿ� �ִ� ���� �˸°� �־��ش�.
        while (token != NULL && token_index < 5) {
            if (token_index == 0)
                strcpy(logs[log_index].date, token);
            else if (token_index == 1)
                strcpy(logs[log_index].time, token);
            else if (token_index == 2)
                strcpy(logs[log_index].user_name, token);
            else if (token_index == 3)
                strcpy(logs[log_index].try_password, token);
            else if (token_index == 4)
                strcpy(logs[log_index].result, token);
            token = strtok(NULL, " ");                  // ��ū �ʱ�ȭ
            token_index++;
        }
        log_index++;
    }
    
    for (int k = 0; k < log_index; k++) {
        printf("LOG : %d\n", k + 1);
        printf("date : %s\n", logs[k].date);
        printf("time : %s\n", logs[k].time);
        printf("user_name : %s\n", logs[k].user_name);
        printf("try_password : %s\n", logs[k].try_password);
        printf("result : %s\n\n", logs[k].result);
        }
    fclose(fp);
    return 0;
    }