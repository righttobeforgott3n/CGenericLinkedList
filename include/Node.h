#ifndef GENERICLINKEDLIST_NODE_H
#define GENERICLINKEDLIST_NODE_H

#include <stdlib.h>

/*
 * Placeholder for the user type Node name created concatenating the value of uType to "Node".
 */
#define NODE_T(userType) \
    userType##Node

/*
 * Define the user type Node named by NODE_T that wrap a itemType item, and a NODE_T* next.
 */
#define DEFINE_NODE_T(userType, itemType) \
    struct NODE_T(userType) { itemType item; struct NODE_T(userType)* next; }

/*
 * Defines a function with the following signature: struct NODE_T(userType)* allocate##userType##Node (void).
 */
#define DEFINE_CALLOC_NODE(userType) \
    struct NODE_T(userType)* allocate##userType##Node (void) { \
        return (struct NODE_T(userType)*) calloc(1, sizeof(struct NODE_T(userType))); \
    }

/*
 * Defines a function with the following signature: void free##userType##Node (struct NODE_T(userType)* selfParam).
 */
#define DEFINE_FREE_NODE(userType, selfParam) \
    void free##userType##Node (struct NODE_T(userType)* selfParam) { \
        free(selfParam); \
    }

/*
 * Defines a function with the following signature: struct NODE_T(userType)* new##userType##Node(itemType itemParam, struct NODE_T(userType)* nextParam).
 */
#define DEFINE_NEW_NODE(userType, itemType, itemParam, nextParam) \
    struct NODE_T(userType)* new##userType##Node(itemType itemParam, struct NODE_T(userType)* nextParam) { \
        struct NODE_T(userType)* newNode = allocate##userType##Node(); \
        newNode->item = itemParam; \
        newNode->next = nextParam; \
        return newNode; \
    }

#endif //GENERICLINKEDLIST_NODE_H