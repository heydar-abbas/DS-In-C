#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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
    return 1;
}

void display(ListEntry le)
{
    printf(" %d ", le);
}