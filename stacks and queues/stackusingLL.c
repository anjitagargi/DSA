#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* head= NULL;

void push(int value){
    struct node *newnode= malloc(sizeof(struct node));
     newnode->data= value;
     newnode->link= NULL;

     newnode->link=head;
     head = newnode;
}

int pop(){
 struct node* temp = head;
    head = head->link;
    free(temp);
}

void display(){
    struct node* temp = head;
    while(temp){
        printf("%d",temp->data);
        temp=temp->link;
    }
}

int main(){

    push(5);
    push(4);
    pop();
    display();
}