#include "matrix.h"
#include "point.h"
#include "Pesanan.h"
#include "listdin.h"

typedef struct {
    int Time;
    int Money;
    POINT Pos;
} Stat;

typedef struct { // Not Done
    Stat Player;
    Matrix Map;
    POINT HQ;
    int NBuild;
    Building Build;
    Matrix Adj;
    int NOrder;
    Pesanan Order;
} Game;

void help();

/*
Waktu, Lokasi, Uang
Daftar Pesanan
To Do List
In Progress List
Tas
Inventory
Peta
*/