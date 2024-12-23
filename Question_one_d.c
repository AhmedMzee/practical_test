// Write a program to input two stacks and compare their contents

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

struct stack{
    int top;
    int s[size];
}st1, st2;

void push(struct stack *st, int item){
    if(st->top==size-1){
        printf("Stack is full\n");
        return;
    }
    st->top++;
    st->s[st->top]=item;
}

int pop(struct stack *st){
    int item;
    if(st->top==-1){
        printf("Stack is empty\n");
        return 0;
    }
    item=st->s[st->top];
    st->top--;
    return item;
}

void display(struct stack *st){
    int i;
    if(st->top==-1){
        printf("Stack is empty\n");
        return;
    }
    for(i=st->top;i>=0;i--){
        printf("%d\n",st->s[i]);
    }
}

int main(){
    st1.top=-1;
    st2.top=-1;
    int n,i;
    printf("Enter the number of elements in stack 1\n");
    scanf("%d",&n);
    printf("Enter the elements in stack 1\n");
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        push(&st1, num);
    }
    printf("Enter the number of elements in stack 2\n");
    scanf("%d",&n);
    printf("Enter the elements in stack 2\n");
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        push(&st2, num);
    }
    printf("The elements in stack 1 are\n");
    display(&st1);
    printf("The elements in stack 2 are\n");
    display(&st2);
    if(st1.top!=st2.top){
        printf("The stacks are not equal\n");
        return 0;
    }
    for(i=0;i<=st1.top;i++){
        if(st1.s[i]!=st2.s[i]){
            printf("The stacks are not equal\n");
            return 0;
        }
    }
    printf("The stacks are equal\n");
    return 0;
}

