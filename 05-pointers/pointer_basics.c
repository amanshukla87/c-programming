#include <stdio.h>

int main(void)
{
    int value = 25;
    int *ptr = &value;

    printf("Value: %d\n", value);
    printf("Address of value: %p\n", (void *)&value);
    printf("Address stored in ptr: %p\n", (void *)ptr);
    printf("Value through pointer: %d\n", *ptr);

    // Modify the variable through the pointer.
    *ptr = 50;

    printf("Updated value: %d\n", value);
    printf("Updated value through pointer: %d\n", *ptr);

    return 0;
}
