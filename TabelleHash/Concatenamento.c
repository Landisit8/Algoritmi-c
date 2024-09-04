#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int hash_index = hash_function(key);
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = hash_table[hash_index];
    hash_table[hash_index] = new_node;
}

Node* search(int key) {
    int hash_index = hash_function(key);
    Node* current = hash_table[hash_index];
    while (current != NULL) {
        if (current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}

void delete(int key) {
    int hash_index = hash_function(key);
    Node* current = hash_table[hash_index];
    Node* prev = NULL;
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return;
    if (prev == NULL) {
        hash_table[hash_index] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

int main() {
    insert(10, 50);
    insert(20, 100);
    Node* result = search(10);
    if (result != NULL) {
        printf("Value at key 10: %d\n", result->value);
    }
    delete(10);
    result = search(10);
    if (result == NULL) {
        printf("Key 10 not found after deletion.\n");
    }
    return 0;
}
