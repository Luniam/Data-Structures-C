#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int length(struct node *head) {
    int len = 0;
    while(head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

//build a simple linked list with three nodes
struct node *buildStart() {
    struct node *head = malloc(sizeof(struct node));
    struct node *second  = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));

    head->data = 1; 
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

void printList(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data); // *(head).data = head->data
        head = head->next;
    }
    printf("\n");
}

//wrong push code, kept for differentiating the currect one
void wrongPush(struct node *head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void push(struct node **headRef, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

//constructs a new linked list from the array by adding elements to the head
struct node *addAtHead(int *array, int length) {
    struct node *head = NULL;
    int i;
    for(i = 0; i < length; i++) {
        push(&head, *array++); // push(&head, array[i]);
    }
    return head;
}

struct node *buildWithSpecialCase(int num) {
    struct node *head = NULL;
    push(&head, 1);
    struct node *tail = head;
    int i;
    for(i = 2; i <= num; i++) {
        push(&tail->next, i);
        tail = tail->next;
    }
    return head;
}

struct node *buildWithDummyNode(int num) {
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = NULL;
    int i;
    for(i = 1; i <= num; i++) {
        push(&tail->next, i);
        tail = tail->next;
    }
    return dummy.next;
}

struct node *buildWithLocalRef(int num) {
    struct node *head = NULL;
    struct node **lastPtrRef = &head;
    int i;
    for(i = 1; i <= num; i++) {
        push(lastPtrRef, i);
        lastPtrRef = &((*lastPtrRef)->next);    
    }
    return head;
}

void appendNode(struct node **headRef, int num) {
    struct node *current = *headRef;
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = num;

    if (current == NULL) {
        *headRef = newNode;
    }
    else {
        while((current->next) != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//appends a new node with the help of the push function
void appendNodeWithPush(struct node **headRef, int num) {
    struct node *current = *headRef;

    if (current == NULL) {
        push(headRef, num);
    }
    else {
        while((current->next) != NULL) {
            current = current->next;
        }
        push(&(current->next), num);
    }
}

struct node *copyListA(struct node *head) {
    struct node *current = head;
    struct node *newList = NULL;
    struct node *tail = NULL;

    if (newList == NULL) {
        newList = malloc(sizeof(struct node));
        newList->data = current->data;
        newList->next = NULL;
        tail = newList;
        current = current->next;
    }

    while(current != NULL) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = current->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        current = current->next;
    }
    return newList;
}

struct node *copyListB(struct node *head) {
    struct node *current = head;
    struct node *newList = NULL;
    struct node *tail = NULL;

    while(current!= NULL) {
        if (newList == NULL) {
            newList = malloc(sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else {
            struct node *newNode = malloc(sizeof(struct node));
            newNode->data = current->data;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
        current = current->next;
    }
    return newList; 
}

struct node *copyListWithPush(struct node *head) {
    struct node *current = head;
    struct node *newList = NULL;
    struct node *tail = NULL;

    while(current != NULL) {
        if (newList == NULL) {
            push(&newList, current->data);
            tail = newList;
        }
        else {
            push(&(tail->next), current->data);
            tail = tail->next;
        }
        current = current->next;
    }
    return newList;
}