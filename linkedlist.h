#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct node {
    int data;
    struct node *next;
};

typedef struct node *List;

int length(struct node *head);
struct node *buildStart();
void printList(struct node *head);
void wrongPush(struct node *head, int data);
void push(struct node **headRef, int data);
struct node *addAtHead(int* array, int length);
struct node *buildWithSpecialCase(int num);
struct node *buildWithDummyNode(int num);
struct node *buildWithLocalRef(int num);
void appendNode(struct node **headRef, int num);
void appendNodeWithPush(struct node **headRef, int num);
struct node *copyListA(struct node *head);
struct node *copyListB(struct node *head);
struct node *copyListWithPush(struct node *head);
int Count(struct node *head, int searchFor);
int GetNth(struct node* head, int index);
#endif