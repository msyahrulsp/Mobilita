/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi deklarasi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#include <stdio.h>
#include <stdlib.h>

#include "listStatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void LS_CreateListGadget(ListGadget *l) {
    /* KAMUS */
    int i;
    /* ALGORITMA */
    for (i = 0; i < LS_CAPACITY; i++) {
        GNAME(*l, i) = LS_NAME_UNDEF;
        GPRICE(*l, i) = LS_VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int LS_length(ListGadget l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    /* KAMUS */
    int NEFF = 0;
    int i;
    /* ALGORITMA */
    for (i = 0; i < LS_CAPACITY; i++) {
        if (GNAME(l, i) == LS_NAME_UNDEF)
            return NEFF;
        NEFF++;
    }
    return NEFF;
}

/* ********** Test Indeks yang valid ********** */
boolean LS_isIdxValid(ListGadget l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0) && (i < LS_CAPACITY);
}
boolean LS_isIdxEff(ListGadget l, int i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0) && (i < LS_length(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean LS_isEmpty(ListGadget l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return LS_length(l) == 0;
}
/* *** Test List penuh *** */
boolean LS_isFull(ListGadget l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return LS_length(l) == LS_CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void LS_readList(ListGadget *l) {
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    /* KAMUS */
    int n, i;
    /* ALGORITMA */
    LS_CreateListGadget(l);
    do
    {
        scanf("%d", &n);
    } while (!(n >= 0 && n <= LS_CAPACITY));

    for (i = 0; i < n; i++) 
        scanf("%c %d", &GNAME(*l, i), &GPRICE(*l, i));
}

void LS_gadgetName(ListGadget l, int idx){
    if (GNAME(l, idx) == 'K'){ // K untuk Kain
        printf("Kain Pembungkus Waktu");
    }
    if (GNAME(l, idx) == 'B'){ // B untuk Big
        printf("Senter Pembesar");
    }
    if (GNAME(l, idx) == 'D'){ // D untuk Door
        printf("Pintu Kemana Saja");
    }
    if (GNAME(l, idx) == 'T'){ // T untuk Time
        printf("Mesin Waktu");
    }
    if (GNAME(l, idx) == 'S'){ // S untuk Small
        printf("Senter Pengecil");
    }
}

void LS_displayList(ListGadget l) {
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

    for (int i = 0; i < LS_CAPACITY; i++){
        printf("%d. ", i + 1);
        if (GNAME(l, i) != LS_NAME_UNDEF){
            LS_gadgetName(l, i);
        }
        else{
            printf("-");
        }
        printf("\n");
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int LS_indexOf(ListGadget l, Gadget val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan LS_ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    /* KAMUS */
    int i = 0;
    /* ALGORITMA */
    while (LS_isIdxEff(l, i)) {
        if (GNAME(l, i) == val.gadgetname)
            return i;
        i++;
    }

    return LS_IDX_UNDEF;
}

/* ********** OPERASI LAIN ********** */
boolean LS_isAllEven(ListGadget l) {
/* Menghailkan true jika semua elemen l genap */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    for (i = 0; i < LS_length(l); i++)
        if (GPRICE(l, i) % 2 == 1)
            return false;
    
    return true;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void LS_insertLast(ListGadget *l, Gadget val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */
    
    /* ALGORITMA */
    LS_ELMT(*l, LS_length(*l)) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void LS_deleteLast(ListGadget *l, Gadget *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    /* KAMUS */
    
    /* ALGORITMA */
    *val = LS_ELMT(*l, LS_length(*l) - 1);
    GNAME(*l, LS_length(*l) - 1) = LS_NAME_UNDEF;
    GPRICE(*l, LS_length(*l) - 1) = LS_VAL_UNDEF;
}

void LS_deleteElmt(ListGadget *l, int idx) {
/* Proses : Menghapus elemen dalam indeks tertentu */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    /* KAMUS */
    
    /* ALGORITMA */
    GNAME(*l, idx) = LS_NAME_UNDEF;
    GPRICE(*l, idx) = LS_VAL_UNDEF;
}