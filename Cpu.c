
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CPU
{
    int priority;
    char device[20];
    struct CPU *next;
}cp;


struct Stack
{
    int data;
    struct Stack *next;
}st;


struct Node
{
    int data;
    struct Node *next;
}nd;


void insertStack(struct Stack **top, int data)
{
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    if (!newNode)
    {
        printf("Memory Error\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void infixToPostfix(char *infix, char *postfix)
{
    struct Stack *stack = NULL;
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            insertStack(&stack, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (stack != NULL && stack->data != '(')
            {
                postfix[j++] = stack->data;
                stack = stack->next;
            }
            stack = stack->next;
            i++;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            insertStack(&stack, infix[i]);
            i++;
        }
        else
        {
            postfix[j++] = infix[i];
            i++;
        }
    }
    postfix[j] = '\0';
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory Error\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory Error\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}


void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    
    struct CPU *head = NULL;
    struct CPU *newNode = (struct CPU *)malloc(sizeof(struct CPU));
    newNode->priority = 1;
    strcpy(newNode->device, "Keyboard");
    newNode->next = head;
    head = newNode;

    newNode = (struct CPU *)malloc(sizeof(struct CPU));
    newNode->priority = 2;
    strcpy(newNode->device, "Mouse");
    newNode->next = head;
    head = newNode;

    newNode = (struct CPU *)malloc(sizeof(struct CPU));
    newNode->priority = 3;
    strcpy(newNode->device, "Scanner");
    newNode->next = head;
    head = newNode;

    newNode = (struct CPU *)malloc(sizeof(struct CPU));
    newNode->priority = 4;
    strcpy(newNode->device, "Printer");
    newNode->next = head;
    head = newNode;

    struct CPU *temp = head;
    while (temp != NULL)
    {
        printf("Priority: %d, Device: %s\n", temp->priority, temp->device);
        temp = temp->next;
    }


    struct Stack *top = NULL;
    insertStack(&top, 1);
    insertStack(&top, 2);
    insertStack(&top, 3);
    insertStack(&top, 4);
    insertStack(&top, 5);

    struct Stack *tempStack = top;
    while (tempStack != NULL)
    {
        printf("%d -> ", tempStack->data);
        tempStack = tempStack->next;
    }
    printf("NULL\n");

 
    char infix[20] = "((a+b)^((c/d)*e))";
    char postfix[20];
    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);


    struct Node *headNode = NULL;
    insertAtBeginning(&headNode, 1);
    insertAtBeginning(&headNode, 2);
    insertAtBeginning(&headNode, 3);
    insertAtBeginning(&headNode, 4);
    insertAtBeginning(&headNode, 5);
    display(headNode);

    insertAtEnd(&headNode, 6);
    insertAtEnd(&headNode   , 7);
 
    insertAtEnd(&headNode, 8);
    insertAtEnd(&headNode, 9);
    insertAtEnd(&headNode, 10);
    display(headNode);

    return 0;
}

