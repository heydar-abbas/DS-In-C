#include <stdio.h>
#include "ArrayList.h"

void createList(List *pl)
{
    pl->size = 0;
}

int destroyList(List *pl)
{
    pl->size = 0;
    return 1;
}

int listEmpty(List *pl)
{
    return !pl->size;
}

int listFull(List *pl)
{
    return pl->size == MAX_LIST;
}

int listSize(List *pl)
{
    return pl->size;
}

void insertList(int pos, ListEntry le, List *pl)
{
    for (int i = pl->size - 1; i >= pos; i--)
        pl->entry[i + 1] = pl->entry[i];
    pl->entry[pos] = le;
    pl->size++;
}

void deleteList(int pos, ListEntry *ple, List *pl)
{
    *ple = pl->entry[pos];
    for (int i = pos + 1; i <= pl->size - 1; i++)
        pl->entry[i - 1] = pl->entry[i];
    pl->size--;
}

void retrieveList(int pos, ListEntry *ple, List *pl)
{
    *ple = pl->entry[pos];
}

void replaceList(int pos, ListEntry le, List *pl)
{
    pl->entry[pos] = le;
}

int traverseList(List *pl, void (*pf)(ListEntry))
{
    if (listEmpty(pl))
        return 0;
    for (int i = 0; i < pl->size; i++)
        (*pf)(pl->entry[i]);
    return 1;
}

void display(ListEntry le)
{
    printf(" %d ", le);
}