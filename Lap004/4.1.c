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
            printf( "Room %d, Student %d Name: ", i + 1, j + 1 ) ;
            scanf( "%s", child[ i ][ j ].name ) ;
            printf( "Age: " ) ;
            scanf( "%d", &child[ i ][ j ].age ) ;
            printf( "Sex (M/F): " ) ;
            scanf( " %c", &child[ i ][ j ].sex ) ; 
            printf( "GPA: " ) ;
            scanf( "%f", &child[ i ][ j ].gpa ) ;
        }
    }
}


struct student (*GetStudentPointer( int *room ))[ 10 ] {
    printf( "Enter number of rooms: " ) ;
    scanf( "%d", room ) ;
    
    struct student (*child)[ 10 ] = malloc( (*room) * sizeof( struct student[ 10 ] ) ) ;
    
    for ( int i = 0 ; i < *room ; i++ ) {
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf( "Room %d, Student %d Name: ", i + 1, j + 1 ) ;
            scanf( "%s", child[ i ][ j ].name ) ;
            printf( "GPA: " ) ;
            scanf( "%f", &child[ i ][ j ].gpa ) ;
        }
    }
    return child ;
}


void go( int **p, int *z ) {

    *p = z ;
}

int main() {
    struct student aboy ;
    aboy.sex = 'M' ;
    aboy.gpa = 3.00 ;
    aboy = upgrade( aboy ) ;
    printf( "--- Result Upgrade: %.2f ---\n\n", aboy.gpa ) ;

    int *a, b = 10, c = 20 ;
    go( &a, &b ) ;
    printf( "--- Result go (1): val=%d, addr=%p ---\n", *a, (void*)a ) ;
    go( &a, &c ) ;
    printf( "--- Result go (2): val=%d, addr=%p ---\n", *a, (void*)a ) ;

    return 0 ;
}
