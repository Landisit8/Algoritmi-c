#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10

int hash_function_division(int key) {
    return key % TABLE_SIZE;
}

int hash_function_multiplication(int key) {
    double A = 0.618033; // Moltiplicazione con costante frazionaria (derivata dalla sezione aurea)
    double integer_part;
    double fractional_part = modf(key * A, &integer_part);
    return (int)(TABLE_SIZE * fractional_part);
}

int main() {
    int key = 1234;
    printf("Hash index (Division Method): %d\n", hash_function_division(key));
    printf("Hash index (Multiplication Method): %d\n", hash_function_multiplication(key));
    return 0;
}
