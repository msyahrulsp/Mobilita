// NIM  : 13520112
// Nama : Fernaldy
// Tanggal : 24 Oktober 2021
// Topik : ADT Berkait

#include "list_linked.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void LL_CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    // Algoritma
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean LL_isEmpty(List l){
/* Mengirim true jika list kosong */
    // Algoritma
    return (FIRST(l)==NULL);
}

/****************** GETTER SETTER ******************/
ElType LL_getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    // Kamus Lokal
    int ctr;
    Address p;
    // Algoritma
    p = FIRST(l);
    ctr = 0;
    while (ctr<idx){
        ctr += 1;
        p = NEXT(p);
    }
    return INFO(p);
}

void LL_setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    // Kamus Lokal
    int ctr;
    Address p;
    // Algoritma
    p = FIRST(*l);
    ctr = 0;
    while (ctr<idx) {
        ctr += 1;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int LL_indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    // Kamus Lokal
    int idx;
    Address p;
    boolean found;
    // Algoritma
    idx = 0;
    p = FIRST(l);
    found = false;
    while (p!=NULL && !(found)){
        if ((INFO(p).time == val.time) && (INFO(p).pu_point==val.pu_point) && (INFO(p).do_point==val.do_point) && (INFO(p).item_type == val.item_type)){
            found = true;
        } else {
            idx += 1;
            p = NEXT(p);
        }
    }
    if (!found){
        idx = IDX_UNDEF;
    }
    return idx;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void LL_insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    // Kamus Lokal
    Address p;
    // Algoritma
    p = newNode(val);
    if (p!=NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void LL_insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // Kamus Lokal
    Address last, p;
    // Algoritma
    if (LL_isEmpty(*l)){
        LL_insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p!=NULL){
            last = FIRST(*l);
            while (NEXT(last)!=NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void LL_insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // Kamus Lokal
    Address p, loc;
    int ctr;
    // Algoritma
    if (idx==0){
        LL_insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p!=NULL) {
            ctr = 0;
            loc = FIRST(*l);
            while (ctr<idx-1){
                ctr += 1;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void LL_deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    // Kamus Lokal
    Address p;
    // Algoritma
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
void LL_deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    // Kamus Lokal
    Address p, loc;
    // Algoritma
    p = FIRST(*l);
    loc = NULL;
    while (NEXT(p)!=NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc==NULL){
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void LL_deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    // Kamus Lokal
    Address loc, p;
    int ctr;
    // Algoritma
    if (idx==0){
        LL_deleteFirst(l, val);
    } else {
        loc = FIRST(*l);
        ctr = 0;
        while (ctr<idx-1){
            ctr += 1;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void LL_displayList_ToDo(List l){
/* I.S. List mungkin kosong */
/* F.S. To Do List tercetak pada layar */
    // Kamus Lokal
    Address p;
    int ctr;
    // Algoritma

    if (LL_isEmpty(l)){
        printf("To Do List Kosong\n");
    } else {
        printf("Pesanan To Do List:\n");
        p = FIRST(l);
        ctr = 1;
        while (p!=NULL){
            printf("%d. %c -> %c ", ctr, INFO(p).pu_point, INFO(p).do_point);
            if (INFO(p).item_type=='N'){
                printf("(Normal Item)");
            } else if (INFO(p).item_type=='H'){
                printf("(Heavy Item)");
            } else if (INFO(p).item_type=='P'){
                printf("(Perishable Item)");
            } else if (INFO(p).item_type=='V'){
                printf("(VIP Item)");
            }
            printf("\n");
            p = NEXT(p);
            ctr += 1;
        }
    }
}

void LL_displayList_InProgress(List l){
/* I.S. List mungkin kosong */
/* F.S. In Progress List tercetak pada layar */
    // Kamus Lokal
    Address p;
    int ctr;
    // Algoritma

    if (LL_isEmpty(l)){
        printf("Tidak ada pesanan yang sedang diantarkan\n");
    } else {
        printf("Pesanan yang sedang diantarkan:\n");
        p = FIRST(l);
        ctr = 1;
        while (p!=NULL){
            //printf("%d. %c -> %c ", ctr, INFO(p).pu_point, INFO(p).do_point);
            if (INFO(p).item_type=='N'){
                printf("%d. Normal Item (Tujuan: %c)", ctr, INFO(p).do_point);
            } else if (INFO(p).item_type=='H'){
                printf("%d. Heavy Item (Tujuan: %c)", ctr, INFO(p).do_point);
            } else if (INFO(p).item_type=='P'){
                printf("%d. Perishable Item (Tujuan: %c)", ctr, INFO(p).do_point);
            } else if (INFO(p).item_type=='V'){
                printf("%d. VIP Item (Tujuan: %c)", ctr, INFO(p).do_point);
            }
            printf("\n");
            p = NEXT(p);
            ctr += 1;
        }
    }
}

int LL_length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    // Kamus Lokal
    Address p;
    int ctr;
    // Algoritma
    if (FIRST(l)==NULL){
        ctr = 0;
    } else {
        ctr = 1;
        p = FIRST(l);
        while (NEXT(p)!=NULL){
            ctr += 1;
            p = NEXT(p);
        }
    }
    return ctr;
}

/****************** PROSES TERHADAP LIST ******************/
List LL_concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    // Kamus Lokal
    List l3;
    Address p;
    // Algoritma
    LL_CreateList(&l3);
    p = FIRST(l1);
    while (p!=NULL){
        LL_insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p!=NULL){
        LL_insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}
