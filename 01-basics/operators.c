#include <stdio.h>

int main(void)
{
    int a = 12;
    int b = 5;
    int result;

    result = a + b;
    printf("Addition: %d\n", result);

    result = a - b;
    printf("Subtraction: %d\n", result);

    result = a * b;
    printf("Multiplication: %d\n", result);

    result = a / b;
    printf("Division: %d\n", result);

    result = a % b;
    printf("Remainder: %d\n", result);

    printf("a > b: %d\n", a > b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);

    printf("Logical AND: %d\n", (a > 10) && (b < 10));
    printf("Logical OR: %d\n", (a < 10) || (b < 10));
    printf("Logical NOT: %d\n", !(a == b));

    a += 3;
    b++;

    printf("a after += 3: %d\n", a);
    printf("b after ++: %d\n", b);

    return 0;
}
