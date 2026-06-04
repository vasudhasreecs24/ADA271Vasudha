#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    swap(&arr[low], &arr[j]);
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    // -------- SMALL INPUT --------
    printf("Enter number of elements (small n): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    printArray(arr, n);

    // -------- LARGE INPUT (TIME ANALYSIS) --------
    int sizes[] = {1000, 5000, 10000, 20000, 50000};
    int numSizes = 5;

    printf("\n\nTime Taken for Quick Sort:\n");
    printf("Size\tTime (seconds)\n");

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int *a = (int *)malloc(size * sizeof(int));

        // Fill with random numbers
        for (int j = 0; j < size; j++)
            a[j] = rand();

        clock_t start = clock();

        quickSort(a, 0, size - 1);

        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%f\n", size, time_taken);

        free(a);
    }

    return 0;
}
