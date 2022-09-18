#include <stdio.h>

/**
 * 
 * Sort integer array by using bubble sort algorithm.
 * 
 * Average Time Complexity : O(N^2)
 * Maximum(Worst) Time Complexity : O(N^2)
 * Memory Size Complexity : O(1)
 * Is not guaranteed by stability of data.
 * 
 */
int selectionSort(int arr[], int arrLength) {
    int i;
    int j;
    int minData;
    int minDataIndex;
    int temp;
    int computationCost = 0;

    if (!arr || arrLength <= 0) {
        return computationCost;
    }

    for (i = 0; i < (arrLength - 1); i++) {
        minData = arr[i];
        minDataIndex = i;
        for (j = i; j < arrLength; j++) {
            if (minData > arr[j]) {
                minData = arr[j];
                minDataIndex = j;
            }
            computationCost++;
        }
        temp = arr[minDataIndex];
        arr[minDataIndex] = arr[i];
        arr[i] = temp;
    }

    return computationCost;    
}

int main(int argc, char *argv[]) {
    int arr[] = { 5, 4, 3, 2, 1 };
    int computationCost = selectionSort(arr, 5);
    int i;

    printf("Computation Cost = %d\n", computationCost);
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}