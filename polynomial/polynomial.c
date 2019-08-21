/**
 * 多项式：f(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
 */
#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 10
#define BENCHMARK 1e6  // 1000000

double poly1(double a[], double x, int n);
double poly2(double a[], double x, int n);
double poly3(double a[], double x, int n);
double poly4(double a[], double x, int n);
void timer(double (*fp)(double a[], double x, int n));

double a[N + 1], x = 1.1;
clock_t start_time, end_time;
double seconds;

int main(void) {

    for (int i = 0; i <= N; i++) {
        a[i] = i;
    }

    printf("%lf\n", poly1(a, x, N));
    printf("%lf\n", poly2(a, x, N));
    printf("%lf\n", poly3(a, x, N));
    printf("%lf\n", poly4(a, x, N));
    return 0;
}

void timer(double (*fp)(double a[], double x, int n)) {

    double sum;

    start_time = clock();
    for (int i = 1; i <= BENCHMARK; i++) {
        sum = fp(a, x, N);
    }
    end_time = clock();
    seconds = (end_time - start_time) / CLK_TCK / BENCHMARK;

    printf("f(x) = %f, time=%6.2e\n", sum, seconds);
}

// 调用函数库
double poly1(double a[], double x, int n) {

    double sum = a[0];

    for (int i = 1; i <= n; i++) {
        sum += a[i] * pow(x, i);
    }

    return sum;
}

// 循环法
double poly2(double a[], double x, int n) {

    double sum = a[0];

    for (int i = 1; i <= n; i++) {

        double term = 1.0;

        for (int j = 1; j <= i; j++) {
            term *= x;
        }

        sum += a[i] * term;
    }

    return sum;
}

// 迭代法
double poly3(double a[], double x, int n) {

    double sum = a[0];
    double term = 1.0;

    for (int i = 1; i <= n; i++) {
        term *= x;
        sum += a[i] * term;
    }

    return sum;
}

// 秦九韶算法
double poly4(double a[], double x, int n) {

    double sum = a[n];

    for (int i = n - 1; i >= 0; i--) {

        sum = sum * x + a[i];
    }

    return sum;
}


