/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "boolean.h"
#include "Pesanan.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef Pesanan S_ElType;
typedef struct {
  S_ElType buffer[CAPACITY]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]

/* *** Konstruktor/Kreator *** */
void S_CreateStack(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean S_isEmpty(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean S_isFull(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */

void S_reverseCopy(Stack *s, Stack input);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void S_push(Stack *s, S_ElType val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void S_pop(Stack *s, S_ElType *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

int S_length(Stack s);

void S_disapPerishable(Stack *tas, int curTime, int addTime);

#endif