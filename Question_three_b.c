// Write a program to merge two linked lists.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
}*head1=NULL, *head2=NULL;

void insert1(int item){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->next=NULL;
    if(head1==NULL){
        head1=new_node;
    }else{
        struct node *temp=head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

void insert2(int item){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->next=NULL;
    if(head2==NULL){
        head2=new_node;
    }else{
        struct node *temp=head2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

void merge(){
    struct node *temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
}

void display(){
    struct node *temp=head1;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int n,i;
    printf("Enter the number of elements in list 1\n");
    scanf("%d",&n);
    printf("Enter the elements in list 1\n");
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        insert1(num);
    }
    printf("Enter the number of elements in list 2\n");
    scanf("%d",&n);
    printf("Enter the elements in list 2\n");
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        insert2(num);
    }
    merge();
    printf("The merged list is\n");
    display();
    return 0;
}

