#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include <string.h>

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

void main(){
    char exp[100];
    int i,num1,num2,ans;
    printf("enter your postfix expression:");
    scanf("%s",exp);

    i=0;
    while(i<= strlen(exp)-1){
        char ele= exp[i];

        if(isdigit(ele))
        {
            push(ele-'0');
        }
            else{
                num1=pop();
                num2=pop();
        switch (ele)
        {
        case '^':
            ans= pow(num2,num1);
            break;
        case '/':
            ans= num2/num1;
            break;
        case '*':
            ans= num2*num1;
            break;
        case '+':
            ans= num2+num1;
            break;
        case '-':
            ans= num2-num1;
            break;
        
        }
        push(ele);
        }
        i++;
    }
    printf("ans=%d", pop());
}
