#include <stdio.h>
#include <string.h>
 
#define RANGE 100
 
// Function to efficiently sort an array with many duplicated values
// using the counting sort algorithm
void customSort(int arr[], int n)
{
    // create a new array to store counts of elements in the input array
    // `freq[i]` stores the total number of items with key equal to `i`
    int freq[RANGE];
 
    // initialize array by 0
    memset(freq, 0, sizeof(freq));
 
    // using the value of elements in the input array as an index,
    // update their frequencies in the new array
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
 
    // overwrite the input array with sorted order
    int k = 0;
    for (int i = 0; i < RANGE; i++)
    {
        while (freq[i]--) {
            arr[k++] = i;
        }
    }
}
 
int main()
{
    int arr[] = { 4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    customSort(arr, n);
 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}