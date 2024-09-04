#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
    bool occupied;
} HashItem;

HashItem hash_table[TABLE_SIZE];

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void insert_open_addressing(int key, int value) {
    int hash_index = hash_function(key);
    int original_index = hash_index;
    while (hash_table[hash_index].occupied) {
        hash_index = (hash_index + 1) % TABLE_SIZE;
        if (hash_index == original_index) return; // Table is full
    }
    hash_table[hash_index].key = key;
    hash_table[hash_index].value = value;
    hash_table[hash_index].occupied = true;
}

int search_open_addressing(int key) {
    int hash_index = hash_function(key);
    int original_index = hash_index;
    while (hash_table[hash_index].occupied) {
        if (hash_table[hash_index].key == key)
            return hash_table[hash_index].value;
        hash_index = (hash_index + 1) % TABLE_SIZE;
        if (hash_index == original_index) break;
    }
    return -1; // Key not found
}

void delete_open_addressing(int key) {
    int hash_index = hash_function(key);
    int original_index = hash_index;
    while (hash_table[hash_index].occupied) {
        if (hash_table[hash_index].key == key) {
            hash_table[hash_index].occupied = false;
            return;
        }
        hash_index = (hash_index + 1) % TABLE_SIZE;
        if (hash_index == original_index) return; // Key not found
    }
}

int main() {
    insert_open_addressing(10, 50);
    insert_open_addressing(20, 100);
    printf("Value at key 10: %d\n", search_open_addressing(10));
    delete_open_addressing(10);
    printf("Value at key 10 after deletion: %d\n", search_open_addressing(10));
    return 0;
}
