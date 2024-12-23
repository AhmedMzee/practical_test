//Write a program to implement a stack that stores names and age of students in the
// class.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

struct stack{
    int top;
    char name[size][20];
    int age[size];
}st;

void push(char name[], int age){
    if(st.top==size-1){
        printf("Stack is full\n");
        return;
    }
    st.top++;
    strcpy(st.name[st.top], name);
    st.age[st.top] = age;
}

void pop(){
    if(st.top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("Name: %s\n", st.name[st.top]);
    printf("Age: %d\n", st.age[st.top]);
    st.top--;
}

void display(){
    int i;
    if(st.top==-1){
        printf("Stack is empty\n");
        return;
    }
    for(i=st.top;i>=0;i--){
        printf("Name: %s\n", st.name[i]);
        printf("Age: %d\n", st.age[i]);
    }
}

int main(){
    st.top=-1;
    int n,i;
    printf("Enter the number of students\n");
    scanf("%d",&n);
    printf("Enter the names and ages of the students\n");
    for(i=0;i<n;i++){
        char name[20];
        int age;
        scanf("%s %d",name,&age);
        push(name, age);
    }
    printf("The students in the stack are\n");
    display();
    printf("The students in the stack after popping are\n");
    for(i=0;i<n;i++){
        pop();
    }
    return 0;
}