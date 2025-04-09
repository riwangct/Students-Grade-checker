#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 4  // Maths, Web Designing, Data Structure, Communication Skills

struct Student {
    char name[50];
    char uid[20];
    float marks[SUBJECTS];
    float total;
    float average;
    char grade;
};

void calculate(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        s->total += s->marks[i];
    }
    s->average = (s->total / (SUBJECTS * 20.0)) * 100;

    if (s->average >= 90)
        s->grade = 'A';
    else if (s->average >= 70)
        s->grade = 'B';
    else if (s->average >= 50)
        s->grade = 'C';
    else
        s->grade = 'D';
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar(); // Clear newline buffer

    for (int i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Enter UID: ");
        fgets(students[i].uid, sizeof(students[i].uid), stdin);
        students[i].uid[strcspn(students[i].uid, "\n")] = '\0';

        printf("Enter marks out of 20 for:\n");
        printf("Maths: ");
        scanf("%f", &students[i].marks[0]);

        printf("Web Designing: ");
        scanf("%f", &students[i].marks[1]);

        printf("Data Structure: ");
        scanf("%f", &students[i].marks[2]);

        printf("Communication Skills: ");
        scanf("%f", &students[i].marks[3]);

        getchar(); // Clear buffer for next student

        calculate(&students[i]);
    }

    // Display final table
    printf("\n\n---------------------------- STUDENTS REPORT ----------------------------\n");
    printf("%-20s %-15s %-15s %-15s %-5s\n", "Name", "UID", "Total Marks", "Average (%)", "Grade");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-20s %-15s %-15.2f %-15.2f %-5c\n",
               students[i].name,
               students[i].uid,
               students[i].total,
               students[i].average,
               students[i].grade);
    }

    return 0;
}