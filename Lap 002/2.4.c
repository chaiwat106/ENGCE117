#include <stdio.h>

void explode(const char str1[], char splitter, char str2[][10], int *count);

int main() {
    char parts[20][10];
    int total;

    explode("I/Love/You", '/', parts, &total);

    for (int i = 0; i < total; i++) {
        printf("%s\n", parts[i]);
    }

    return 0;
}

void explode(const char str1[], char splitter, char str2[][10], int *count) {
    int bucket = 0;
    int pos = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == splitter) {
            str2[bucket][pos] = '\0';
            bucket++;
            pos = 0;
        } else if (pos < 9) {  // ป้องกัน overflow
            str2[bucket][pos++] = str1[i];
        }
    }

    str2[bucket][pos] = '\0';
    *count = bucket + 1;
}
