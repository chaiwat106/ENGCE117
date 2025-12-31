#include <stdio.h>

#define STUDENTS 5

int main() {
    int scores[STUDENTS];
    int sum = 0;
    float average = 0.0;
    int above_average_count = 0;
    int i;


    for (i = 0; i < STUDENTS; i++) {
        printf("Enter score for student %d: ", i + 1);
        scanf("%d", &scores[i]);
    }


    for (i = 0; i < STUDENTS; i++) {
        sum += scores[i];
    }

    average = (float)sum / STUDENTS;

  
    for (i = 0; i < STUDENTS; i++) {
        if (scores[i] > average) {
            above_average_count++;
        }
    }

    printf("\n--- STUDENT SCORE ANALYSIS REPORT ---\n");
    printf("Recorded Scores: ");
    for (i = 0; i < STUDENTS; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
    
    printf("Total Sum: %d\n", sum);
    printf("Average Score: %.2f\n", average);
    printf("Number of Scores Above Average: %d\n", above_average_count);

    return 0;
}
