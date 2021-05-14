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
    struct Node ***table;
    int *levelCapacity;
    int tail;
} SkipList;

void addNewLevel(struct SkipList *skipList);

void skipInsert(int number, SkipList *skipList,int randomNumber);

void printSkipList(struct SkipList *skipList);

struct SkipList *makeSkipList();

struct Node *makeNode(int value);

#endif //SKIPLIST_MAIN_H
