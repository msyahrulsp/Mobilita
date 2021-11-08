#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct {
    int time;
    char pu_point;
    char do_point;
    char item_type;
} LL_ElType;
typedef struct node* LL_Address;
typedef struct node {
    LL_ElType info;
    LL_Address next;
} LL_Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

LL_Address newNode(LL_ElType val);


#endif
