#include <stdio.h>
#include <conio.h>   /* Turbo C ke liye */

// To demonstrate the Quick Sort technique for sorting an array of elements.
// The program allows user to input a list of elements, applies the
// divide-and-conquer strategy of Quick Sort using partitioning,
// and displays the sorted output.

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    int pi;
    if (low < high) {
        pi = partition(arr, low, high);  /* Get pivot index */
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nSorted array (using Quick Sort):\n");
    printArray(arr, n);

    getch();
    return 0;
}
