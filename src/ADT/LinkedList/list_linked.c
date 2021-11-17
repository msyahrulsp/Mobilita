#include "list_linked.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void LL_CreateList(LL_List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    // Algoritma
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean LL_isEmpty(LL_List l){
/* Mengirim true jika list kosong */
    // Algoritma
    return (FIRST(l)==NULL);
}

/****************** GETTER SETTER ******************/
LL_ElType LL_getElmt(LL_List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    // Kamus Lokal
    int ctr;
    LL_Address p;
    // Algoritma
    p = FIRST(l);
    ctr = 0;
    while (ctr<idx){
        ctr += 1;
        p = NEXT(p);
    }
    return INFO(p);
}

void LL_setElmt(LL_List *l, int idx, LL_ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    // Kamus Lokal
    int ctr;
    LL_Address p;
    // Algoritma
    p = FIRST(*l);
    ctr = 0;
    while (ctr<idx) {
        ctr += 1;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int LL_indexOf(LL_List l, LL_ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    // Kamus Lokal
    int idx;
    LL_Address p;
    boolean found;
    // Algoritma
    idx = 0;
    p = FIRST(l);
    found = false;
    while (p!=NULL && !(found)){
        if ((INFO(p).duration == val.duration) && (INFO(p).pickUpPoint==val.pickUpPoint) && (INFO(p).dropOffPoint == val.dropOffPoint) && (INFO(p).jenisItem == val.jenisItem)){
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

int LL_pesananAvailable(LL_List l, POINT titik, ListDin daftarbangunan){
// Mengembalikan idx todolist apabila ada pesanan yang bisa dipickup dari p, dan IDX_UNDEF jika tidak ada
    // Kamus Lokal
    int idx;
    LL_Address p;
    boolean found;
    // Algoritma
    idx = 0;
    p = FIRST(l);
    found = false;
    while (p!=NULL && !(found)){
        if (P_EQ(LD_buildingtToPoint(daftarbangunan, INFO(p).pickUpPoint),titik)){
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
void LL_insertFirst(LL_List *l, LL_ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    // Kamus Lokal
    LL_Address p;
    // Algoritma
    p = newNode(val);
    if (p!=NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void LL_insertLast(LL_List *l, LL_ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // Kamus Lokal
    LL_Address last, p;
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

void LL_insertAt(LL_List *l, LL_ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // Kamus Lokal
    LL_Address p, loc;
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
void LL_deleteFirst(LL_List *l, LL_ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    // Kamus Lokal
    LL_Address p;
    // Algoritma
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
void LL_deleteLast(LL_List *l, LL_ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    // Kamus Lokal
    LL_Address p, loc;
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

void LL_deleteAt(LL_List *l, int idx, LL_ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    // Kamus Lokal
    LL_Address loc, p;
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
void LL_displayList_ToDo(LL_List l){
/* I.S. List mungkin kosong */
/* F.S. To Do List tercetak pada layar */
    // Kamus Lokal
    LL_Address p;
    int ctr;
    // Algoritma

    if (LL_isEmpty(l)){
        printf("To Do List Kosong\n");
    } else {
        printf("Pesanan To Do List:\n");
        p = FIRST(l);
        ctr = 1;
        while (p!=NULL){
            printf("%d. %c -> %c ", ctr, INFO(p).pickUpPoint, INFO(p).dropOffPoint);
            if (INFO(p).jenisItem=='N'){
                printf("(Normal Item)");
            } else if (INFO(p).jenisItem=='H' || INFO(p).jenisItem=='n'){
                printf("(Heavy Item)");
            } else if (INFO(p).jenisItem=='P'){
                printf("(Perishable Item)");
            }
            printf("\n");
            p = NEXT(p);
            ctr += 1;
        }
    }
}

void LL_displayList_InProgress(LL_List l){
/* I.S. List mungkin kosong */
/* F.S. In Progress List tercetak pada layar */
    // Kamus Lokal
    LL_Address p;
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
            if (INFO(p).jenisItem=='N'){
                printf("%d. Normal Item (Tujuan: %c)", ctr, INFO(p).dropOffPoint);
            } else if (INFO(p).jenisItem=='H' || INFO(p).jenisItem=='n'){
                printf("%d. Heavy Item (Tujuan: %c)", ctr, INFO(p).dropOffPoint);
            } else if (INFO(p).jenisItem=='P'){
                printf("%d. Perishable Item (Tujuan: %c) (Sisa Waktu: %d)", ctr, INFO(p).dropOffPoint, INFO(p).timer);
            }
            printf("\n");
            p = NEXT(p);
            ctr += 1;
        }
    }
}

int LL_length(LL_List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    // Kamus Lokal
    LL_Address p;
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
LL_List LL_concat(LL_List l1, LL_List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    // Kamus Lokal
    LL_List l3;
    LL_Address p;
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

int heavy_InProgress(LL_List l){
    LL_Address p;
    int ctr = 0;

    p = FIRST(l);
    while (p!=NULL){
        if (INFO(p).jenisItem=='H'){
            ctr += 1;
        }
        p = NEXT(p);
    }

    return ctr;
}

int LL_pu_isIn(LL_List l, char x){
    int idx;
    LL_Address p;
    boolean found;
    // Algoritma
    idx = 0;
    p = FIRST(l);
    found = false;
    while (p!=NULL && !(found)){
        if (INFO(p).pickUpPoint==x){
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

int LL_do_isIn(LL_List l, char x){
    int idx;
    LL_Address p;
    boolean found;
    // Algoritma
    idx = 0;
    p = FIRST(l);
    found = false;
    while (p!=NULL && !(found)){
        if (INFO(p).dropOffPoint==x){
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

int LL_dropOffAvailable(LL_List l, POINT titik, ListDin daftarbangunan){

    int idx;
    LL_Address p;
    boolean found;
    // Algoritma
    idx = 0;
    p = FIRST(l);
    found = false;
    if (p!=NULL){
        if (P_EQ(LD_buildingtToPoint(daftarbangunan, INFO(p).dropOffPoint),titik)){
            found = true;
        }
    }
    if (!found){
        idx = IDX_UNDEF;
    }
    return idx;
}

void LL_disapPerishable (LL_List *l, int time, int timeadd, int *disap){
    int idx = 0;
    LL_Address p = FIRST(*l);
    LL_ElType val;
    while (p!=NULL){
        if (INFO(p).jenisItem == 'P'){
            INFO(p).timer -= timeadd;
        }
        if (INFO(p).jenisItem == 'P' && INFO(p).timer <= 0){
            LL_deleteAt(l, idx, &val);
            *disap += 1;
        }
        idx += 1;
        p = NEXT(p);
    }
}