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

    resetWord();
    printf("\nENTER COMMAND: ");
    startWord();
    if(isEqual(currentWord, "1")){
        if(*money >= 800){
            Gadget gd;
            gd.gadgetname = 'K';
            gd.gadgetprice = 800;
            LS_insertLast(&inventory, gd);
            *money -= gd.gadgetprice;
            printf("Kain Pembungkus Waktu berhasil dibeli!\n");
            printf("Uang Anda sekarang: %d Yen\n", *money);
            //Kain Pembungkus Waktu berhasil dibeli!
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
            LS_insertLast(&inventory, gd);
            *money -= gd.gadgetprice;
            printf("Senter Pembesar berhasil dibeli!\n");
            printf("Uang Anda sekarang: %d Yen\n", *money);
            //Senter Pembesar berhasil dibeli!
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
            LS_insertLast(&inventory, gd);
            *money -= gd.gadgetprice;
            printf("Pintu Kemana Saja berhasil dibeli!\n");
            printf("Uang Anda sekarang: %d Yen\n", *money);
            //Pintu Kemana Saja berhasil dibeli!
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
            LS_insertLast(&inventory, gd);
            *money -= gd.gadgetprice;
            printf("Mesin Waktu berhasil dibeli!\n");
            printf("Uang Anda sekarang: %d Yen\n", *money);
            //Mesin Waktu berhasil dibeli!
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
            LS_insertLast(&inventory, gd);
            *money -= gd.gadgetprice;
            printf("Senter Pengecil berhasil dibeli!\n");
            printf("Uang Anda sekarang: %d Yen\n", *money);
            //Senter Pengecil berhasil dibeli!
        }
        else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
    else{
        printf("Gadget dengan kode tersebut tidak ada.\n");
    }
}

int main(){

    int time, position;
    int totalbangunan;
    POINT currentPos;
    Matrix adj;
    LL_List todolist;
    LL_List inprogresslist;
    ListDin daftarbangunan;
    ListDin moveable;
    Pesanan order, valpesanan;
    Stack bag;
    int idxtdl;
    int bagCapacity;
    int money;

    ListGadget inventory;
    LS_CreateListGadget(&inventory);
    // kapasitas tas int
    // ability (speed boost , return to sender) list statis boolean

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

    load();
    // Read konfigurasi
    //
    // inisialisasi waktu dan posisi
    time = 0;
    position = 0; // index HQ of daftarbangunan
    bagCapacity = 3; // batasan untuk ukuran tas
	
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
                if(adj[position][j] == 1){
                    // Insert to moveable List
                    LD_insertLast(&moveable, ELMT(daftarbangunan,j);
                }
            }
            // Input
            printf("Posisi yang dapat dicapai:\n");
            for(int i = 0; i < LD_length(moveable); i++){
                printf("%d. %c (%d,%d)\n",(i+1),BNAME(moveable,i),BPOINT(&moveable,i)[0],BPOINT(moveable,i)[1]);
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
                    printf("\nMove dibatalkan!");
                }
                else {
                    int i = 1;
                    while(i <= LD_length(moveable) && (!isEqualInt(currentWord,i)){
                        i++;
                    }
                    if(i <= LD_length(moveable)){
                        valid = true;
                        i--;
                        // Time Handle
                        /*
                        if(isActiveAbility(SpeedBoost)){
                            later
                        }
                        else if(isCarryItem(Heavy){ // TODO in In_Progress
                            int n = TotalItem(Heavy)
                            time += (n+1)
                        }
                        else {
                            (time++);
                        }
                        */
                        // Move
                        printf("Mobita sekarang berada di titik %c (%d,%d)\n",BNAME(moveable,i),BPOINT(moveable,i)[0],BPOINT(moveable,i)[1]);
                        position = LD_indexOf(daftarbangunan, moveable[i]);
                    }
                    else{
                        printf("\nSilahkan pilih sesuai opsi!\n");
                    }
                }
            }
            LD_dealocate(&moveable);
        } else if (isEqual(currentWord, "PICK_UP")) {
            idxtdl = LL_pesananAvailable(todolist, currentPos, daftarbangunan);
            if (idxtdl != IDX_UNDEF){
                LL_deleteAt(&todolist, idxtdl, &valpesanan);
                LL_insertFirst(&inprogresslist, valpesanan);
                push(&bag, valpesanan);
            } else {
                printf("Pesanan tidak ditemukan!");
            }
        } else if (isEqual(currentWord, "DROP_OFF")) {
            
        } else if (isEqual(currentWord, "MAP")) {
            char posisiMobita, lokasiPickUp;
            char lokasiDropOff, destinasiAvail;
            
            
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

            // Memroses inputan menjadi indeks sebenarnya
            int idx = 0; // Sementara saja, yang benernya idx diterima dari mesin kata
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
                    // Waktu perishable asalnya dimana ya?
                    // Saya gatau di mana jadi belum bisa ambil nilai waktu asalnya
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
                // Move ke bangunan mana saja
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
            }
        } else if (isEqual(currentWord, "HELP")) {
            help();
        } else if (isEqual(currentWord, "SAVE_GAME")) {
            save();
        } else if (isEqual(currentWord, "RETURN")) {
            
        } else {
            printf("Command salah\n");
        }
        printf("Waktu: %d\n",time);
        resetWord();
        printf("ENTER COMMAND: ");
        startWord();
        // endgame -> running = false

    }

    printf("\nKELUAR"); // sementara
    return 0;
}