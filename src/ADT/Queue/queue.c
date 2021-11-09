/* File : queue.c */
/* Realisasi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include <stdio.h>

#include "queue.h"

/* *** Kreator *** */
void Q_CreateQueue(Queue *q) {
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
boolean Q_isEmpty(Queue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    /* KAMUS */

    /* ALGORITMA */
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
boolean Q_isFull(Queue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    /* KAMUS */

    /* ALGORITMA */
    return ((IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITY - 1));
}
int Q_length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    /* KAMUS */

    /* ALGORTIMA */
    if (Q_isEmpty(q)) return 0;
    else return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Pesanan val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    if(isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;} 
    else{ // *q is not empty
        if(IDX_TAIL(*q) == (CAPACITY-1)) {
            for(i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
                (*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
            }
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q)++;
    }
    TAIL(*q) = val;
}

void vipEnqueue(Queue *q, Pesanan val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    if (Q_isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } else {
        if (IDX_TAIL(*q) == (CAPACITY - 1)) { 
            for(i = IDX_HEAD(*q);  i <= IDX_TAIL(*q); i++) {
                (*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
            }
        IDX_TAIL(*q) -= IDX_HEAD(*q);
        IDX_HEAD(*q) = 0;
        }           
        
        // Sorted Insert
        i = 0;
        while ((JENIS_ITEM((*q).buffer[i]) == 'V') && i < Q_length(*q)) i++;

        for (j = IDX_TAIL(*q); j >= i; j--) 
            (*q).buffer[j + 1] = (*q).buffer[j];

        IDX_TAIL(*q)++;
        (*q).buffer[i] = val;
    }
}

void Q_enqueue(Queue *q, Pesanan val) {
/* Proses: Menambahkan val pada q dengan aturan sorted insert */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    if (Q_isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } else {
        if (IDX_TAIL(*q) == (CAPACITY - 1)) { 
            for(i = IDX_HEAD(*q);  i <= IDX_TAIL(*q); i++) {
                (*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
            }
        IDX_TAIL(*q) -= IDX_HEAD(*q);
        IDX_HEAD(*q) = 0;
        }           
        
        // Sorted Insert
        i = 0;
        while ((WAKTU_PESANAN((*q).buffer[i]) <= WAKTU_PESANAN(val)) && i < Q_length(*q)) i++;

        for (j = IDX_TAIL(*q); j >= i; j--) 
            (*q).buffer[j + 1] = (*q).buffer[j];

        IDX_TAIL(*q)++;
        (*q).buffer[i] = val;
    }
}

void Q_dequeue(Queue *q, Pesanan *val) {
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

void Q_enqueueToDoList(Queue *daftarPesanan, Queue *toDoList, int curTime) {
/* Proses: Memindahkan pesanan dari daftarPesanan ke toDoList */
/* I.S. daftarPesanan terdefinisi */
/* F.S toDoList mungkin bertambah mungkin tidak */
    /* KAMUS */
    Pesanan val;
    /* ALGORITMA */
    if (!Q_isEmpty(*daftarPesanan)) {
        while ((!Q_isEmpty(*daftarPesanan)) && (WAKTU_PESANAN(HEAD(*daftarPesanan))) == curTime) {
            Q_dequeue(daftarPesanan, &val);
            if (JENIS_ITEM(val) == 'V') {
                vipEnqueue(toDoList, val);
            } else {
                if (JENIS_ITEM(val) == 'P') PERISH_TIME(val) = PERISH_TIME(val) + curTime;
                enqueue(toDoList, val);
            }
        }
    }
}

void Q_checkPerish(Queue *toDoList, int curTime) {
/* Proses: menghapus Perishable Item saat waktunya habis */
/* I.S. toDoList terdefinisi */
/* F.S. toDoList mungkin berkurang mungkin tidak */
    /* KAMUS */
    int i, j;
    Pesanan val;
    /* ALGORITMA */
    i = IDX_HEAD(*toDoList);
    while (i <= IDX_TAIL(*toDoList)) {
        if (curTime == PERISH_TIME((*toDoList).buffer[i])) {
            if (IDX_HEAD(*toDoList) == IDX_TAIL(*toDoList)) {
                Q_dequeue(toDoList, &val);
            } else {
                for(j = i;  i <= IDX_TAIL(*toDoList); j++) {
                    (*toDoList).buffer[j] = (*toDoList).buffer[j+1];
                }
                IDX_TAIL(*toDoList) -= 1;
            }
        } else {
            i++;
        }
    }
}

void Q_displayToDoList(Queue q, int curTime) {
/* Proses: Menampilkan toDoList ke layar */
/* I.S. toDoList terdefinisi */
/* F.S. menampilkan toDoList ke layar */
    /* KAMUS */
    int i, j;
    Pesanan val;
    /* ALGORTIMA */
    printf("Pesanan pada To Do List:\n");
    j = 1;
    for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
        Q_dequeue(&q, &val);
        printf("%d. %c -> %c (", j);
        if (JENIS_ITEM(val) == 'N') printf("Normal)\n"); 
        else if (JENIS_ITEM(val) == 'H') printf("Heavy)\n");
        else if (JENIS_ITEM(val) == 'P') printf("Perishable, sisa waktu %d)\n", PERISH_TIME(val) - curTime);
        else if (JENIS_ITEM(val) == 'V') printf("VIP)\n");
        printf(")\n");
        j++;
    }
}