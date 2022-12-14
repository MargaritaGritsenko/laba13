#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#define MAX_LINE 256

char * fgets(char*, int);
int  count_words(char*, char);

int main(void) {
    setlocale(LC_ALL, "RU");
    char ch, str[MAX_LINE];
    printf("Введите символ: "); 
    ch = getchar();
    fgets(str, MAX_LINE);

    printf("Введите строку: ");
    fgets(str, MAX_LINE);
    puts("");

    printf("Количество слов: %d\n", count_words(str, ch));
    return 0;
}
char * fgets(char* str, int size) {
    char ch;
    int i = 0, max_len = size - 1;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (i < max_len)
            str[i++] = ch;
    }
    str[i] = '\0';
}
int count_words(char* s, char symbol) {
    enum { IN = 0, OUT };               
    int words = 0, state = OUT;         
    for (int i = 0; s[i] != '\0'; i++) 
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            if (state == OUT) {         
                state = IN;            
                if (s[i] == symbol) {   
                    words++;           
                    puts("");
                }
            }
        }
        else
            state = OUT;
    return words;
}