#include "Pesanan.h"

void Q_CreatePesanan(Pesanan *p, int waktuPesanan, char pickUpPoint, char dropOffPoint, char jenisItem, int perishTime) {
/* I.S. sembarang */
/* F.S. Sebuah Pesanan terbentuk sesuai dengan parameter input */
    /* KAMUS */

    /* ALGORITMA */
    WAKTU_PESANAN(*p) = waktuPesanan;
    PICK_UP_POINT(*p) = pickUpPoint;
    DROP_OFF_POINT(*p) = dropOffPoint;
    JENIS_ITEM(*p) = jenisItem;
    if (jenisItem == 'P') PERISH_TIME(*p) = perishTime;
    else PERISH_TIME(*p) = NULL_PERISHTIME;
}