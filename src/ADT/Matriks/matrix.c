#include <stdio.h>

#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void M_CreateMatrix(int nRow, int nCol, Matrix *m) {
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    /* KAMUS */

    /* ALGORITMA */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean M_isIdxValid(int i, int j) {
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index M_getLastIdxRow(Matrix m) {
/* Mengirimkan Index baris terbesar m */
    /* KAMUS */

    /* ALGORITMA */
    return (ROWS(m) - 1);
}
Index M_getLastIdxCol(Matrix m) {
/* Mengirimkan Index kolom terbesar m */
    /* KAMUS */

    /* ALGORITMA */
    return (COLS(m) - 1);
}
boolean M_isIdxEff(Matrix m, Index i, Index j) {
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < ROWS(m)) && (j >= 0 && j < COLS(m));
}

/* ********** Assignment  Matrix ********** */
void M_copyMatrix(Matrix mIn, Matrix *mRes) {
/* Melakukan assignment MRes = MIn */
    /* KAMUS */

    /* ALGORITMA */
    *mRes = mIn;
}

void M_displayMatrix(Matrix m) {
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            printf("%d", M_ELMT(m, i, j));
            if (j != M_getLastIdxCol(m)) printf(" ");
        }
        if (i != M_getLastIdxRow(m)) printf("\n");
    }
}


/* ********** Operasi lain ********** */
int M_count(Matrix m) {
/* Mengirimkan banyaknya elemen m */
    /* KAMUS */

    /* ALGORITMA */
    return (ROWS(m) * COLS(m));
}



void M_ContructorMap (ListDin daftarbangunan, Matrix *m, int b, int k){
/* Membentuk sebuah Map "kosong" yang siap diisi berukuran b x k di "ujung kiri" memori */
/* I.S. b dan k adalah valid untuk memori matriks(map) yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    /* KAMUS */
    int i, j, idx;
    boolean found;
    /* ALGORITMA */
    ROWS(*m) = b + 2;
    COLS(*m) = k + 2;
    for (i = 0; i < ROWS(*m); i++){
        for (j = 0; j < COLS(*m); j++) {
            if (i == 0 || j == 0 || i == ROWS(*m)-1 || j == COLS(*m)-1) {
                M_ELMT(*m, i, j) = '*';
            } else {
                found = false;
                idx = 0;
                while (idx < NEFF(daftarbangunan) && !found){
                    if (i == BPOINTX(daftarbangunan, idx) && j == BPOINTY(daftarbangunan, idx)){
                        found = true;
                    } else {
                        idx += 1;
                    }
                }
                if (found) {
                    M_ELMT(*m, i, j) = BNAME(daftarbangunan, idx);
                } else {
                    M_ELMT(*m, i, j) = ' ';
                }
            }
            
        }
    }
        
}

void M_displayMap (Matrix m, int position, LL_List todolist, LL_List inprogresslist ,ListDin daftarbangunan, ListDin moveable) {
/* I.S. daftarbangunan terdefinisi */
/* F.S. Map tercetak */
    // Kamus 
    int i, j;
    // ALgoritma
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            if (i == BPOINTX(daftarbangunan, position) && j == BPOINTY(daftarbangunan, position)) {
                print_yellow(M_ELMT(m, i, j));
            } else if (LL_do_isIn(inprogresslist, M_ELMT(m, i, j))!=IDX_UNDEF) {
                print_blue(M_ELMT(m, i, j));
            } else if (LL_pu_isIn(todolist, M_ELMT(m, i, j))!=IDX_UNDEF) {
                print_red(M_ELMT(m, i, j));
            } else if (LD_isBuildingIn(moveable, M_ELMT(m, i, j))) {
                print_green(M_ELMT(m, i, j));
            } else {
                printf("%c", M_ELMT(m, i, j));
            }
        }
        if (i != M_getLastIdxRow(m)) printf("\n");
    }
    printf("\n");
}