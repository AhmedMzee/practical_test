// Write a program to reverse a list of given numbers in stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

struct stack{
    int top;
    int s[size];
}st;


void push(int item){
    if(st.top==size-1){
        printf("Stack is full\n");
        return;
    }
    st.top++;
    st.s[st.top]=item;
}

int pop(){
    int item;
    if(st.top==-1){
        printf("Stack is empty\n");
        return 0;
    }
    item=st.s[st.top];
    st.top--;
    return item;
}

void display(){
    int i;
    if(st.top==-1){
        printf("Stack is empty\n");
        return;
    }
    for(i=st.top;i>=0;i--){
        printf("%d\n",st.s[i]);
    }
}

int main(){
    st.top=-1;
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        push(num);
    }
    printf("The elements in the stack are\n");
    display();
    printf("The elements in the stack after reversing are\n");
    for(i=0;i<n;i++){
        printf("%d\n",pop());
    }
    return 0;
}

