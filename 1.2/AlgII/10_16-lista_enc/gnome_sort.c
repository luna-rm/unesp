#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

  
void gnome_sort(int arr[], int n) { 
    int index = 0; 

    while (index < n) { 
        if (index == 0){
            index++; 
        } 
        if (arr[index] >= arr[index - 1]) 
            index++; 
        else { 
            int aux = arr[index];
            arr[index] = arr[index-1];
            arr[index-1] = aux;
            index--; 
        } 
    } 
    return; 
} 
  
// Driver program to test above functions. 
int main() 
{ 
    int arr[] = { 4, 1, 5, 3, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    gnomeSort(arr, n); 
  
    return (0); 
} 