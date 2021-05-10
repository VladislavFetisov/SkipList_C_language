
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Main.h"


SkipList buildSkipList() {
    SkipList skipList;
    skipList.table = NULL;
    skipList.tail = 0;
    skipList.levelCapacity = NULL;
    addNewLevel(&skipList);
    return skipList;
}

void addNewLevel(SkipList *skipList) {
    skipList->tail++;
    skipList->table = realloc(skipList->table, skipList->tail * sizeof(struct Node *));
    skipList->table[skipList->tail - 1] = NULL;
    skipList->table[skipList->tail - 1] = calloc(2, sizeof(struct Node));
    Node first = {INT_MIN, NULL, NULL, NULL};
    Node last = {INT_MAX, NULL, NULL, NULL};
    if (skipList->tail != 1) {
        first.down = &skipList->table[skipList->tail - 2][0];
        last.down = &skipList->table[skipList->tail - 2][1];
    }
    last.left = &first;
    first.right = &last;
    skipList->table[skipList->tail - 1][0] = first;
    skipList->table[skipList->tail - 1][1] = last;

    skipList->levelCapacity = realloc(skipList->levelCapacity, skipList->tail * sizeof(int));
    skipList->levelCapacity[skipList->tail - 1] = 2;
}

void skipInsert(int number, SkipList *skipList) {
    int i = 0;
    do {
        i++;
        if (skipList->tail < i) addNewLevel(skipList);
    } while (rand() % 2 == 1);
    Node current = skipList->table[i - 1][0];
    Node *prevP = NULL;
    while (i != 0) {
        while (number > current.right->key) {
            current = *current.right;
        }
        if (current.right->key == current.key) return;
        skipList->levelCapacity[i - 1]++;
        skipList->table[i - 1] = realloc(skipList->table[i - 1], skipList->levelCapacity[i - 1] * sizeof(struct Node));
        Node new = {number, NULL, &current, current.right};
        if (i != skipList->tail) prevP->down = &new;

        skipList->table[i - 1][skipList->levelCapacity[i - 1] - 1] = new;
        prevP = &(skipList->table[i - 1][skipList->levelCapacity[i - 1] - 1]);
        current.right->left = &new;
        current.right = &new;
        current = *current.down;
        i--;
    }

}

void printSkipList(SkipList *skipList) {
    for (int i = skipList->tail - 1; i >= 0; --i) {
        printf("level:%d ", skipList->tail);
        for (int j = 0; j < skipList->levelCapacity[i]; ++j) {
            printf("%d ", skipList->table[i][j].key);
        }
        printf("\n");
    }
}