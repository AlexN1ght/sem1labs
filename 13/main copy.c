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
    return (c == ' ' || c == ',' || c == '\n' || c == EOF || c == '\t' || c == '\r') ? 1 : 0;
}

int main(void)
{
    int c;
    int str = 0;
    unsigned int letters_set = 0;

    do {
        c = getchar();
        if (is_spase(c)) {
            if (((letters_set & ~VOWELS) & ~SH_LETTERS) == 0 && letters_set != 0) {
                printf("Yes\n");
                return 0;
            } else if (str == 0 && ( c == '\n' || c == '\r')) {
                printf("Yes\n");
                return 0;
            }
            if (c == '\n') {
                str = 0;
            }
            letters_set = 0;
        } else {
            str = 1;
            letters_set = letters_set | char_to_set(c);
        }
    } while (c != EOF);
    printf("No\n");
    return 0;
}
