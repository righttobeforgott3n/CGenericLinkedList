#ifndef GENERICLINKEDLIST_LINKEDLIST_H
#define GENERICLINKEDLIST_LINKEDLIST_H

#include "Node.h"
#include <stdlib.h>

/*
 * Placeholder for the new user type name created concatenating the value of uType to "LinkedList".
 */
#define LINKEDLIST_T(userType) \
    userType##LinkedList

/*
 * Defines a new user type LinkedList named by LINKEDLIST_T macro and with nodes that wrap item of type iType.
 */
#define DEFINE_LINKEDLIST_T(userType, itemType) \
    struct LINKEDLIST_T(userType) { DEFINE_NODE_T(userType, itemType)* head; size_t size; }

/*
 * Defines a function with the following signature: struct LINKEDLIST_T(uType)* allocate##uType##LinkedList (void).
 */
#define DEFINE_CALLOC_LINKEDLIST(userType) \
    struct LINKEDLIST_T(userType)* allocate##userType##LinkedList (void) { \
        return (struct LINKEDLIST_T(userType)*) calloc(1, sizeof(struct LINKEDLIST_T(userType))); \
    }

/*
 * Defines a function with the following signature: void free##uType##LinkedList (struct LINKEDLIST_T(uType)* vName).
 */
#define DEFINE_FREE_LINKEDLIST(userType, selfParam) \
    DEFINE_FREE_NODE(userType, self) \
    void free##userType##LinkedList (struct LINKEDLIST_T(userType)* selfParam) { \
        for (struct NODE_T(userType)* currentNode = (void*)0; (currentNode = selfParam->head->next);) { selfParam->head->next = currentNode->next; free##userType##Node(currentNode); } \
        free##userType##Node(selfParam->head); \
        free(selfParam); \
    }

/*
 * Defines a function with the following signature: struct LINKEDLIST_T(uType)* new##uType##LinkedList (void).
 * It allocates a new instance of user type LinkedList, returning a pointer.
 */
#define DEFINE_NEW_LINKEDLIST(userType, itemType) \
    DEFINE_CALLOC_NODE(userType) \
    DEFINE_NEW_NODE(userType, itemType, item, next) \
    struct LINKEDLIST_T(userType)* new##userType##LinkedList (void) { \
        struct LINKEDLIST_T(userType)* newLinkedList = allocate##userType##LinkedList(); \
        newLinkedList->head = new##userType##Node(0, 0); \
        newLinkedList->size = 0; \
        return newLinkedList; \
    }

/*
 *
 */
#define DEFINE_LINKEDLIST_ADD_FIRST(userType, selfParam, itemType, itemParam) \
    void addFirst##userType##LinkedList (struct LINKEDLIST_T(userType)* selfParam, itemType itemParam) { \
        struct NODE_T(userType)* newNode = new##userType##Node(itemParam, selfParam->head->next); \
        selfParam->head->next = newNode; \
        selfParam->size++; \
    }

/*
 *
 */
#define DEFINE_LINKEDLIST_REMOVE_FIRST(userType, selfParam, itemType) \
    itemType removeFirst##userType##LinkedList (struct LINKEDLIST_T(userType)* selfParam) { \
        itemType removedItem = 0; \
        if (selfParam->head->next) { \
            struct NODE_T(userType)* nodeToRemove = selfParam->head->next; \
            removedItem = nodeToRemove->item; \
            selfParam->head->next = nodeToRemove->next; \
            free##userType##Node(nodeToRemove); \
            selfParam->size--; \
        } \
        return removedItem; \
    }

/*
 * Defines a function with the following signature: void applyForEach##userType##LinkedList (struct LINKEDLIST_T(userType)* selfParam, void(*funcParam)(itemType)).
 */
#define DEFINE_LINKEDLIST_FOREACH(userType, selfParam, itemType, funcParam) \
    void applyForEach##userType##LinkedList (struct LINKEDLIST_T(userType)* selfParam, void(*funcParam)(itemType)) { \
        for (struct NODE_T(userType)* currentNode = selfParam->head; (currentNode = currentNode->next);) { \
            funcParam(currentNode->item); \
        } \
    }

#endif //GENERICLINKEDLIST_LINKEDLIST_H
