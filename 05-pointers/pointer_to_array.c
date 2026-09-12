#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    int (*ptr)[4] = &values;

    printf("Array elements using pointer to array:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("values[%d] = %d\n", i, (*ptr)[i]);
    }

    return 0;
}
