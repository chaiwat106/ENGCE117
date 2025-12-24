#include <stdio.h>

struct student {
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
};

// เปลี่ยนมารับค่าเป็น Pointer (ใช้เครื่องหมาย *)
void upgrade( struct student *child ) {
    if( child -> sex == 'M' ) {
        child -> gpa = child -> gpa * 1.10 ; // ใช้เครื่องหมาย -> เพื่อเข้าถึงสมาชิกผ่าน Pointer
    } else if( child -> sex == 'F' ) {
        child -> gpa = child -> gpa * 1.20 ;
    }
}

int main() {
    struct student aboy ;
    aboy.sex = 'M' ;
    aboy.gpa = 3.00 ;

    // ส่งที่อยู่ของ aboy ไปด้วยเครื่องหมาย &
    upgrade( &aboy ) ; 

    printf( "Updated GPA: %.2f" , aboy.gpa ) ; // ผลลัพธ์จะเป็น 3.30
    return 0 ;
}
