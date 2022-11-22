#include <stdio.h>

void printDebug(int arr[], int arrLength, int i, int j, int flag) {
    int k;

    if (!arr || arrLength <= 0) {
        return;
    }

    //printf("(j - 1 = \033[0;31m%d\033[0m, j = \033[0;32m%d\033[0m), [ ", i, j);
    printf("[ ");
    for (k = 0; k < arrLength; k++) {
        if ((k == i || k == j) && flag == 0) {
            printf("\033[0;31m%d\033[0m, ", arr[k]);
        } else if ((k == i || k == j) && flag == 1) {
            printf("\033[0;32m%d\033[0m, ", arr[k]);
        } else {
            printf("%d, ", arr[k]);
        }
    }
    printf("\b\b ]");
}

/**
 * 
 * Sort integer array by using insertion sort algorithm.
 * 
 * Average Time Complexity : O(N^2)
 * Maximum(Worst) Time Complexity : O(N^2)
 * Memory Size Complexity : O(1)
 * Is guaranteed by stability of data.
 * 
 * Returns computation count of loop.
 * 
 * Returns 0 when array isn't vallid or array's length is 0 or negative.
 * Returns positive number whe array has been sucessfully ordered.
 * 
 */
int insertionSort(int arr[], int arrLength) {
    int i = 0;
    int j = 0;
    int temp;
    int computationCost = 0;

    if (!arr || arrLength <= 0) {
        return computationCost;
    }

    for (i = 1; i < arrLength; i++) {
        for (j = i; (j > 0) && (arr[j - 1] > arr[j]); j--) {
            printDebug(arr, arrLength, j - 1, j, 0);
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            computationCost++;
            printf(" -> ");
            printDebug(arr, arrLength, j - 1, j, 1);
            printf("\n");
        }
    }

    return computationCost;
}

int main(int argc, char *argv[]) {
    int arr[] = { 5, 4, 3, 2, 1 };
    int computationCost = insertionSort(arr, 5);
    int i;

    printf("Computation Cost = %d\n", computationCost);
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}