#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// Function to find the maximum element in the array
int findMax(int array[], size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Counting sort function to sort the array based on a specific digit
void countingSort(int array[], size_t size, int exp) {
    int* output = (int*)malloc(size * sizeof(int));
    int count[10] = {0};

    for (size_t i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
}

// Radix sort function
void radix_sort(int array[], size_t size) {
    int max = findMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, size, exp);
    }
}

void print_array(const int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

