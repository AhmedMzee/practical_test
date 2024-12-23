// Write a program to check nesting of parentheses using a stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

struct stack{
    int top;
    char s[size];
}st;

void push(char element) {
    if (st.top == size - 1) {
        printf("Stack overflow\n");
    } else {
        st.s[++st.top] = element;
    }
}

char pop() {
    if (st.top == -1) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return st.s[st.top--];
    }
}

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int checkParentheses(char exp[]) {
    st.top = -1;
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (st.top == -1) {
                return 0;
            } else if (!isMatchingPair(pop(), exp[i])) {
                return 0;
            }
        }
    }
    if (st.top == -1)
        return 1; 
    else
        return 0; 
}

int main() {
    char exp[size];
    printf("Enter an expression: ");
    gets(exp);

    if (checkParentheses(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}

