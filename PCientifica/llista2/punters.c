#include <stdio.h>

int main ( v o i d ) {
i n t *p , x = 3210 , b ;
p r i n t f (” a d r e c e s de l e s v a r i a b l e s : \ n &p = %p &x = %p &b = %p\n ” ,
&p , &x , &b ) ;
p r i n t f (” c o n t i n g u t s : p = %p x = %d b = %d\n ” , p , x , b ) ;
p = &x ;
b = *p + 4 ;
p r i n t f (” c o n t i n g u t s : p = %p x = %d b = %d\n ” , p , x , b ) ;
r e t u r n 0 ;
}
