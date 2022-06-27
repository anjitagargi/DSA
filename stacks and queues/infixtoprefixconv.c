//  INfix to POSTfix


#include<stdio.h>
#include<stdlib.h>

#define max 20       // defining the number of elements


char stack_arr[max];
int first = -1;


// PUSH in stacks

void push(char data){
    first += 1;
    for(int i = first; i>0; i--){
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;
}


// POP in stacks

int pop(){
    int i, value;
    value = stack_arr[0];
    for(int i = 0; i < first; i++){
        stack_arr[i] = stack_arr[i+1];
    }
    first -= 1;
    return value;
}


// Priority function

int priority(char data){            // to tell the priority of operands.
    if(data == '('){
        return 0;
    }
    if(data == '+' || data == '-'){
        return 1;
    }
    if(data == '*' || data == '/'){
        return 2;
    }
    if(data == '^'){
        return 3;
    }
}


// func isalnum == alpha(a,b,c..)numeric(1,2,3..) checks the exp 

int isalphanum(char data){
    if((data >= '0' && data <= '9') || (data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z') ){
        return 1;
    }
    else return 0;
}



// Main function


int main(){
    int n;
    printf("Enter the length of expression : \n");
    scanf("%d", &n);
    char expr[n], data;
    
    printf("Enter the expression : \n");
    for(int i = 0;i< n; i++){
        scanf("%c", &expr[i]);
    }
    
    printf("POSTfix expression : \n");
    
    for(int i=0;i<n; i++){
        if(isalphanum(expr[i])==1){          
            printf("%c", expr[i]);
        }
        
        else if(expr[i] == '('){
            push(expr[i]);
        }
        
        else if(expr[i] == ')'){
            while((data = pop()) != '('){
                printf("%c",data);
            }
        }
        
        else{
            while(priority(stack_arr[0]) > priority(expr[i])){
                printf("%c",pop());
            }
            push(expr[i]);
        }
    }
    
    // Printing the rest characters in stack
    
    for(int i  = 0; i<n;i++){
        if(stack_arr[i] != '(' && stack_arr[i] != ')'){
            printf("%c", stack_arr[i]);
        }
    }
}