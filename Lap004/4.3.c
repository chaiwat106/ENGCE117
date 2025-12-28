#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

struct student upgrade( struct student child ) {
    if ( child.sex == 'M' ) {
        child.gpa *= 1.10 ; 
    } else if ( child.sex == 'F' ) {
        child.gpa *= 1.20 ; 
    }
    return child ;
}


void GetStudent( struct student child[][ 10 ], int *room ) {
    printf( "Enter number of rooms: " ) ;
    scanf( "%d", room ) ;
    for ( int i = 0 ; i < *room ; i++ ) {
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf( "Room %d Student %d Name: ", i + 1, j + 1 ) ;
            scanf( "%s", child[ i ][ j ].name ) ;
            scanf( " %c", &child[ i ][ j ].sex ) ;
            scanf( "%f", &child[ i ][ j ].gpa ) ;
        }
    }
}


struct student (*GetStudentPointer( int *room ))[ 10 ] {
    printf( "Enter number of rooms: " ) ;
    scanf( "%d", room ) ;
    struct student (*child)[ 10 ] = (struct student(*)[10])malloc( (*room) * sizeof( struct student[ 10 ] ) ) ;
    return child ;
}


void go( int **p, int *z ) {
    *p = z ;
}


void goTriple( int ***p, int **z ) {
    *p = z ;
}

void SaveNode( struct studentNode *child, char n[], int a, char s, float g ) {
    strcpy( child->name, n ) ;
    child->age = a ;
    child->sex = s ;
    child->gpa = g ;
    child->next = NULL ;
}


void GoNext1( struct studentNode **walk ) {
    if ( (*walk)->next != NULL ) {
        *walk = (*walk)->next ;
        printf( "Next Node Name: %s\n", (*walk)->name ) ;
    }
}

int main() {
  
    struct student aboy ;
    aboy.sex = 'M' ; aboy.gpa = 3.00 ;
    aboy = upgrade( aboy ) ;
    printf( "Upgrade Result: %.2f\n", aboy.gpa ) ;

   
    int *a, b = 10, c = 20 ;
    go( &a, &b ) ;
    printf( "a points to b: %d\n", *a ) ;

    struct studentNode *start, *now1 ;
    start = (struct studentNode*)malloc(sizeof(struct studentNode)) ;
    SaveNode( start, "one", 6, 'M', 3.11 ) ;
    start->next = (struct studentNode*)malloc(sizeof(struct studentNode)) ;
    SaveNode( start->next, "two", 8, 'F', 3.22 ) ;

    now1 = start ;
    GoNext1( &now1 ) ; 

    return 0 ;
}
