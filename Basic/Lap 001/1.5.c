#include <stdio.h>

int main() {
    int number ;
    int evenSum = 0 ;
    int oddSum = 0 ;

    printf( "Enter integers (0 to stop) : " ) ;

    while (1) {
    
        if (scanf( "%d", &number) != 1) {
            break ; 
        }

    
        if (number == 0 ) {
            break;
        }

    
        if (number % 2 == 0) {
            
            evenSum += number ;
        } else {

            oddSum += number ;
        }
    }


    printf( "\nEven Sum: %d\n" , evenSum ) ;
    printf( "Odd Sum: %d\n" , oddSum ) ;

    return 0 ;
}
