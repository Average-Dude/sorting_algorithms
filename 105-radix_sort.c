#include <stdio.h>
#include <stdlib.h>

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

        // Print the array after each significant digit
        for (size_t i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}

int main() {
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    radix_sort(array, size);

    printf("\nSorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

