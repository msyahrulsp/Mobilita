#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Butuh tipe data Game > Buat load + save ( Ini nampung semua data )
void printMobilita() {
    printf("  __  __  ___  ___ ___ _    ___ _____ _   \n");
    printf(" |  \\/  |/ _ \\| _ )_ _| |  |_ _|_   _/_\\  \n");
    printf(" | |\\/| | (_) | _ \\| || |__ | |  | |/ _ \\ \n");
    printf(" |_|  |_|\\___/|___/___|____|___| |_/_/ \\_\\\n");
    printf("                                          \n");
}

void help(int type) {
    if (type == 1) {
        printf("\n------- HELP MENU MOBILITA -------\n");
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
        printf("11. RETURN -> Untuk mengembalikan item teratas di tas\n");
    } else {
        printf("\n------- HELP MAIN MENU MOBILITA -------\n");
        printf("1. NEW_GAME -> Untuk memulai game baru\n");
        printf("2. LOAD_GAME -> Untuk memulai game dari game yang telah di save\n\n");
    }
}

void buy(ListGadget *inventory, int *money){
    printf("\nUang Anda sekarang: %d Yen\n", *money);
    printf("Gadget yang tersedia:\n");
    printf("1. Kain Pembungkus Waktu (800 Yen)\n");
    printf("2. Senter Pembesar (1200 Yen)\n");
    printf("3. Pintu Kemana Saja (1500 Yen)\n");
    printf("4. Mesin Waktu (3000 Yen)\n");
    printf("5. Senter Pengecil (800 Yen)\n");
    printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");

    boolean added;
    resetWord();
    printf("\nENTER COMMAND: ");
    startWord();
    int temp = atoi(currentWord.contents);

    while (temp < 0 || temp > 4) {
        printf("Silahkan pilih sesuai opsi!");
        resetWord();
        printf("\nENTER COMMAND: ");
        startWord();
        temp = atoi(currentWord.contents);
    }

    if(temp == 1){
        if(*money >= 800){
            Gadget gd;
            gd.gadgetname = 'K';
            gd.gadgetprice = 800;
            added = LS_insertGadget(inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Kain Pembungkus Waktu berhasil dibeli!
            }
        } else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    } else if(temp == 2){
        if(*money >= 1200){
            Gadget gd;
            gd.gadgetname = 'B';
            gd.gadgetprice = 1200;
            added = LS_insertGadget(inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Senter Pembesar berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Senter Pembesar berhasil dibeli!
            }
        } else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }  else if(temp == 3){
        if(*money >= 1500){
            Gadget gd;
            gd.gadgetname = 'D';
            gd.gadgetprice = 1500;
            added = LS_insertGadget(inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Pintu Kemana Saja berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Pintu Kemana Saja berhasil dibeli!
            }
        } else {
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
    else if(temp == 4){
        if(*money >= 3000){
            Gadget gd;
            gd.gadgetname = 'T';
            gd.gadgetprice = 3000;
            added = LS_insertGadget(inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Mesin Waktu berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Mesin Waktu berhasil dibeli!
            }
        } else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    } else if(temp == 5){
        if(*money >= 800){
            Gadget gd;
            gd.gadgetname = 'S';
            gd.gadgetprice = 800;
            added = LS_insertGadget(inventory, gd);
            if (!added) {
                printf("Inventory kamu sudah penuh!\n");
            } else {
                *money -= gd.gadgetprice;
                printf("Senter Pengecil berhasil dibeli!\n");
                printf("Uang Anda sekarang: %d Yen\n", *money);
                //Senter Pengecil berhasil dibeli!
            }
        } else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
}

void delSenterPengecilEff(Stack *bag){
    Stack tempBag; // Membuat stack untuk tempat penampungan item sementara
    S_CreateStack(&tempBag);

    boolean foundGadgetEff = false;
    S_ElType item; // Variabel untuk menampung item yang dipindahkan
    while(!foundGadgetEff){
        if(JENIS_ITEM(TOP(*bag)) != 'N'){
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
    // Semua var dari hasil load dah diubah ke macro
    // Pos Mobita dah ke load, tapi gk tau var apa yang perlu diubah disini

    int idxtdl, idxipl;
    int position; 
    Building dumpBuilding;
    POINT point_currentPos; // holder ?
    ListDin moveable;
    Pesanan order, valpesanan; // holder
    LL_List perishablelist;
    Ability SpeedBoost, ReturnToSender;
    Matrix map;

    // main menu
    printMobilita();
    printf(">>> Main Menu <<<\n");
    printf("ENTER COMMAND: ");
    startWord();

    while(!isEqual(currentWord, "NEW_GAME") && !isEqual(currentWord, "LOAD_GAME")) {
        if(isEqual(currentWord, "EXIT")) {
            printf("\n======= THANKS FOR PLAYING =======\n");
            exit(0);
        } else {
            if (isEqual(currentWord, "HELP")) {
                help(0);
            } else {
                printf("Command salah!\n");
                printf("Silahkan cek HELP untuk melihat list command\n");
            }
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
    position = LD_point_indexOf(Building(data), Pos(data)); // index HQ of Building(data)
    LL_CreateList(&perishablelist);
    AB_createAbility(&SpeedBoost, true);
    AB_createAbility(&ReturnToSender, false);
    LD_CreateListDin(&moveable, NBuild(data));
    M_ContructorMap(Building(data), &map, Map(data).rowEff, Map(data).colEff);

    // Menyalin perishable item dari to do list
    // Untuk keperluan efek gadget Kain Pembungkus Waktu
    LL_Address perishableptr = FIRST(ToDo(data));
    while (perishableptr != NULL){
        if (JENIS_ITEM(INFO(perishableptr)) == 'P'){
            LL_insertFirst(&perishablelist, INFO(perishableptr));
        }
        perishableptr = NEXT(perishableptr);
    }

    printf("\n======= SELAMAT BERMAIN =======\n\n");
    printf("Waktu: %d\n", Time(data));
    printf("Uang: %d Yen\n", Money(data));
    printf("Posisi: Building %c (%d, %d)\n", BuiNAME(data, position) ,PosX(data), PosY(data));
    resetWord();
    printf("ENTER COMMAND: ");
    startWord();

    while (!isEqual(currentWord, "EXIT")) {
        while (!LD_isEmpty(moveable)) {
            LD_deleteLast(&moveable, &dumpBuilding);
        }
        // Melihat konfigurasi adjacency Matrix (Adj(data))
        for(int j = 0; j < COLS(Adj(data)); j++){
            if (M_ELMT(Adj(data),position,j)==1){
                // Insert to moveable List
                LD_insertLast(&moveable, LD_ELMT(Building(data),j));
            }
        }
        if (isEqual(currentWord, "MOVE")) {
            // Input
            printf("Posisi yang dapat dicapai:\n");
            for(int i = 0; i < LD_length(moveable); i++){
                printf("%d. %c (%d,%d)\n",(i+1),BNAME(moveable,i),BPOINTX(moveable,i),BPOINTY(moveable,i));
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
                        if(AB_isActive(SpeedBoost)){
                            if ((Count(SpeedBoost) % 2)!=0){
								Time(data)++;
							}
							AB_useAbility(&SpeedBoost);
							if (Count(SpeedBoost) == 0){
								AB_deactivate(&SpeedBoost);
							}
                        } else {
                            Time(data) = Time(data) + 1 + heavy_InProgress(IPL(data));
                        }
                        // Handle Perishable item
                        LL_disapPerishable(&IPL(data), Time(data));
                        Stack tempTas;
                        Pesanan tempPesanan;
                        while (S_isEmpty(Tas(data))) {
                            S_pop(&Tas(data), &tempPesanan);
                            if (JENIS_ITEM(tempPesanan) == 'P' && PERISH_TIME(tempPesanan) == Time(data)) {
                                // DO NOTHING
                            } else {
                                S_push(&tempTas, tempPesanan);
                            }
                        }
                        while (S_isEmpty(tempTas)) {
                            S_pop(&tempTas, &tempPesanan);
                            S_push(&Tas(data), tempPesanan);
                        }
                        // Daftar Pesanan -> To Do List
                        while (HEAD(Order(data)).waktuPesanan <= Time(data)){
                            Q_dequeue(&Order(data), &order);
                            LL_insertLast(&ToDo(data), order);
                        }
                        // Move
                        printf("Mobita sekarang berada di titik %c (%d,%d)\n",BNAME(moveable,i),BPOINTX(moveable,i),BPOINTY(moveable,i));
                        position = LD_indexOf(Building(data), LD_ELMT(moveable,i));
                        PosX(data) = BPOINTX(Building(data), position);
                        PosY(data) = BPOINTY(Building(data), position);
                    } else{
                        printf("Silahkan pilih sesuai opsi!\n");
                    }
                }
            }
            // LD_dealocate(&moveable);
        } else if (isEqual(currentWord, "PICK_UP")) {
            point_currentPos = BPOINT(Building(data), position);
            idxtdl = LL_pesananAvailable(ToDo(data), point_currentPos, Building(data));
            if (idxtdl != IDX_UNDEF){
                if (LL_length(IPL(data))<MTas(data)){
                    if(JENIS_ITEM(TOP(Tas(data))) != 'V'){
                        LL_deleteAt(&ToDo(data), idxtdl, &valpesanan);
                        LL_insertFirst(&IPL(data), valpesanan);
                        S_push(&Tas(data), valpesanan);
                        if (valpesanan.jenisItem == 'N'){
                            printf("Pesanan berupa Normal Item berhasil diambil!\n");
                        } else if (valpesanan.jenisItem == 'H'){
                            printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                        } else if (valpesanan.jenisItem == 'P'){
                            printf("Pesanan berupa Perishable Item berhasil diambil!\n");
                        } else if (valpesanan.jenisItem == 'V'){
                            printf("Pesanan berupa VIP Item berhasil diambil!\n");
                        }
                        if(JENIS_ITEM(valpesanan) == 'H'){
                           AB_reset(&SpeedBoost,true);
                        }
                    } else {
                        printf("Item VIP sedang dalam proses, tidak dapat mengambil item\n");
                    }
                } else {
                    printf("Tidak bisa mengambil pesanan karena tas sudah penuh\n");
                }
            } else {
                printf("Pesanan tidak ditemukan\n");
            }
        } else if (isEqual(currentWord, "DROP_OFF")) {
            // TODO : handle kesesuaian lokasi pengiriman
            point_currentPos = BPOINT(Building(data), position);
            idxipl = LL_dropOffAvailable(IPL(data), point_currentPos, Building(data));
            if (idxipl != IDX_UNDEF){
                LL_deleteFirst(&IPL(data), &valpesanan);
                S_pop(&Tas(data), &valpesanan);
                if (JENIS_ITEM(valpesanan) == 'N') {
                    //delSenterPengecilEff(&Tas(data));
                    printf("Pesanan Normal Item berhasil diantarkan\n");
                    Money(data) += 200;
                    printf("Uang yang didapatkan: 200 Yen");
                } else if (JENIS_ITEM(valpesanan) == 'H') {
                    // Dapet Reward
                    if(heavy_InProgress(IPL(data))==0){
                        AB_activate(&SpeedBoost);
                    }
                    //delSenterPengecilEff(&Tas(data));
                    printf("Pesanan Heavy Item berhasil diantarkan\n");
                    Money(data) += 400;
                    printf("Uang yang didapatkan: 400 Yen");
                } else if (JENIS_ITEM(valpesanan) == 'P') {
                    // dapet reward
                    // check perishableitem
                    if (MTas(data) != 100) {
                        MTas(data)++; // ability increase Capacity
                    }
                    // delSenterPengecilEff(&Tas(data));
                    printf("Pesanan Perishable Item berhasil diantarkan\n");
                    Money(data) += 400;
                    printf("Uang yang didapatkan: 400 Yen");
                } /*else if (JENIS_ITEM(valpesanan) == 'V') {
                    // dapet reward
                    // delSenterPengecilEff(&Tas(data));
                    //AB_isActive(ReturnToSender) ? AB_stackAbility(&ReturnToSender): AB_activate(&ReturnToSender);
                    printf("Pesanan VIP Item berhasil diantarkan\n");
                    Money(data) += 600;
                    printf("Uang yang didapatkan: 600 Yen");
                }*/
                // Hapus item drop off dari Order(data)
                NDrop(data)++;
                NOrder(data)--;
            } else {
                printf("Tidak ada pesanan yang bisa diantarkan!\n"); 
            }
        } else if (isEqual(currentWord, "MAP")) {
            M_displayMap(map, position, ToDo(data), IPL(data), Building(data), moveable);
        } else if (isEqual(currentWord, "TO_DO")) {
            LL_displayList_ToDo(ToDo(data));
        } else if (isEqual(currentWord, "IN_PROGRESS")) {
            LL_displayList_InProgress(IPL(data));
        } else if (isEqual(currentWord, "BUY")) {
            buy(&Invent(data), &Money(data));
        } else if (isEqual(currentWord, "INVENTORY")) {
            LS_displayList(Invent(data));
            printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
            resetWord();
            printf("\nENTER COMMAND: ");
            startWord();

            int idx;
            // Memroses inputan menjadi indeks sebenarnya
            int temp = atoi(currentWord.contents);

            while(temp < 0 || temp > 5) {
                printf("Silahkan pilih sesuai opsi!");
                resetWord();
                printf("\nENTER COMMAND: ");
                startWord();
                temp = atoi(currentWord.contents);
            }

            if (temp != 0) {
                idx = temp - 1;
                
                char gd = GNAME(Invent(data), idx);
                if (gd == 'K'){
                    Stack tempBag; // Membuat stack untuk tempat penampungan item sementara
                    S_CreateStack(&tempBag);

                    boolean foundPerishable = false;
                    S_ElType item; // Variabel untuk menampung item yang dipindahkan
                    while(!foundPerishable){
                        if(JENIS_ITEM(TOP(Tas(data))) != 'P'){
                            foundPerishable = true;
                        }
                        else{
                            S_pop(&Tas(data), &item);
                            S_push(&tempBag, item); // Item dipindahkan ke temporaryBag
                        }
                    }
                    if (foundPerishable == true){
                        // Mengembalikan waktu perishable item.
                        LL_Address ptr = FIRST(perishablelist);
                        while (ptr != NULL){
                            // Semua perishable item sudah disalin ke perishable list
                            // Seharusnya gadget pasti terpakai apabila foundPerishable == true
                            boolean flag = WAKTU_PESANAN(TOP(Tas(data))) == WAKTU_PESANAN(INFO(ptr));
                            flag = flag && (PICK_UP_POINT(TOP(Tas(data))) == PICK_UP_POINT(INFO(ptr)));
                            flag = flag && (DROP_OFF_POINT(TOP(Tas(data))) == DROP_OFF_POINT(INFO(ptr)));
                            if (flag){
                                PERISH_TIME(TOP(Tas(data))) = PERISH_TIME(INFO(ptr));
                            }
                            else{
                                ptr = NEXT(ptr);
                            }
                        }
                        LS_deleteElmt(&Invent(data), idx);
                        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
                    }
                    else{
                        printf("Tidak ada perishable item di tas!\n");
                    }
                    while(S_isEmpty(tempBag) != true){
                        S_pop(&tempBag, &item);
                        S_push(&Tas(data), item);
                    }
                }
                if (gd == 'B'){
                    if (MTas(data) <= 100){
                        MTas(data) = MTas(data) * 2;
                        if (MTas(data) > 100){
                            MTas(data) = 100;
                        }
                        LS_deleteElmt(&Invent(data), idx);
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
                        int int_currentWord = atoi(currentWord.contents);
                        if (int_currentWord == 0){ // Cancel move
                            valid = true;
                            printf("\nMove dibatalkan!\n");
                        } else {
                            int i = 1;
                            while(i <= LD_length(Building(data)) && (int_currentWord != i)){
                                i++;
                            }
                            if(i <= LD_length(Building(data))){
                                valid = true;
                                i--;     
                                // Move
                                printf("Mobita sekarang berada di titik %c (%d,%d)\n",BNAME(Building(data),i),BPOINTX(Building(data),i),BPOINTY(Building(data),i));

                                position = LD_indexOf(Building(data), LD_ELMT(Building(data),i));
                                LS_deleteElmt(&Invent(data), idx);
                            } else{
                                printf("\nMasukan tidak sesuai!\n");
                            }
                        }
                    }
                }
                if (gd == 'T'){
                    if (Time(data) < 50){
                        Time(data) = 0;
                    }
                    else{
                        Time(data) = Time(data) - 50;
                    }
                    LS_deleteElmt(&Invent(data), idx);
                    printf("Mesin Waktu berhasil digunakan!\n");
                }
                if (gd == 'S'){
                    // Menghilangkan efek heavy item
                    Stack tempBag; // Membuat stack untuk tempat penampungan item sementara
                    S_CreateStack(&tempBag);

                    boolean foundHeavy = false;
                    S_ElType item; // Variabel untuk menampung item yang dipindahkan
                    while(!foundHeavy){
                        if(JENIS_ITEM(TOP(Tas(data))) != 'H'){
                            foundHeavy = true;
                        }
                        else{
                            S_pop(&Tas(data), &item);
                            S_push(&tempBag, item); // Item dipindahkan ke temporaryBag
                        }
                    }
                    if (foundHeavy == true){
                        JENIS_ITEM(TOP(Tas(data))) = 'n';
                        LS_deleteElmt(&Invent(data), idx);
                        printf("Senter Pengecil berhasil digunakan!\n");
                    }
                    else{
                        printf("Tidak ada heavy item di tas!\n");
                    }
                    while(S_isEmpty(tempBag) != true){
                        S_pop(&tempBag, &item);
                        S_push(&Tas(data), item);
                    }
                }
                if (gd == 'U') {
                    printf("Kamu tidak punya Gadget di slot tersebut!\n");
                }
            }
        } else if (isEqual(currentWord, "HELP")) {
            help(1);
        } else if (isEqual(currentWord, "SAVE_GAME")) {
            save();
        } /*else if (isEqual(currentWord, "RETURN")) {
            if(AB_isActive(ReturnToSender)){
                if(!S_isEmpty(Tas(data)) && !LL_isEmpty(IPL(data))){
                    if(JENIS_ITEM(TOP(Tas(data))) != 'V'){
                        LL_deleteFirst(&IPL(data), &valpesanan);
                        S_pop(&Tas(data), &valpesanan);
                        // TODO : reset durasi persishable, kembalikan item ke lokasi pickup
                        LL_insertLast(&ToDo(data), valpesanan);
                    }
                    else {
                        printf("Ability tidak dapat digunakan untuk item VIP\n");
                    }
                } else {
                    printf("Tidak ada item yang sedang dibawa\n");
                }
                printf("Ability berhasil digunakan\n");
                delSenterPengecilEff(&Tas(data));
                AB_useAbility(&ReturnToSender);
                if (Count(ReturnToSender)==0){
                    AB_reset(&ReturnToSender, false);
                }
            } else {
                printf("Anda tidak memiliki ability ini\n");
            }
        }*/ else {
            printf("Command salah!\n");
        }
        printf("\nWaktu: %d\n", Time(data));
        printf("Uang: %d Yen\n", Money(data));
        printf("Posisi: Building %c (%d, %d)\n", BuiNAME(data, position) ,PosX(data), PosY(data));
        resetWord();
        printf("ENTER COMMAND: ");
        startWord();
        // endgame -> running = false

    }

    printf("\n======= THANKS FOR PLAYING =======\n");
    return 0;
}
