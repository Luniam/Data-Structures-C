#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void CountTest() {
    List myList = buildWithLocalRef(10);
    appendNode(&myList, 2);
    appendNode(&myList, 2);
    int count = Count(myList, 2);
    // returns 3 since there are 3 '2' in the list
    printf("%d\n", count);
    DeleteList(&myList);
}

void GetNthTest() {
    List myList = buildWithLocalRef(10);
    //should return 3
    int lastNode = GetNth(myList, 2);
    printf("%d\n", lastNode);
    DeleteList(&myList);
}

void PopTest() {
    List myList = buildWithLocalRef(10);
    int one = Pop(&myList);
    for (int i = 0; i < 9; ++i) {
        Pop(&myList);
    }
    int len = length(myList);
    printf("%d %d\n", one, len);
    DeleteList(&myList);
}

void InsertNthTest() {
    struct node* head = NULL;
    for (int i = 0; i < 10; ++i) {
        InsertNth(&head, i, i);
    }
    InsertNth(&head, 0, 13);
    InsertNth(&head, 1, 42);
    InsertNth(&head, 1, 5);
    printList(head);
    DeleteList(&head);
}

void SortedInsertTest() {
    List myList = buildWithLocalRef(10);
    for (int i = 21; i >= 10; --i) {
        struct node *a = malloc(sizeof(struct node));
        a->data = i;
        SortedInsert(&myList, a);
    }
    printList(myList);
    DeleteList(&myList);
}

int main(void) {
    printf("%s\n", "###Linked List###");
    printf("%s\n", "count test");
    CountTest();

    printf("%s\n", "getnth test");
    GetNthTest();

    printf("%s\n", "pop test");
    PopTest();

    printf("%s\n", "insert nth test");
    InsertNthTest();

    printf("%s\n", "sorted insert test");
    SortedInsertTest();
}