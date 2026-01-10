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


void SaveNode( struct studentNode *child , char n[] , int a , char s , float g ) ;
void GoNext1( struct studentNode **walk ) ;

int main() {
    struct studentNode *start, *now1, **now2 ;
    
 
    start = new struct studentNode;
    SaveNode( start , "one" , 6 , 'M' , 3.11 ) ;
    

    start->next = new struct studentNode;
    SaveNode( start->next , "two" , 8 , 'F' , 3.22 ) ;
    

    start->next->next = new struct studentNode;
    SaveNode(start->next->next, "three", 10, 'M', 3.33);
    

    start->next->next->next = new struct studentNode;
    SaveNode( start->next->next->next , "four" , 12 , 'F' , 3.44 ) ;
    

    now1 = start ;
    now2 = &now1 ;

 
    GoNext1( &now1 ) ; 
    

    printf( "%s " , now1->name ) ; 

    return 0 ;
}


void GoNext1(struct studentNode **walk) {

    if ((*walk) != NULL && (*walk)->next != NULL) {
 
        *walk = (*walk)->next ;
        
    
        printf( "Current Node Name: %s\n" , (*walk)->name ) ;
        printf( "Age: %d, GPA: %.2f\n" , ( *walk ) -> age , ( *walk ) -> gpa ) ;
        printf( "--------------------\n" ) ;
    } else {
        printf("No next node available.\n" ) ;
    }
}

void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
    strcpy(child->name , n ) ;
    child->age = a ;
    child->sex = s ;
    child->gpa = g ;
    child->next = NULL ;
}
