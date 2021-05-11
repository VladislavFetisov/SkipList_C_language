#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Main.h"

int main() {
    SkipList skipList;
    skipList.table = NULL;
    skipList.tail = 0;
    skipList.levelCapacity = NULL;
    addNewLevel(&skipList);
    skipInsert(12, &skipList);
    printSkipList(&skipList);
    return EXIT_SUCCESS;
}
