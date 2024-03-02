#ifndef GENERICLINKEDLIST_MAIN_H
#define GENERICLINKEDLIST_MAIN_H

#include "LinkedList.h"
#include "IntLinkedList.h"
#include <stdio.h>

void doSomethingWithIntLinkedList(LINKEDLIST_T(Int)* intLinkedList) {
    printf("List size : %d, item : %d\n", (int)LINKEDLIST_SIZE(intLinkedList), LINKEDLIST_HEAD_ITEM(intLinkedList));
    LINKEDLIST_ADD_FIRST(Int, intLinkedList, 69)
    printf("List size : %d, item : %d\n", (int)LINKEDLIST_SIZE(intLinkedList), LINKEDLIST_HEAD_ITEM(intLinkedList));
}

#endif //GENERICLINKEDLIST_MAIN_H
