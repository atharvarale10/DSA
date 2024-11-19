#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearchRecursive(arr, left, mid - 1, target);

        return binarySearchRecursive(arr, mid + 1, right, target);
    }

    return -1;
}

int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int main() {
    int size, target, result;

    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &size);

    int arr[size];
    
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    result = binarySearchRecursive(arr, 0, size - 1, target);
    if (result != -1)
        printf("Target %d found at index %d (recursive search)\n", target, result);
    else
        printf("Target %d not found (recursive search)\n", target);

    result = binarySearchIterative(arr, size, target);
    if (result != -1)
        printf("Target %d found at index %d (iterative search)\n", target, result);
    else
        printf("Target %d not found (iterative search)\n", target);

    return 0;
}
