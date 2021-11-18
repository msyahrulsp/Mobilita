#include <stdio.h>
#include "listdin.h"

int main(){

    ListDin l;
    Building b;

    LD_CreateListDin(&l, 1);
    NEFF(l) = 1;
    BNAME(l, 0) = 'C';
    BPOINTX(l, 0) = 1;
    BPOINTY(l, 0) = 2;

    printf("%d\n", LD_isEmpty(l));
    printf("%c (%d,%d)", BNAME(l, 0), BPOINTX(l, 0), BPOINTY(l, 0));

    return 0;
}
