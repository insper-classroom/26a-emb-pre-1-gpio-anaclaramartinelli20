#include <stdio.h>

static int foo(int a) {
    return a + 1;
}

int main(void) {
    int a = 0;
    int b = 0;

    while (a <= 10) {
        a = foo(a);

        if (a > 5) {
            b = 1;
        }
    }

    return 0;
}