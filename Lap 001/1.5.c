#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int **matrix, int *rows, int *cols) {
    scanf("%d %d", rows, cols);

    int total = (*rows) * (*cols);
    *matrix = malloc(total * sizeof(int));

    if (*matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < total; i++) {
        scanf("%d", &(*matrix)[i]);
    }
}

void PrintMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int *data;
    int m, n;

    GetMatrix(&data, &m, &n);

    printf("Matrix (%d x %d):\n", m, n);
    PrintMatrix(data, m, n);

    free(data);
    return 0;
}
