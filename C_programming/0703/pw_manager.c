#include <stdio.h>
#include <string.h>

typedef struct user_info
{
    char ID[20];
    char PW[20];
}user_info;

user_info users[20]; // 전역 변수로 users 배열 생성

int new_user() {
    char get_ID[20] = "";
    char get_PW[20] = "";
    for (int i = 0; i < 20; i++) {
        // ID의 값이 NULL일 경우에만 등록 진행
        if (strcmp(users[i].ID, "") == 0) {
            printf("%d번의 새로운 유저 등록\n 등록할 ID를 입력하세요 :\n", i);
            scanf("%s", get_ID);
            getchar();
            printf("등록할 PW를 입력하세요 :\n");
            scanf("%s", get_PW);
            getchar();
            if (find_ID(get_ID) == 0) {
                
                if (check_pw(get_PW) == 0) {
                    strcpy(users[i].ID, get_ID);
                    strcpy(users[i].PW, get_PW);
                    printf("등록이 완료되었습니다 ID :%s   PW: %s\n", users[i].ID, users[i].PW);
                }
                else
                    printf("PW는 최소 6글자 이상, 20글자 미만이여야 합니다.\n 메인으로 돌아갑니다.");
            }

            else
                printf("The user is already activated\n");
            break;
        }
        else
            printf("최대 인원수를 초과하였습니다. 메인으로 돌아갑니다.\n");
    }
    return 0;
}

int user_data() {
    if (strcmp(users[0].ID, "") == 0 && strcmp(users[0].PW, "") == 0) {
        printf("The database is empty\n");
    }
    else
    {
        for (int i = 0; i < 20; i++) {
            if (strcmp(users[i].ID, "") == 0 && strcmp(users[i].PW, "") == 0)
                break;

            printf("유저 ID : %s \t 유저 PW : %s\n", users[i].ID, users[i].PW);
        }
    }
    return 0;
}

int find_ID(char* get_id) {        // Find ID
    for (int num = 0; num < 20; num++) {
        if (strcmp(users[num].ID, get_id) == 0) {
            return 1;
        }
    }
    return 0;
}
// 계정 로그인 함수
int user_login() {
    char get_ID[20];
    char get_PW[20];
    int gomenu = 0;
    int try_num = 0;
    while (try_num <= 5)
    {
        printf("ID를 입력해주세요 : \n");
        scanf("%s", get_ID);
        getchar();

        printf("PW를 입력해주세요 : \n");
        scanf("%s", get_PW);
        getchar();
        // 계정 0~19에 담긴ID/PW 와 입력받은 값을 비교하여 둘다 같을 경우 로그인 처리 
        for (int i = 0; i < 20; i++) {
            if (strcmp(users[i].ID, get_ID) == 0) {
                if (strcmp(users[i].PW, get_PW) == 0) {
                    printf("Welcome !! %s\n", get_ID);
                    printf("if want to go back menu, press 1\n");
                    scanf("%d", &gomenu);
                    // main()함수로 돌아갈 수 있도록 break 지정
                    if (gomenu == 1)
                        try_num = 6; break;
                    
                }
                else {
                    printf("실패했습니다 다시 입력해주세요 남은 횟수 :%d번\n", 5 - try_num);
                    try_num++;
                    break;
                }
            }
        }
    }

    return 0;
}
// PW check 함수 : PW길이가 5 초과 20 미만일 경우 0, 아닐경우 1의 값을 리턴한다.
int check_pw(char* get_PW) {
    int len = strlen(get_PW);
    return (len > 5 && len < 20) ? 0 : 1;
}
int main() {
    for (int i = 0; i < 20; i++) {
        strcpy(users[i].ID, "");
        strcpy(users[i].PW, "");
    }

    while (1) {
        int menu = 0;
        printf("패스워드 매니저 프로그램입니다.\n 원하는 항목을 선택하세요\n");
        printf("1. 현재 유저 열람\n");
        printf("2. 유저 생성\n");
        printf("3. 로그인\n");
        printf("4. 프로그램 종료\n");
        scanf("%d", &menu);
        getchar();

        if (menu == 1) {
            user_data();
        }
        if (menu == 2) {
            new_user();
        }
        if (menu == 3) {
            user_login();
        }
        if (menu == 4) {
            printf("프로그램을 종료합니다\n");
            break;
        }
    }
}






//int find_ID() {		// 잃어버린 ID 찾기
//	struct user_info info;
//	int num = 0;
//	char result_id[20] = { 0 };
//	for (int num = 0; num < 20; num++) {
//		// 숫자 탐색
//		for (int j = 48; j <= 57; j++) {
//			if (info.ID[num] == j) {
//				char temp2[2] = { (char)j, '\0' };
//				strcat(result_id, temp2);
//			}
//		}
//		// 대문자 탐색
//		for (int k = 48; k <= 57; k++) {
//			if (info.ID[num] == k) {
//				char temp2[2] = { (char)k, '\0' };
//				strcat(result_id, temp2);
//			}
//		}
//		// 소문자 탐색
//		for (int i = 97; i <= 122; i++) {
//			if (info.ID[num] == (char)i) {
//				char temp[2] = { (char)i, '\0' };
//				strcat(result_id, temp);
//			}
//		}
//	}
//	return result_id;
//}
//
//int find_PW() {			// 잃어버린 PW 찾기
//	struct user_info info;
//	int num = 0;
//	char result_pw[20] = { 0 };
//	for (int num = 0; num < 20; num++) {
//		// 숫자 탐색
//		for (int j = 48; j <= 57; j++) {
//			if (info.PW[num] == j) {
//				char temp2[2] = { (char)j, '\0' };
//				strcat(result_pw, temp2);
//			}
//		}
//		// 대문자 탐색
//		for (int k = 48; k <= 57; k++) {
//			if (info.PW[num] == k) {
//				char temp2[2] = { (char)k, '\0' };
//				strcat(result_pw, temp2);
//			}
//		}
//		// 소문자 탐색
//		for (int i = 97; i <= 122; i++) {
//			if (info.PW[num] == (char)i) {
//				char temp[2] = { (char)i, '\0' };
//				strcat(result_pw, temp);
//			}
//		}
//	}
//	return 0;
//}
