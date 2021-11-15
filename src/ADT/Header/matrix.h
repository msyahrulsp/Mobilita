/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef Matrix_H
#define Matrix_H

#include "boolean.h"
#include "listdin.h"
#include "pcolor.h"
#include "list_linked.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int Index; /* Index baris, kolom */
typedef char M_ElType;
typedef struct
{
   M_ElType contents[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void M_CreateMatrix(int nRow, int nCol, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROWS(M) (M).rowEff
#define COLS(M) (M).colEff
#define M_ELMT(M, i, j) (M).contents[(i)][(j)]

/* *** Selektor "DUNIA Matrix" *** */
boolean M_isIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index M_getLastIdxRow(Matrix m);
/* Mengirimkan Index baris terbesar m */
Index M_getLastIdxCol(Matrix m);
/* Mengirimkan Index kolom terbesar m */
boolean M_isIdxEff(Matrix m, Index i, Index j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

/* ********** Assignment  Matrix ********** */
void M_copyMatrix(Matrix mIn, Matrix *mRes);
/* Melakukan assignment MRes = MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void M_displayMatrix(Matrix m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** Operasi lain ********** */
int M_count(Matrix m);
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
void M_ContructorMap (ListDin daftarbangunan, Matrix *m, int b, int k);
/* I.S. Map sembarang */
/* F.S. Map terdefinisi */

void M_displayMap (Matrix m, int position, LL_List todolist, LL_List inprogresslist ,ListDin daftarbangunan, ListDin moveable);
/* I.S. daftarbangunan terdefinisi */
/* F.S. Map tercetak */

#endif