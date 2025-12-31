#include <stdio.h>

#define SIZE 5

int find_and_update(int *arr_ptr, int size, int search_value, int new_value) {
    int found = 0;
    
 
    for (int i = 0; i < size; i++) {
  
        if (*(arr_ptr + i) == search_value) {
            *(arr_ptr + i) = new_value;
            found = 1;
        }
    }
    
  
    return found;
}


void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // 2. การดำเนินงานใน main
    int numbers[SIZE];
    int search_val;
    int new_val;
    int status;
    int i;

  
    printf("Enter %d integer elements for the array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

   
    printf("\nEnter value to search (Search Value): ");
    scanf("%d", &search_val);
    printf("Enter new value to replace it with (New Value): ");
    scanf("%d", &new_val);

    printf("\n--- ARRAY UPDATE REPORT ---\n");
 
    printf("Array BEFORE Update: ");
    print_array(numbers, SIZE);

    
    status = find_and_update(numbers, SIZE, search_val, new_val);


    printf("Array AFTER Update: ");
    print_array(numbers, SIZE);

    printf("Status: ");
    if (status == 1) {
        printf("SUCCESS (Value Updated)\n");
    } else {
        printf("FAILED (Value Not Found)\n");
    }

    return 0;
}
