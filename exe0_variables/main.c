#include <stdio.h> 

int a = 0; 
int b = 0; 

void foo(void) {
    a = a + 1;
}

int main(void) {
    while (a <= 10) { 
        foo();
        
        if (a > 5) {
            b = 1;
        }
    }
    return 0;
}