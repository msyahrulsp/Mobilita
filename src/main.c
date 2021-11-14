#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Butuh tipe data Game > Buat load + save ( Ini nampung semua data )

void help() {
    printf("\nHELP MENU MOBILITA\n");
    printf("1. MOVE -> Untuk berpindah ke lokasi selanjutnya\n");
    printf("2. PICK_UP -> Untuk mengambil item di lokasi sekarang\n");
    printf("3. DROP_OFF -> Untuk mengantarkan item ke lokasi jika item di tumpukan teratas tas\n");
    printf("4. MAP -> Untuk memunculkan peta\n");
    printf("5. TO_DO -> Untuk menampilkan pesanan yang masuk\n");
    printf("6. IN_PROGRESS -> Untuk menampilkan pesanan yang sedang dikerjakan\n");
    printf("7. BUY -> Untuk menampilkan gadget yang dapat dibeli lalu membelinya\n");
    printf("8. INVENTORY -> Untuk melihat gadget yang dimiliki dan menggunakannya\n");
    printf("9. HELP -> Untuk mengeluarkan list command dan kegunaannya\n");
    printf("10. SAVE_GAME -> Untuk melakukan save state\n");
    printf("11. RETURN -> Untuk mengembalikan item teratas di tas\n\n");
}

void buy(ListGadget inventory, int *money){
    printf("Uang Anda sekarang: %d Yen\n", *money);
    printf("Gadget yang tersedia:\n");
    printf("1. Kain Pembungkus Waktu (800 Yen)\n");
    printf("2. Senter Pembesar (1200 Yen)\n");
    printf("3. Pintu Kemana Saja (1500 Yen)\n");
    printf("4. Mesin Waktu (3000 Yen)\n");
    printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");

    boolean added;
    resetWord();
    printf("\nENTER COMMAND: ");
    startWord();
    if(isEqual(currentWord, "1")){
        if(*money >= 800){
            Gadget gd;
            gd.gadgetname = 'K';
            gd.gadgetprice = 800;
            added = LS_insertGadget(&inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Kain Pembungkus Waktu berhasil dibeli!
            }
        }
        else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
    else if(isEqual(currentWord, "2")){
        if(*money >= 1200){
            Gadget gd;
            gd.gadgetname = 'B';
            gd.gadgetprice = 1200;
            added = LS_insertGadget(&inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Senter Pembesar berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Senter Pembesar berhasil dibeli!
            }
        }
        else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
    else if(isEqual(currentWord, "3")){
        if(*money >= 1500){
            Gadget gd;
            gd.gadgetname = 'D';
            gd.gadgetprice = 1500;
            added = LS_insertGadget(&inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Pintu Kemana Saja berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Pintu Kemana Saja berhasil dibeli!
            }
        }
        else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
    else if(isEqual(currentWord, "4")){
        if(*money >= 3000){
            Gadget gd;
            gd.gadgetname = 'T';
            gd.gadgetprice = 3000;
            added = LS_insertGadget(&inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Mesin Waktu berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Mesin Waktu berhasil dibeli!
            }
        }
        else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
    else if(isEqual(currentWord, "5")){
        if(*money >= 800){
            Gadget gd;
            gd.gadgetname = 'S';
            gd.gadgetprice = 800;
            added = LS_insertGadget(&inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Senter Pengecil berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Senter Pengecil berhasil dibeli!
            }
        }
        else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
    else if(isEqual(currentWord, "0")) {
        // Back
    }
    else{
        printf("Gadget dengan kode tersebut tidak ada.\n");
    }
}

void delSenterPengecilEff(Stack *bag){
    Stack tempBag; // Membuat stack untuk tempat penampungan item sementara
    S_CreateStack(&tempBag);

    boolean foundGadgetEff = false;
    S_ElType item; // Variabel untuk menampung item yang dipindahkan
    while(!foundGadgetEff){
        if(JENIS_ITEM(TOP(*bag)) != 'n'){
            foundGadgetEff = true;
        }
        else{
            S_pop(bag, &item);
            S_push(&tempBag, item); // Item dipindahkan ke temporaryBag
        }
    }
    if (foundGadgetEff == true){
        JENIS_ITEM(TOP(*bag)) = 'H';
    }
    while(S_isEmpty(tempBag) != true){
        S_pop(&tempBag, &item);
        S_push(bag, item);
    }
}


/*==================================================================*/
int main(){
	// KAMUS
    int idxtdl;
    int time, position;
    int bagCapacity, money;
    int totalbangunan;
    int N, M; // Ukuran matriks peta
    int hqX, hqY; // Lokasi HeadQuarters
    POINT point_currentPos;
    Matrix adj;
    Queue daftarpesanan;
    LL_List todolist, inprogresslist;
    ListDin daftarbangunan, moveable;
    Pesanan order, valpesanan;
    Stack bag;
    ListGadget inventory;
    LL_List perishablelist;
    //Ability SpeedBoost, ReturnToSender;

    // main menu
    printf("MOBILITA - Main Menu\n");
    printf("ENTER COMMAND: ");
    startWord();

    while(!isEqual(currentWord, "NEW_GAME") && !isEqual(currentWord, "LOAD_GAME")) {
        if(isEqual(currentWord, "EXIT")) {
            exit(1); // sementara
        } else {
            printf("Command salah\n");
            resetWord();
            printf("ENTER COMMAND: ");
            startWord();
        }
    }

    if (isEqual(currentWord, "NEW_GAME")) {
        load(1); // Nama File harus Default
    } else {
        load(0); // Nama File bebas, asal gk Default
    }
    
    // inisialisasi variabel
    time = 0;
    position = 0; // index HQ of daftarbangunan
    bagCapacity = 3; // batasan untuk ukuran tas
    LS_CreateListGadget(&inventory);
    LL_CreateList(&todolist);
    LL_CreateList(&inprogresslist);
    LL_CreateList(&perishablelist);
    S_CreateStack(&bag);
    //AB_createAbility(&SpeedBoost, true);
    //AB_createAbility(&ReturnToSender, false);

    // Menyalin perishable item dari to do list
    // Untuk keperluan efek gadget Kain Pembungkus Waktu
    LL_Address perishableptr = FIRST(todolist);
    while (perishableptr != NULL){
        if (JENIS_ITEM(INFO(perishableptr)) == 'P'){
            LL_insertFirst(&perishablelist, INFO(perishableptr));
        }
        perishableptr = NEXT(perishableptr);
    }

    printf("\nSELAMAT BERMAIN!!\n\n");
    printf("Waktu: %d\n",time);
    resetWord();
    printf("ENTER COMMAND: ");
    startWord();

    while (!isEqual(currentWord, "EXIT")) {
        if (isEqual(currentWord, "MOVE")) {
            LD_CreateListDin(&moveable, totalbangunan);
            // Melihat konfigurasi adjacency Matrix (adj)
            for(int j = 0; j < COLS(adj); j++){
                if (M_ELMT(adj,position,j)==1){
                    // Insert to moveable List
                    LD_insertLast(&moveable, LD_ELMT(daftarbangunan,j));
                }
            }
            // Input
            printf("Posisi yang dapat dicapai:\n");
            for(int i = 0; i < LD_length(moveable); i++){
                printf("%.d. %c (%d,%d)\n",(i+1),BNAME(moveable,i),BPOINTX(moveable,i),BPOINTY(moveable,i));
            }
            // Validation Loop
            boolean valid = false;
            while(!valid){
                printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
                resetWord();
                printf("ENTER COMMAND: ");
                startWord();
                if (isEqual(currentWord, "0")){ // Cancel move
                    valid = true;
                    printf("Move dibatalkan!\n");
                } else {
                    int i = 1;
                    int int_currentWord = atoi(currentWord.contents);
                    while((i <= LD_length(moveable)) && (int_currentWord!=i)){
                        i++;
                    }
                    if(i <= LD_length(moveable)){
                        valid = true;
                        i--;
                        // Time Handle
                        /*if(AB_isActive(SpeedBoost)){
                            if ((Count(SpeedBoost) % 2)!=0){
								time++;
							}
							AB_useAbility(&SpeedBoost);
							if (Count(SpeedBoost) == 0){
								AB_deactivate(&SpeedBoost);
							}
                        } */
                        time = time + 1 + heavy_InProgress(inprogresslist);
                        // Daftar Pesanan -> To Do List
                        while (HEAD(daftarpesanan).waktuPesanan <= time){
                            Q_dequeue(&daftarpesanan, &order);
                            LL_insertLast(&todolist, order);
                        }
                        // Move
                        printf("Mobita sekarang berada di titik %c (%d,%d)\n",BNAME(moveable,i),BPOINTX(moveable,i),BPOINTY(moveable,i));
                        position = LD_indexOf(daftarbangunan, LD_ELMT(moveable,i));
                    } else{
                        printf("Silahkan pilih sesuai opsi!\n");
                    }
                }
            }
            LD_dealocate(&moveable);
        } else if (isEqual(currentWord, "PICK_UP")) {
            point_currentPos = BPOINT(daftarbangunan, position);
            idxtdl = LL_pesananAvailable(todolist, point_currentPos, daftarbangunan);
            if (idxtdl != IDX_UNDEF){
                if (LL_length(inprogresslist)<bagCapacity){
                    if(JENIS_ITEM(TOP(bag)) != 'V'){
                        LL_deleteAt(&todolist, idxtdl, &valpesanan);
                        LL_insertFirst(&inprogresslist, valpesanan);
                        S_push(&bag, valpesanan);
                        if (valpesanan.jenisItem == 'N'){
                            printf("Pesanan berupa Normal Item berhasil diambil!\n");
                        } else if (valpesanan.jenisItem == 'H'){
                            printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                        } else if (valpesanan.jenisItem == 'P'){
                            printf("Pesanan berupa Perishable Item berhasil diambil!\n");
                        } else if (valpesanan.jenisItem == 'V'){
                            printf("Pesanan berupa VIP Item berhasil diambil!\n");
                        }
                        /*if(JENIS_ITEM(valpesanan) == 'H'){
                           AB_reset(&SpeedBoost,true);
                        }*/
                    } /*else{
                        printf("Item VIP sedang dalam proses, tidak dapat mengambil item\n");
                    }*/
                } else {
                    printf("Tidak bisa mengambil pesanan karena tas sudah penuh\n");
                }
            } else {
                printf("Pesanan tidak ditemukan\n");
            }
        } /*else if (isEqual(currentWord, "DROP_OFF")) {
            // TODO : handle kesesuaian lokasi pengiriman
            if (!S_isEmpty(bag) && !LL_isEmpty(inprogresslist)) {
                LL_deleteFirst(&inprogresslist, &valpesanan);
                S_pop(&bag, &valpesanan);
                if (JENIS_ITEM(valpesanan) == 'N') {
                    delSenterPengecilEff(&bag);
                    printf("Pesanan Normal Item berhasil diantarkan\n");
                    printf("Uang yang didapatkan: 200 Yen");
                } else if ((JENIS_ITEM(valpesanan) == 'H') || (JENIS_ITEM(valpesanan) == 'n')) {
                    // Dapet Reward
                    if(!isCarryItem(Heavy)){
                          AB_activate(&SpeedBoost);
                    }*/
                    /*delSenterPengecilEff(&bag);
                    printf("Pesanan Heavy Item berhasil diantarkan\n");
                    printf("Uang yang didapatkan: 400 Yen");
                } else if (JENIS_ITEM(valpesanan) == 'P') {
                    // dapet reward
                    // check perishableitem
                    bagCapacity++; // ability increase Capacity
                    delSenterPengecilEff(&bag);
                    printf("Pesanan Perishable Item berhasil diantarkan\n");
                    printf("Uang yang didapatkan: 400 Yen");
                } else if (JENIS_ITEM(valpesanan) == 'V') {
                    // dapet reward
                    delSenterPengecilEff(&bag);
                    AB_isActive(ReturnToSender) ? AB_stackAbility(ReturnToSender): AB_activate(ReturnToSender);
                    printf("Pesanan VIP Item berhasil diantarkan\n");
                    printf("Uang yang didapatkan: 600 Yen");
                }
            } else {
                printf("Tidak ada pesanan yang sedang diantarkan!\n");
            }
        }*/else if (isEqual(currentWord, "MAP")) {
            Matrix peta;
            M_CreateMatrix(N + 2, M + 2, &peta);
            for (int i = 0; i < ROWS(peta); i++){
                for (int j = 0; j < COLS(peta); j++){
                    boolean starSymbol = (i == 0) || (j == 0);
                    starSymbol = starSymbol || (i == M_getLastIdxRow(peta));
                    starSymbol = starSymbol || (j == M_getLastIdxCol(peta));
                    if (starSymbol){
                        printf("*");
                    }
                    else{
                        int k = 0;
                        while (k < LD_length(daftarbangunan)){
                            boolean xAvail = i == BPOINTX(daftarbangunan, k);
                            boolean yAvail = j == BPOINTY(daftarbangunan, k);
                            if (xAvail && yAvail){
                                // Pengecekan Posisi Mobita
                                boolean posMobita = i == Absis(point_currentPos);
                                posMobita = posMobita && (j == Ordinat(point_currentPos));
                                if (posMobita == true){
                                    print_yellow(BNAME(daftarbangunan, k));
                                }
                                // Pengecekan bangunan lokasi pick up
                                boolean pickupLoc;
                                LL_Address ptr = FIRST(inprogresslist);
                                boolean searching = true;
                                POINT pickUpPoint;
                                int bIdx = 0;
                                while ((searching) && (bIdx < LD_length(daftarbangunan))){
                                    if (BNAME(daftarbangunan, bIdx) == PICK_UP_POINT(INFO(ptr))){
                                        pickUpPoint = BPOINT(daftarbangunan, bIdx);
                                        searching = false;
                                    }
                                    bIdx += 1;
                                }
                                pickupLoc = i == Absis(pickUpPoint);
                                pickupLoc = pickupLoc && (j == Ordinat(pickUpPoint));
                                pickupLoc = pickupLoc && (!posMobita);
                                if (pickupLoc == true){
                                    print_red(PICK_UP_POINT(INFO(ptr)));
                                }
                                // Pengecekan bangunan lokasi drop off
                                boolean dropOffLoc;
                                S_ElType ptrBag = TOP(bag);
                                POINT dropOffPoint;
                                bIdx = 0;
                                searching = true;
                                while ((searching) && (bIdx < LD_length(daftarbangunan))){
                                    if (BNAME(daftarbangunan, bIdx) == PICK_UP_POINT(ptrBag)){
                                        dropOffPoint = BPOINT(daftarbangunan, i);
                                        searching = false;
                                    }
                                    bIdx += 1;
                                }
                                dropOffLoc = i == Absis(dropOffPoint);
                                dropOffLoc = dropOffLoc && (j == Ordinat(dropOffPoint));
                                dropOffLoc = dropOffLoc && (!pickupLoc);
                                if (dropOffLoc == true){
                                    print_blue(PICK_UP_POINT(ptrBag));
                                }

                                // Pengecekan destinasi yang bisa dicapai untuk tampilan peta
                                LD_CreateListDin(&moveable, totalbangunan);
                                // Melihat konfigurasi adjacency Matrix (adj)
                                for(int z = 0; z < COLS(adj); z++){
                                    if (M_ELMT(adj, position, z) == 1){
                                        // Insert to moveable List
                                        LD_insertLast(&moveable, LD_ELMT(daftarbangunan,z));
                                    }
                                }
                                boolean destinasiAvail;
                                int s = 0; // indeks untuk iterasi moveable
                                while (s < LD_length(moveable)){
                                    destinasiAvail = i == BPOINTX(moveable, s);
                                    destinasiAvail = destinasiAvail && (j == BPOINTY(moveable, s));
                                    destinasiAvail = destinasiAvail && (!dropOffLoc);
                                    if (destinasiAvail == true){
                                        print_green(BNAME(moveable, s));
                                    }
                                    s += 1;
                                }
                                if (!destinasiAvail){
                                    printf("%c", BNAME(daftarbangunan, k));
                                }
                            }
                            k += 1;
                        }
                        boolean isHQloc = i == hqX;
                        isHQloc = isHQloc && (j == hqY);
                        if (isHQloc){
                            printf("8");
                        }
                    }
                }
                printf("\n");
            }
        } else if (isEqual(currentWord, "TO_DO")) {
            LL_displayList_ToDo(todolist);
        } else if (isEqual(currentWord, "IN_PROGRESS")) {
            LL_displayList_InProgress(inprogresslist);
        } else if (isEqual(currentWord, "BUY")) {
            buy(inventory, &money);
        } else if (isEqual(currentWord, "INVENTORY")) {
            LS_displayList(inventory);
            printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
            resetWord();
            printf("\nENTER COMMAND: ");
            startWord();

            int idx;
            // Memroses inputan menjadi indeks sebenarnya
            if (!isEqual(currentWord, "0")){
                boolean valid = false;
                if (isEqual(currentWord, "1")){
                    idx = 0;
                    boolean valid = true;
                }
                else if (isEqual(currentWord, "2")){
                    idx = 1;
                    boolean valid = true;
                }
                else if (isEqual(currentWord, "3")){
                    idx = 2;
                    boolean valid = true;
                }
                else if (isEqual(currentWord, "4")){
                    idx = 3;
                    boolean valid = true;
                }
                else if (isEqual(currentWord, "5")){
                    idx = 4;
                    boolean valid = true;
                }
                if (valid == true){
                    char gd = GNAME(inventory, idx);
                    if (gd == 'K'){
                        Stack tempBag; // Membuat stack untuk tempat penampungan item sementara
                        S_CreateStack(&tempBag);

                        boolean foundPerishable = false;
                        S_ElType item; // Variabel untuk menampung item yang dipindahkan
                        while(!foundPerishable){
                            if(JENIS_ITEM(TOP(bag)) != 'P'){
                                foundPerishable = true;
                            }
                            else{
                                S_pop(&bag, &item);
                                S_push(&tempBag, item); // Item dipindahkan ke temporaryBag
                            }
                        }
                        if (foundPerishable == true){
                            // Mengembalikan waktu perishable item.
                            LL_Address ptr = FIRST(perishablelist);
                            while (ptr != NULL){
                                // Semua perishable item sudah disalin ke perishable list
                                // Seharusnya gadget pasti terpakai apabila foundPerishable == true
                                boolean flag = WAKTU_PESANAN(TOP(bag)) == WAKTU_PESANAN(INFO(ptr));
                                flag = flag && (PICK_UP_POINT(TOP(bag)) == PICK_UP_POINT(INFO(ptr)));
                                flag = flag && (DROP_OFF_POINT(TOP(bag)) == DROP_OFF_POINT(INFO(ptr)));
                                if (flag){
                                    PERISH_TIME(TOP(bag)) = PERISH_TIME(INFO(ptr));
                                }
                                else{
                                    ptr = NEXT(ptr);
                                }
                            }
                            LS_deleteElmt(&inventory, idx);
                            printf("Kain Pembungkus Waktu berhasil digunakan!\n");
                        }
                        else{
                            printf("Tidak ada perishable item di tas!\n");
                        }
                        while(S_isEmpty(tempBag) != true){
                            S_pop(&tempBag, &item);
                            S_push(&bag, item);
                        }
                    }
                    if (gd == 'B'){
                        if (bagCapacity <= 100){
                            bagCapacity = bagCapacity * 2;
                            if (bagCapacity > 100){
                                bagCapacity = 100;
                            }
                            LS_deleteElmt(&inventory, idx);
                            printf("Senter Pembesar berhasil digunakan!\n");
                        }
                        else{
                            printf("Kapasitas tas sudah tidak bisa dibesarkan lagi!\n");
                        }
                    }
                    if (gd == 'D'){
                        boolean valid = false;
                        while(!valid){
                            printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
                            resetWord();
                            printf("ENTER COMMAND: ");
                            startWord();
                            if (isEqual(currentWord, "0")){ // Cancel move
                                valid = true;
                                printf("\nMove dibatalkan!");
                            } else {
                                int i = 1;
                                int int_currentWord = atoi(currentWord.contents);
                                while(i <= LD_length(daftarbangunan) && (!isEqualInt(currentWord,i))){
                                    i++;
                                }
                                if(i <= LD_length(daftarbangunan)){
                                    valid = true;
                                    i--;     
                                    // Move
                                    printf("Mobita sekarang berada di titik %c (%d,%d)\n",BNAME(daftarbangunan,i),BPOINTX(daftarbangunan,i),BPOINTY(daftarbangunan,i));

                                    position = LD_indexOf(daftarbangunan, LD_ELMT(daftarbangunan,i));
                                    LS_deleteElmt(&inventory, idx);
                                } else{
                                    printf("\nMasukan tidak sesuai!\n");
                                }
                            }
                        }
                    }
                    if (gd == 'T'){
                        if (time < 50){
                            time = 0;
                        }
                        else{
                            time = time - 50;
                        }
                        LS_deleteElmt(&inventory, idx);
                        printf("Mesin Waktu berhasil digunakan!\n");
                    }
                    if (gd == 'S'){
                        // Menghilangkan efek heavy item
                        Stack tempBag; // Membuat stack untuk tempat penampungan item sementara
                        S_CreateStack(&tempBag);

                        boolean foundHeavy = false;
                        S_ElType item; // Variabel untuk menampung item yang dipindahkan
                        while(!foundHeavy){
                            if(JENIS_ITEM(TOP(bag)) != 'H'){
                                foundHeavy = true;
                            }
                            else{
                                S_pop(&bag, &item);
                                S_push(&tempBag, item); // Item dipindahkan ke temporaryBag
                            }
                        }
                        if (foundHeavy == true){
                            JENIS_ITEM(TOP(bag)) = 'n';
                            LS_deleteElmt(&inventory, idx);
                            printf("Senter Pengecil berhasil digunakan!\n");
                        }
                        else{
                            printf("Tidak ada heavy item di tas!\n");
                        }
                        while(S_isEmpty(tempBag) != true){
                            S_pop(&tempBag, &item);
                            S_push(&bag, item);
                        }
                    }
                }
                else{
                    printf("Nomor tidak dikenali!\n");
                }
            }
        } else if (isEqual(currentWord, "HELP")) {
            help();
        } else if (isEqual(currentWord, "SAVE_GAME")) {
            save();
        } /*else if (isEqual(currentWord, "RETURN")) {
            if(AB_isActive(ReturnToSender)){
                if(!S_isEmpty(bag) && !LL_isEmpty(inprogresslist)){
                    if(JENIS_ITEM(TOP(bag)) != 'V'){
                        LL_deleteFirst(&inprogresslist, &valpesanan);
                        S_pop(&bag, &valpesanan);
                        // TODO : reset durasi persishable, kembalikan item ke lokasi pickup
                        LL_insertLast(&todolist, valpesanan);
                    }
                    else {
                        printf("Ability tidak dapat digunakan untuk item VIP\n");
                    }
                } else {
                    printf("Tidak ada item yang sedang dibawa\n");
                }
                printf("Ability berhasil digunakan\n");
                delSenterPengecilEff(&bag);
                AB_useAbility(&ReturnToSender);
                if (Count(ReturnToSender)==0){
                    AB_reset(&ReturnToSender, false);
                }
            } else {
                printf("Anda tidak memiliki ability ini\n");
            }
        } else {
            printf("Command salah\n");
        }*/
        printf("Waktu: %d\n",time);
        resetWord();
        printf("ENTER COMMAND: ");
        startWord();
        // endgame -> running = false

    }

    printf("\nKELUAR"); // sementara
    return 0;
}
