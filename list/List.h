#include "../Global.h"

typedef struct list
{
    ListEntry entry[MAX_LIST];
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
int retrieveList(int, ListEntry *, List *);
void replaceList(int, ListEntry, List *);
void display(QueueEntry);
