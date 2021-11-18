#include <stdio.h>
#include "Pesanan.h"

int main() {
    /* KAMUS */
    Pesanan pesanan;
    // int waktuPesanan, duration, timer;
    // char pickUpPoint, dropOffPoint, jenisItem;
    /* ALGORITMA */
    Q_CreatePesanan(&pesanan, 10, 'A', 'B', 'P', 10, 5);
    printf("%c -> %c\n", PICK_UP_POINT(pesanan), DROP_OFF_POINT(pesanan));
    printf("Jenis Item: %c\n", JENIS_ITEM(pesanan));
    printf("%d/%d\n", TIMER(pesanan), DURATION(pesanan));

    return 0;
}