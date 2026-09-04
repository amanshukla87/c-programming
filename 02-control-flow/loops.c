#include <stdio.h>

int main(void)
{
    int i;
    int sum = 0;

    printf("For loop: ");
    for (i = 1; i <= 5; i++)
    {
        printf("%d ", i);
        sum += i;
    }
    printf("\nSum = %d\n", sum);

    printf("While loop: ");
    i = 5;
    while (i >= 1)
    {
        printf("%d ", i);
        i--;
    }
    printf("\n");

    printf("Do-while loop: ");
    i = 1;
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= 5);
    printf("\n");

    return 0;
}
