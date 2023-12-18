#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c =='^');
}

// Function to determine the precedence of an operator
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c =='^')
        return 3;
    return 0;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char stack[MAX_SIZE];
    int top = 0;
    stack[top]= '(';

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            stack[++top] = token;
        } else if (token == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--; // Pop the '(' from the stack
            }
        } else if (isOperator(token)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = token;
        }
    }



    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
