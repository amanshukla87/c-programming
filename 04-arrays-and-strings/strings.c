#include <stdio.h>
#include <string.h>

#define STRING_SIZE 50

int main(void)
{
    char text[STRING_SIZE];
    size_t length;

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';
    length = strlen(text);

    printf("\nString: %s\n", text);
    printf("Length: %zu\n", length);

    return 0;
}
