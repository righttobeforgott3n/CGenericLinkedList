#ifndef GENERICLINKEDLIST_LINKEDLIST_H
#define GENERICLINKEDLIST_LINKEDLIST_H

#include <stdlib.h>

// ******************* start Node type *******************

/*
 * Placeholder for the user type Node name created concatenating the value of uType to "Node".
 */
#define NODE_T(userType) \
    userType##Node

/*
 * Define the user type Node named by NODE_T that wrap a itemType item, and a NODE_T* next.
 */
#define DEFINE_NODE_TYPE(userType, itemType) \
    struct NODE_T(userType) { itemType item; struct NODE_T(userType)* next; }

/*
 * Placeholder for Node allocate function: allocate##userType##Node .
 */
#define CALLOC_NODE_FUNCTION_NAME(userType) \
    allocate##userType##Node

/*
 * Defines a function with the following signature: struct NODE_T(userType)* allocate##userType##Node (void).
 */
#define DEFINE_CALLOC_NODE(userType) \
    struct NODE_T(userType)* CALLOC_NODE_FUNCTION_NAME(userType) (void) { \
        return (struct NODE_T(userType)*) calloc(1, sizeof(struct NODE_T(userType))); \
    }

/*
 * Placeholder for Node free function: free##userType##Node .
 */
#define FREE_NODE_FUNCTION_NAME(userType) \
    free##userType##Node

/*
 * Defines a function with the following signature: void free##userType##Node (struct NODE_T(userType)* selfParam).
 */
#define DEFINE_FREE_NODE(userType, selfParam) \
    void FREE_NODE_FUNCTION_NAME(userType) (struct NODE_T(userType)* selfParam) { \
        free(selfParam); \
    }

/*
 * Placeholder for Node new function: new##userType##Node .
 */
#define NEW_NODE_FUNCTION_NAME(userType) \
    new##userType##Node

/*
 * Defines a function with the following signature: struct NODE_T(userType)* new##userType##Node(itemType itemParam, struct NODE_T(userType)* nextParam).
 */
#define DEFINE_NEW_NODE(userType, itemType, itemParam, nextParam) \
    struct NODE_T(userType)* NEW_NODE_FUNCTION_NAME(userType) (itemType itemParam, struct NODE_T(userType)* nextParam) { \
        struct NODE_T(userType)* newNode = allocate##userType##Node(); \
        newNode->item = itemParam; \
        newNode->next = nextParam; \
        return newNode; \
    }

// ******************* end Node type *******************

// ******************* start LinkedList type *******************

/*
 * Placeholder for the new user type name created concatenating the value of uType to "LinkedList".
 */
#define LINKEDLIST_T(userType) \
    userType##LinkedList

/*
 * Defines a new user type LinkedList named by LINKEDLIST_T macro and with nodes that wrap item of type iType.
 */
#define DEFINE_LINKEDLIST_TYPE(userType, itemType) \
    struct LINKEDLIST_T(userType) { DEFINE_NODE_TYPE(userType, itemType)* head; size_t size; }

/*
 * Placeholder for LinkedList allocation function: allocate##userType##LinkedList .
 */
#define CALLOC_LINKEDLIST_FUNCTION_NAME(userType) \
    allocate##userType##LinkedList

/*
 * Defines a function with the following signature: struct LINKEDLIST_T(uType)* allocate##uType##LinkedList (void).
 */
#define DEFINE_CALLOC_LINKEDLIST(userType) \
    struct LINKEDLIST_T(userType)* CALLOC_LINKEDLIST_FUNCTION_NAME(userType) (void) { \
        return (struct LINKEDLIST_T(userType)*) calloc(1, sizeof(struct LINKEDLIST_T(userType))); \
    }

/*
 * Placeholder for LinkedList free function: free##userType##LinkedList .
 */
#define FREE_LINKEDLIST_FUNCTION_NAME(userType) \
    free##userType##LinkedList

/*
 * Defines a function with the following signature: void free##uType##LinkedList (struct LINKEDLIST_T(uType)* vName).
 */
