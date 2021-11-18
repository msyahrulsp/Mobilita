#include <stdio.h>
#include "listStatik.h"

int main(){

    ListGadget l;

    LS_CreateListGadget(&l);
    GNAME(l, 0) = 'K';
    GPRICE(l, 0) = 500;
    GNAME(l, 1) = 'L';
    GPRICE(l, 1) = 500;

    int i = 0;
    while (i<100 & GNAME(l, i)!=LS_NAME_UNDEF){
        printf("%c %d\n", GNAME(l, i), GPRICE(l, i));
        i ++;
    }

    return 0;
}
