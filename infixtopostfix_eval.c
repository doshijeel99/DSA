#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

char infix[MAX_SIZE], postfix[MAX_SIZE], stack[MAX_SIZE];
int top = -1;

void push(char a) {
    stack[++top] = a;
}

char pop() {
    return stack[top--];
}

int priority(char a) {
    if (a == '%' || a == '^') return 3;
    if (a == '*' || a == '/') return 2;
    if (a == '+' || a == '-') return 1;
    return 0;
}

void infixToPost() {
    int i = 0, j = 0;
    char x, y;

    while (infix[i] != '\0') {
        x = infix[i];

        if (isalpha(x) || isdigit(x)) {
            postfix[j++] = x;
        } else if (x == '(') {
            push(x);
        } else if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^' || x == '%') {
            while (top != -1 && (priority(x) <= priority(stack[top]))) {
                y = pop();
                postfix[j++] = y;
            }
            push(x);
        } else if (x == ')') {
            y = pop();
            while (y != '(') {
                postfix[j++] = y;
                y = pop();
            }
        } else {
            printf("Expression not correct!\n");
            return;
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void evaluate() {
    char x;
    float op2, op1, result;
    int i = 0;

    while (postfix[i] != '\0') {
        x = postfix[i];

        if (isalpha(x) || isdigit(x)) {
            push(x - '0');
        } else if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%') {
            op2 = pop();
            op1 = pop();

            switch (x) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = (int)op1 % (int)op2; break;
            }

            push(result);
        }

        i++;
    }

    printf("\nResult: %d\n", stack[top]);
}

int main() {
    printf("Enter the infix expression:\n");
    scanf("%s", infix);

    printf("Infix Statement:\n%s\n", infix);
    infixToPost();

    printf("Postfix Statement:\n%s\n", postfix);
    evaluate();
    
    return 0;
}
