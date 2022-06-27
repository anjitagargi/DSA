#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10

int pqueue[MAX]; 
int front, rear; 
void create_queue() 
{ 
    front = rear = -1; 
}  
void insert_element(int data) 
{ 
    if (rear >= MAX - 1) 
    { 
        printf("\nQUEUE OVERFLOW"); 
        return; 
    } 
    if ((front == -1) && (rear == -1)) 
    { 
        front++; 
        rear++; 
        pqueue[rear] = data; 
        return; 
    }    
    else 
        check_priority(data); 
    rear++; 
}  
void check_priority(int data) 
{ 
    int i,j;  
    for (i = 0; i <= rear; i++) 
    { 
        if (data >= pqueue[i]) 
        { 
            for (j = rear + 1; j > i; j--) 
            { 
                pqueue[j] = pqueue[j - 1]; 
            } 
            pqueue[i] = data; 
            return; 
        } 
    } 
    pqueue[i] = data; 
}  
void delete_element(int data)  
{ 
    int i;  
    if ((front==-1) && (rear==-1)) 
    { 
        printf("\nEmpty Queue"); 
        return; 
    }  
    for (i = 0; i <= rear; i++) 
    { 
        if (data == pqueue[i]) 
        { 
            for (; i < rear; i++) 
            { 
                pqueue[i] = pqueue[i + 1]; 
            } 
            pqueue[i] = -99; 
            rear--; 
            if (rear == -1) 
               front = -1; 
            return; 
        } 
    } 
    printf("\n%d element not found in queue", data); 
} 
void display_priorityqueue() 
{ 
    if ((front == -1) && (rear == -1)) 
    { 
        printf("\nEmpty Queue "); 
        return; 
    }  
    for (; front <= rear; front++) 
    { 
        printf(" %d ", pqueue[front]); 
    } 
     front = 0; 
} 