#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CAPACITY 10000

struct stack
{
    int data;
    struct stack *next;
} *top;
int size = 0;

void push(int element);
int  pop();
int isEmpty();
int isFull();
void display();
int peek();

int main()
{
    int choice,y=1,data,x;


    while(y==1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. isFull\n");
        printf("4. isEmpty\n");
        printf("5. Peek\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to push into stack: ");
                scanf("%d", &data);
                push(data);
                display();
                break;

            case 2:
                data = pop();
                if (data != INT_MIN)
                    printf("Data => %d\n", data);
                display();
                break;

             case 3:
                x=isFull();
                if(x==1)
                {
                    printf("\nStack is full");
                }
                else
                {
                    printf("\nStack is not full yet\n");
                }
                display();
                break;

            case 4:
                x=isEmpty();
                if(x==1)
                    printf("\nStack is empty");
                else
                {
                    printf("\nStack is not empty\n");
                }
                display();
                break;

            case 5:
                x=peek();
                printf("\nThe topmost element is %d",x);
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting from app.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\n-----18BCE0559-----\nIf you want to continue press 1 or else 0: ");
        scanf("%d",&y);
    }


    return 0;
}


void push(int element)
{
    if (size >= CAPACITY)
    {
        printf("Stack Overflow, can't add more element to stack.\n");
        return;
    }

    struct stack * newNode = (struct stack *) malloc(sizeof(struct stack));

    newNode->data = element;
    newNode->next = top;
    top = newNode;
    size++;

    printf("Data pushed to stack.\n");
}


int pop()
{
    int data = 0;
    struct stack * topNode;
    if (size <= 0 || !top)
    {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    topNode = top;
    data = top->data;
    top = top->next;
    free(topNode);
    size--;
    return data;
}

int isEmpty()
{
    return top == NULL;
}

int peek()
{
    if (!isEmpty(top))
        return top->data;
    else
        exit(EXIT_FAILURE);
}

void display()
{
    struct stack* temp;
    if (top == NULL)
    {
        printf("\nStack Underflow");
    }
    else {
        temp = top;
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
    }
}

int isFull()
{

    return size>=CAPACITY;
}

