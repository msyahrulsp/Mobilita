/* File : Pesanan.h */
/* Definisi ADT Pesanan */

#ifndef __PESANAN__
#define __PESANAN__

#define NULL_PERISHTIME -1

/* Definisi Pesanan */
typedef struct {
    int waktuPesanan;
    char pickUpPoint;
    char dropOffPoint;
    char jenisItem; // N = Normal, H = Heavy, P = Perishable, V = VIP
    int duration;
    int timer;
} Pesanan;

#define  WAKTU_PESANAN(p) (p).waktuPesanan
#define  PICK_UP_POINT(p) (p).pickUpPoint
#define DROP_OFF_POINT(p) (p).dropOffPoint
#define     JENIS_ITEM(p) (p).jenisItem
#define       DURATION(p) (p).duration
#define          TIMER(p) (p).timer

/* Konstruktor */
void Q_CreatePesanan(Pesanan *p, int waktuPesanan, char pickUpPoint, char dropOffPoint, char jenisItem, int duration, int timer);
/* I.S. sembarang */
/* F.S. Sebuah Pesanan terbentuk sesuai dengan parameter input */

#endif