#include<stdio.h>
#include<stdlib.h>

#define size 10  //size of queue is initialized to 10

int queue[size],front,rear,count;

int push(int);
int pop();
void display();

void main()
{
    int e,element,ch;
    front=rear=-1;
    count=0;

    printf("\tImplementation of Stack Using Queue\n");
    
    do{
        printf("\nStack Operations: \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
    
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1:
                
                if((rear+1)%size==front)
                    printf("\n   --> Stack Overflow, Cannot insert element\n");
                
                else
                {
                    printf("\n   Enter the element to be inserted: ");
                    scanf("%d",&element);
                    
                    push(element);
                    
                    printf("\n   --> Element %d is pushed to the stack\n",element);
                }
            break;
    
            case 2:
                
                if(count==0)
                    pop();
                    
                else if(count==1)
                {   
                    printf("\n   --> Element %d is popped from stack\n",queue[front]);
                    pop();
                }
                
                else
                {
                    for(int i=0;i<(count-1);i++)
                    {
                        e=pop();
                        push(e);
                    }
                    printf("\n   --> Element %d is popped from stack\n",queue[front]);
                    pop();
                }
            break;
    
            case 3:display();
            break;
    
            case 4:{
                    printf("\n   --> Exited the program\n");
                    exit(0);
                    }
    
            default:printf("\n   --> Invalid choice, Enter a valid choice\n");
        
        }

    }while(ch!=4);
}


int push(int item)
{
    if(front==-1)
    {
        front++;
    }   
    
    rear=(rear+1)%size;
    queue[rear]=item;    
    count++;    
    
}

int pop()
{
    int item;
    
    if(front==-1)
        printf("\n   --> Stack Underflow, Cannot pop element\n");

    else
    {
        item=queue[front];
        count--;
        
        if(front==rear)
        {
            front=rear=-1;
        }
        
        else
        {
            front=(front+1)%size;
        }
    }
    
    return(item);
}

void display()
{
    int t=rear;
    
    if(front==-1)
        printf("\n   --> Stack is empty\n");
    
    else
    {
        printf("\n   Elements in the stack: \n\n");
    
        while(t!=front)
        {
            printf("\t\t%d\n",queue[t]);
            
            if(t==0)
                t=size-1;
                
            else
                t=t-1;
                
        }
        printf("\t\t%d\n",queue[t]);
    }
    
}
