#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createList(int n);
void insertNodeInBeginning(int data);
void insertNodeAtMiddle(int data, int position);
void insertNodeAtEnd(int data);
void deleteFirstNode();
void deleteMiddleNode(int position);
int  search(int key);
void deleteLastNode();
void displayList();


int main()
{
    int n,j,data,c,position,key,x,y;

    printf("Enter the total number of nodes in the list(initially): ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list before insertion/deletion: \n");
    displayList();
    x=1;
    while(x==1)
    {
    printf("Enter 1 for insertion and 2 for deletion: ");
    scanf("%d",&y);

    if(y==1)
    {
    printf("\nEnter data to insert: ");
    scanf("%d", &data);

    printf("\nEnter the required option for insertion \n1.In the beginning \n2.In the middle \n3.In the end \n4.By data \n ");
    scanf("%d",&c);

    switch(c)
    {
    case 1 :
        insertNodeAtBeginning(data);
        break;
    case 2 :
        printf("\nEnter the position to insert new node: " );
        scanf("%d", &position);
        insertNodeAtMiddle(data, position);
        break;
    case 3:
        insertNodeAtEnd(data);
        break;
    case 4:
        printf("\nEnter the data and the option required \n1.Before \n2.After \n");
        scanf("%d %d",&key,&j);
        position=search(key);
        if (position >= 0)
        {
            position =position+1;
            if(j==2)
            position=position+1;
            insertNodeAtMiddle(data, position);
        }
        else
            printf("%d not found in the list.\n", key);
        break;
    }

    printf("\nData in the list after the insertion \n");
    displayList();

    printf("\n------18BCE0559------ \nEnter 1 if you want to start or continue the process else 0: ");
    scanf("%d",&x);
    }
    else
    {
    printf("\nEnter the required option for deletion \n1.In the beginning \n2.In the middle \n3.In the end \n4.By data \n ");
    scanf("%d",&c);

    switch(c)
    {
    case 1 :
        deleteFirstNode();
        break;
    case 2 :
        printf("\nEnter the position to delete the node: " );
        scanf("%d", &position);
        deleteMiddleNode(position);
        break;
    case 3:
        deleteLastNode();
        break;
    case 4:
        printf("\nEnter the data and the option required \n1.Before \n2.After \n");
        scanf("%d %d",&key,&j);
        position=search(key);
        if (position >= 0)
        {
            if(j==2)
            position=position+2;
            deleteMiddleNode(position);
        }
        else
            printf("%d not found in the list.\n", key);
        break;
    }

    printf("\nData in the list after the deletion \n");
    displayList();

    printf("\n------18BCE0559------ \nEnter 1 if you want to start or continue the process else 0: ");
    scanf("%d",&x);
    }
    }
    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;

                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;

        head = newNode;

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;

        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}

void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

int search(int key)
{
    int index;
    struct node *curNode;

    index = 0;
    curNode = head;

    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }


    return (curNode != NULL) ? index : -1;
}

void deleteFirstNode()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}

void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {

            secondLastNode->next = NULL;
        }


        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}

void displayList()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        }
    }
}
