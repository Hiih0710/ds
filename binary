#include <stdio.h>
#define max 5

//Implement a program to perform Binary Search to find a target value,and display whether the element is present.

int main() {
    int i, j, mid, temp, val, arr[max];
    int lower = 0, upper = max - 1, flag = 1;

    printf("Enter %d array elements:\n", max);
    for (i = 0; i < max; i++) {
        scanf("%d", &arr[i]);
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("The sorted elements are:\n");
    for (i = 0; i < max; i++)
        printf("%d\t", arr[i]);

    printf("\nEnter the value to search: ");
    scanf("%d", &val);

    while (lower <= upper) {
        mid = (lower + upper) / 2;
        if (arr[mid] == val) {
            printf("%d is at position %d\n", arr[mid], mid);
            flag = 0;
            break;
        } else if (arr[mid] > val) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }

    if (flag == 1)
        printf("Number is not in the array\n");
    getch();
    return 0;
}
