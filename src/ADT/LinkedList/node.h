#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct {
    int time;
    char pu_point;
    char do_point;
    char item_type;
} ElType;
typedef struct node* Address;
typedef struct node {
    ElType info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val);


#endif
