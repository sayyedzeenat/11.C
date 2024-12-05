
/*
    EXP 11
    TITLE : WAP TO MAINTAIN A SIMPLE EMPLOYEE DATABASE USING FILE HANDLING.

    Name: SAYYED ZEENAT ABDUL KARIM
    UIN: 241PO23
    ROLL NO: 22
    BRANCH: COMPUTER ENGINEERING
    DIV: C
    BATCH: C2

 */

#include <stdio.h>

struct employee {
    int id;
    char name[50];
    float salary;
};
void add_employee() {
    struct employee emp;
    FILE *file = fopen("employee_database.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    getchar();
    gets(emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);
    fprintf(file, "%d %.2f %s\n", emp.id, emp.salary, emp.name);
    fclose(file);
    printf("Employee record added successfully!\n");
}
void display_employees() {
    struct employee emp;
    FILE *file = fopen("employee_database.txt", "r");
    if (file == NULL) {
        printf("No employee records found!\n");
        return;
    }
    printf("\nEmployee Records:\n");
    printf("ID\tName\t\tSalary\n");
    printf("------------------------------------\n");
    while (fscanf(file, "%d %f %[^\n]", &emp.id, &emp.salary, emp.name) != EOF) {
        printf("%d\t%-15s\t%.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(file);
}
int main(){
    int choice;
    printf("\t\t\t***Employee Database***\n\n\n");
    while (1) {
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee Record\n");
        printf("2. Display Employee Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
 /*
 OUTPUT:                 ***Employee Database***

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Exit
Enter your choice: 1
Enter Employee ID: 18
Enter Employee Name: ZEENAT
Enter Employee Salary: 1000000
Employee record added successfully!

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Exit
Enter your choice: 2

Employee Records:
ID      Name            Salary
------------------------------------
18      ZEENAT           1000000.00

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Exit
Enter your choice: 3
Exiting the program.
*/

