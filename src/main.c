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
    removeFirstIntLinkedList(intLinkedList);
    applyForEachIntLinkedList(intLinkedList, printInt);

    freeIntLinkedList(intLinkedList);
    return 0;

}