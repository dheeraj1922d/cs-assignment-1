#include <stdio.h>
#include <math.h>

double custom_pow(double base, double exponent) {
    if (exponent == 0)
        return 1.0;

    double result = base;
    for (int i = 1; i < fabs(exponent); i++) {
        result *= base;
    }

    if (exponent < 0)
        result = 1.0 / result;

    return result;
}

int main() {
    double base, exponent;
    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%lf", &exponent);

    double result = custom_pow(base, exponent);
    printf("Result: %lf\n", result);

    return 0;
}
