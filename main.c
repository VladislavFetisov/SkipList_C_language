#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "Main.h"

int main() {
    SkipList *skipList = makeSkipList();
    srand(time(NULL));
    skipInsert(10, skipList,rand());
    skipInsert(6, skipList, rand());
    skipInsert(78, skipList, rand());
    skipInsert(15, skipList, rand());
    skipInsert(-20, skipList, rand());
    skipInsert(-20, skipList, rand());
    skipInsert(10, skipList, rand());
    printSkipList(skipList);
    return EXIT_SUCCESS;
}
