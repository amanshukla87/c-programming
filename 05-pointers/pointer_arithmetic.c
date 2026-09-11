#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array elements using pointer arithmetic:\n");

    for (int i = 0; i < size; i++)
    {
        printf("numbers[%d] = %d\n", i, *(ptr + i));
    }

    printf("\nPointer movement:\n");
    printf("Current value: %d\n", *ptr);

    ptr++;
    printf("After ptr++: %d\n", *ptr);

    ptr++;
    printf("After another ptr++: %d\n", *ptr);

    ptr--;
    printf("After ptr--: %d\n", *ptr);

    return 0;
}
