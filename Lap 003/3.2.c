#include <stdio.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

// 1. ส่วนการสร้างฟังก์ชัน (Function Definition)
void upgrade( struct student *child ) {
    // ใช้เครื่องหมาย -> เพราะรับค่ามาเป็น Pointer
    if( child -> sex == 'M' ) {
        child -> gpa = child -> gpa * 1.10 ; // เพิ่ม 10%
    } else if( child -> sex == 'F' ) {
        child -> gpa = child -> gpa * 1.20 ; // เพิ่ม 20%
    }
}

int main() {
    struct student aboy ;
    aboy.sex = 'M' ;
    aboy.gpa = 3.00 ;

    // 2. ส่วนการเรียกใช้ฟังก์ชัน (Function Call)
    // ในภาพโจทย์เขียนว่า upgrade( aboy ); ซึ่งจะ Error 
    // ต้องแก้เป็น upgrade( &aboy ); เพื่อส่ง Address ของ aboy ไป
    upgrade( &aboy ) ; 

    printf( "%.2f", aboy.gpa ) ; // ผลลัพธ์จะออกมาเป็น 3.30
    return 0 ;
}
