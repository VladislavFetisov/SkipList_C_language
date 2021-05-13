#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Main.h"

int main() {
    SkipList *skipList = makeSkipList();
    skipInsert(10, skipList);
    printSkipList(skipList);
    return EXIT_SUCCESS;
}
