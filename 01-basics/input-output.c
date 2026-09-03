#include <stdio.h>

int main(void)
{
    int age;
    float temperature;
    char grade;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter temperature: ");
    scanf("%f", &temperature);

    printf("Enter grade: ");
    scanf(" %c", &grade);

    printf("\nAge: %d\n", age);
    printf("Temperature: %.2f C\n", temperature);
    printf("Grade: %c\n", grade);

    return 0;
}
