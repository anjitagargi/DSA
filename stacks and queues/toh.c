#include <stdio.h>

int main()
{
    int n;
    int a,b,c;
   
    TOH(3,'a','b','c');

    return 0;
}

void TOH(int n, char x, char y, char z){
    if(n>0){
        TOH(n-1,x,z,y);
        printf("move from %c to %c\n",x,y);
        TOH(n-1,z,y,x);
    }
}