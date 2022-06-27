#include<stdio.h>
#include<math.h>
#include<ctype.h>

int stack[100];
int top = -1;
char x;

void push(char x){
    stack[++top]= x;
}
char pop(){
if(top=-1)
    return -1;
    else return stack[top--];
}

void display(){
    for(int i=0; i<=100 ; i++){
    printf("%d", stack[i]); 
    }
}

int priority(){
    if(x== '(')
    return 0;
    if(x== '+' || x== '-')
    return 1;
    if(x== '*' || x== '/')
    return 2;
}

int main(){
    char exp[100];
    char *e,x;

    printf("Enter the expression:");
    scanf("%s",exp);
    e=exp;

    while(*e!='\0'){
        if(*e=='('){
            push(*e);
        }
        else if(isalnum(*e)){
            push(*e);
        }
        else if(*e==')'){
            while((x=pop()!= '('))
            printf("%c",x);
        }
        
        else{
            while(priority(stack[top]) >= priority(*e))
            printf("%c",pop());
            push(*e);
        }
        e++;
    }

    while(top!=-1){
        printf("%c",pop());
    }
    return 0;
}