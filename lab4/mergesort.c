#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Merge function
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    // -------- SMALL INPUT (FOR DISPLAY) --------
    printf("Enter number of elements (small n): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    printArray(arr, n);


    // -------- LARGE INPUT (FOR TIME ANALYSIS) --------
    int sizes[] = {1000, 5000, 10000, 20000, 50000};
    int numSizes = 5;

    printf("\n\nTime Taken for Merge Sort:\n");
    printf("Size\tTime (seconds)\n");

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int *a = (int *)malloc(size * sizeof(int));

        // Fill with random numbers
        for (int j = 0; j < size; j++)
            a[j] = rand();

        clock_t start = clock();

        mergeSort(a, 0, size - 1);

        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%f\n", size, time_taken);

        free(a);
    }

    return 0;
}
