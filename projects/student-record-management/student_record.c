#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int roll_no;
    char name[NAME_LENGTH];
    float marks;
};

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student record limit reached.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll_no);

    printf("Enter name: ");
    scanf(" %49[^\n]", students[*count].name);

    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
    printf("Student record added successfully.\n");
}

void displayStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-10s %-30s %-10s\n", "Roll No.", "Name", "Marks");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10.2f\n",
               students[i].roll_no,
               students[i].name,
               students[i].marks);
    }
}

int findStudent(const struct Student students[], int count, int roll_no) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll_no) {
            return i;
        }
    }
    return -1;
}

void searchStudent(const struct Student students[], int count) {
    int roll_no;

    printf("Enter roll number to search: ");
    scanf("%d", &roll_no);

    int index = findStudent(students, count, roll_no);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("\nRoll No.: %d\n", students[index].roll_no);
    printf("Name    : %s\n", students[index].name);
    printf("Marks   : %.2f\n", students[index].marks);
}

void updateStudent(struct Student students[], int count) {
    int roll_no;

    printf("Enter roll number to update: ");
    scanf("%d", &roll_no);

    int index = findStudent(students, count, roll_no);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %49[^\n]", students[index].name);

    printf("Enter new marks: ");
    scanf("%f", &students[index].marks);

    printf("Student record updated successfully.\n");
}

void deleteStudent(struct Student students[], int *count) {
    int roll_no;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll_no);

    int index = findStudent(students, *count, roll_no);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;
    printf("Student record deleted successfully.\n");
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateStudent(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
