#include <stdio.h>

int main(void)
{
    int i;
    int sum = 0;
    int number;

    /* for loop */
    printf("For loop: ");
    for (i = 1; i <= 5; i++)
    {
        printf("%d ", i);
    }

    /* while loop */
    printf("\nWhile loop: ");
    i = 1;
    while (i <= 5)
    {
        printf("%d ", i);
        i++;
    }

    /* do-while loop */
    printf("\nDo-while loop: ");
    i = 1;
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= 5);

    /* Practical example: sum of first n positive integers */
    printf("\n\nEnter a positive integer: ");
    scanf("%d", &number);

    if (number > 0)
    {
        for (i = 1; i <= number; i++)
        {
            sum += i;
        }

        printf("Sum from 1 to %d = %d\n", number, sum);
    }
    else
    {
        printf("Please enter a positive integer.\n");
    }

    return 0;
}
