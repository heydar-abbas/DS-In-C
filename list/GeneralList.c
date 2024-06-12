// #include "arraylist.c"
#include "linkedlist.c"

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
    printf("\n\nAfter delete from position 3:\n");
    printf("Size of List: [ %d ]\n", listSize(&list));
    printf("Delete value: [ %d ]\n", le);
    if (!traverseList(&list, &display))
        printf("List is empty!");
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
    printf("\nClear List:\n");
    createList(&list);
    printf("Size of List: [ %d ]\n", listSize(&list));
    if (!traverseList(&list, &display))
        printf("List is empty!");

    return 0;
}
