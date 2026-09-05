#include <stdio.h>

int main(void)
{
    int row, column;

    printf("Simple number pattern:\n");

    for (row = 1; row <= 5; row++)
    {
        for (column = 1; column <= row; column++)
        {
            printf("%d ", column);
        }
        printf("\n");
    }

    return 0;
}
