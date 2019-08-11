#include <stdio.h>

#define MAX_LEN 1000
#define IN 1  // 在单词内
#define OUT 0  // 在单词外

int ch_arr_len;
int word_status;
int char_count(char arr[MAX_LEN]);
int line_count(char arr[MAX_LEN]);
int word_count(char arr[MAX_LEN]);

int main(void) {

    char ch_arr[MAX_LEN];
    int i = 0;
    char c;

    while ((c = getchar()) != EOF) {
        ch_arr[i] = c;
        i++;
    }

    ch_arr[i] = '\0';
    ch_arr_len = i;

    int nc = char_count(ch_arr);
    int nl = line_count(ch_arr);
    int nw = word_count(ch_arr);

    printf("char count: %d\n", nc);
    printf("line count: %d\n", nl);
    printf("word count: %d\n", nw);
}

int char_count(char arr[]) {
    int count = 0;

    for (int i = 0; i < ch_arr_len; i++) {
        if (arr[i] == '\0') {
            break;
        }
        if (arr[i] != '\n') {
            count++;
        }
    }

    return count;
}

int line_count(char arr[]) {
    int count = 0;

    for (int i = 0; i < ch_arr_len; i++) {

        if (arr[i] == '\0') {
            break;
        }

        if (arr[i] == '\n') {
            count++;
        }
    }

    return count;
}

int word_count(char arr[]) {

    int count = 0;

    for (int i = 0; i < ch_arr_len; i++) {
        char ch = arr[i];

        if (ch == '\0') {
            break;
        } else if (ch == '\n' || ch == ' ' || ch == '\t') {
            word_status = OUT;
        } else if (word_status == OUT) {
            word_status = IN;
            count++;
        }
    }

    return count;
}



