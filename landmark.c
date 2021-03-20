#include<stdio.h>
#include <stdlib.h>

char a[5][5]={'W','W','W','W','W','W','L','L','L','W','W','L','W','L','W','W','L','L','L','W','W','W','W','W','W'};

struct node
{
    int data_x,data_y;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;
int visited [5][5]={0};

void enqueue(int x,int y)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data_x=x;
    temp->data_y=y;
    if(rear == NULL)
    {   
        temp->next=NULL;
        front = rear = temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

struct node* dequeue()
{
    struct node *t=front;
    if(front == rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
        front=front->next;
    return t;
}

int isempty()
{
    if(front==NULL || rear==NULL)
        return 1;
    return 0;
}

void BST(struct node *root)
{
    if(root==NULL)
        return;
    visited[root->data_x][root->data_y]=1;
    enqueue(root->data_x,root->data_y);
    while(!isempty())
    {
        struct node *v=dequeue();
        int i=v->data_x;
        int j=v->data_y;
        visited[i][j]=1;
        
        if(i+1 < 5)
            if(visited[i+1][j]==0 && a[i+1][j]=='W')
                enqueue(i+1,j);
        if(i-1 >= 0)
            if(visited[i-1][j]==0 && a[i-1][j]=='W')
                enqueue(i-1,j);
        if(j-1 >= 0)
            if(visited[i][j-1]==0 && a[i][j-1]=='W')
                enqueue(i,j-1);
        if(j+1 < 5)
            if(visited[i][j+1]==0 && a[i][j+1]=='W')
                enqueue(i,j+1);
    }
}

int BST_landmark(struct node *root)
{
    int count=0;
    if(root==NULL)
        return 0;
    visited[root->data_x][root->data_y]=1;
    enqueue(root->data_x,root->data_y);
    count++;
    while(!isempty())
    {
        struct node *v=dequeue();
        int i=v->data_x;
        int j=v->data_y;
        
        if(i+1 < 5)
            if(visited[i+1][j]==0)
            {
                enqueue(i+1,j);
                visited[i+1][j]=1;
                count++;
            }
        if(i-1 >= 0)
            if(visited[i-1][j]==0)
            {
                enqueue(i-1,j);
                visited[i-1][j]=1;
                count++;
            }
        if(j-1 >= 0)
            if(visited[i][j-1]==0)
            {    
                enqueue(i,j-1);
                visited[i][j-1]=1;
                count++;
            }
        if(j+1 < 5)
            if(visited[i][j+1]==0)
            {
                enqueue(i,j+1);
                visited[i][j+1]=1;
                count++;
            }
    }
    return count;
}

int main()
{
    int i=0,j=0;
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->next=NULL;
    printf("\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%c ",a[i][j]);
        printf("\n");
    }
    printf("\n");

    //seperating outside and inner water
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(a[i][j]=='W')
            {
                root->data_x=i;
                root->data_y=j;
                BST(root);
                i=5;
                break;
            }
        }
    }

    //looking for largest landmark
    int area=0,max_area=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(!visited[i][j])
            {
                root->data_x=i;
                root->data_y=j;
                area=BST_landmark(root);
            }
            if(area>max_area)
                max_area=area;
        }
    }
    printf("Largest landmark size: %d units\n\n",max_area);

    return 0;
}
