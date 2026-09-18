#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *values;

    printf("Enter number of values: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    values = malloc((size_t)n * sizeof(*values));

    if (values == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integer values:\n", n);

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &values[i]) != 1)
        {
            printf("Invalid input.\n");
            free(values);
            return 1;
        }
    }

    printf("\nValues stored in dynamically allocated memory:\n");

    for (int i = 0; i < n; i++)
    {
        printf("values[%d] = %d\n", i, values[i]);
    }

    free(values);
    values = NULL;

    printf("\nDynamic memory released successfully.\n");

    return 0;
}
