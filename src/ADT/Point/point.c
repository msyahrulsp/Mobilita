/* File: point.c */
/* Tanggal: 1 September 2021 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include <math.h>
#include <stdio.h>

#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT P_makePOINT (int X, int Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
    /* KAMUS */
    POINT point;
    /* ALGORITMA */
    Absis(point) = X;
    Ordinat(point) = Y;
    
    return point;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void P_readPOINT (POINT * P) { 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    /* KAMUS */
    int x, y;
    /* ALGORITMA */
    scanf("%f %f", &x, &y);
    *P = P_makePOINT(x, y);
}
void P_displayPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */ 
    /* KAMUS */

    /* ALGORITMA */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}               

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean P_EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
boolean P_NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean P_IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}
boolean P_IsOnSbX (POINT P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    /* KAMUS */

    /* ALGORITMA */
    return (Ordinat(P) == 0);
}
boolean P_IsOnSbY (POINT P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    /* KAMUS */

    /* ALGORITMA */
    return (Absis(P) == 0);
}
int P_Kuadran (POINT P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    /* KAMUS */

    /* ALGORITMA */
    if ((Absis(P) > 0) && (Ordinat(P) > 0))
        return 1;
    else if ((Absis(P) < 0) && (Ordinat(P) > 0))
        return 2;
    else if ((Absis(P) < 0) && (Ordinat(P) < 0))
        return 3;
    else
        return 4;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT P_NextX (POINT P) {
/* Mengirim salinan P dengan absis ditambah satu */    
    /* KAMUS */

    /* ALGORITMA */
    return P_makePOINT(Absis(P) + 1, Ordinat(P));
}          
POINT P_NextY (POINT P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
    /* KAMUS */

    /* ALGORITMA */
    return P_makePOINT(Absis(P), Ordinat(P) + 1);
}
POINT P_PlusDelta (POINT P, int deltaX, int deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    /* KAMUS */

    /* ALGORITMA */
    return P_makePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}
POINT P_MirrorOf (POINT P, boolean SbX) {
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    /* KAMUS */

    /* ALGORITMA */
    if (SbX)
        return P_makePOINT(Absis(P), -Ordinat(P));
    else
        return P_makePOINT(-Absis(P), Ordinat(P));
}
int P_Jarak0 (POINT P) {
/* Menghitung jarak P ke (0,0) */
    /* KAMUS */

    /* ALGORITMA */
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
}
int P_Jarak (POINT P1, POINT P2) {
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
    /* KAMUS */

    /* ALGORITMA */
    return sqrt(pow(Absis(P1) - Absis(P2), 2) + pow(Ordinat(P1) - Ordinat(P2), 2));
}
void P_Geser (POINT *P, int deltaX, int deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    /* KAMUS */

    /* ALGORITMA */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
void P_GeserKeSbX (POINT *P) {
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    /* KAMUS */

    /* ALGORITMA */
    Ordinat(*P) = 0;
}
void P_GeserKeSbY (POINT *P) {
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    /* KAMUS */

    /* ALGORITMA */
    Absis(*P) = 0;
}
void P_Mirror (POINT *P, boolean SbX) {
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    if (SbX)
        Ordinat(*P) *= -1;
    else
        Absis(*P) *= -1; 
}
void P_Putar (POINT *P, float Sudut) {
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    /* KAMUS */
    POINT tempPoint = *P;
    float radSudut = (Sudut * (M_PI / 180.0));
    /* ALGORITMA */
    radSudut *= -1; // CW
    Absis(*P) = (Absis(tempPoint) * cos(radSudut)) - (Ordinat(tempPoint) * sin(radSudut));
    Ordinat(*P) = (Absis(tempPoint) * sin(radSudut)) + (Ordinat(tempPoint) * cos(radSudut));
}