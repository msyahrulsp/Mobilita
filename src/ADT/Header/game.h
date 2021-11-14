#include "matrix.h"
#include "point.h"
#include "Pesanan.h"
#include "listdin.h"
#include "list_linked.h"
#include "stack.h"
#include "listStatik.h"
#include "queue.h"

typedef struct {
    int Time;
    int Money;
    POINT Pos;
} Stat;

#define Money(d) (d).Player.Money
#define Time(d) (d).Player.Time
#define PosX(d) (d).Player.Pos.X // PosX Mobita
#define PosY(d) (d).Player.Pos.Y // PosY Mobita
#define Map(d) (d).Map
#define HQ(d) (d).HQ
#define NBuild(d) (d).NBuild

// Building
#define Building(d) (d).Building
#define BuiNEFF(d) (d).Building.nEff
#define BuiNAME(d, i) (d).Building.buffer[i].buildingName
#define BuiPOINT(d, i) (d).Building.buffer[i].position 

#define Adj(d) (d).Adj
#define AdjE(d, i, j) (d).Adj.contents[(i)][(j)]

#define NOrder(d) (d).NOrder
#define Order(d) (d).Order
#define OrderE(d, i) (d).Order.buffer[(i)]

#define NToDo(d) (d).NToDo
#define NIPL(d) (d).NIPL
#define MTas(d) (d).MaxTas

#define InventE(d, i) (d).Invent.contents[i]

typedef struct { 
    Stat Player; // Uang, Waktu, Lokasi
    Matrix Map; // Peta
    POINT HQ; // X Y
    int NBuild;
    ListDin Building;
    Matrix Adj; // NBuild + 1
    int NOrder;
    Queue Order; // Daftar Pesanan
    LL_List ToDo; // To Do List
    int NIPL;
    LL_List IPL; // In Progress List
    int MaxTas;
    Stack Tas; // Tas
    ListGadget Invent; // Invent Gadget
} Game;

void help();