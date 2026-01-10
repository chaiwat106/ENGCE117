#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};


struct studentNode* AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa);
void InsNode(struct studentNode *now, char name[], int age, char sex, float gpa);
void DelNode(struct studentNode *now);
void ShowAll(struct studentNode *walk);

int main() {
    struct studentNode *start, *now;
    start = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11);   ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);   ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33);         ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44);          ShowAll(start);
    DelNode(now);                                 ShowAll(start);

    return 0;
}


struct studentNode* AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa) {
   
    while (*walk != NULL) {
        walk = &(*walk)->next;
    }

   
    *walk = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy((*walk)->name, name);
    (*walk)->age = age;
    (*walk)->sex = sex;
    (*walk)->gpa = gpa;
 
    (*walk)->next = NULL;

    return *walk; 
}


void InsNode(struct studentNode *now, char name[], int age, char sex, float gpa) {
    if (now == NULL) return;

    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

 
    struct studentNode *temp = now->next; 
    now->next = newNode;
    newNode->next = temp; 
}


void DelNode(struct studentNode *now) {
    if (now == NULL || now->next == NULL) return;


    struct studentNode *temp = now->next;
    now->next = temp->next;


    free(temp);
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}
