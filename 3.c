#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define CAPACITY 100    // Queue max capacity


typedef struct node
{
    int data;
    struct node * next;
} Queue;    // Queue is a typedef of struct node

/* Queue size */
unsigned int size = 0;


int enqueue(Queue ** rear, Queue ** front, int data);
int dequeue(Queue ** front);
int getRear(Queue * rear);
void display(Queue * rear);

int getFront(Queue * front);
int isEmpty();
int isFull();


int main()
{
    int ch, data;
    Queue *rear, *front;

    rear  = NULL;
    front = NULL;

    /* Run indefinitely until user manually terminates */
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Get Rear\n");
        printf("5. Get Front\n");
        printf("6. Display\n");

        printf("0. Exit\n");
        printf("Select an option: ");

        scanf("%d", &ch);


        /* Menu control switch */
        switch (ch)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);

                // Enqueue function returns 1 on success
                // otherwise 0
                if (enqueue(&rear, &front, data))
                    printf("Element added to queue.");
                else
                    printf("Queue is full.");

                break;

            case 2:
                data = dequeue(&front);

                // on success dequeue returns element removed
                // otherwise returns INT_MIN
                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);

                break;

            case 3:

                // isEmpty() function returns 1 if queue is emtpy
                // otherwise returns 0
                if (isEmpty())
                    printf("Queue is empty.");
                else
                    printf("Queue size => %d", size);

                break;

            case 4:
                data = getRear(rear);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Rear => %d", data);

                break;

            case 5:

                data = getFront(front);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Front => %d", data);

                break;

            case 6:
                display(rear);
                break;

            case 0:
                printf("Exiting from app.\n");
                exit(0);

            default:
                printf("Invalid choice, please input number between (0-5).");
                break;
        }

        printf("\n\n18BCE0559\n");
    }
}




int enqueue(Queue ** rear, Queue ** front, int data)
{
    Queue * newNode = NULL;

    // Check queue out of capacity error
    if (isFull())
    {
        return 0;
    }

    // Create a new node of queue type
    newNode = (Queue *) malloc (sizeof(Queue));

    // Assign data to new node
    newNode->data = data;

    // Initially new node does not point anything
    newNode->next = NULL;

    // Link new node with existing last node
    if ( (*rear) )
    {
        (*rear)->next = newNode;
    }


    // Make sure newly created node is at rear
    *rear = newNode;

    // Link first node to front if its NULL
    if ( !( *front) )
    {
        *front = *rear;
    }

    // Increment quque size
    size++;

    return 1;
}



int dequeue(Queue ** front)
{
    Queue *toDequque = NULL;
    int data = INT_MIN;

    if (isEmpty())
    {
        return INT_MIN;
    }

    toDequque = *front;
    data = toDequque->data;

    *front = (*front)->next;

    size--;

    free(toDequque);

    return data;
}



int getRear(Queue * rear)
{
    return (isEmpty())
            ? INT_MIN
            : rear->data;
}



int getFront(Queue * front)
{

    return (isEmpty())
            ? INT_MIN
            : front->data;
}



int isEmpty()
{
    return (size <= 0);
}



int isFull()
{
    return (size > CAPACITY);
}

void display(Queue ** front)
{
    Queue *toDequque = NULL;
    int data = INT_MIN;

    if (isEmpty())
    {
        return INT_MIN;
    }

    toDequque = *front;
    data = toDequque->data;
    printf("%d",&data);
    *front = (*front)->next;

    size--;

    free(toDequque);

}



