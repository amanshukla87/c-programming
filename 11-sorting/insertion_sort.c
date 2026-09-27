#include <stdio.h>

void print_array(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main(void)
{
    int numbers[] = {12, 11, 13, 5, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Before sorting: ");
    print_array(numbers, size);

    insertion_sort(numbers, size);

    printf("After sorting:  ");
    print_array(numbers, size);

    return 0;
}
