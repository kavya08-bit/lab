#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow.\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop(void) {
    if (top < 0) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    return stack[top--];
}

char peek(void) {
    if (top < 0) {
        return -1;
    }
    return stack[top];
}

int isEmpty(void) {
    return top == -1;
}

void str_rev(char* str) {
    int len = strlen(str);
    int i = 0;
    int j = len - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void reverseAndSwapParentheses(char* input, char* output) {
    int len = strlen(input);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (input[i] == '(') {
            output[j++] = ')';
        } else if (input[i] == ')') {
            output[j++] = '(';
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0;
    int j = 0;
    char c, temp;

    while ((c = infix[i++]) != '\0') {
        
        if (isalnum(c)) {
            postfix[j++] = c;
        } 
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && (temp = peek()) != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop();
            }
        }
        else {
            while (!isEmpty() && peek() != '(' && 
                   (precedence(peek()) > precedence(c) || 
                   (precedence(peek()) == precedence(c) && c != '^'))) {
                
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}


int main() {
    char infix[MAX];
    char reversed_infix[MAX];
    char temp_postfix[MAX];
    char prefix[MAX];

    printf("Enter an infix expression: ");
    if (fgets(infix, MAX, stdin) != NULL) {
        
        infix[strcspn(infix, "\n")] = 0;

        reverseAndSwapParentheses(infix, reversed_infix);
        
        infixToPostfix(reversed_infix, temp_postfix);

        strcpy(prefix, temp_postfix);
        str_rev(prefix);

        printf("Infix Expression:   %s\n", infix);
        printf("Prefix Expression:  %s\n", prefix);
    }

    return 0;
}