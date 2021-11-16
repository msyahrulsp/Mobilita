#include <stdio.h>
#include "loadsave.h"

Game data;
static int retval;

void load(int type) {
    resetWord();
    printf("Masukkan nama file permainan: ");
    startWord();
    if (type == 1) {
        while(!isEqual(currentWord, "Default")) {
            printf("File New Game salah!\n");
            resetWord();
            printf("Masukkan nama file permainan: ");
            startWord();
        }
        toPath();
        loadFile = fopen(currentWord.contents, "r");
    } else {
        while(isEqual(currentWord, "Default")) {
            printf("File Load Game salah!\n");
            resetWord();
            printf("Masukkan nama file permainan: ");
            startWord();
        }
        toPath();
        loadFile = fopen(currentWord.contents, "r");

        while(loadFile == NULL) {
            printf("File Load Game tidak ada!\n");
            resetWord();
            printf("Masukkan nama file permainan: ");
            startWord();
            toPath();
            loadFile = fopen(currentWord.contents, "r");
        }
    }
    startScan();

    // Stat Load
    Money(data) = Scanner.num;
    advScan();
    Time(data) = Scanner.num;
    advScan();
    NDrop(data) = Scanner.num;
    advScan();
    PosX(data) = Scanner.num;
    advScan();
    PosY(data) = Scanner.num;

    // Map
    advScan();
    Map(data).rowEff = Scanner.num;
    advScan();
    Map(data).colEff = Scanner.num;

    // Koor HQ
    advScan();
    HQ(data).X = Scanner.num;
    advScan();
    HQ(data).Y = Scanner.num;

    // NBuild
    advScan();
    NBuild(data) = Scanner.num;

    // Building
    LD_CreateListDin(&Building(data), NBuild(data) + 1);
    BuiNAME(data, 0) = '8';
    BuiPOINT(data, 0).X = HQ(data).X;
    BuiPOINT(data, 0).Y = HQ(data).Y;
    BuiNEFF(data) = 1;
    int i;
    for (i = 1; i < NBuild(data) + 1; i++) {
        advScan();
        BuiNAME(data, i) = Scanner.let;
        advScan();
        BuiPOINT(data, i).X = Scanner.num;
        advScan();
        BuiPOINT(data, i).Y = Scanner.num;
        BuiNEFF(data) += 1;
    }

    // Adjacency
    Adj(data).colEff = NBuild(data) + 1;
    Adj(data).rowEff = NBuild(data) + 1;
    int j;
    for (i = 0; i < NBuild(data) + 1; i++) {
        for (j = 0; j < NBuild(data) + 1; j++) {
            advScan();
            AdjE(data, i, j) = Scanner.num;
        }
    }

    // Order
    advScan();
    NOrder(data) = Scanner.num;

    Pesanan odr;
    int to, p;
    char bp, bd, ji;
    Q_CreateQueue(&Order(data));
    LL_CreateList(&ToDo(data));
    for (i = 0; i < NOrder(data); i++) {
        advScan();
        to = Scanner.num;
        advScan();
        bp = Scanner.let;
        advScan();
        bd = Scanner.let;
        advScan();
        ji = Scanner.let;
        if (currentChar == BLANK) {
            advScan();
            p = Scanner.num;
        } else {
            p = NULL_PERISHTIME;
        }
        Q_CreatePesanan(&odr, to, bp, bd, ji, p);

        if (to <= Time(data)) {
            LL_insertLast(&ToDo(data), odr);
        }

        Q_enqueue(&Order(data), odr);
    }
    // IPL
    advScan();
    NIPL(data) = Scanner.num;
    LL_CreateList(&IPL(data));
    for (i = 0; i < NIPL(data); i++) {
        advScan();
        ji = Scanner.let;
        advScan();
        bd = Scanner.let;
        Q_CreatePesanan(&odr, 'U', 'U', bd, ji, -1);
        LL_insertLast(&IPL(data), odr);
    }

    // Tas
    advScan();
    MTas(data) = Scanner.num;
    advScan();
    NTas(data) = Scanner.num;
    S_CreateStack(&Tas(data));
    for (i = 0; i < NTas(data); i++) {
        advScan();
        to = Scanner.num;
        advScan();
        bp = Scanner.let;
        advScan();
        bd = Scanner.let;
        advScan();
        ji = Scanner.let;
        if (currentChar == BLANK) {
            advScan();
            p = Scanner.num;
        } else {
            p = NULL_PERISHTIME;
        }
        Q_CreatePesanan(&odr, to, bp, bd, ji, p);
        S_push(&Tas(data), odr);
    }

    // Invent;
    for (i = 0; i < 5; i++) {
        advScan();
        InventE(data, i).gadgetname = Scanner.let;
        advScan();
        InventE(data, i).gadgetprice = Scanner.num;
    }

    fclose(loadFile);
}

