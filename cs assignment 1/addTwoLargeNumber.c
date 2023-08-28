#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* add_large_numbers(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Make sure num1 is the longer number
    if (len1 < len2) {
        const char* temp = num1;
        num1 = num2;
        num2 = temp;

        int tempLen = len1;
        len1 = len2;
        len2 = tempLen;
    }

    int maxLength = len1 + 1;
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    result[maxLength] = '\0';

    int carry = 0;
    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = maxLength - 1; i >= 0; i--, j--, k--) {
        int digitSum = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
        result[k] = digitSum % 10 + '0';
        carry = digitSum / 10;
    }

    if (carry) {
        result[0] = carry + '0';
        return result;
    } else {
        return result + 1; // Skip the first character (leading zero)
    }
}


int main() {
    char num1[1025];
    char num2[1025];

    printf("Enter the first large number: ");
    scanf("%s", num1);

    printf("Enter the second large number: ");
    scanf("%s", num2);

    char* sum_result = add_large_numbers(num1, num2);
    printf("Sum: %s\n", sum_result);

    free(sum_result);

    return 0;
}
