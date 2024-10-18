#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#define MAX 100

int top = -1;
char stack[MAX];

int isfull() {
    return top == MAX - 1;
}

int isempty() {
    return top == -1;
}

void push(char item) {
    if (isfull()) {
        printf("Overflow!\n");
    } else {
        stack[++top] = item;
        printf("Item %c added to the stack\n", item); 
    }
}

char pop() {
    if (isempty()) {
        printf("Underflow\n");
        return '\0'; 
    } else {
        return stack[top--]; 
    }
}

int prec(char op) {
    if (op == '/') {
        return 4;
    } else if (op == '*') {
        return 3;
    }else if(op == '+'){
        return 2;
    }else if(op == '-'){
        return 1;
    }
    return 0; 
}

void infixtopostfix(char* exp) {
    char postfix[MAX];
    int j = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        char token = exp[i];

        if (isalpha(token)) {
            postfix[j++] = token;
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!isempty() && prec(stack[top]) >= prec(token)) {
                postfix[j++] = pop(); 
            }
            push(token); 
        } else if (token == '(') {
            push(token); 
        } else if (token == ')') {
            while (!isempty() && stack[top] != '(') {
                postfix[j++] = pop(); 
            }
            pop(); 
        }
    }

    // Pop all 
    while (!isempty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate a+b(c-)
    
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixtopostfix(infix);
    return 0;
}
