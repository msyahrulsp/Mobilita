/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include <stdio.h>
#include <stdlib.h>

#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void LD_CreateListDin(ListDin *l, int LD_CAPACITY) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* KAMUS */

    /* ALGORITMA */
    CAP(*l) = LD_CAPACITY;
    NEFF(*l) = 0;
    BUFFER(*l) = (Building*) malloc(CAP(*l) * sizeof(Building));
}

void LD_dealocate(ListDin *l) {
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAP(l)=0; NEFF(l)=0 */
    /* KAMUS */

    /* ALGORITMA */
    CAP(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int LD_length(ListDin l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType LD_getLastIdx(ListDin l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean LD_isIdxValid(ListDin l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return i >= 0 && i < CAP(l);
}
boolean LD_isIdxEff(ListDin l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    /* KAMUS */

    /* ALGORITMA */
    return i >= 0 && i < NEFF(l);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean LD_isEmpty(ListDin l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) == 0;
}
/* *** Test list penuh *** */
boolean LD_isFull(ListDin l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) == CAP(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void LD_readList(ListDin *l) {
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAP(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAP(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    /* KAMUS */
    int N, i;
    /* ALGORITMA */
    do
    {
        scanf("%d", &N);
    } while (!(LD_isIdxValid(*l, N) || N == CAP(*l)));

    NEFF(*l) = N;

    for (i = 0; i < NEFF(*l); i++) {
        scanf("%c %d %d", &BNAME(*l, i), &Absis(BPOINT(*l, i)), &Ordinat(BPOINT(*l, i)));
    }

}
void LD_displayList(ListDin l) {
/* Proses : Menuliskan isi list dengan traversal, list ditulis dengan format berikut:
   A (1,4)
   B (2,6)
   C (7,2)*/
/* I.S. l terdefinisi*/
/* F.S. Jika l tidak kosong: menampilkan isi list sesuai format di atas */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    for (i = 0; i < LD_length(l); i++) {
        printf("%c (%d,%d)\n", BNAME(l, i), Absis(BPOINT(l, i)), Ordinat(BPOINT(l, i)));
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType LD_indexOf(ListDin l, Building val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    /* KAMUS */
    int i = 0;
    boolean found = false;
    /* ALGORITMA */

    while (i<LD_length(l) && !found){
        if (BNAME(l,i)==val.buildingName && P_EQ(BPOINT(l,i), val.position)){
            found = true;
        } else {
            i += 1;
        }
    }

    if (!found){
        i = IDX_UNDEF;
    }

    return i;
}



/* ********** OPERASI LAIN ********** */
void LD_copyList(ListDin lIn, ListDin *lOut) {
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    LD_CreateListDin(lOut, CAP(lIn));

    NEFF(*lOut) = NEFF(lIn);

    for (i = 0; i < NEFF(lIn); i++) {
        LD_ELMT(*lOut, i) = LD_ELMT(lIn, i);
    }
}

int LD_countVal(ListDin l, Building val) {
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    /* KAMUS */
    int i;
    int count = 0;
    /* ALGORTIMA */
    for (i = 0; i < NEFF(l); i++) {
        if (BNAME(l, i) == val.buildingName) {
            count += 1;
        }
    }

    return count;
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void LD_insertLast(ListDin *l, Building val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */

    /* ALGORITMA */
    LD_ELMT(*l, LD_length(*l)) = val;
    NEFF(*l) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void LD_deleteLast(ListDin *l, Building *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    /* KAMUS */

    /* ALGORITMA */
    *val = LD_ELMT(*l, LD_length(*l) - 1);
    NEFF(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void LD_growList(ListDin *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    /* KAMUS */
    ListDin temp;
    int i;
    /* ALGORITMA */
    //realloc(l, CAP(*l) + num);
    LD_copyList(*l, &temp);
    LD_dealocate(l);
    LD_CreateListDin(l, CAP(temp) + num);
    NEFF(*l) = NEFF(temp);
    for (i = 0; i < LD_length(temp); i++) {
        LD_ELMT(*l, i) = LD_ELMT(temp, i);
    }
    LD_dealocate(&temp);
}

void LD_shrinkList(ListDin *l, int num) {
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS */
    ListDin temp;
    int i;
    /* ALGORITMA */
    //realloc(l, CAP(*l) - num);
    LD_copyList(*l, &temp);
    LD_dealocate(l);
    LD_CreateListDin(l, CAP(temp) - num);
    NEFF(*l) = NEFF(temp);
    for (i = 0; i < LD_length(temp); i++) {
        LD_ELMT(*l, i) = LD_ELMT(temp, i);
    }
    LD_dealocate(&temp);
}

void LD_compactList(ListDin *l) {
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
    /* KAMUS */
    ListDin temp;
    int i;
    /* ALGORITMA */
    //realloc(l, NEFF(*l));
    LD_copyList(*l, &temp);
    LD_dealocate(l);
    LD_CreateListDin(l, NEFF(temp));
    NEFF(*l) = NEFF(temp);
    for (i = 0; i < LD_length(temp); i++) {
        LD_ELMT(*l, i) = LD_ELMT(temp, i);
    }
    LD_dealocate(&temp);
}

POINT LD_buildingtToPoint (ListDin l, char nama){
    int i = 0;
    boolean found;
    /* ALGORITMA */
    found = false;
    while (LD_isIdxEff(l, i) && !found) {
        if (BNAME(l, i) == nama){
            found = true;
        } else {
            i++;
        }
    }
    return l.buffer[i].position;
}

boolean LD_isBuildingIn (ListDin l, char b){

    int i = 0;
    boolean found = false;
    /* ALGORITMA */

    while (i<LD_length(l) && !found){
        if (BNAME(l,i)==b){
            found = true;
        } else {
            i += 1;
        }
    }

    return found;

}

IdxType LD_point_indexOf(ListDin l, POINT val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    /* KAMUS */
    int i = 0;
    boolean found = false;
    /* ALGORITMA */

    while (i<LD_length(l) && !found){
        if (P_EQ(BPOINT(l,i), val)){
            found = true;
        } else {
            i += 1;
        }
    }

    if (!found){
        i = IDX_UNDEF;
    }

    return i;
}