#define DEFINE_FREE_LINKEDLIST(userType) \
    DEFINE_FREE_NODE(userType, self) \
    void FREE_LINKEDLIST_FUNCTION_NAME(userType) (struct LINKEDLIST_T(userType)* self) { \
        for (struct NODE_T(userType)* currentNode = (void*)0; (currentNode = self->head->next);) { self->head->next = currentNode->next; free##userType##Node(currentNode); } \
        free##userType##Node(self->head); \
        free(self); \
    }

/*
 * Placeholder for LinkedList new function: new##userType##LinkedList .
 */
#define NEW_LINKEDLIST_FUNCTION_NAME(userType) \
    new##userType##LinkedList

/*
 * Defines a function with the following signature: struct LINKEDLIST_T(uType)* new##uType##LinkedList (void).
 * It allocates a new instance of user type LinkedList, returning a pointer.
 */
#define DEFINE_NEW_LINKEDLIST(userType, itemType) \
    DEFINE_CALLOC_NODE(userType) \
    DEFINE_NEW_NODE(userType, itemType, item, next) \
    struct LINKEDLIST_T(userType)* NEW_LINKEDLIST_FUNCTION_NAME(userType) (void) { \
        struct LINKEDLIST_T(userType)* newLinkedList = CALLOC_LINKEDLIST_FUNCTION_NAME(userType)(); \
        newLinkedList->head = new##userType##Node(0, 0); \
        newLinkedList->size = 0; \
        return newLinkedList; \
    }

/*
 * Placeholder for LinkedList addFirst function: addFirst##userType##LinkedList .
 */
#define ADD_FIRST_LINKEDLIST_FUNCTION_NAME(userType) \
    addFirst##userType##LinkedList

/*
 * Define the following function: void ADD_FIRST_LINKEDLIST_FUNCTION_NAME(userType) (struct LINKEDLIST_T(userType)* selfParam, itemType itemParam).
 */
#define DEFINE_LINKEDLIST_ADD_FIRST(userType, itemType) \
    void ADD_FIRST_LINKEDLIST_FUNCTION_NAME(userType) (struct LINKEDLIST_T(userType)* self, itemType item) { \
        struct NODE_T(userType)* newNode = new##userType##Node(item, self->head->next); \
        self->head->next = newNode; \
        self->size++; \
    }

/*
 * Placeholder for LinkedList removeFirst function: removeFirst##userType##LinkedList .
 */
#define REMOVE_FIRST_LINKEDLIST_FUNCTION_NAME(userType) \
    removeFirst##userType##LinkedList

/*
 * Define the following function: itemType REMOVE_FIRST_LINKEDLIST_FUNCTION_NAME(userType) (struct LINKEDLIST_T(userType)* selfParam).
 */
#define DEFINE_LINKEDLIST_REMOVE_FIRST(userType, itemType) \
    itemType REMOVE_FIRST_LINKEDLIST_FUNCTION_NAME(userType) (struct LINKEDLIST_T(userType)* self) { \
        itemType removedItem = 0; \
        if (self->head->next) { \
            struct NODE_T(userType)* nodeToRemove = self->head->next; \
            removedItem = nodeToRemove->item; \
            self->head->next = nodeToRemove->next; \
            free##userType##Node(nodeToRemove); \
            self->size--; \
        } \
        return removedItem; \
    }

/*
 * Placeholder for LinkedList forEach function: forEach##userType##LinkedList .
 */
#define FOREACH_LINKEDLIST_FUNCTION_NAME(userType) \
    forEach##userType##LinkedList

/*
 * Defines a function with the following signature: void applyForEach##userType##LinkedList (struct LINKEDLIST_T(userType)* selfParam, void(*funcParam)(itemType)).
 */
#define DEFINE_LINKEDLIST_FOREACH(userType, itemType) \
    void FOREACH_LINKEDLIST_FUNCTION_NAME(userType) (struct LINKEDLIST_T(userType)* self, void(*apply)(itemType)) { \
        for (struct NODE_T(userType)* currentNode = self->head; (currentNode = currentNode->next);) { \
            apply(currentNode->item); \
        } \
    }

/*
 *
 */
#define GENERIC_LINKEDLIST_LIST(userType, itemType) \
    DEFINE_LINKEDLIST_TYPE(userType, itemType);     \
    DEFINE_CALLOC_LINKEDLIST(userType)              \
    DEFINE_FREE_LINKEDLIST(userType)                \
    DEFINE_NEW_LINKEDLIST(userType, itemType)       \
    DEFINE_LINKEDLIST_ADD_FIRST(userType, itemType) \
    DEFINE_LINKEDLIST_REMOVE_FIRST(userType, itemType) \
    DEFINE_LINKEDLIST_FOREACH(userType, itemType)

// ******************* end LinkedList type *******************

#endif //GENERICLINKEDLIST_LINKEDLIST_H
