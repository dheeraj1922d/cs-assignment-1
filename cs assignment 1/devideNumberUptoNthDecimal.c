#include <stdio.h>

void precisionCompute(int x, int y, int n)
{
    if (y == 0) {
        printf("Infinite\n");
        return;
    }
    if (x == 0) {
        printf("0\n");
        return;
    }
    if (n <= 0) {
        printf("%d\n", x / y);
        return;
    }
    if (((x > 0) && (y < 0)) || ((x < 0) && (y > 0))) {
        printf("-");
        x = x > 0 ? x : -x;
        y = y > 0 ? y : -y;
    }
    int d = x / y;
    for (int i = 0; i <= n; i++) {
        printf("%d", d);
        x = x - (y * d);
        if (x == 0)
            break;
        x = x * 10;
        d = x / y;
        if (i == 0)
            printf(".");
    }
}

int main()
{
    int x = 22, y = 7, n = 15;
    precisionCompute(x, y, n);
    return 0;
}
