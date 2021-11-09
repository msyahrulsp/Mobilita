#include "matrix.h"
#include "point.h"
#include "Pesanan.h"
#include "listdin.h"

typedef struct {
    int Time;
    int Money;
} Stat;

typedef struct { // Not Done
    Matrix Map;
    POINT HQ;
    int NBuild;
    Building Build;
    Matrix Adj;
    int NOrder;
    Pesanan Order;
    Stat Player;
} Game