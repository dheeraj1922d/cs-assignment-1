#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) {
        char* result = (char*)malloc(sizeof(char) * 2);
        strcpy(result, "0");
        return result;
    }
    
    int* result = (int*)calloc(len1 + len2, sizeof(int));
    
    int i_n1 = 0;
    int i_n2 = 0;
    
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        
        i_n2 = 0;
        
        for (int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            
            carry = sum / 10;
            
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        
        i_n1++;
    }
    
    int i = len1 + len2 - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    
    if (i == -1) {
        char* result_str = (char*)malloc(sizeof(char) * 2);
        strcpy(result_str, "0");
        return result_str;
    }
    
    char* result_str = (char*)malloc(sizeof(char) * (i + 2));
    int j = 0;
    while (i >= 0) {
        result_str[j++] = result[i--] + '0';
    }
    result_str[j] = '\0';
    
    free(result);
    
    return result_str;
}
