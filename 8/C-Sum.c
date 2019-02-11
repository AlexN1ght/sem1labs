#include<stdio.h>

int main(void)
{
    int a, b, c;
    b = 0;

    scanf("%d", &a);
    while (a) {
        scanf("%d", &c);
        if (c >= 10) {
            b += c;
        }
        a--;
    }
    printf("%d\n", b);
    return (0);
}
