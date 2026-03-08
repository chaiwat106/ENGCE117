#include <iostream>
#include <cstring>

using namespace std ;

struct studentNode {
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

class LinkedList {
protected :
    struct studentNode *start , **now ;
public :
    LinkedList() {
        start = NULL ;
        now = &start ;
    }

    ~LinkedList() {
        struct studentNode *temp ;
        while (start != NULL ) {
            temp = start ;
            start = start->next ;
            delete temp ;
        }
    }

    void InsNode( char n[] , int a , char s , float g ) {
        struct studentNode *newNode = new studentNode;
        strcpy( newNode->name , n ) ;
        newNode -> age = a ;
        newNode -> sex = s ;
        newNode -> gpa = g ;
        newNode -> next = NULL ;

        if (start == NULL) {
            start = newNode ;
            now = &start ;
        } else {
            struct studentNode *temp = start ;
            while ( temp->next != NULL) {
                temp = temp->next ;
            }
            temp ->next = newNode ;
        }
    }

    void InsertNode( char n[] , int a , char s , float g ) {
        InsNode( n , a , s , g ) ;
    }

    void DelNode() {
        if ( *now != NULL ) {
            struct studentNode *temp = *now ;
            *now = ( *now ) -> next ;
            delete temp ;
        }
    }

    void GoNext() {
        if ( *now != NULL && ( *now ) -> next != NULL)  {
            now = &( ( *now ) -> next ) ;
        }
    }

    virtual void ShowNode() {
        if (*now != NULL) {
            cout << ( *now ) -> name << " " << ( *now ) -> age << " " << ( *now ) -> sex << " " << ( *now ) -> gpa << endl ;
        }
    }
} ;

class NewList : public LinkedList {
public :
    void GoFirst() {
        now = &start ;
    }

    virtual void ShowNode() {
        struct studentNode *temp = start ;
        while ( temp != NULL ) {
            cout << temp -> name << " " << temp -> age << " " << temp -> sex << " " << temp -> gpa << endl ;
            temp = temp -> next ;
        }
    }
};

int main() {
    LinkedList listA ;
    NewList listB ;
    LinkedList *listC ;

    listA.InsNode( "one", 1 , 'A' , 1.1 ) ;
    listA.InsNode( "two", 2 , 'B' , 2.2 ) ;
    listA.InsNode( "three" , 3 , 'C' , 3.3 ) ;
    listA.GoNext() ;
    listA.ShowNode() ;

    listB.InsertNode( "four" , 4 , 'D' , 4.4 ) ;
    listB.InsertNode( "five" , 5 , 'E' , 5.5 ) ;
    listB.InsertNode( "six" , 6 , 'F' , 6.6 ) ;
    listB.GoNext() ;
    listB.DelNode() ;
    listB.ShowNode() ;

    listC = &listA ;
    listC -> GoNext() ;
    listC -> ShowNode() ;

    listC = &listB ;
    listC -> ShowNode() ;

    return 0 ;
}
