#include<stdio.h>
#define max 50
int queue[50];
int front=0,rear=0;

int enqueue(int data){
    queue[++rear]=data;
}

int dequeue(){
    if(front==0){
        return 0;
    }
  return queue[front--];
}

bool isFull(){
    if(rear== max-1)
    return true;

    else return false;
}
 
 bool isEmpty(){
    if(front<0 || front>rear){
        return true;

        else return false;
    }
 }

void display(){
    for(int i=0; i<=100 ; i++){
    printf("%d", queue[i]); 
    }
}

 int main(){
    enqueue(3);
    enqueue(4);
    dequeue();
    display();

 }