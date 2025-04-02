#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100007  // A prime number for better hash distribution

typedef struct Node {
    long long key;
    long long value;
    struct Node* next;
} Node;

long long countBadPairs(int* nums, int numsSize) {
    long long totalPairs = (long long)numsSize * (numsSize - 1) / 2;
    Node** hashTable = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    
    long long goodPairs = 0;
    
    for (int i = 0; i < numsSize; i++) {
        long long diff = (long long)nums[i] - i;
        long long hash = (diff < 0 ? -diff : diff) % HASH_SIZE;
        
        Node* curr = hashTable[hash];
        while (curr != NULL) {
            if (curr->key == diff) {
                goodPairs += curr->value;
                curr->value++;
                break;
            }
            curr = curr->next;
        }
        
        if (curr == NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->key = diff;
            newNode->value = 1;
            newNode->next = hashTable[hash];
            hashTable[hash] = newNode;
        }
    }
    
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashTable);
    
    return totalPairs - goodPairs;
}