#include <stdio.h>

#define NUM_ELEMENTS 5

static int multiplyNumbers(int x, int y) {
    return x * y;
}

int main(void) {
    int a = 5;
    int b = 5;

    int result = multiplyNumbers(a, b);
    printf("Result: %d\n", result);

    int arr[NUM_ELEMENTS];

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = i;
    }

    return 0;
}