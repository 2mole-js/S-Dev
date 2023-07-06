#include <stdio.h>
#include <string.h>

typedef struct user_info
{
    char ID[20];
    char PW[20];
}user_info;

user_info users[20]; // ���� ������ users �迭 ����

int new_user() {
    char get_ID[20] = "";
    char get_PW[20] = "";
    for (int i = 0; i < 20; i++) {
        // ID�� ���� NULL�� ��쿡�� ��� ����
        if (strcmp(users[i].ID, "") == 0) {
            printf("%d���� ���ο� ���� ���\n ����� ID�� �Է��ϼ��� :\n", i);
            scanf("%s", get_ID);
            getchar();
            printf("����� PW�� �Է��ϼ��� :\n");
            scanf("%s", get_PW);
            getchar();
            if (find_ID(get_ID) == 0) {
                
                if (check_pw(get_PW) == 0) {
                    strcpy(users[i].ID, get_ID);
                    strcpy(users[i].PW, get_PW);
                    printf("����� �Ϸ�Ǿ����ϴ� ID :%s   PW: %s\n", users[i].ID, users[i].PW);
                }
                else
                    printf("PW�� �ּ� 6���� �̻�, 20���� �̸��̿��� �մϴ�.\n �������� ���ư��ϴ�.");
            }

            else
                printf("The user is already activated\n");
            break;
        }
        else
            printf("�ִ� �ο����� �ʰ��Ͽ����ϴ�. �������� ���ư��ϴ�.\n");
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

            printf("���� ID : %s \t ���� PW : %s\n", users[i].ID, users[i].PW);
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
// ���� �α��� �Լ�
int user_login() {
    char get_ID[20];
    char get_PW[20];
    int gomenu = 0;
    int try_num = 0;
    while (try_num <= 5)
    {
        printf("ID�� �Է����ּ��� : \n");
        scanf("%s", get_ID);
        getchar();

        printf("PW�� �Է����ּ��� : \n");
        scanf("%s", get_PW);
        getchar();
        // ���� 0~19�� ���ID/PW �� �Է¹��� ���� ���Ͽ� �Ѵ� ���� ��� �α��� ó�� 
        for (int i = 0; i < 20; i++) {
            if (strcmp(users[i].ID, get_ID) == 0) {
                if (strcmp(users[i].PW, get_PW) == 0) {
                    printf("Welcome !! %s\n", get_ID);
                    printf("if want to go back menu, press 1\n");
                    scanf("%d", &gomenu);
                    // main()�Լ��� ���ư� �� �ֵ��� break ����
                    if (gomenu == 1)
                        try_num = 6; break;
                    
                }
                else {
                    printf("�����߽��ϴ� �ٽ� �Է����ּ��� ���� Ƚ�� :%d��\n", 5 - try_num);
                    try_num++;
                    break;
                }
            }
        }
    }

    return 0;
}
// PW check �Լ� : PW���̰� 5 �ʰ� 20 �̸��� ��� 0, �ƴҰ�� 1�� ���� �����Ѵ�.
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
        printf("�н����� �Ŵ��� ���α׷��Դϴ�.\n ���ϴ� �׸��� �����ϼ���\n");
        printf("1. ���� ���� ����\n");
        printf("2. ���� ����\n");
        printf("3. �α���\n");
        printf("4. ���α׷� ����\n");
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
            printf("���α׷��� �����մϴ�\n");
            break;
        }
    }
}






//int find_ID() {		// �Ҿ���� ID ã��
//	struct user_info info;
//	int num = 0;
//	char result_id[20] = { 0 };
//	for (int num = 0; num < 20; num++) {
//		// ���� Ž��
//		for (int j = 48; j <= 57; j++) {
//			if (info.ID[num] == j) {
//				char temp2[2] = { (char)j, '\0' };
//				strcat(result_id, temp2);
//			}
//		}
//		// �빮�� Ž��
//		for (int k = 48; k <= 57; k++) {
//			if (info.ID[num] == k) {
//				char temp2[2] = { (char)k, '\0' };
//				strcat(result_id, temp2);
//			}
//		}
//		// �ҹ��� Ž��
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
//int find_PW() {			// �Ҿ���� PW ã��
//	struct user_info info;
//	int num = 0;
//	char result_pw[20] = { 0 };
//	for (int num = 0; num < 20; num++) {
//		// ���� Ž��
//		for (int j = 48; j <= 57; j++) {
//			if (info.PW[num] == j) {
//				char temp2[2] = { (char)j, '\0' };
//				strcat(result_pw, temp2);
//			}
//		}
//		// �빮�� Ž��
//		for (int k = 48; k <= 57; k++) {
//			if (info.PW[num] == k) {
//				char temp2[2] = { (char)k, '\0' };
//				strcat(result_pw, temp2);
//			}
//		}
//		// �ҹ��� Ž��
//		for (int i = 97; i <= 122; i++) {
//			if (info.PW[num] == (char)i) {
//				char temp[2] = { (char)i, '\0' };
//				strcat(result_pw, temp);
//			}
//		}
//	}
//	return 0;
//}
