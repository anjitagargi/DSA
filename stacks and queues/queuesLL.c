#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

int enqueue(int value){
     struct node *newnode = malloc(sizeof(struct node));
     newnode->data = value;
     newnode->link = NULL;

     if(front == NULL && rear == NULL)
        front = rear = newnode;
    else{
    rear->link = newnode;
    rear = newnode;
    }
}

int dequeue(){
    struct node *temp= front;
    front= front->link;
    free(temp);

}

void display(){
    if(front== NULL)
    printf("queue is empty");

    else{
        while(front){
            printf("%d",front->data);
            front= front->link;

        }
    }
}

int main(){

     enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Queue :");
    display();
    dequeue();
    printf("After dequeue the new Queue :");
    
    dequeue();
    printf("After dequeue the new Queue :");


    return 0;
}