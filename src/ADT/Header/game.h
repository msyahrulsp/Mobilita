#include "matrix.h"
#include "point.h"
#include "Pesanan.h"
#include "listdin.h"
#include "list_linked.h"
#include "stack.h"
#include "listStatik.h"
#include "queue.h"
#include "ability.h"

typedef struct {
    int Money;
    int Time;
    int NDrop;
    POINT Pos;
} Stat;

typedef struct {
    Ability Speed;
    Ability RTS;
} Abty;

/*==================== LIST MACRO FOR MAIN ====================*/
// Stat
#define Money(d) (d).Player.Money
#define Time(d) (d).Player.Time
#define NDrop(d) (d).Player.NDrop
#define Pos(d) (d).Player.Pos
#define PosX(d) (d).Player.Pos.X // PosX Mobita
#define PosY(d) (d).Player.Pos.Y // PosY Mobita

// Ability
#define Speed(d) (d).Skill.Speed
#define Ret(d) (d).Skill.RTS

// Map
#define Map(d) (d).Map

// HQ
#define HQ(d) (d).HQ

// Building
#define NBuild(d) (d).NBuild
#define Building(d) (d).Building
#define BuiNEFF(d) (d).Building.nEff
#define BuiNAME(d, i) (d).Building.buffer[i].buildingName
#define BuiPOINT(d, i) (d).Building.buffer[i].position 

// Adjacency Matrix
#define Adj(d) (d).Adj
#define AdjE(d, i, j) (d).Adj.contents[(i)][(j)]

// Pesanan
#define NOrder(d) (d).NOrder
#define Order(d) (d).Order
#define OrderE(d, i) (d).Order.buffer[(i)]

// ToDoList
#define NToDo(d) (d).NToDo
#define ToDo(d) (d).ToDo

// InProgressList
#define NIPL(d) (d).NIPL
#define IPL(d) (d).IPL

// Tas
#define MTas(d) (d).MaxTas
#define NTas(d) (d).NTas
#define Tas(d) (d).Tas

// Inventory
#define Invent(d) (d).Invent
#define InventE(d, i) (d).Invent.contents[i]

typedef struct { 
    Stat Player; // Uang, Waktu, Lokasi
    Abty Skill; // SpeedBoost, RTS
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
    int NTas;
    Stack Tas; // Tas
    ListGadget Invent; // Invent Gadget
} Game;

void help(int type);

void printMobilita();

int endGame(int position);