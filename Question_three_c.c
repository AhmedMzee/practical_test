// Given a linked list sorted in increasing order, write a function that removes
// duplicate nodes from it by traversing the list only once. For example, the list {1, 2,
// 2, 2, 3, 4, 4, 5} should be converted into the list {1, 2, 3, 4, 5}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
}*head=NULL;

void insert(int item){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
    }else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

void remove_duplicates(){
    struct node *temp=head;
    while(temp!=NULL){
        struct node *temp1=temp;
        while(temp1->next!=NULL){
            if(temp1->next->data==temp->data){
                struct node *temp2=temp1->next;
                temp1->next=temp1->next->next;
                free(temp2);
            }else{
                temp1=temp1->next;
            }
        }
        temp=temp->next;
    }
}

void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        insert(num);
    }
    printf("The elements in the list are\n");
    display();
    remove_duplicates();
    printf("The elements in the list after removing duplicates are\n");
    display();
    return 0;
}

