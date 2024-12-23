// Write a program to implement a dequeue with the help of a linked list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
}*front=NULL, *rear=NULL;

void enque_front(int item){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(front==NULL){
        front=new_node;
        rear=new_node;
    }else{
        new_node->next=front;
        front->prev=new_node;
        front=new_node;
    }
}

void enque_rear(int item){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(rear==NULL){
        front=new_node;
        rear=new_node;
    }else{
        rear->next=new_node;
        new_node->prev=rear;
        rear=new_node;
    }
}

int deque_front(){
    int item;
    if(front==NULL){
        printf("Queue is empty\n");
        return 0;
    }
    item=front->data;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }else{
        front->prev=NULL;
    }
    return item;
}

int deque_rear(){
    int item;
    if(rear==NULL){
        printf("Queue is empty\n");
        return 0;
    }
    item=rear->data;
    rear=rear->prev;
    if(rear==NULL){
        front=NULL;
    }else{
        rear->next=NULL;
    }
    return item;
}

int queue_size(){
    int count=0;
    struct node *temp=front;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int max(){
    int max=front->data;
    struct node *temp=front->next;
    while(temp!=NULL){
        if(temp->data>max){
            max=temp->data;
        }
        temp=temp->next;
    }
    return max;
}

int main(){
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        enque_rear(num);
    }
    printf("The max element in the queue is %d\n", max());
    printf("The size of the queue is %d\n", queue_size());
    return 0;
}

