/* File : queue.h */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "Pesanan/Pesanan.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */

typedef struct {
    Pesanan buffer[CAPACITY]; 
    int idxHead;
    int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void Q_CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean Q_isEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean Q_isFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
int Q_length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Pesanan val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
void vipEnqueue(Queue *q, Pesanan val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void Q_enqueue(Queue *q, Pesanan val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void Q_dequeue(Queue *q, Pesanan *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */

void Q_enqueueToDoList(Queue *daftarPesanan, Queue *toDoList, int curTime);
/* Proses: Memindahkan pesanan dari daftarPesanan ke toDoList */
/* I.S. daftarPesanan terdefinisi */
/* F.S toDoList mungkin bertambah mungkin tidak */

void Q_displayToDoList(Queue toDoList, int curTime);
/* Proses: Menampilkan toDoList ke layar */
/* I.S. toDoList terdefinisi */
/* F.S. menampilkan toDoList ke layar */

void Q_checkPerish(Queue *toDoList, int curTime);
/* Proses: menghapus Perishable Item saat waktunya habis */
/* I.S. toDoList terdefinisi */
/* F.S. toDoList mungkin berkurang mungkin tidak */

#endif