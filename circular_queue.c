#include <stdio.h>
#include <stdlib.h>

#define size 5

struct queue
{
    int que[size];
    int rear,front;
    int count;
}q;

void insert(item)
{
    if(q.count==size)
    {
        printf("\n The Queue is full");
    }
    else
    {
        q.rear=((q.rear+1)%size);
        q.que[q.rear]=item;
        q.count++;
    }

}

void delete()
{
    if(q.count==0)
    {
        printf("\n Queue is empty");
    }
    else
    {
        int item;
        item=q.que[q.front];
        q.front=((q.front+1)%size);
        q.count--;

    }
    if(q.count==0)
    {
        q.front=0;
        q.rear=-1;
    }

}

void display()
{
    if(q.count==0)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\n The queue contents are: \n");
        int i,j;
        i=q.front;//use front pointer  as the front pointer is always before rear pointer unless it is empty
        for(j=1;j<=q.count;j++) //use j to iterate the number of times eq to the number of elements (count)
        {
            printf(" %d",q.que[i]);
            i=(i+1)%size; //use this way to move to next place as it is circular queue
        }
    }
}


int main()
{
    int choice, i , item;
    q.rear=-1;
    q.front=0;
    q.count=0;

    for(;;)
    {
        printf("\n Enter 1 to insert");
        printf("\n Enter 2 to delete");
        printf("\n Enter 3 to display");
        printf("\n Enter 4 to exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter the element to insert: ");
                    scanf("%d",&item);
                    insert(item);
                    display();
                    break;
            case 2: delete();
                    display();
                    break;
            case 3:display();
                    break;
            case 4: exit(0);
                    break;
            default:printf("\n Invalid choice !");continue;
        }


    }

    return 0;

}
