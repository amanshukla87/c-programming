#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll_no;
    char name[50];
    float marks;
};

int main(void)
{
    struct Student *students = NULL;
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n===== Dynamic Student Records =====\n");
        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Search by roll number\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            free(students);
            return 1;
        }

        if (choice == 1)
        {
            struct Student *temp;

            temp = realloc(students, (size_t)(count + 1) * sizeof(*students));

            if (temp == NULL)
            {
                printf("Memory allocation failed.\n");
                free(students);
                return 1;
            }

            students = temp;

            printf("Enter roll number: ");
            scanf("%d", &students[count].roll_no);

            printf("Enter name: ");
            scanf(" %49[^\n]", students[count].name);

            printf("Enter marks: ");
            scanf("%f", &students[count].marks);

            count++;
            printf("Student record added successfully.\n");
        }
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("No student records available.\n");
                continue;
            }

            printf("\n%-10s %-25s %-10s\n", "Roll No.", "Name", "Marks");
            printf("-----------------------------------------------\n");

            for (int i = 0; i < count; i++)
            {
                printf("%-10d %-25s %-10.2f\n",
                       students[i].roll_no,
                       students[i].name,
                       students[i].marks);
            }
        }
        else if (choice == 3)
        {
            int roll_no;
            int found = 0;

            printf("Enter roll number to search: ");
            scanf("%d", &roll_no);

            for (int i = 0; i < count; i++)
            {
                if (students[i].roll_no == roll_no)
                {
                    printf("\nRecord found:\n");
                    printf("Roll No.: %d\n", students[i].roll_no);
                    printf("Name    : %s\n", students[i].name);
                    printf("Marks   : %.2f\n", students[i].marks);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Student record not found.\n");
            }
        }
        else if (choice == 4)
        {
            free(students);
            students = NULL;
            printf("Dynamic memory released. Program ended.\n");
            return 0;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
}
