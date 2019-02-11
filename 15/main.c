#include <stdio.h>
#include <limits.h>


int main(void)
{
    int N;
    int M;
    int tests;
    scanf("%d", &tests);
    scanf("%d", &M);
    int m[M][M];

    for (int itr = 0; itr < tests; itr++) {

        int max = INT_MIN;
        int min = INT_MAX;
        int min_r = 0;
        unsigned int max_rs = 0;
        scanf("%d", &N);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &m[i][j]);
                if (m[i][j] > max) {
                    max = m[i][j];
                    max_rs = 1u << (i + 1);

                } else if (m[i][j] == max) {
                    max_rs |= 1u << (i + 1);
                }
                if (m[i][j] < min) {
                    min = m[i][j];
                    min_r = i;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (((1u << (i + 1)) & max_rs) != 0) {
                for (int j = 0; j < N; j++) {
                    m[i][j] = m[min_r][j];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", m[i][j]);
            }
            putchar('\n');
        }
        
    }
    return 0;
}
