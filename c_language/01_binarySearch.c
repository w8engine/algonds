#include <stdio.h>

/**
 * 
 * Returns index of value exists in array.
 * 
 * returns non-negative integers when the value is found in the array.
 * returns -1 when value isn't found in the array.
 * 
 */
int binarySearch(int targetValue, int arr[], int arrSize) {
    int leftIndex = 0;
    int rightIndex = arrSize - 1;
    int midIndex;

    if (targetValue == arr[leftIndex]) {
        return leftIndex;
    }

    if (targetValue == arr[rightIndex]) {
        return rightIndex;
    }

    while (leftIndex <= rightIndex) {
        midIndex = (leftIndex + rightIndex) / 2;
        if (targetValue == arr[midIndex]) {
            return midIndex;
        } else if (targetValue > arr[midIndex]) {
            leftIndex = midIndex + 1;
        } else if (targetValue < arr[midIndex]) {
            rightIndex = midIndex - 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    int sampleData[] = { -12, -5, 0, 1, 4, 8, 9, 14, 65, 345, 565 };
    int sampleTestCase[] = { 9, 255, 1024, 565, -12, 8 };
    int i;

    printf("int sampleData[11] = { ");
    for (i = 0; i < (sizeof(sampleData) / sizeof(int) - 1); i++) {
        printf("%d, ", sampleData[i]);
    }
    printf("%d }\n", sampleData[sizeof(sampleData) / sizeof(int) - 1]);

    printf("int sampleTestCase[6] = { ");
    for (i = 0; i < (sizeof(sampleTestCase) / sizeof(int) - 1); i++) {
        printf("%d, ", sampleTestCase[i]);
    }
    printf("%d }\n\n", sampleTestCase[sizeof(sampleTestCase) / sizeof(int) - 1]);

    for (i = 0; i < (sizeof(sampleTestCase) / sizeof(int)); i++) {
        printf("binarySearch(%d) : %s\n", sampleTestCase[i], (binarySearch(sampleTestCase[i], sampleData, sizeof(sampleData) / sizeof(int)) >= 0) ? "\033[0;32mFounded!\033[0m" : "\033[0;31mNot Founded!\033[0m");
    }

    return 0;
}