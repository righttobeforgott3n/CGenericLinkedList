/*
 * Driver source to explicit the GenericLinkedList usage.
 */

#include "../include/IntLinkedList.h"
#include <stdio.h>

void printInt(int i) { printf("%d\n", i); }

int main() {

    struct IntLinkedList* intLinkedList = newIntLinkedList();
    addFirstIntLinkedList(intLinkedList, 69);
    addFirstIntLinkedList(intLinkedList, 69);
    addFirstIntLinkedList(intLinkedList, 69);
    addFirstIntLinkedList(intLinkedList, 69);
    addFirstIntLinkedList(intLinkedList, 69);
    addIntLinkedList(intLinkedList, 3, 0);
    addIntLinkedList(intLinkedList, 4, 6);
    removeIntLinkedList(intLinkedList, 6);
    //removeFirstIntLinkedList(intLinkedList);
    forEachIntLinkedList(intLinkedList, printInt);

    freeIntLinkedList(intLinkedList);
    return 0;

}