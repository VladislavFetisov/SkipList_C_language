#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Main.h"

int main() {
    SkipList skipList = buildSkipList();
    addNewLevel(&skipList);
    addNewLevel(&skipList);
//    skipInsert(12, &skipList);
    printSkipList(&skipList);
//    Node *nodes = NULL;
//    nodes = calloc(2, sizeof(Node));
//    Node first = {INT_MIN, NULL, NULL, NULL};
//    Node last = {INT_MAX, NULL, &first, NULL};
//    first.right = &last;
//
//    nodes[0]=first;
//    nodes[1]=last;
//    Node current=nodes[0];
//    while (2>current.key)

    return EXIT_SUCCESS;
}
