#include <stdio.h>

/* Function prototype */
int add_numbers(int a, int b);
void print_message(void);

/* Function definition */
int add_numbers(int a, int b)
{
    return a + b;
}

void print_message(void)
{
    printf("Functions help divide a program into reusable blocks.\n");
}

int main(void)
{
    int first;
    int second;
    int sum;

    print_message();

    printf("Enter two integers: ");
    scanf("%d %d", &first, &second);

    sum = add_numbers(first, second);

    printf("Sum = %d\n", sum);

    return 0;
}
