#define _CRT_SECURE_NO_WARNINGS         //fopen 에러 방지용
#define MAX_LENGTH 1024                 //최대 길이로 사용할 길이 변수 정의

#include <stdio.h>
#include <string.h>

// 구조체의 전체 길이는 20으로 통일
// 각 데이터의 정확한 characters 크기로 지정하려고 했으나 이상하게 정확한 characters크기로 지정될 경우
// 구조체 안에 입력할때 다른 배열의 값도 같이 입력되는 문제가 있어
// date, time, result char 값의 +1 을 넣어 해결하였다 => 원인 모름..
typedef struct Logtace {
    char date[11];
    char time[9];
    char user_name[20];
    char try_password[20];
    char result[8];
} Logtace;
// 몇개 담을지 구조체의 크기 지정
Logtace logs[MAX_LENGTH];

int main() {
    // File 값 가져오기 및 파일 존재 확인
    FILE* fp = NULL;
    if ((fp = fopen("log.txt", "rt")) == NULL) {
        printf("ERROR, file is not exist\n");
        return -1;
    }
    char dump[MAX_LENGTH] = "";
    char succes_attack[MAX_LENGTH] = "";
    int i = 0, log_index = 0;
    // 파일을 한줄 한줄 받아와서 dump에 저장하는데 반복하는 횟수는 MAX_LENGTH까지 반복하거나,다음 줄이 없을때(NULL)까지
    while (fgets(dump, sizeof(dump), fp) != NULL && log_index < MAX_LENGTH) {
        char *token = strtok(dump, " ");                    //받아온 문자열에서 공백값 제거
        int token_index = 0;
        //공백이 제거되어 분리되어 있는 값을 알맞게 넣어준다.
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
            token = strtok(NULL, " ");                  // 토큰 초기화
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