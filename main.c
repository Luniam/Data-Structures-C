#include <stdio.h>
#include "linkedlist.h"

void CountTest() {
    List myList = buildWithLocalRef(10);
    appendNode(&myList, 2);
    appendNode(&myList, 2);
    int count = Count(myList, 2);
    // returns 3 since there are 3 '2' in the list
    printf("%d\n", count);
}

void GetNthTest() {
    List myList = buildWithLocalRef(10);
    //should return 3
    int lastNode = GetNth(myList, 2);
    printf("%d\n", lastNode);
}

int main(void) {
    printf("%s\n", "###Linked List###");
    printf("%s\n", "count test");
    CountTest();

    printf("%s\n", "getnth test");
    GetNthTest();
}