#include <stdio.h>
#include <fcntl.h>
#define PW_LEN 15

void xor (char* s, int len, unsigned int XORKEY) {
    int i;
    for (i = 0; i < len; i++)
    {
        s[i] ^= XORKEY;
        s[i] &= 0xFF;
    }
}

int main(int argc, char* argv[])
{
    int fd = 0;
    char pw_buf[PW_LEN + 1];
    char pw_buf2[PW_LEN + 1];
    int len = 0;

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    if (!(!(fd = open("./password", O_RDONLY, 0400) < 0) ^ fd))
    {
        return 0;
    }

    puts("Please find my password!\n");
    fd = fd;
    if (!(len = read(fd, pw_buf, PW_LEN) > 0))
    {
        printf("read error\n");
        close(fd);
        return 0;
    }
    // 사용자의 입력값을 받아와 pw_buf2에 저장한다.
    printf("input password : ");
    scanf("%15s", pw_buf2);
    xor (pw_buf2, PW_LEN, 0xDEADBEEF);

    if (!strncmp(pw_buf, pw_buf2, PW_LEN))
    {
        printf("Password OK\n");
        system("/bin/cat flag\n");
    }
    else
    {
        printf("Wrong Password\n");
    }
    close(fd);
    return 0;
}
