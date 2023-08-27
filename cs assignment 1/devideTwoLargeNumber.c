#include <stdio.h>
#include <string.h>

char* longDivision(char* number, int divisor)
{
    char* ans = malloc(strlen(number) + 1);
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    int ansIdx = 0;
    while (strlen(number) > idx) {
        ans[ansIdx++] = (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    ans[ansIdx] = '\0';

    if (strlen(ans) == 0) {
        strcpy(ans, "0");
    }

    return ans;
}

int main()
{
    char number[] = "1248163264128256512";
    int divisor = 125;
    printf("%s", longDivision(number, divisor));
    return 0;
}
