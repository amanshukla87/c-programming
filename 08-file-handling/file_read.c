#include <stdio.h>

int main(void)
{
    FILE *file = fopen("data.txt", "r");
    int ch;

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("File contents:\n");

    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
