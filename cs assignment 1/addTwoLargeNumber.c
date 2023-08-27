#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* GetBigInteger(char* str)
{
    int x = strlen(str), a = 0;
    
    int* arr = (int*)malloc(strlen(str) * sizeof(int));
    
    while (a != x) {
        arr[a] = str[a] - '0';
        a++;
    }
    
    return arr;
}

int main()
{
    char str[] = "12345678098765431234567809876543";
    
    int* arr = GetBigInteger(str);
    
    for (int i = 0; i < strlen(str); i++) {
        printf("%d", arr[i]);
    }
    
    free(arr);
    
    return 0;
}
