#include <stdio.h>
#include "list_linked.h"
#include "Pesanan.h"

int main(){

    Pesanan val;
    LL_List l;

    Q_CreatePesanan(&val, 50, 'C', 'E', 'P', 10, 10);
    printf("%d %c %c %c %d %d\n", WAKTU_PESANAN(val), PICK_UP_POINT(val), DROP_OFF_POINT(val), JENIS_ITEM(val), DURATION(val), TIMER(val));

    LL_CreateList(&l);
    printf("%d", LL_isEmpty(l));
    LL_insertFirst(&l, val);
    LL_displayList_ToDo(l);
    LL_displayList_InProgress(l);


    return 0;
}
