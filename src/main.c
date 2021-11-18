#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int endGame(int position) {
    if (NOrder(data) == 0 && LL_isEmpty(ToDo(data)) && LL_isEmpty(IPL(data)) && S_isEmpty(Tas(data))) {
        if (position != 0) return 1;
        return 2;
    }
    return 0;
}

void printMobilita() {
    printf("%s  __  __  ___  ___ ___ _    ___ _____ _   \n", CYAN);
    printf(" |  \\/  |/ _ \\| _ )_ _| |  |_ _|_   _/_\\  \n");
    printf(" | |\\/| | (_) | _ \\| || |__ | |  | |/ _ \\ \n");
    printf(" |_|  |_|\\___/|___/___|____|___| |_/_/ \\_\\\n");
    printf("                                          %s\n", NORMAL);
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
    printf("\n%sENTER COMMAND%s: ", BLUE, NORMAL);
    startWord();

    while (!(isEqual(currentWord, "0") || isEqual(currentWord, "1") || isEqual(currentWord, "2") || isEqual(currentWord, "3") || isEqual(currentWord, "4") || isEqual(currentWord, "5"))) {
        printf("Silahkan pilih sesuai opsi!");
        resetWord();
        printf("\n%sENTER COMMAND%s: ", BLUE, NORMAL);
        startWord();
    }

    if(isEqual(currentWord, "1")){
        if(*money >= 800){
            Gadget gd;
            gd.gadgetname = 'K';
            gd.gadgetprice = 800;
            added = LS_insertGadget(inventory, gd, 0);
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
    } else if(isEqual(currentWord, "2")){
        if(*money >= 1200){
            Gadget gd;
            gd.gadgetname = 'B';
            gd.gadgetprice = 1200;
            added = LS_insertGadget(inventory, gd, 1);
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
    }  else if(isEqual(currentWord, "3")){
        if(*money >= 1500){
            Gadget gd;
            gd.gadgetname = 'D';
            gd.gadgetprice = 1500;
            added = LS_insertGadget(inventory, gd, 2);
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
    else if(isEqual(currentWord, "4")){
        if(*money >= 3000){
            Gadget gd;
            gd.gadgetname = 'T';
            gd.gadgetprice = 3000;
            added = LS_insertGadget(inventory, gd, 3);
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
    } else if(isEqual(currentWord, "5")){
        if(*money >= 800){
            Gadget gd;
            gd.gadgetname = 'S';
            gd.gadgetprice = 800;
            added = LS_insertGadget(inventory, gd, 4);
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
    } else {
        printf("Buy dibatalkan!\n");
    }
}

void printStat(int position) {
    printf("\n%s----- Stat -----\t\t----- Ability -----%s\n", BLUE, NORMAL);
    printf("Waktu: %s%d\t\t\t%s", CYAN, Time(data), NORMAL);
    printf("Speed Boost: "); 
    if (AB_isActive(Speed(data))) { 
        printf("%sActive%s ", GREEN, NORMAL);
        printf("(%d Move Left)\n", Count(Speed(data)));
    } else { 
        printf("%sNot Active%s\n", RED, NORMAL);
    }
    printf("Uang: %s%d%s Yen\t\t\t", CYAN, Money(data), NORMAL);
    printf("Return To Sender: ");
    if (AB_isActive(RTS(data))) { 
        printf("%sActive%s ", GREEN, NORMAL);
        printf("(%d Return Left)\n", Count(RTS(data)));
    } else { 
        printf("%sNot Active%s\n", RED, NORMAL);
    }
    printf("Posisi: %sTitik %c%s (%s%d%s,%s%d%s)\t\t", YELLOW, BuiNAME(data, position), NORMAL, CYAN, PosX(data), NORMAL, CYAN, PosY(data), NORMAL);
    printf("Tas (Max|Current): (%s%d%s|%s%d%s)\n", CYAN, MTas(data), NORMAL, CYAN, NTas(data), NORMAL);
}

void delSenterPengecilEff(){
    Stack tempBag; // Membuat stack untuk tempat penampungan item sementara
    S_CreateStack(&tempBag);

    S_ElType item; // Variabel untuk menampung item yang dipindahkan
    while(!S_isEmpty(Tas(data))){
        if(JENIS_ITEM(TOP(Tas(data))) == 'n'){
            JENIS_ITEM(TOP(Tas(data))) = 'H';
        }
        else{
            S_pop(&Tas(data), &item);
            S_push(&tempBag, item); // Item dipindahkan ke temporaryBag
        }
    }

    while(!S_isEmpty(tempBag)){
        S_pop(&tempBag, &item);
        S_push(&Tas(data), item);
    }

    LL_Address p = FIRST(IPL(data));
    if (p != NULL) {
        while(p != NULL) {
            if (JENIS_ITEM(INFO(p)) == 'n') {
                JENIS_ITEM(INFO(p)) = 'H';
            }
            p = NEXT(p);
        }
    }
}


/*==================================================================*/
int main(){
	// KAMUS
    // Semua var dari hasil load dah diubah ke macro

    int idxtdl, idxipl, timeadd, disap;
    int position; 
    Building dumpBuilding;
    POINT point_currentPos; // holder ?
    ListDin moveable;
    Pesanan order, valpesanan; // holder
    Matrix map;

    // main menu
    printMobilita();
    printf(">>> Main Menu <<<\n");
    printf("%sENTER COMMAND%s: ", BLUE, NORMAL);
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
            printf("%sENTER COMMAND%s: ", BLUE, NORMAL);
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
    // LL_CreateList(&perishablelist);
    LD_CreateListDin(&moveable, NBuild(data));
    M_ContructorMap(Building(data), &map, Map(data).rowEff, Map(data).colEff);

    printf("\n======= SELAMAT BERMAIN =======\n");

    while (!isEqual(currentWord, "EXIT") && endGame(position) != 2) {
        printStat(position);
        if (endGame(position) == 1) printf("\nPesan: %sKembali ke HQ!%s\n", GREEN, NORMAL);
        resetWord();
        printf("\n%sENTER COMMAND%s: ", BLUE, NORMAL);
        startWord();

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
                printf("%sENTER COMMAND%s: ", BLUE, NORMAL);
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
                        if(AB_isActive(Speed(data))) {
							AB_useAbility(&Speed(data));
                            if ((Count(Speed(data)) % 2)==0){
								Time(data)++;
                                disap = 0;
                                LL_disapPerishable(&IPL(data), Time(data), 1, &disap);
                                S_disapPerishable(&Tas(data), Time(data), 1);
                                NIPL(data) -= disap;
                                NTas(data) -= disap;
							}
							if (Count(Speed(data)) == 0){
								AB_reset(&Speed(data), true);
							}
                        } else {
                            timeadd = 1 + heavy_InProgress(IPL(data));
                            Time(data) = Time(data) + timeadd;
                            disap = 0;
                            LL_disapPerishable(&IPL(data), Time(data), timeadd, &disap);
                            S_disapPerishable(&Tas(data), Time(data), timeadd);
                            NIPL(data) -= disap;
                            NTas(data) -= disap;
                        }
                        // Daftar Pesanan -> To Do List
                        if (!Q_isEmpty(Order(data))) {
                            while (!Q_isEmpty(Order(data)) && HEAD(Order(data)).waktuPesanan <= Time(data)){
                                Q_dequeue(&Order(data), &order);
                                LL_insertLast(&ToDo(data), order);
                                NToDo(data)++;
                                NOrder(data)--;
                            }
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
                    if (JENIS_ITEM(TOP(Tas(data))) != 'V') {
                        LL_deleteAt(&ToDo(data), idxtdl, &valpesanan);
                        NToDo(data)--;
                        LL_insertFirst(&IPL(data), valpesanan);
                        S_push(&Tas(data), valpesanan);
                        NIPL(data) += 1;
                        NTas(data) += 1;
                        if (valpesanan.jenisItem == 'N'){
                            printf("Pesanan berupa Normal Item berhasil diambil!\n");
                        } else if (valpesanan.jenisItem == 'H'){
                            printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                        } else if (valpesanan.jenisItem == 'P'){
                            printf("Pesanan berupa Perishable Item berhasil diambil!\n");
                        }else if (valpesanan.jenisItem == 'V'){
                            printf("Pesanan berupa VIP Item berhasil diambil!\n");
                        }
                        if(JENIS_ITEM(valpesanan) == 'H'){
                            AB_reset(&Speed(data),true);
                        }
                        printf("Tujuan Pesanan: %c\n", valpesanan.dropOffPoint);
                    } else {
                        printf("Terdapat VIP Item di Tas! Tidak bisa mengambil pesanan\n");
                    }
                } else {
                    printf("Tidak bisa mengambil pesanan karena tas sudah penuh\n");
                }
            } else {
                printf("Pesanan tidak ditemukan\n");
            }
        } else if (isEqual(currentWord, "DROP_OFF")) {
            point_currentPos = BPOINT(Building(data), position);
            idxipl = LL_dropOffAvailable(IPL(data), point_currentPos, Building(data));
            if (idxipl != IDX_UNDEF){
                LL_deleteFirst(&IPL(data), &valpesanan);
                S_pop(&Tas(data), &valpesanan);
                NIPL(data) -= 1;
                NTas(data) -= 1;
                if (JENIS_ITEM(valpesanan) == 'N') {
                    printf("Pesanan Normal Item berhasil diantarkan\n");
                    Money(data) += 200;
                    printf("Uang yang didapatkan: 200 Yen\n");
                } else if (JENIS_ITEM(valpesanan) == 'H' || JENIS_ITEM(valpesanan) == 'n') {
                    if(heavy_InProgress(IPL(data))==0){
                        AB_activate(&Speed(data));
                    } else {
                        AB_reset(&Speed(data), true);
                    }
                    printf("Pesanan Heavy Item berhasil diantarkan\n");
                    Money(data) += 400;
                    printf("Uang yang didapatkan: 400 Yen\n");
                } else if (JENIS_ITEM(valpesanan) == 'P') {
                    if (MTas(data) != 100) {
                        MTas(data)++;
                    }
                    printf("Pesanan Perishable Item berhasil diantarkan\n");
                    Money(data) += 400;
                    printf("Uang yang didapatkan: 400 Yen\n");
                } else if (JENIS_ITEM(valpesanan) == 'V') {
                    AB_isActive(RTS(data)) ? AB_stackAbility(&RTS(data)) : AB_activate(&RTS(data)); 
                    printf("Pesanan VIP Item berhasil diantarkan\n");
                    Money(data) += 600;
                    printf("Uang yang didapatkan: 600 Yen\n");
                }
                delSenterPengecilEff();
                NDrop(data)++;
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
            if (position == 0){
                buy(&Invent(data), &Money(data));
            } else {
                printf("Pembelian gadget hanya dapat dilakukan di Headquarters!\n");
            }
        } else if (isEqual(currentWord, "INVENTORY")) {
            LS_displayList(Invent(data));
            printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
            resetWord();
            printf("\n%sENTER COMMAND%s: ", BLUE, NORMAL);
            startWord();

            while (!(isEqual(currentWord, "0") || isEqual(currentWord, "1") || isEqual(currentWord, "2") || isEqual(currentWord, "3") || isEqual(currentWord, "4") || isEqual(currentWord, "5"))) {
                printf("Silahkan pilih sesuai opsi!");
                resetWord();
                printf("\n%sENTER COMMAND%s: ", BLUE, NORMAL);
                startWord();
            }

            int idx;
            // Memroses inputan menjadi indeks sebenarnya
            int temp = atoi(currentWord.contents);

            if (!isEqual(currentWord, "0")) {
                idx = temp - 1;
                
                char gd = GNAME(Invent(data), idx);
                if (gd == 'K'){ // Kain Pembungkus Waktu
                    boolean foundPerishable = false;
                    S_ElType item; // Variabel untuk menampung item yang dipindahkan

                    // Cek Item paling atas Tas
                    if(JENIS_ITEM(TOP(Tas(data))) == 'P'){
                        foundPerishable = true;
                    }

                    if (foundPerishable){
                        // Mengembalikan waktu perishable item.
                        TIMER(TOP(Tas(data))) = DURATION(TOP(Tas(data)));
                        LL_Address ptr = FIRST(IPL(data));
                        TIMER(INFO(ptr)) = DURATION(INFO(ptr));
                        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
                    } else {
                        printf("Kain Pembungkus Waktu gagal digunakan! (Wasted)\n");
                    }
                    LS_deleteElmt(&Invent(data), idx);
                }
                if (gd == 'B'){ // Senter Pembesar
                    if (MTas(data) < 100){
                        MTas(data) = MTas(data) * 2;
                        if (MTas(data) > 100){
                            MTas(data) = 100;
                        }
                        printf("Senter Pembesar berhasil digunakan!\n");
                    } else {
                        printf("Senter Pembesar gagal digunakan! (Wasted)\n");
                    }
                    LS_deleteElmt(&Invent(data), idx);
                }
                if (gd == 'D'){ // Pintu Kemana Saja
                    boolean valid = false;
                    while(!valid){
                        printf("Posisi yang bisa dicapai:\n");
                        for(int i = 0; i < LD_length(Building(data)); i++){
                            if (BNAME(Building(data),i)=='8'){
                                printf("%d. HQ (%d,%d)\n",(i+1),BPOINTX(Building(data),i),BPOINTY(Building(data),i));
                            } else {
                                printf("%d. %c (%d,%d)\n",(i+1),BNAME(Building(data),i),BPOINTX(Building(data),i),BPOINTY(Building(data),i));
                            }
                        }
                        printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n\n");
                        resetWord();
                        printf("%sENTER COMMAND%s: ", BLUE, NORMAL);
                        startWord();
                        int int_currentWord = atoi(currentWord.contents);
                        if (int_currentWord == 0) {
                            if (!isEqual(currentWord, "0")) {
                                int_currentWord = -1;
                            }
                        }
                        // printf("%d", int_currentWord);
                        while (!(int_currentWord >= 0 && int_currentWord <= NBuild(data))) {
                            printf("Silahkan pilih sesuai opsi!\n");
                            resetWord();
                            printf("%sENTER COMMAND%s: ", BLUE, NORMAL);
                            startWord();
                            int_currentWord = atoi(currentWord.contents);
                            if (int_currentWord == 0) {
                                if (!isEqual(currentWord, "0")) {
                                    int_currentWord = -1;
                                }
                            }
                            // printf("%d", int_currentWord);
                        }
                        
                        if (int_currentWord == 0){ // Cancel move
                            valid = true;
                            printf("\nMove dibatalkan!\n");
                        } else {
                            int i = 1;

                            while(i <= NBuild(data) && (int_currentWord != i)){
                                i++;
                            }

                            valid = true;
                            i--;     
                            // Move
                            printf("Mobita sekarang berada di titik %c (%d,%d)\n",BNAME(Building(data),i),BPOINTX(Building(data),i),BPOINTY(Building(data),i));

                            position = LD_indexOf(Building(data), LD_ELMT(Building(data),i));
                            PosX(data) = BPOINTX(Building(data), position);
                            PosY(data) = BPOINTY(Building(data), position);
                            LS_deleteElmt(&Invent(data), idx);
                        }
                    }
                }
                if (gd == 'T'){ // Mesin Waktu
                    if (Time(data) < 50){
                        Time(data) = 0;
                    }
                    else{
                        Time(data) = Time(data) - 50;
                    }
                    LS_deleteElmt(&Invent(data), idx);
                    printf("Mesin Waktu berhasil digunakan!\n");
                }
                if (gd == 'S'){ // Senter Pengecil
                    // Menghilangkan efek heavy item
                    boolean foundHeavy = false;
                    S_ElType item; // Variabel untuk menampung item yang dipindahkan

                    // Senter Pengecil cuman work buat Heavy Item
                    // yang ada di top tas
                    if(JENIS_ITEM(TOP(Tas(data))) == 'H'){
                        foundHeavy = true;
                    }
                    
                    if (foundHeavy){
                        JENIS_ITEM(TOP(Tas(data))) = 'n';
                        LL_Address pheavy = FIRST(IPL(data));
                        JENIS_ITEM(INFO(pheavy)) = 'n';
                        printf("Senter Pengecil berhasil digunakan!\n");
                    } else {
                        printf("Senter Pengecil gagal digunakan! (Wasted)\n");
                    }
                    LS_deleteElmt(&Invent(data), idx);
                }
                if (gd == 'U') {
                    printf("Kamu tidak punya Gadget di slot tersebut!\n");
                }
            } else {
                printf("Inventory dibatalkan!\n");
            }
        } else if (isEqual(currentWord, "HELP")) {
            help(1);
        } else if (isEqual(currentWord, "SAVE_GAME")) {
            save();
        } else if (isEqual(currentWord, "RETURN")) {
            if(AB_isActive(RTS(data))){
                if(!S_isEmpty(Tas(data)) && !LL_isEmpty(IPL(data))){
                    if(JENIS_ITEM(TOP(Tas(data))) != 'V'){
                        LL_deleteFirst(&IPL(data), &valpesanan);
                        S_pop(&Tas(data), &valpesanan);
                        NIPL(data)--;
                        NTas(data)--;

                        // reset timer
                        if (valpesanan.jenisItem == 'P') valpesanan.timer = valpesanan.duration;

                        LL_insertLast(&ToDo(data), valpesanan);
                        NToDo(data)++;

                        // Cek jenis item
                        if (valpesanan.jenisItem == 'N') {
                            printf("Normal Item");
                        } else if (valpesanan.jenisItem == 'H' || valpesanan.jenisItem == 'n') {
                            printf("Heavy Item");
                            if (valpesanan.jenisItem == 'n') printf(" (Kecil)");
                        } else if (valpesanan.jenisItem == 'P') {
                            printf("Perishable Item");
                        }
                        printf(" berhasil dikembalikan ke Pick Up Point %c\n", valpesanan.pickUpPoint);

                        delSenterPengecilEff();
                        AB_useAbility(&RTS(data));
                        if (RTS(data).count == 0){
                            AB_reset(&RTS(data), false);
                        }
                    }
                    else {
                        printf("Ability Return To Sender tidak dapat digunakan untuk VIP Item\n");
                    }
                } else {
                    printf("Tidak ada item yang sedang dibawa\n");
                }
            } else {
                printf("Mobita tidak memiliki Ability Return To Sender\n");
            }
        } else if (isEqual(currentWord, "EXIT")) {
            // DO NOTHING
        } else {
            printf("Command salah!\n");
            printf("Silahkan cek HELP untuk melihat list command\n");
        }
    }

    if (isEqual(currentWord, "EXIT")) {
        printf("\n======= THANKS FOR PLAYING =======\n");
    } else if (endGame(position) == 2) {
        printf("\n----- CONGRATS!! You've finished the game! -----");
        printf("%s\n\n========= STAT =========\n%s", BLUE, NORMAL);
        printf("Sisa uang >> %s%d%s Yen\n", CYAN, Money(data), NORMAL);
        printf("Banyak item yang diantar >> %s%d%s Item\n", CYAN, NDrop(data), NORMAL);
        printf("Waktu yang dilampaui >> %s%d%s\n", CYAN, Time(data), NORMAL);
    }
    return 0;
}