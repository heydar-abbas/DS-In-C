#include <stdio.h>
#include "List.h"

void main(void)
{
    List list;
    ListEntry le;

    createList(&list);

    /*****************  Insert into List  *****************/
    for (int i = 10; i <= 60; i += 10)
    {
        int pos = 0;
        le.data = i;
        if (!insertList(pos++, le, &list))
            printf("\n List is Full!! \n\n");
    }
    /*
    User level check "post condition"
    if (!listFull(&list))
        insertList(pos++, le, &list);
    else
        printf("The List is full!");
    */
    /*****************  Traverse all List  *****************/
    printf("Size of List: [ %d ]\n", listSize(&list));
    if (!traverseList(&list, &display))
        printf("List is empty!");

    /*****************  Delete from List  *****************/
    deleteList(3, &le, &list);
    printf("\n\nAfter delete from position 3:\n");
    printf("Size of List: [ %d ]\n", listSize(&list));
    printf("Delete value: [ %d ]\n", le);
    if (!traverseList(&list, &display))
        printf("List is empty!");
    /*
    User level check "post condition"
    if (!listEmpty(&list))
        deleteList(3, &le, &list);
    else
        printf("The List is empty!");
    */
    /*****************  Replace  *****************/
    le.data = 100;
    replaceList(2, le, &list);
    printf("\n\nAfter replace to position 2:\n");
    printf("Size of List: [ %d ]\n", listSize(&list));
    if (!traverseList(&list, &display))
        printf("List is empty!");

    /*****************  Retrieve from List  *****************/
    retrieveList(2, &le, &list);
    printf("\n\nRetrieve Value is [ %d ]\n", le.data);

    /*****************  Clear List  *****************/
    createList(&list);
    printf("\nClear List:\n");
    printf("Size of List: [ %d ]\n", listSize(&list));
    if (!traverseList(&list, &display))
        printf("List is empty!");
}

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

int insertList(int pos, ListEntry le, List *pl)
{
    if (listFull(pl))
        return 0;
    for (int i = pl->size - 1; i >= pos; i--)
        pl->entry[i + 1] = pl->entry[i];
    pl->entry[pos] = le;
    pl->size++;
    return 1;
}

void deleteList(int pos, ListEntry *ple, List *pl)
{
    *ple = pl->entry[pos];
    for (int i = pos + 1; i <= pl->size - 1; i++)
        pl->entry[i - 1] = pl->entry[i];
    pl->size--;
}

int retrieveList(int pos, ListEntry *ple, List *pl)
{
    if (listEmpty(pl))
        return 0;
    *ple = pl->entry[pos];
    return 1;
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