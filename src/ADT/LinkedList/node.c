/* File: node.c */
/* Implementasi Node */

#include "node.h"
#include <stdlib.h>

LL_Address newNode(LL_ElType val) {
    LL_Address p = (LL_Address) malloc(sizeof(LL_Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
