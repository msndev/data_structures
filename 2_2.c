#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CAPACITY 10000

struct Node {
    int data;
    struct Node* link;
};
struct Node* top;

int size = 0;

void push(int data);
void  pop();
int isEmpty();
int isFull();
void display();
int peek();

void push(int data)
{
    // create new node temp and allocate memory
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    // check if stack (heap) is full. Then inserting an element would
    // lead to stack overflow
    if (!temp) {
        printf("\nHeap Overflow");
    }

    // initialize data into temp data field
    temp->data = data;

    // put top pointer reference into temp link
    temp->link = top;

    // make temp as top of Stack
    top = temp;
}

// Utility function to check if the stack is empty or not
int isEmpty()
{
    return top == NULL;
}

// Utility function to return top element in a stack
int peek()
{
    // check for empty stack
    if (!isEmpty(top))
        return top->data;
    else
        exit(EXIT_FAILURE);
}

// Utility function to pop top element from the stack

void pop()
{
    struct Node* temp;

    // check for stack underflow
    if (top == NULL) {
        printf("\nStack Underflow");
    }
    else {
        // top assign into temp
        temp = top;

        // assign second node to top
        top = top->link;

        // destroy connection between first and second
        temp->link = NULL;

        // release memory of top node
        free(temp);
    }
}

void display() // remove at the beginning
{
    struct Node* temp;

    // check for stack underflow
    if (top == NULL) {
        printf("\nStack Underflow");
    }
    else {
        temp = top;
        while (temp != NULL) {

            // print node data
            printf("%d->", temp->data);

            // assign temp link to temp
            temp = temp->link;
        }
    }
}

int isFull()
{

    return size>=CAPACITY;
}


int main()
{
    int choice, data,x;

    while(1)
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
                break;

            case 2:
                pop();
                break;

             case 3:
                x=isFull();
                if(x==1)
                {
                    printf("Stack is full");
                    dispaly();
                }
                else
                {
                    printf("Stack is not full yet");
                    display();
                }
                break;

            case 4:
                x=isEmpty();
                if(x==1)
                    printf("Stack is empty");
                else
                {
                    printf("Stack is not empty");
                    display();
                }
                break;

            case 5:
                x=peek();
                printf("The topmost element is %d",x);
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

        printf("\n\n");
    }


    return 0;
}
