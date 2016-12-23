#include <stdio.h>
#include "linkedlist.h"

int main(void) {
    printf("%s\n", "build with local ref");
    struct node *head1 = buildWithLocalRef(6);
    printList(head1);

    printf("%s\n", "Append nodes to head1 with push");
    appendNodeWithPush(&head1, 7);
    appendNodeWithPush(&head1, 100);
    appendNodeWithPush(&head1, 500);
    printList(head1);

    printf("%s\n", "copying head1");
    struct node *head2 = copyListWithPush(head1);
    printList(head2);
}