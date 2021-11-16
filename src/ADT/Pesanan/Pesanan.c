#include "Pesanan.h"

void Q_CreatePesanan(Pesanan *p, int waktuPesanan, char pickUpPoint, char dropOffPoint, char jenisItem, int duration, int timer) {
/* I.S. sembarang */
/* F.S. Sebuah Pesanan terbentuk sesuai dengan parameter input */
    /* KAMUS */

    /* ALGORITMA */
    WAKTU_PESANAN(*p) = waktuPesanan;
    PICK_UP_POINT(*p) = pickUpPoint;
    DROP_OFF_POINT(*p) = dropOffPoint;
    JENIS_ITEM(*p) = jenisItem;
    if (jenisItem == 'P') {
        DURATION(*p) = duration;
        TIMER(*p) = timer;
    }
    else  {
        DURATION(*p) = NULL_PERISHTIME;
        TIMER(*p) = NULL_PERISHTIME;
    }
}