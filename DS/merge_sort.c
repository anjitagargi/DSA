#include <stdio.h>
void swap(int* arr, int i, int j){
    arr[i]=arr[i]^arr[j];
    arr[j]=arr[i]^arr[j];
    arr[i]=arr[i]^arr[j];
}

void merge(int *arr,int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;

    int a[n1],b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }
}

void mergesort(int *arr,int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr, l,mid);
        mergesort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[5]={9,8,7,6,5};
    mergesort(arr,0,5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}