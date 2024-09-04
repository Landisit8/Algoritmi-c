//  indirizamento diretto nelle tabelle hash  

#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY 1000

int direct_address_table[MAX_KEY];

void insert_direct(int key, int value) {
    direct_address_table[key] = value;
}

int search_direct(int key) {
    return direct_address_table[key];
}

void delete_direct(int key) {
    direct_address_table[key] = 0;
}

int main() {
    insert_direct(10, 50);
    printf("Valore della chiave 10: %d\n", search_direct(10));
    delete_direct(10);
    printf("Valore alla chiave 10 dopo la cancellazione: %d\n", search_direct(10));
    return 0;
}