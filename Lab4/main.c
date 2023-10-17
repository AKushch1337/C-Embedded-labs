#include <stdio.h>

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int countDigits(const char *str) {
    int count = 0;
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if (isDigit(str[i])) {
            count++;
        }
    }

    return count;
}

int main() {
    char input[100]; // You can adjust the size based on your needs

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int numCount = countDigits(input);
    printf("Number of digits in the string: %d\n", numCount);

    return 0;
}
