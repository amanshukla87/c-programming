#include <stdio.h>

int main(void)
{
    FILE *source = fopen("data.txt", "r");
    FILE *destination = fopen("copy.txt", "w");
    int ch;

    if (source == NULL)
    {
        printf("Unable to open source file.\n");
        return 1;
    }

    if (destination == NULL)
    {
        printf("Unable to create destination file.\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");
    return 0;
}
