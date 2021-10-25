/* File : prioqueue.c */
/* Representasi priority queue dengan array eksplisit dan alokasi stastik */
/* Queue terurut mengecil berdasarkan elemen score (nilai Daspro) */
/* Jika score sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */

#include <stdio.h>

#include "prioqueue.h"

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq) {
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
    /* KAMUS */

    /* ALGORITMA */
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq) {
/* Mengirim true jika pq kosong: lihat definisi di atas */
    /* KAMUS */

    /* ALGORITMA */
    return (IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq) {
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    /* KAMUS */

    /* ALGORITMA */
    return (IDX_HEAD(pq) == 0) && (IDX_TAIL(pq) == CAPACITY - 1);
}

int length(PrioQueue pq) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */
    /* KAMUS */

    /* ALGORTIMA */
    if (isEmpty(pq)) return 0;
    else return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1);
}

/*** Primitif Add/Delete ***/
void enqueue(PrioQueue *pq, ElType val) {
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* KAMUS */
    PrioQueue tempPrioQueue;
    ElType tempVal;
    int i, idx;
    /* ALGORITMA */
    // if (isEmpty(*pq)) {
    //     IDX_HEAD(*pq) = 0;
    //     IDX_TAIL(*pq) = 0;
    // } else if (IDX_TAIL(*pq) == CAPACITY - 1) {
    //     CreatePrioQueue(&tempPrioQueue);
    //     for (i = IDX_HEAD(*pq); i <= IDX_TAIL(*pq); i++) {
    //         dequeue(pq, &tempVal);
    //         enqueue(&tempPrioQueue, tempVal);
    //     }
    //     for (i = IDX_HEAD(tempPrioQueue); i <= IDX_TAIL(tempPrioQueue); i++) {
    //         dequeue(&tempPrioQueue, &tempVal);
    //         enqueue(pq, tempVal);
    //     }
    //     IDX_TAIL(*pq)++;
    // } else {
    //     IDX_TAIL(*pq)++;
    // }
    // TAIL(*pq) = val;

    // while (/* condition */)
    // {
    //     /* code */
    // }

    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    } else {
        if (IDX_TAIL(*pq) == CAPACITY-1) {
            for (idx = 0; idx < length(*pq); idx++)
                (*pq).buffer[idx] = (*pq).buffer[IDX_HEAD(*pq) + idx];
            IDX_TAIL(*pq) = CAPACITY - 1 - IDX_HEAD(*pq);
            IDX_HEAD(*pq) = 0;
        }
        idx = 0;
        while((*pq).buffer[idx].score > val.score  && idx < length(*pq))
            idx++;
        if (val.score == (*pq).buffer[idx].score) {
            while((*pq).buffer[idx].tArrival < val.tArrival && val.score == (*pq).buffer[idx].score  && idx < length(*pq))
                idx++;
            if(val.tArrival == (*pq).buffer[idx].tArrival && idx < length(*pq))
                while((*pq).buffer[idx].tArrival == val.tArrival && val.score == (*pq).buffer[idx].score)
                    idx++;
        }

        for(i = IDX_TAIL(*pq) ; i >= idx ; i--)
            (*pq).buffer[i+1] = (*pq).buffer[i];

        (*pq).buffer[idx] = val;
        IDX_TAIL(*pq)++;
    }
}

void dequeue(PrioQueue * pq, ElType *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */
    /* KAMUS */

    /* ALGORITMA */
    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)) {
            IDX_HEAD(*pq) = IDX_UNDEF;
            IDX_TAIL(*pq) = IDX_UNDEF;
    } else IDX_HEAD(*pq)++;
}