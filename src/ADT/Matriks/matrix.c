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
ElType M_getElmtDiagonal(Matrix m, Index i) {
/* Mengirimkan elemen m(i,i) */
    /* KAMUS */

    /* ALGORITMA */
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void M_copyMatrix(Matrix mIn, Matrix *mRes) {
/* Melakukan assignment MRes = MIn */
    /* KAMUS */

    /* ALGORITMA */
    *mRes = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void M_readMatrix(Matrix *m, int nRow, int nCol) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    M_CreateMatrix(nRow, nCol, m);

    for (i = 0; i < ROWS(*m); i++)
        for (j = 0; j < COLS(*m); j++)
            scanf("%d", &ELMT(*m, i, j));
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
            printf("%d", ELMT(m, i, j));
            if (j != M_getLastIdxCol(m)) printf(" ");
        }
        if (i != M_getLastIdxRow(m)) printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix M_addMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m1); i++) 
        for (j = 0; j < COLS(m1); j++) 
            ELMT(m1, i, j) += ELMT(m2, i, j);

    return m1;
}
Matrix M_subtractMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m1); i++) 
        for (j = 0; j < COLS(m1); j++) 
            ELMT(m1, i, j) -= ELMT(m2, i, j);

    return m1;
}
Matrix M_multiplyMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    /* KAMUS */
    Matrix m;
    int i, j, k;
    /* ALGORITMA */
    M_CreateMatrix(ROWS(m1), COLS(m2), &m);

    for (i = 0; i < ROWS(m); i++) 
        for (j = 0; j < COLS(m); j++) {
            ELMT(m, i, j) = 0;
            for (k = 0; k < COLS(m1); k++) {
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }

    return m;
}
Matrix M_multiplyConst(Matrix m, ElType x) {
/* Mengirim hasil perkalian setiap elemen m dengan x */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m); i++) 
        for (j = 0; j < COLS(m); j++) 
            ELMT(m, i, j) *= x;

    return m;
}
void M_pMultiplyConst(Matrix *m, ElType k) {
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(*m); i++) 
        for (j = 0; j < COLS(*m); j++) 
            ELMT(*m, i, j) *= k;
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean M_isEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    if (M_getLastIdxCol(m1) != M_getLastIdxCol(m2) || M_getLastIdxRow(m1) != M_getLastIdxRow(m2)) return false;
    else {
        for (i = 0; i < ROWS(m1); i++) 
            for (j = 0; j < COLS(m1); j++) 
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) return false;
    }
    return true;
}
boolean M_isNotEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    /* KAMUS */

    /* ALGORITMA */
    return !M_isEqual(m1, m2);
}
boolean M_isSizeEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* KAMUS */

    /* ALGORITMA */
    return (COLS(m1) == COLS(m2)) && (ROWS(m1) == ROWS(m2));
}

/* ********** Operasi lain ********** */
int M_count(Matrix m) {
/* Mengirimkan banyaknya elemen m */
    /* KAMUS */

    /* ALGORITMA */
    return (ROWS(m) * COLS(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean M_isSquare(Matrix m) {
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    /* KAMUS */

    /* ALGORITMA */
    return COLS(m) == ROWS(m);
}
boolean M_isSymmetric(Matrix m) {
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    if (!M_isSquare(m)) return false;
    for (i = 0; i < ROWS(m); i++) 
        for (j = 0; j < COLS(m); j++) 
            if (ELMT(m, i, j) != ELMT(m, j, i)) return false;
    return true;
}
boolean M_isIdentity(Matrix m) {
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    if (!M_isSquare(m)) return false;
    for (i = 0; i < ROWS(m); i++) 
        for (j = 0; j < COLS(m); j++) {
            if (i == j) {
                if (M_getElmtDiagonal(m, i) != 1) return false;
            } else {
                if (ELMT(m, i, j) != 0) return false;
            }
        }
            
    return true;
}
boolean M_isSparse(Matrix m) {
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    /* KAMUS */
    int i, j; 
    float countNot0 = 0;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m); i++) 
        for (j = 0; j < COLS(m); j++) 
            if (ELMT(m, i, j) != 0) countNot0++;
    return countNot0 / count(m) <= 0.05;
}
Matrix M_inverse1(Matrix m) {
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    /* KAMUS */

    /* ALGORITMA */
    return M_multiplyConst(m, -1);
}
void M_pInverse1(Matrix *m) {
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    /* KAMUS */

    /* ALGORITMA */
    M_pMultiplyConst(m, -1);
}
float M_determinant(Matrix m) {
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
/* METODE: MINOR KOFAKTOR */
    /* KAMUS */
    float det;
    int i, iM, jM, iMi, jMi;
    /* ALGORITMA */
    if (COLS(m) == 1) det = ELMT(m, 0, 0);
    else {
        det = 0;
        for (i = 0; i < ROWS(m); i++) {
            Matrix Minor;
            M_CreateMatrix((ROWS(m) - 1), (COLS(m) - 1), &Minor);
            iMi = 0;
            for (iM = 0; iM <= M_getLastIdxRow(m); iM++)
            {
                if (iM != i)
                {
                    jMi = 0;
                    for (jM = 0; jM <= M_getLastIdxCol(m); jM++)
                    {
                        if (jM !=0)
                        {
                            ELMT(Minor, iMi, jMi) = ELMT(m, iM, jM);
                            jMi++;
                        }
                    }
                    iMi++;
                }
            }
            det += (i % 2 == 0 ? 1 : -1) * ELMT(m, i, 0) * M_determinant(Minor);
        }
    }
    return det;
    // /* KAMUS */
    // float det = 0;
    // /* ALGORITMA */
    // if (COLS(m) == 1) return ELMT(m, 0, 0);
    // else if (COLS(m) == 2) return (ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 1, 0) * ELMT(m, 0, 1)); 
    // else {
    //     Matrix tempM;
    //     for (int j = 0; j < COLS(m); j++) {
    //         copyMatrix(m, &tempM);
    //         ROWS(tempM) -= 1;
    //         COLS(tempM) -= 1;
    //         for (int k = 0; k < ROWS(tempM); k++) {
    //             for (int l = 0; l < COLS(tempM); l++) {
    //                 ELMT(tempM, k, l) = ELMT(tempM, k + 1, l);
    //             }
    //         }
    //         for (int k = 0; k < ROWS(tempM); k++) {
    //             for (int l = j; l < COLS(tempM); l++) {
    //                 ELMT(tempM, k, l) = ELMT(tempM, k, l + 1);
    //             }
    //         }
    //         det += (j % 2 == 1 ? 1 : -1) * ELMT(m, 0, j) * determinant(tempM);
    //     }
    //     return det;
    // }
}
void M_transpose(Matrix *m) {
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    /* KAMUS */
    int i, j;
    ElType temp;
    /* ALGORITMA */
    for (i = 0; i < ROWS(*m); i++)
        for (j = i + 1; j < COLS(*m); j++) {
            temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
}