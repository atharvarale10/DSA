#include <stdio.h>

// Function to find the highest element in the array
int findHighest(int arr[], int size) {
    int highest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

// Function to find the lowest element in the array
int findLowest(int arr[], int size) {
    int lowest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    return lowest;
}

int main() {
    int size;

    // Input: size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];

    // Input: elements of the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Finding highest and lowest elements
    int highest = findHighest(arr, size);
    int lowest = findLowest(arr, size);

    // Output: highest and lowest elements
    printf("Highest element: %d\n", highest);
    printf("Lowest element: %d\n", lowest);

    return 0;
}
