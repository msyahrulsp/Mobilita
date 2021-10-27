/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi deklarasi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#include <stdio.h>
#include <stdlib.h>

#include "listpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY; i++) 
        ELMT(*l, i) = VAL_UNDEF;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    /* KAMUS */
    int NEFF = 0;
    int i;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY; i++) {
        if (ELMT(l, i) == VAL_UNDEF)
            return NEFF;
        NEFF++;
    }
    return NEFF;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0) && (i < CAPACITY);
}
boolean isIdxEff(ListPos l, int i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0) && (i < length(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return length(l) == 0;
}
/* *** Test List penuh *** */
boolean isFull(ListPos l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return length(l) == CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l) {
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
    CreateListPos(l);
    do
    {
        scanf("%d", &n);
    } while (!(n >= 0 && n <= CAPACITY));

    for (i = 0; i < n; i++) 
        scanf("%d", &ELMT(*l, i));
}
void displayList(ListPos l) {
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    printf("[");
    for (i = 0; i < length(l); i++) {
        printf("%d", ELMT(l, i));
        if (i != length(l) - 1)
            printf(",");
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus) {
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    /* KAMUS */
    ListPos l3;
    int i;
    /* ALGORITMA */
    CreateListPos(&l3);

    if (plus) {
        for (i = 0; i < length(l1); i++)
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
    } else {
        for (i = 0; i < length(l1); i++)
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
    }

    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2) {
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
    /* KAMUS */
    boolean equal;
    int i = 0;
    /* ALGORITMA */
    equal = length(l1) == length(l2);

    while (equal && isIdxEff(l1, i)) {
        equal = ELMT(l1, i) == ELMT(l2, i);
        i++;
    }

    return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    /* KAMUS */
    int i = 0;
    /* ALGORITMA */
    while (isIdxEff(l, i)) {
        if (ELMT(l, i) == val)
            return i;
        i++;
    }

    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min) {
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (i = 1; i < length(l); i++) {
        if (*max < ELMT(l, i))
            *max = ELMT(l, i);
        if (*min > ELMT(l, i))
            *min = ELMT(l, i);
    }
}

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l) {
/* Menghailkan true jika semua elemen l genap */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    for (i = 0; i < length(l); i++)
        if (ELMT(l, i) % 2 == 1)
            return false;
    
    return true;
}

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc) {
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    /* KAMUS */
    int i, j, temp;
    /* ALGORITMA */
    if (asc) {
        for (i = 0; i < length(*l) - 1; i++)
            for (j = 0; j < length(*l) - i - 1; j++)
                if (ELMT(*l, j) > ELMT(*l, j + 1)) {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
    } else {
        for (i = 0; i < length(*l) - 1; i++)
            for (j = 0; j < length(*l) - i - 1; j++)
                if (ELMT(*l, j) < ELMT(*l, j + 1)) {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }

    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */
    
    /* ALGORITMA */
    ELMT(*l, length(*l)) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    /* KAMUS */
    
    /* ALGORITMA */
    *val = ELMT(*l, length(*l) - 1);
    ELMT(*l, length(*l) - 1) = VAL_UNDEF;
}