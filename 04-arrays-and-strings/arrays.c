#include <stdio.h>

#define ARRAY_SIZE 5

int main(void)
{
    int numbers[ARRAY_SIZE];
    int sum = 0;
    int maximum;
    int i;

    printf("Enter %d integers:\n", ARRAY_SIZE);

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    maximum = numbers[0];

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        sum += numbers[i];

        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }

    printf("\nArray elements: ");

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\nSum = %d\n", sum);
    printf("Maximum = %d\n", maximum);

    return 0;
}
