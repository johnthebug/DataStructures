#include <stdio.h>
#include <stdlib.h>

#define size 5

struct queue 
{
    int rear,front;
    int que[size];
}q;

void insert_rear(int item)
{
    if(q.rear==size-1)
    {
        printf("\n Queue is full");
    }
    else
    {
        q.rear++;
        q.que[q.rear]=item;
    }
}

void delete_front()
{
    int item;
    if(q.front>q.rear)
    {
        printf("\n Queue is full");
    }
    item=q.que[q.front];
    q.front++;
    printf("\n The element deleted is %d",item);
    if(q.front>q.rear)
    {
        q.front=0;
        q.rear=-1;
    }
    
}
void insert_front(int item)
{
    if(q.front==0 && q.rear!=0)
    {
        printf("\n insertion at front is not possible");
    }
    else if(q.front==0 && q.rear ==size-1)
    {
        printf("\n Queue is full");
    }
    else
    {
    if(q.front==0 && q.rear==-1)//insertion for first time 
    {
        q.rear++;
        q.que[q.front]=item;
    }
    else
    {
        q.front--;
        q.que[q.front]=item;
    }
    }
}

void delete_rear()
{
    if(q.rear==-1)
    {
        printf("\n Queue is empty");
    }
    else if(q.front>q.rear)
    {
        printf("\n Queue is empty");
        q.front=0;
        q.rear=-1;
    }
    else
    {
        int item;
        item=q.que[q.rear];
        q.rear--;
        printf("\n The content deleted is %d",item);
    }
}

void display()
{
    if(q.front>q.rear)
    {
        printf("\n Queue is empty !");
    }
    else
    {
        int i;
        printf("\n The elements are:\n");
        for(i=q.front;i<=q.rear;i++)
        {
            printf("%d\t",q.que[i]);
        }
    }
}

int main()
{
    int choice, i, item;
    q.rear=-1;
    q.front=0;
    for(;;)
    {
        printf("\n Enter 1 to insert at rear end \n Enter 2 to insert at front end\n Enter 3 to delete at front end\n Enter 4 to delete at rear end\n Enter 5 to display\n Enter 6 to exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n Enter the element:");
                    scanf("%d",&item);
                    insert_rear(item);
                    display();
                    break;
            case 2: printf("\n Enter the element:");
                    scanf("%d",&item);
                    insert_front(item);
                    display();
                    break;
            case 3: delete_front();
                    display();
                    break;
            case 4: delete_rear();
                    display();
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
            default: printf("\n Invalid Choice !");continue;
        }
    }      
    return 0;
}







