#include <stdio.h>

short is_op(char op);
double compute(double a, char op, double b);
short get_op_priority(char op);

int main(void) {
    double a, b, c;
    char op1, op2;

    scanf("%lf%c%lf%c%lf", &a, &op1, &b, &op2, &c);
    char ch = getchar();

    if (!is_op(op1)) {
        printf("op1 %c is not valid!\n", op1);
        return 0;
    }

    if (!is_op(op2)) {
        printf("op2 %c is not valid!\n", op2);
        return 0;
    }

    if (ch != '=') {
        printf("please input '=' to compute!\n");
        return 0;
    }

    double temp, result;
    if (get_op_priority(op1) >= get_op_priority(op2)) {
        temp = compute(a, op1, b);
        result = compute(temp, op2, c);
    } else {
        temp = compute(b, op2, c);
        result = compute(a, op1, temp);
    }

    printf("result: %.2lf\n", result);
}

short get_op_priority(char op) {

    if (op == '+' || op == '-') {
        return 1;
    }

    if (op == '*' || op == '/') {
        return 2;
    }

    return 0;
}

short is_op(char op) {

    if (op == '+' || op == '-' || op == '*' || op == '/') {
        return 1;
    }

    return 0;
}

double compute(double a, char op, double b) {

    double result;

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }

    return result;
}
