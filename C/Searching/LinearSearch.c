#include <stdio.h>

void linearSearchSingle(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Target %d found at index %d (single occurrence)\n", target, i);
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("Target %d not found (single occurrence search)\n", target);
    }
}

void linearSearchMultiple(int arr[], int size, int target) {
    int found = 0;
    printf("All occurrences of target %d: ", target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("%d ", i); 
            found = 1;
        }
    }
    if (!found) {
        printf("not found");
    }
    printf("\n");
}

int main() {
    int size, target;

    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    linearSearchSingle(arr, size, target);

    linearSearchMultiple(arr, size, target);

    return 0;
}
