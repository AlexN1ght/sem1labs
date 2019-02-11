#include<stdio.h>

int is_8dig(int ch)
{
    return ch - '0' < 8 && ch - '0' >= 0 ? 1 : 0;
}

int is_space(int ch)
{
    return ch == ' ' || ch == ',' || ch == '\n' || ch == EOF ? 1 : 0;
}

int main(void)
{
    int ch = 0;
    int len = 0;
    int num = 0;
    int is_dig = 0;
    int sos = 0;
    do {
        switch (sos) {
            case 0 :
                ch = getchar();
                sos = 1;
                break;
            case 1 :
                if (is_8dig(ch)) {
                    if (len == 0) {
                        len = 1;
                    }
                    len *= 10;
                    num = num * 10 + ch - '0';
                    ch = getchar();
                } else if (is_space(ch)) {
                    len /= 10;
                    sos = 33;
                } else {
                    len = 0;
                    num = 0;
                    sos = 22;
                }
                break;
            case  33 :
                if (is_dig == 1 && len != 0) {
                    printf(" ");
                }
                if (len != 0) {
                    is_dig = 1;
                }
                while (len != 0) {
                    int dig = num / len;
                    for (int i = 4; i >= 1; i /= 2) {
                        if (dig - i >= 0) {
                            printf("%d", 1);
                            dig -= i;
                        } else {
                            printf("%d", 0);
                        }
                    }
                    num %= len;
                    len /= 10;
                }
                num = 0;
                sos = 22;
                break;
            case 22 :
                if (ch == '\n' || ch == EOF) {
                    sos = 2;
                } else if (ch == ' ' || ch == ',') {
                    sos = 0;
                } else {
                    ch = getchar();
                }
                break;
            case 2 :
                if (is_dig == 1) {
                    printf("\n");
                    is_dig = 0;
                }
                sos = 0;
                if (ch == EOF) {
                    sos = -1;
                }
                break;
        }
    } while (sos != -1);
    return 0;
}
