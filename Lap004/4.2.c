#include <stdio.h>
#include <stdlib.h> 

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;


struct student upgrade( struct student child ) {
    if ( child.sex == 'M' ) {
        child.gpa = child.gpa * 1.10 ;
    } else if ( child.sex == 'F' ) {
        child.gpa = child.gpa * 1.20 ; 
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

    struct student (*child)[ 10 ] = malloc( (*room) * sizeof( struct student[ 10 ] ) ) ;
    return child ;
}


void go1( int **p, int *z ) {
    *p = z ; 
}

void go2( int ***p, int **z ) {
    *p = z ; 
}


int main() {

    struct student s = { "John", 20, 'M', 3.00 } ;
    s = upgrade( s ) ;
    printf( "Upgraded GPA: %.2f\n", s.gpa ) ;

    int *a, b = 10, c = 20 ;
    go1( &a, &b ) ;
    printf( "a points to: %d\n", *a ) ;
    go1( &a, &c ) ;
    printf( "a now points to: %d\n", *a ) ;

    return 0 ;
}
