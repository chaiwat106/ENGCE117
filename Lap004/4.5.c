#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};


void SaveNode(struct studentNode *child, char n[], int a, char s, float g);
void GoNext1(struct studentNode **walk);
void GoNext2(struct studentNode **walk);

int main() {
    struct studentNode *start, *now1, **now2;

  
    start = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(start, "one", 6, 'M', 3.11);

    start->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(start->next, "two", 8, 'F', 3.22);

    start->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next, "three", 10, 'M', 3.33);

    start->next->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next->next, "four", 12, 'F', 3.44);


    now1 = start;
    now2 = &now1;

    printf("Testing GoNext1:\n");
    GoNext1(&now1); 
    printf("After GoNext1, now1 is at: %s\n\n", now1->name);

    printf("Testing GoNext2:\n");
    GoNext2(now2); 
    printf("After GoNext2, now2 points to: %s\n", (*now2)->name);

    return 0;
}


void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}


void GoNext1(struct studentNode **walk) {
    if (*walk != NULL && (*walk)->next != NULL) {
        *walk = (*walk)->next; 
        printf("%s ", (*walk)->name); 
    }
}


void GoNext2(struct studentNode **walk) {
    if (*walk != NULL && (*walk)->next != NULL) {
        *walk = (*walk)->next;
        printf("%s ", (*walk)->name);
    }
}
