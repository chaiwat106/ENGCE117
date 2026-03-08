#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

class LinkedList {
protected:
    struct studentNode *start , **now ;
public:
    LinkedList() {
        start = NULL ;
        now = &start ;
    }

    ~LinkedList() {
        struct studentNode *temp ;
        while (start != NULL) {
            temp = start ;
            start = start->next ;
            delete temp ;
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        struct studentNode *newNode = new studentNode ;
        strcpy( newNode->name, n ) ;
        newNode->age = a ;
        newNode->sex = s ;
        newNode->gpa = g ;
        newNode->next = NULL ;

        struct studentNode **temp = &start ;
        while (*temp != NULL) {
            temp = &((*temp)->next) ;
        }
        *temp = newNode ;
    }

    void DelNode() {
        if (*now != NULL) {
            struct studentNode *temp = *now ;
            *now = (*now)->next ;
            delete temp ;
        }
    }

    void GoNext() {
        if (*now != NULL && (*now)->next != NULL ) {
            now = &((*now)->next) ;
        }
    }

    void GoFirst() {
        now = &start ;
    }

    void GoLast() {
        now = &start ;
        while (*now != NULL && (*now) -> next != NULL ) {
            now = &( ( *now)->next ) ;
        }
    }

    void ShowAll() {
        struct studentNode *temp = start ;
        while (temp != NULL) {
            printf( "%-20s %3d %2c %5.2f\n" , temp->name , temp->age , temp->sex , temp->gpa) ;
            temp = temp->next ;
        }
    }

    int FindNode(char n[]) {
        now = &start ;
        while (*now != NULL) {
            if ( strcmp((*now)->name , n) == 0) return 1 ;
            now = &((*now)->next) ;
        }
        return 0 ;
    }

    struct studentNode *NowNode() {
        return *now ;
    }

    void EditNode(char n[] , int a , char s , float g ) {
        if ( *now != NULL ) {
            strcpy(( *now)->name , n ) ;
            (*now)->age = a ;
            (*now)->sex = s ;
            (*now)->gpa = g ;
        }
    }

    struct studentNode* getStart() { return start ; }
};

void AddData(LinkedList *l1) {
    char n[20] , s ;
    int a ;
    float g ;
    printf( "Enter Name: " ) ; scanf( "%s", n ) ;
    printf( "Enter Age: " ) ; scanf( "%d", &a ) ;
    printf( "Enter Sex (M/F): " ) ; scanf( " %c", &s ) ;
    printf( "Enter GPA: " ) ; scanf( "%f" , &g ) ;
    l1->InsNode (n , a , s , g ) ;
}

void EditData(LinkedList *l1) {
    char n[20] ;
    printf( "Enter Name to Edit: " ) ; scanf( "%s" , n ) ;
    if ( l1->FindNode(n)) {
        char newN[20] , s ;
        int a ;
        float g ;
        printf( "New Name: " ) ; scanf( "%s", newN ) ;
        printf( "New Age: " ) ; scanf( "%d", &a ) ;
        printf( "New Sex: " ) ; scanf( " %c", &s ) ;
        printf( "New GPA: " ) ; scanf( "%f", &g ) ;
        l1->EditNode( newN, a , s , g ) ;
    } else {
        printf( "Student not found.\n" ) ;
    }
}

void FindData( LinkedList *l1 ) {
    char n[20] ;
    printf("Enter Name to Find: " ) ; scanf("%s", n) ;
    if ( l1->FindNode(n)) {
        struct studentNode *curr = l1->NowNode() ;
        printf( "Found: %s %d %c %.2f\n" , curr->name , curr->age , curr->sex , curr->gpa ) ;
    } else {
        printf( "Student not found.\n" ) ;
    }
}

void readfile(LinkedList *l1) {
    FILE *fp = fopen( "student.dat" , "rb" ) ;
    if ( fp == NULL ) return ;
    struct studentNode temp ;
    while ( fread( &temp, sizeof( struct studentNode) , 1 , fp ) ) {
        l1 -> InsNode( temp.name , temp.age , temp.sex , temp.gpa ) ;
    }
    fclose(fp) ;
}

void writefile( LinkedList *l1) {
    FILE *fp = fopen("student.dat", "wb") ;
    if ( fp == NULL) return ;
    l1 -> GoFirst() ;
    struct studentNode *temp = l1->getStart() ;
    while (temp != NULL) {
        fwrite( temp , sizeof( struct studentNode) , 1 , fp ) ;
        temp = temp -> next ;
    }
    fclose(fp) ;
}

int main() {
    LinkedList listA ;
    int menu ;
    readfile(&listA) ;
    
    do {
        printf("\nMenu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : " ) ;
        scanf( "%d" , &menu ) ;
        switch (menu) {
            case 1: AddData(&listA) ; break ;
            case 2: EditData(&listA) ; break ;
            case 3: 
                char n[20] ;
                printf( "Enter Name to Delete: " ) ; scanf("%s", n ) ;
                if (listA.FindNode(n)) listA.DelNode() ;
                else printf( "Not found.\n" ) ;
                break ;
            case 4: FindData(&listA) ; break ;
            case 5: listA.ShowAll() ; break ;
        }
    } while ( menu != 0) ;

    writefile( &listA ) ;
    return 0 ;
}
