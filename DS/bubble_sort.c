#include <stdio.h>

//function to swap numbers using bitwise operator
void swap(int *arr, int i, int j){
    arr[i]=arr[i]^arr[j];
    arr[j]=arr[i]^arr[j];
    arr[i]=arr[i]^arr[j];
}

//function to implement sorting
void bubbleSort(int *arr, int n){

    for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr, j, j+1);  //calling of swap fn
            }
        }
    }
}

//main function
int main(){
    int arr[5]={0,3,1,2,8};
    bubbleSort(arr,5);
    for(int i=0;i<5;i++){ //printing the final sorted array
        printf("%d ",arr[i]);
    }
    return 0;
}