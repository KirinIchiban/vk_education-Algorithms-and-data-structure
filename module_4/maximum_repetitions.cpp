#include <iostream>
#include <cstring>
using namespace std;


struct node {
    char key;
    int value;
    struct node* next;
};

struct hashMap {
    int numOfElements, capacity;
    // hold base address array of linked list
    struct node** arr;
};


void create_node(struct node* node, char key, int value) {
    node->key = key;
    node->value = value;
    node->next = NULL;
    return;
}


// like constructor
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node**)calloc(mp->capacity, sizeof(struct node*));
    return;
}

int hashFunction(struct hashMap* mp, char key) {
    int bucketIndex;
    string nkey = to_string(key);
    int sum = 0, factor = 31;
    for (int i = 0; i < nkey.size(); i++) {
        // sum = sum + (ascii value of
        // char * (primeNumber ^ x))...
        // where x = 1, 2, 3....n
        sum = ((sum % mp->capacity) + (((int)nkey[i]) * factor) % mp->capacity) % mp->capacity;
        // factor = factor * prime
        // number....(prime
        // number) ^ x
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    bucketIndex = sum;
    return bucketIndex;
}

void insert(struct hashMap* mp, char key, int value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    create_node(newNode, key, value);
    // Bucket index is empty....no collision
    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
        mp->numOfElements++;
    }
    // Collision
    else {
        // Adding newNode at the head of
        // linked list which is present
        // at bucket index....insertion at
        // head in linked list
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
        mp->numOfElements++;
    }
    return;
}

void deleteKey(struct hashMap* mp, char key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];
    while (currNode != NULL) {
        if (key == currNode->key) {
            // Head node deletion
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            }
            // Last node or middle node
            else {
                prevNode->next = currNode->next;
            }
            free(currNode);
            break;
        }

        prevNode = currNode;
        currNode = currNode->next;
    }
    return;
}

int search(struct hashMap* mp, char key) {
    // Getting the bucket index for the given key
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        // Key is found in the hashMap
        if (bucketHead->key == key) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }

    // If no key found in the hashMap equal to the given key
    return -1;
}


int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);
    string word;
    getline(cin, word);
   
    for (int i = 0; i < word.size(); i++) {
        int found = search(mp, word[i]);
        if (found != -1) {
            int buf = hashFunction(mp, word[i]);
            node* temp = mp->arr[buf];
            while (temp != NULL) {
                if (temp->key == word[i]) {
                    temp->value++;
                    break;
                }
                temp = temp->next;
            }
        }
        else { insert(mp, word[i], 1); }
    }

    int max = 0;
    for (int i = 0; i < mp->capacity; i++) {
        node* temp = mp->arr[i];
        while (temp != NULL) {
            if (temp->value > max) {
                max = temp -> value;
            }
            temp = temp->next;
        }
    }
    cout << max <<'\n';

    return 0;
}