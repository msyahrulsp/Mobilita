#include <stdio.h>
#include "matrix.h"

int main(){

    Matrix m;

    M_CreateMatrix(2, 2, &m);

    M_ELMT(m, 0, 0) = 'A';
    M_ELMT(m, 0, 1) = 'B';
    M_ELMT(m, 1, 0) = 'C';
    M_ELMT(m, 1, 1) = 'D';

    for (int i = 0; i<=2; i++){
        for (int j=0; j<=2; j++){
            printf("%c", M_ELMT(m, i, j));
        }
    }

    return 0;
}
