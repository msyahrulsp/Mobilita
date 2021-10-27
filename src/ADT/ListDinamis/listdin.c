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
void CreateListDin(ListDin *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* KAMUS */

    /* ALGORITMA */
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType*) malloc(CAPACITY(*l) * sizeof(ElType));
}

void dealocate(ListDin *l) {
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    /* KAMUS */

    /* ALGORITMA */
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return i >= 0 && i < CAPACITY(l);
}
boolean isIdxEff(ListDin l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    /* KAMUS */

    /* ALGORITMA */
    return i >= 0 && i < NEFF(l);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) == 0;
}
/* *** Test list penuh *** */
boolean isFull(ListDin l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    /* KAMUS */
    int N, i;
    /* ALGORITMA */
    do
    {
        scanf("%d", &N);
    } while (!(isIdxValid(*l, N) || N == CAPACITY(*l)));

    NEFF(*l) = N;

    for (i = 0; i < NEFF(*l); i++) {
        scanf("%d", &ELMT(*l, i));
    }
    
}
void displayList(ListDin l) {
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
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
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    /* KAMUS */
    ListDin l3;
    int i;
    /* ALGORITMA */
    CreateListDin(&l3, CAPACITY(l1));
    NEFF(l3) = NEFF(l1);

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
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
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
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
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
void extremes(ListDin l, ElType *max, ElType *min) {
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
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
void copyList(ListDin lIn, ListDin *lOut) {
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    CreateListDin(lOut, CAPACITY(lIn));

    NEFF(*lOut) = NEFF(lIn);

    for (i = 0; i < NEFF(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}
ElType sumList(ListDin l) {
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    /* KAMUS */
    int i;
    ElType sum = 0;
    /* ALGORTIMA */
    for (i = 0; i < NEFF(l); i++) {
        sum += ELMT(l, i);
    }

    return sum;
}
int countVal(ListDin l, ElType val) {
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
     /* KAMUS */
    int i;
    int count = 0;
    /* ALGORTIMA */
    for (i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) == val) {
            count += 1;
        }
    }

    return count;
}
boolean isAllEven(ListDin l) {
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    for (i = 0; i < length(l); i++)
        if (ELMT(l, i) % 2 == 1)
            return false;
    
    return true;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
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
void insertLast(ListDin *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */

    /* ALGORITMA */
    ELMT(*l, length(*l)) = val;
    NEFF(*l) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    /* KAMUS */
    
    /* ALGORITMA */
    *val = ELMT(*l, length(*l) - 1);
    NEFF(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    /* KAMUS */
    ListDin temp;
    int i;
    /* ALGORITMA */
    //realloc(l, CAPACITY(*l) + num);
    copyList(*l, &temp);
    dealocate(l);
    CreateListDin(l, CAPACITY(temp) + num);
    NEFF(*l) = NEFF(temp);
    for (i = 0; i < length(temp); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
    dealocate(&temp);
}

void shrinkList(ListDin *l, int num) {
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS */
    ListDin temp;
    int i;
    /* ALGORITMA */
    //realloc(l, CAPACITY(*l) - num);
    copyList(*l, &temp);
    dealocate(l);
    CreateListDin(l, CAPACITY(temp) - num);
    NEFF(*l) = NEFF(temp);
    for (i = 0; i < length(temp); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
    dealocate(&temp);
}

void compactList(ListDin *l) {
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
    /* KAMUS */
    ListDin temp;
    int i;
    /* ALGORITMA */
    //realloc(l, NEFF(*l));
    copyList(*l, &temp);
    dealocate(l);
    CreateListDin(l, NEFF(temp));
    NEFF(*l) = NEFF(temp);
    for (i = 0; i < length(temp); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
    dealocate(&temp);
}
