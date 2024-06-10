#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    List list;
    ListEntry le;

    createList(&list);

    /*****************  Insert into List  *****************/
    for (int i = 10; i <= 60; i += 10)
    {
        int pos = 0;
        le.data = i;
        if (!listFull(&list))
            insertList(pos++, le, &list);
        else
            printf("The List is full!\n\n");
    }
    /*****************  Traverse all List  *****************/
    printf("Size of List: [ %d ]\n", listSize(&list));
    if (!traverseList(&list, &display))
        printf("List is empty!");

    /*****************  Delete from List  *****************/
    if (!listEmpty(&list))
        deleteList(3, &le, &list);
    else
        printf("The List is empty!");
    printf("After delete from position 3:\n");
    printf("Size of List: [ %d ]\n", listSize(&list));
    printf("Delete value: [ %d ]\n", le);
    if (!traverseList(&list, &display))
        printf("List is empty!");
    /*****************  Replace  *****************/
    le.data = 100;
    replaceList(2, le, &list);
    printf("After replace to position 2:\n");
    printf("Size of List: [ %d ]\n", listSize(&list));
    if (!traverseList(&list, &display))
        printf("List is empty!");
    /*****************  Retrieve from List  *****************/
    retrieveList(2, &le, &list);
    printf("Retrieve Value is [ %d ]\n\n", le.data);

    /*****************  Destroy List  *****************/
    printf("Destroy List:\n");
    destroyList(&list);
    printf("Size of List: [ %d ]\n", listSize(&list));
    if (!traverseList(&list, &display))
        printf("List is empty!");

    return 0;
}

void createList(List *pl)
{
    pl->head = NULL;
    pl->size = 0;
    pl->current = NULL;  // new
    pl->current_pos = 0; // new
}

int destroyList(List *pl)
{
    if (listEmpty(pl))
        return 0;
    ListNode *pln;
    while (pl->head)
    {
        pln = pl->head->next;
        free(pl->head);
        pl->head = pln;
    }
    pl->size = 0;
    return 1;
}

int listEmpty(List *pl)
{
    return (pl->size == 0); //  or return !pl->head
}

int listFull(List *pl)
{
    return 0;
}

int listSize(List *pl)
{
    return pl->size;
}

int insertList(int pos, ListEntry le, List *pl)
{
    // ListNode *p, *q;
    // int i;
    ListNode *p;
    if (p = (ListNode *)malloc(sizeof(ListNode)))
    {
        p->entry = le;
        p->next = NULL;
        if (pos == 0)
        {
            p->next = pl->head;
            pl->head = p;
            pl->current_pos = 0;    // new
            pl->current = pl->head; //  new
        }
        else
        {
            /** 'pl->current' is used in place in 'q' previously **/
            if (pos <= pl->current_pos) //  new
            {
                pl->current_pos = 0;    // as 'i = 0'
                pl->current = pl->head; //  as 'q = pl->head'
            }
            // for (q = pl->head, i = 0; i < pos - 1; i++)
            //     q = q->next;
            for (; pl->current_pos != pos - 1; pl->current_pos++)
                pl->current = pl->current->next;
            // p->next = q->next;
            p->next = pl->current->next;
            // q->next = p;
            pl->current->next = p;
        }
        pl->size++;
        return 1;
    }
    return 0;
}

void deleteList(int pos, ListEntry *ple, List *pl)
{
    // ListNode *q, *tmp;
    // int i;
    ListNode *tmp;
    if (pos == 0)
    {
        *ple = pl->head->entry;
        // tmp = pl->head->next;
        pl->current = pl->head->next; // new
        free(pl->head);
        // pl->head = tmp;
        pl->head = pl->current; //  new
        pl->current_pos = 0;    // new
    }
    else
    {
        /** 'pl->current' is used in place in 'q' previously **/
        if (pos <= pl->current_pos) //  new
        {
            pl->current_pos = 0;    // as 'i = 0'
            pl->current = pl->head; //  as 'q = pl->head'
        }
        // for (q = pl->head, i = 0; i < pos - 1; i++)
        //     q = q->next;
        for (; pl->current_pos != pos - 1; pl->current_pos++)
            pl->current = pl->current->next;
        // *ple = q->next->entry;
        *ple = pl->current->next->entry;
        // tmp = q->next->next;
        tmp = pl->current->next->next;
        // free(q->next);
        free(pl->current->next);
        // q->next = tmp;
        pl->current->next = tmp;
    }
    pl->size--;
}

void retrieveList(int pos, ListEntry *ple, List *pl)
{
    ListNode *pln;
    int i;
    for (pln = pl->head, i = 0; i < pos; i++)
        pln = pln->next;
    *ple = pln->entry;
}

void replaceList(int pos, ListEntry le, List *pl)
{
    ListNode *pln;
    int i;
    for (pln = pl->head, i = 0; i < pos; i++)
        pln = pln->next;
    pln->entry = le;
}

int traverseList(List *pl, void (*pf)(ListEntry))
{
    if (listEmpty(pl))
        return 0;
    ListNode *pln = pl->head;
    while (pln)
    {
        (*pf)(pln->entry);
        pln = pln->next;
    }
    printf("\n\n");
    return 1;
}

void display(ListEntry le)
{
    printf(" %d ", le);
}