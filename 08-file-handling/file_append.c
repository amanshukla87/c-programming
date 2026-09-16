#include <stdio.h>

int main(void)
{
    FILE *file = fopen("data.txt", "a");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(file, "This line was appended later.\n");

    fclose(file);

    printf("Data appended successfully.\n");
    return 0;
}
