#include <stdio.h>

int main(void)
{
    FILE *file = fopen("data.txt", "w");

    if (file == NULL)
    {
        printf("Unable to create file.\n");
        return 1;
    }

    fprintf(file, "Hello, C file handling!\n");
    fprintf(file, "This data is written to a file.\n");

    fclose(file);

    printf("Data written successfully.\n");
    return 0;
}
