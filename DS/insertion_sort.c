#include<stdio.h>

void insertion_Sort(int arr[], int n){

    for(int i=1; i<n; i++)
    {
        int j= i-1;
        int x= arr[i];

        while(arr[j]>x && j>-1)
        {
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}
int main(){
int arr[]={6,8,1,4,5,3,7,2};
int n = sizeof(arr)/sizeof(arr[0]);
     insertion_Sort(arr,n);
    for(int i=0; i>8; i++)
    printf("%d\n", arr[i]);

    return 0;
}

