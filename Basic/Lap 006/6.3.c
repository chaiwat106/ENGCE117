#include <stdio.h>

int main() {
    int gross_salary;
    float tax_rate = 0.0;
    float tax_amount = 0.0;
    float net_salary = 0.0;


    printf("Enter Gross Salary (THB/month): ");
    scanf("%d", &gross_salary);

  
    if (gross_salary < 20000) {
        tax_rate = 0.00; 
    } else if (gross_salary < 50000) {
        tax_rate = 0.05;
    } else {
        tax_rate = 0.10; 
    }

    tax_amount = (float)gross_salary * tax_rate;
    net_salary = (float)gross_salary - tax_amount;

  
    printf("\n--- SALARY CALCULATION REPORT ---\n");
    printf("Gross Salary: %d THB\n", gross_salary);
    printf("Tax Rate Applied: %.0f%%\n", tax_rate * 100);
    printf("Tax Amount Deducted: %.2f THB\n", tax_amount);
    printf("Net Salary: %.2f THB\n", net_salary);

    return 0;
}
2. Two-Dimensional Array (3x3)
This program uses nested loops to store and display integer data in a table format.

C

#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {

    int data[ROWS][COLS];
    int i, j;

    printf("Enter %d integer numbers for the 3x3 array:\n", ROWS * COLS);


    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Enter element for Row %d, Col %d: ", i, j);
            scanf("%d", &data[i][j]); 
        }
    }


    printf("\n--- TWO-DIMENSIONAL ARRAY REPORT ---\n");
    printf("Array Size: %d Rows x %d Columns\n", ROWS, COLS);
    printf("Content (Table Format):\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", data[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
