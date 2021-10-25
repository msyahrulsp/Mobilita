/* File : queue.c */
/* Realisasi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include <stdio.h>

#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
        /* KAMUS */

        /* ALGORITMA */
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
        /* KAMUS */

        /* ALGORITMA */
        return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFull(Queue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
        /* KAMUS */

        /* ALGORITMA */
        return ((IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITY - 1));
}
int length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
        /* KAMUS */

        /* ALGORTIMA */
        if (isEmpty(q)) return 0;
        else return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
        /* KAMUS */
        Queue tempQueue;
        ElType tempVal;
        int i;
        /* ALGORITMA */
        if (isEmpty(*q)) {
                IDX_HEAD(*q) = 0;
                IDX_TAIL(*q) = 0;
        } else if (IDX_TAIL(*q) == CAPACITY - 1) {
                CreateQueue(&tempQueue);
                for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
                        dequeue(q, &tempVal);
                        enqueue(&tempQueue, tempVal);
                }
                for (i = IDX_HEAD(tempQueue); i <= IDX_TAIL(tempQueue); i++) {
                        dequeue(&tempQueue, &tempVal);
                        enqueue(q, tempVal);
                }
                IDX_TAIL(*q)++;
        } else {
                IDX_TAIL(*q)++;
        }
        TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
        /* KAMUS */

        /* ALGORITMA */
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
                IDX_HEAD(*q) = IDX_UNDEF;
                IDX_TAIL(*q) = IDX_UNDEF;
        } else IDX_HEAD(*q)++;
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
        /* KAMUS */
        int i;
        ElType val;
        /* ALGORTIMA */
        printf("[");
        if (isEmpty(q)) printf("]");
        else {
                for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
                        dequeue(&q, &val);
                        printf("%d",val);
                        if (IDX_TAIL(q) == IDX_UNDEF) {
                                printf("]");
                        } else {
                                printf(",");
                        }
                }
        }
}