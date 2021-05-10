//
// Created by fetis on 07.05.2021.
//

#ifndef SKIPLIST_MAIN_H
#define SKIPLIST_MAIN_H

typedef struct Node {
    int key;
    struct Node *down;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct SkipList {
    struct Node **table;
    int *levelCapacity;
    int tail;
} SkipList;

struct SkipList buildSkipList();

void addNewLevel(struct SkipList *skipList);

void skipInsert(int number, struct SkipList *skipList);

void printSkipList(struct SkipList *skipList);

#endif //SKIPLIST_MAIN_H
