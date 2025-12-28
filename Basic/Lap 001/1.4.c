#include <stdio.h>

int main() {
    int N , sum = 0 , i ;

    if( scanf( "%d" , &N ) != 1 ) {
        printf( "Input error\n" ) ;
        return 1 ;
    }

    for( i = 1 ; i <= N ; i++ ) {
        sum += i ;
    }
    printf( "Sum = %d\n" , sum ) ;

    return 0 ;
}
