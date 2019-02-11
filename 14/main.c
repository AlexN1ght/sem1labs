#include <stdio.h>


int main(void)
{
    int N;
    int M;
    int tests;
    scanf("%d", &tests);
    scanf("%d", &M);
    int m[M][M];

    for (int itr = 0; itr < tests; itr++) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &m[i][j]);
            }
        }
        int i = N;
        int j = 0;
        for (int t = 0; t < 2; t++) {
            for (int k = 0; k < N; k++) {
                i += t - 1;
                j += t;
                int diag_i = i;
                int diag_j = j;
                while (diag_i < N && diag_j < N) {
                    printf("%d ", m[diag_i][diag_j]);
                    diag_i++;
                    diag_j++;
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
