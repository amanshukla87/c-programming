#include <stdio.h>
#include <string.h>

#define STRING_SIZE 50

int main(void)
{
    char first[STRING_SIZE];
    char second[STRING_SIZE];
    char combined[STRING_SIZE * 2];

    printf("Enter first string: ");
    fgets(first, sizeof(first), stdin);
    first[strcspn(first, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(second, sizeof(second), stdin);
    second[strcspn(second, "\n")] = '\0';

    strcpy(combined, first);
    strcat(combined, " ");
    strcat(combined, second);

    printf("\nFirst string: %s\n", first);
    printf("Second string: %s\n", second);
    printf("Combined string: %s\n", combined);

    if (strcmp(first, second) == 0)
    {
        printf("Comparison: Strings are equal.\n");
    }
    else
    {
        printf("Comparison: Strings are different.\n");
    }

    return 0;
}
