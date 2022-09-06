#include <stdio.h>

/**
 * 
 * Sort integer array by using bubble sort algorithm.
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
int bubbleSort(int arr[], int arrLength) {
    int i;
    int temp;
    int orderCount = 0;
    int computationCost = 0;

    if (!arr || arrLength <= 0) {
        return 0;
    }

    while (orderCount != (arrLength - 1)) {
        orderCount = 0;
        for (i = 0; i < (arrLength - 1); i++) {
            computationCost++;
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            } else {
                orderCount++;
            }
        }

        printf("try %d : { ", computationCost / (arrLength - 1) + (computationCost % (arrLength - 1) ? 1 : 0));
        for (i = 0; i < (arrLength - 1); i++) {
            printf("%d, ", arr[i]);
        } printf("%d }\n", arr[7]);
    }

    return computationCost;
}

int main(int argc, char *argv[]) {
    int sampleData[5][8] = {
        { -432, 54, 23, 12, 34, 7, 7, 1 },
        { 12, 54, 76, 3, 12, 6576, -423, 0 },
        { -435345, 435, 234, -64564, 23, 12, 54, 32 },
        { -32, 1, 1, 0, 43, 12, 54, 8767 },
        { 8, 7, 6, 5, 4, 3, 2, 1 }
    };
    int i = 0;
    int j = 0;
    int computationCost = -1;

    for (i = 0; i < 5; i++) {
        printf("sampleData[%d][] = { ", i);
        for (j = 0; j < 7; j++) {
            printf("%d, ", sampleData[i][j]);
        }
        printf("%d }\n", sampleData[i][7]);

        computationCost = bubbleSort((int*)(sampleData[i]), 8);
        printf("bubbleSort[%d][] = { ", i);
        for (j = 0; j < 7; j++) {
            printf("%d, ", sampleData[i][j]);
        }
        printf("%d }, compute %d times (less than %d)\n\n", sampleData[i][7], computationCost, 64);
        computationCost = -1;
    }


    return 0;
}