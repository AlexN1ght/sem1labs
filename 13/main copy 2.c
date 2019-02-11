#include <stdio.h>

#define SH_LETTERS (1u << ('k' - 'a') | 1u << ('p' - 'a') | 1u << ('t' - 'a') | 1u << ('s' - 'a') | 1u << ('f' - 'a') | 1u << ('c' - 'a') | 1u << ('q' - 'a'))
#define VOWELS (1u << ('a' - 'a') | 1u << ('i' - 'a') | 1u << ('e' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))

int tolower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

unsigned int char_to_set(char c)
{
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c - 'a');
    }
}

int is_spase(int c)
{
    return (c == ' ' || c == '\n' || c == '\r') ? 1 : 0;
}

int main(void)
{
    int c;
    int is_empty = 1;
    unsigned int letters_set = 0;

    while ((c = getchar()) != EOF) {
        if (is_spase(c)) {
            if (((letters_set & ~VOWELS) & ~SH_LETTERS) == 0 && letters_set != 0) {
                printf("Yes\n");
                return 0;
            } else if (c == '\n' || c == '\r') {
                if (is_empty == 1) {
                    printf("Yes\n");
                    return 0;
                }
                is_empty = 1;
            }
            letters_set = 0;
        } else {
            is_empty = 0;
            letters_set = letters_set | char_to_set(c);
        }
    }
    printf("No\n");
    return 0;
}
