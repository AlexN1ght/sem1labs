#include <stdio.h>
#include <stdbool.h>

#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))


char toLower(char c);
unsigned int charToSet(char c);
bool isLetter(char c);


enum State {
    READING,
    WORD_SKIP
};


int main(void)
{
    bool isFound = false;
    bool isEmptyLine = true;
    unsigned int lettersSet = 0;
    enum State state = READING;

    int c;
    while ((c = getchar()) != EOF && !isFound) {
        switch (state) {
            case READING:
                if (!isLetter(c)) {
                    if (lettersSet != 0) {
                        isFound = true;
                    } else if (c == '\n' || c == '\r') {
                        isEmptyLine ? isFound = true : (isEmptyLine = true);
                    }
                } else {
                    isEmptyLine = false;
                    if ((lettersSet & (charToSet(c) & ~VOWELS)) != 0) {
                        lettersSet = 0;
                        state = WORD_SKIP;
                    } else {
                        lettersSet = lettersSet | charToSet(c);
                    }
                }
            case WORD_SKIP :
                if (!isLetter(c)) {
                    if (c == '\n' || c == '\r') {
                        isEmptyLine = true;
                    }
                    state = READING;
                }
        }
    }
    isFound ? printf("Yes\n") : printf("No\n");
    return 0;
}


char toLower(char c)
{
    return c < 'A' || c > 'Z' ? c : c + ('a' - 'A');
}


unsigned int charToSet(char c)
{
    c = toLower(c);
    return c < 'a' || c > 'z' ? 0 : 1u << (c - 'a');
}


bool isLetter(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == ',' || c == '\r' || c == EOF) {
        return false;
    }
    return true;
}
