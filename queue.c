#include <stdio.h>
#include <stdlib.h>

#define size 3

struct queue
{
    int que[size];
    int rear, front;
}q;

int insert(int item)
{
    if(q.rear >= size-1)
    {
        printf("\n The Queue is full, cannot insert element");
    }
    else{
    (q.rear)++;
    q.que[q.rear]=item;
    }

}

int delete()
{
    if(q.front > q.rear)
    {
        printf("\n The Queue is empty, deletion is not possible");
    }
    else
    {
        int item;
        item = q.que[q.front];
        (q.front)++;
        printf("\nThe element deleted is %d",item);
    }
    if(q.front >  q.rear)
    {
        q.front=0;
        q.rear=-1;
    }
}

void display()
{
    int i;
    if(q.front>q.rear)
    {
        printf("\n Empty Queue !");
    }
    printf("\nThe queue contents are :");
    for(i=q.front;i<=q.rear;i++)
    {
        printf("%d ",q.que[i]);
    }
}

int main()
{
    int choice,i,item;
    q.rear=-1;
    q.front=0;

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
            case 1: printf("\nEnter the element:");
                    scanf("%d",&item);
                    insert(item);
                    display();
                    break;
            case 2: delete();
                    display();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);

            default: printf("\n Invalid choice");continue;
        }
    }
    return 0;
}

