#include <stdio.h>
#include <math.h>

double calculateExpression1(double a);
double calculateExpression2(double a);

int main() {
    double a = 0.0;
    printf("Enter a value for 'a': ");
    scanf("%lf", &a);

    double result1 = calculateExpression1(a);
    double result2 = calculateExpression2(a);

    printf("cos(3*%.2f)/(1 + sin(3*%.2f)) = %lf\n", a, a, result1);
    printf("ctg(5pi/4 + 3*%.2f/2) = %lf\n", a, result2);
    return 0;
}

double calculateExpression1(double a) {
    double expr1 = cos(3 * a) / (1 + sin(3 * a));
    return expr1;
}

double calculateExpression2(double a) {
    double expr2 = 1 / tan(3 * a / 2 + M_PI / 4);
    return expr2;
}
