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
    scanf( "%d", room ) ; //
    for ( int i = 0 ; i < *room ; i++ ) {
        for ( int j = 0 ; j < 10 ; j++ ) {
           
            scanf( "%s %d %c %f", child[i][j].name, &child[i][j].age, &child[i][j].sex, &child[i][j].gpa ) ; 
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


void checkGrade( int score ) {
    if ( score >= 80 ) printf( "Grade A" ) ;
    else if ( score >= 70 ) printf( "Grade B" ) ;
    else if ( score >= 60 ) printf( "Grade C" ) ;
    else if ( score >= 50 ) printf( "Grade D" ) ;
    else printf( "Grade F" ) ; 
}

int main() {
  
    struct student aboy ;
    aboy.sex = 'M' ; aboy.gpa = 3.00 ;
    aboy = upgrade( aboy ) ;
    printf( "Upgrade GPA: %.2f\n", aboy.gpa ) ;

   
    int *a, b = 10, c = 20 ;
    go( &a, &b ) ;
    printf( "a points to: %d\n", *a ) ;
    go( &a, &c ) ;
    printf( "a points to: %d\n", *a ) ;

    return 0 ;
}
