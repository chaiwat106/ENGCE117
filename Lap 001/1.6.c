#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *rPtr, int *cPtr) {
    int r, c;
    scanf("%d %d", &r, &c);

    int total = r * c;
    int *box = malloc(total * sizeof(int));

    if (box == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < total; i++) {
        scanf("%d", &box[i]);
    }

    *rPtr = r;
    *cPtr = c;

    return box;
}

void PrintMatrix(int *m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", m[i * c + j]);
        }
        printf("\n");
    }
}

int main() {
    int *data;
    int m, n;

    data = GetMatrix(&m, &n);

    printf("Matrix (%d x %d):\n", m, n);
    PrintMatrix(data, m, n);

    free(data);
    return 0;
}