void save() {
    FILE *saveFile;

    resetWord();
    printf("Masukkan nama save file permainan: ");
    startWord();
    while(isEqual(currentWord, "Default")) {
        printf("Tidak bisa mengubah file Default\n");
        resetWord();
        printf("Masukkan nama save file permainan: ");
        startWord();
    }
    toPath();
    saveFile = fopen(currentWord.contents, "w");

    // Stat (Uang, Waktu, Pos)
    fprintf(saveFile, "%d %d %d %d %d\n", Money(data), Time(data), NDrop(data), PosX(data), PosY(data));
    // Ukuran Map
    fprintf(saveFile, "%d %d\n", Map(data).rowEff, Map(data).colEff);
    // HQ
    fprintf(saveFile, "%d %d\n", HQ(data).X, HQ(data).Y);

    // Building
    fprintf(saveFile, "%d\n", NBuild(data));
    int i;
    for (i = 0; i < NBuild(data); i++) {
        fprintf(saveFile, "%c %d %d\n", BuiNAME(data, i), BuiPOINT(data, i).X, BuiPOINT(data, i).Y); // Build + Koor
    }

    // Matriks Adj
    int j;
    for (i = 0; i < Adj(data).rowEff; i++) {
        for (j = 0; j < Adj(data).colEff; j++) {
            fprintf(saveFile, "%d", AdjE(data, i, j));

            if (j != Adj(data).colEff) fprintf(saveFile, " ");
        }
        fprintf(saveFile, "\n");
    }

    // Order
    int to, p;
    char bp, bd, ji;
    fprintf(saveFile, "%d\n", NOrder(data));
    for (i = 0; i < NOrder(data); i++) {
        to = Order(data).buffer[i].waktuPesanan;
        bp = Order(data).buffer[i].pickUpPoint;
        bd = Order(data).buffer[i].dropOffPoint;
        ji = Order(data).buffer[i].jenisItem;
        fprintf(saveFile, "%d %c %c %c", to, bp, bd, ji);
        p = Order(data).buffer[i].perishTime;
        if (p != -1) {
            fprintf(saveFile, " %d\n", p);
        } else {
            fprintf(saveFile, "\n");
        }
    }

    // ToDo
    fprintf(saveFile, "%d\n", NIPL(data));
    for (i = 0; i < NIPL(data); i++) {
        bd = Order(data).buffer[i].dropOffPoint;
        ji = Order(data).buffer[i].jenisItem;
        fprintf(saveFile, "%c %c\n", ji, bd);
    }

    // Tas
    Stack temp;
    Pesanan holder;
    S_reverseCopy(&temp, Tas(data));
    fprintf(saveFile, "%d\n", MTas(data));
    while(!S_isEmpty(temp)) {
        S_pop(&temp, &holder);
        fprintf(saveFile, "%d %c %c %c", holder.waktuPesanan, holder.pickUpPoint, holder.dropOffPoint, holder.jenisItem);
        if (holder.perishTime != - 1) {
            fprintf(saveFile, " %d\n", holder.perishTime);
        } else {
            fprintf(saveFile, "\n");
        }
    }

    // Invent
    for (i = 0; i < 5; i++) {
        fprintf(saveFile, "%c %d\n", InventE(data, i).gadgetname, InventE(data, i).gadgetprice);
    }
    printf("Save file berhasil terbuat!\n");

    fclose(saveFile);
}