#include<stdio.h>


int absR(int a)
{
    return a > 0 ? a : -a;
}

int modR(int a, int b)
{
    return (a % b + absR(b)) % absR(b);
}

int divR(int a, int b)
{
    return (a - modR(a, b)) / b;
}

int signR(int a)
{
    return a > 0 ? 1 : (a < 0 ? -1 : 0);
}

int maxR(int a, int b)
{
    return a > b ? a : b;
}

int minR(int a, int b)
{
    return a < b ? a : b;
}


int i_P(int i, int j, int l, int k)
{
    return minR(modR(l, 5), modR(i * k, 5)) + j + divR(k, 3);
}

int j_P(int i, int j, int l, int k)
{
    return divR(maxR(-3 * i, 2 * j), 5) - absR(j - l);
}

int l_P(int i, int j, int l, int k)
{
    return j + modR(l, 7) + modR(k * signR(i), 10);
}


int main(void)
{

    const int sideS = 10;
    const int I_S = 10;
    const int J_S = -10;

    int i_p;
    int j_p;
    int l_p;

    int i;
    int j;
    int l;
    
    int k = 0;

    scanf("%d%d%d", &i, &j, &l);

    if (I_S - sideS / 2 <= i && i <= I_S + sideS / 2 && J_S - sideS / 2 <= j && j <= J_S + sideS / 2) {
        printf("Yes\n%d %d %d %d\n", i, j, l, k);
        return 0;
    }

    while (k < 50) {
        i_p = i_P(i, j, l, k);
        j_p = j_P(i, j, l, k);
        l_p = l_P(i, j, l, k);
        i = i_p;
        j = j_p;
        l = l_p;

        k++;

        if (I_S - sideS / 2 <= i && i <= I_S + sideS / 2 && J_S - sideS / 2 <= j && j <= J_S + sideS / 2) {
            printf("Yes\n%d %d %d %d\n", i, j, l, k);
            return 0;
        }
    }

    printf("No\n%d %d %d %d\n", i, j, l, k);
    
    return 0;
}
