#include <stdio.h>

double compute(double a, char op, double b);
short get_op_priority(char op);
short is_op(char op);
short is_divide_0(char op, double num);

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

        if (is_divide_0(op1, b)) {
            printf("a number divided by 0!\n");
            return 0;
        }

        temp = compute(a, op1, b);

        if (is_divide_0(op2, c)) {
            printf("a number divided by 0!\n");
            return 0;
        }

        result = compute(temp, op2, c);
    } else {

        if (is_divide_0(op2, c)) {
            printf("a number divided by 0!\n");
            return 0;
        }

        temp = compute(b, op2, c);

        if (is_divide_0(op1, temp)) {
            printf("a number divided by 0!\n");
            return 0;
        }

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

short is_divide_0(char op, double num) {

    if (op == '/' && num == 0) {
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
