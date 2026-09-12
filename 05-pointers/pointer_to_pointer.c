#include <stdio.h>

int main(void)
{
    int value = 25;
    int *ptr = &value;
    int **ptr_to_ptr = &ptr;

    printf("Value       : %d\n", value);
    printf("*ptr        : %d\n", *ptr);
    printf("**ptr_to_ptr: %d\n", **ptr_to_ptr);

    **ptr_to_ptr = 50;

    printf("Updated value: %d\n", value);

    return 0;
}
