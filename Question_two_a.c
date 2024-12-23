// Given a Queue Q, write a method that will find the max element in the queue. You
// may only use queue operations such as eneque, dequeue, size etc.. No other data
// structure can be used other than queues. Queue must remain intact after finding
// the max.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

struct queue{
    int front;
    int rear;
    int items[size];
}q;

void enque(int item){
    if(q.rear==size-1){
        printf("Queue is full\n");
        return;
    }
    q.items[++q.rear]=item;
}

int deque(){
    int item;
    if(q.front>q.rear){
        printf("Queue is empty\n");
        return 0;
    }
    item=q.items[q.front++];
    return item;
}

int queue_size(){
    return q.rear-q.front+1;
}

int max(){
    int max=q.items[q.front];
    for(int i=q.front+1;i<=q.rear;i++){
        if(q.items[i]>max){
            max=q.items[i];
        }
    }
    return max;
}

int main(){
    q.front=0;
    q.rear=-1;
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        enque(num);
    }
    printf("The max element in the queue is %d\n", max());
    printf("The size of the queue is %d\n", queue_size());
    return 0;
}
