#include <stdio.h>

double compute(double a, char op, double b);
short get_op_priority(char op);
short is_op(char op);
short is_divide_0(char op, double num);

int main(void) {

    double a = 0.0, b, c;
    double result;
    char op1 = '+', op2, ch;

    scanf("%lf", &b);

    while (ch = getchar()) {

        if (ch == '=') {

            if (is_divide_0(op1, b)) {
                printf("a number divided by 0!\n");
                return 0;
            }

            result = compute(a, op1, b);
            printf("result: %.2lf\n", result);
            return 0;
        } else if (is_op(ch)) {

            op2 = ch;
            scanf("%lf", &c);

            if (get_op_priority(op1) >= get_op_priority(op2)) {

                if (is_divide_0(op1, b)) {
                    printf("a number divided by 0!\n");
                    return 0;
                }

                a = compute(a, op1, b);
                op1 = op2;
                b = c;
            } else {

                if (is_divide_0(op2, c)) {
                    printf("a number divided by 0!\n");
                    return 0;
                }

                b = compute(b, op2, c);
            }
        } else if (ch != ' ') {

            printf("invalid op or input '=' to compute!\n");
            return 0;
        }
    }
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
