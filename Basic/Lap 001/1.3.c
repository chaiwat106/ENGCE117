#include <stdio.h>

int main() {
    int score ;

        printf( "Enter your score: " ) ;
    if ( scanf( "%d" , &score) != 1 ) {
        return 1 ;
    }


    if (score >= 80) {
        printf( "Grade A" ) ;
    } else if ( score >= 70 ){
        printf( "Grade B" ) ;
    } else if ( score >= 60) {
        printf( "Grade C" ) ;
    } else if ( score >= 50 ) {
        printf( "Grade D" ) ;
    } else if( score < 50 ) {
        printf( "Grade F" ) ;
    }

    return 0 ;
} 
