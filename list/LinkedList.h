#include "../Global.h"

typedef struct listNode
{
    ListEntry entry;
    struct listNode *next;
} ListNode;

typedef struct list
{
    ListNode *head;
    int size;
} List;

void createList(List *);
int destroyList(List *);
int listEmpty(List *);
int listFull(List *);
int listSize(List *);
int insertList(int, ListEntry, List *);
void deleteList(int, ListEntry *, List *);
int traverseList(List *, void (*pf) (ListEntry));
void retrieveList(int, ListEntry *, List *);
void replaceList(int, ListEntry, List *);
void display(ListEntry);
