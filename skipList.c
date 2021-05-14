
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Main.h"

void addNewLevel(SkipList *skipList) {
    (skipList->tail)++;
    skipList->table = realloc(skipList->table, skipList->tail * sizeof(struct Node **));
    skipList->table[skipList->tail - 1] = NULL;
    skipList->table[skipList->tail - 1] = malloc(2 * sizeof(struct Node *));
    Node *first = makeNode(INT_MIN);
    Node *last = makeNode(INT_MAX);
    if (skipList->tail != 1) {
        first->down = (skipList->table[skipList->tail - 2][0]);
        last->down = (skipList->table[skipList->tail - 2][1]);
    }
    last->left = first;
    first->right = last;
    skipList->table[skipList->tail - 1][0] = first;
    skipList->table[skipList->tail - 1][1] = last;

    skipList->levelCapacity = realloc(skipList->levelCapacity, skipList->tail * sizeof(int));
    skipList->levelCapacity[skipList->tail - 1] = 2;
}

void skipInsert(int number, SkipList *skipList,int randomNumber) {
    int i = 0;
    do {
        i++;
        if (skipList->tail < i) {
            addNewLevel(skipList);
        }
    } while (rand() % 2 == 1);

    Node *current = NULL;
    current = skipList->table[i - 1][0];
    Node *prevP = NULL;

    while (i != 0) {
        while (number > current->right->key) {
            current = current->right;
        }
        if (current->right->key == number) return;

        (skipList->levelCapacity[i - 1])++;
        skipList->table[i - 1] = realloc(skipList->table[i - 1],
                                         skipList->levelCapacity[i - 1] * sizeof(struct Node *));


        Node *new = makeNode(number);
        new->left = current;
        new->right = current->right;
        if (prevP != NULL) prevP->down = new;

        skipList->table[i - 1][skipList->levelCapacity[i - 1] - 1] = new;
        current->right->left = new;
        current->right = new;
        prevP = new;
        i--;
        if (i == 0) break;
        current = current->down;
    }
}

void printSkipList(SkipList *skipList) {
    for (int i = skipList->tail - 1; i >= 0; --i) {
        printf("level:%d ", i + 1);
        Node *current = NULL;
        current = skipList->table[i][0];
        while (current->right != NULL) {
            printf("%d ", current->key);
            current = current->right;
        }
        printf("%d", current->key);
        printf("\n");
    }
}

struct Node *makeNode(int value) {
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->key = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->down = NULL;
    return temp;
}

struct SkipList *makeSkipList() {
    struct SkipList *skipList = (struct SkipList *) malloc(sizeof(struct SkipList));
    skipList->tail = 0;
    skipList->table = NULL;
    skipList->levelCapacity = NULL;
    addNewLevel(skipList);
    return skipList;
}