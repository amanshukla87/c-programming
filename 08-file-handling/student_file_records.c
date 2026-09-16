#include <stdio.h>

#define MAX_STUDENTS 100

typedef struct
{
    int roll_no;
    char name[50];
    float marks;
} Student;

int main(void)
{
    Student students[MAX_STUDENTS];
    int count = 0;
    FILE *file;

    printf("Enter number of students: ");
    scanf("%d", &count);

    if (count < 1 || count > MAX_STUDENTS)
    {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &students[i].roll_no);

        printf("Name: ");
        scanf(" %49[^\n]", students[i].name);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    file = fopen("students.txt", "w");

    if (file == NULL)
    {
        printf("Unable to create student record file.\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d|%s|%.2f\n",
                students[i].roll_no,
                students[i].name,
                students[i].marks);
    }

    fclose(file);

    printf("\nStudent records saved successfully.\n");
    printf("Records:\n");

    file = fopen("students.txt", "r");

    if (file == NULL)
    {
        printf("Unable to read student record file.\n");
        return 1;
    }

    while (fscanf(file, "%d|%49[^|]|%f\n",
                  &students[0].roll_no,
                  students[0].name,
                  &students[0].marks) == 3)
    {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               students[0].roll_no,
               students[0].name,
               students[0].marks);
    }

    fclose(file);
    return 0;
}
