/* File : stack.c */
/* Realisasi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#include <stdio.h>

#include "stack.h"

/* *** Konstruktor/Kreator *** */
void S_CreateStack(Stack *s) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
    /* KAMUS */

    /* ALGORITMA */
    IDX_TOP(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean S_isEmpty(Stack s) {
/* Mengirim true jika s kosong: lihat definisi di atas */
    /* KAMUS */

    /* ALGORITMA */
    return IDX_TOP(s) == IDX_UNDEF;
}
boolean S_isFull(Stack s) {
/* Mengirim true jika tabel penampung nilai s stack penuh */
    /* KAMUS */

    /* ALGORITMA */
    return IDX_TOP(s) == CAPACITY - 1;
}

void S_reverseCopy(Stack *s, Stack input) {
    S_CreateStack(s);
    S_ElType holder;
    while(!S_isEmpty(input)) {
        S_pop(&input, &holder);
        S_push(s, holder);
    }
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void S_push(Stack *s, S_ElType val) {
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
    /* KAMUS */

    /* ALGORITMA */
    if (S_isEmpty(*s)){
        IDX_TOP(*s) = 0;
    } else {
        IDX_TOP(*s) += 1;
    }
    TOP(*s) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void S_pop(Stack *s, S_ElType *val) {
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
    /* KAMUS */

    /* ALGORITMA */
    *val = TOP(*s);
    if (IDX_TOP(*s)==0){
        IDX_TOP(*s) = IDX_UNDEF;
    } else {
        IDX_TOP(*s) -= 1;
    }
}

int S_length(Stack s){
    Stack s1;
    S_ElType val;
    S_CreateStack(&s1);
    int ctr = 0;
    while (!S_isEmpty(s)){
        S_pop(&s, &val);
        S_push(&s1, val);
        ctr += 1;
    }
    while (!S_isEmpty(s1)){
        S_pop(&s1, &val);
        S_push(&s, val);
    }
    return ctr;
}

void S_disapPerishable(Stack *tas, int curTime, int addTime) {
    Stack tempTas;
    Pesanan tempPesanan;
    S_CreateStack(&tempTas);
    while (!S_isEmpty(*tas)) {
        S_pop(tas, &tempPesanan);
        if (JENIS_ITEM(tempPesanan) == 'P') {
            TIMER(tempPesanan) -= addTime;
        }
        S_push(&tempTas, tempPesanan);
    }
    while (!S_isEmpty(tempTas)) {
        S_pop(&tempTas, &tempPesanan);
        if (JENIS_ITEM(tempPesanan) == 'P' && TIMER(tempPesanan) <= 0) {
            // DO NOTHING
        } else {
            S_push(tas, tempPesanan);
        }
    }
}