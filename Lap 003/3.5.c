#include <stdio.h>
#include <stdlib.h> 

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

struct student (*GetStudent( int *room ) ) [ 10 ] {
    printf( "Enter number of rooms: " ) ;
    scanf( "%d", room ) ;

    struct student (*child)[ 10 ] = malloc( (*room) * sizeof( *child ) ) ;

    for ( int i = 0 ; i < *room ; i++ ) {
        for ( int j = 0 ; j < 10 ; j++ ) {
            scanf( "%s", child[ i ][ j ].name ) ;
            scanf( "%d", &child[ i ][ j ].age ) ;
            scanf( " %c", &child[ i ][ j ].sex ) ;
            scanf( "%f", &child[ i ][ j ].gpa ) ;
        }
    }
    return child ;
}

int main() {
    struct student ( *children )[ 10 ] ;
    int group ;
    children = GetStudent( &group ) ;

    return 0 ;
}
