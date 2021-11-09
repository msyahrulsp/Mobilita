#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "LinkedList\list_linked.h"
#include "ListDinamis\listdin.h"
#include "ListStatis\listStatik.h"
#include "Matriks\matrix.h"
#include "MesinKardanMesinKata\wordmachine.h"
#include "PColor\pcolor.h"
#include "Queue\queue.h"
#include "Stack\stack.h"
#include "ListDinamis\Point\point.h"
#include "Pesanan\Pesanan.h"

// Butuh tipe data Game > Buat load + save ( Ini nampung semua data )

int main(){

    int time;
    POINT currentPos;
    LL_List todolist;
    LL_List inprogresslist;
    ListDin daftarbangunan;
    Pesanan order, valpesanan;
    Stack bag;
    int idxtdl;
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

    if (isEqual(currentWord, "NEW_GAME")) {
        // load default konfigurasi
    } else {
        // load game
    }

    printf("\nSELAMAT BERMAIN!!\n\n");
    resetWord();
    printf("ENTER COMMAND: ");
    startWord();

    while (!isEqual(currentWord, "EXIT")) {
        if (isEqual(currentWord, "MOVE")) {
            // move
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
            
        } else if (isEqual(currentWord, "TO_DO")) {
            LL_displayList_ToDo(todolist);
        } else if (isEqual(currentWord, "IN_PROGRESS")) {
            LL_displayList_InProgress(inprogresslist);
        } else if (isEqual(currentWord, "BUY")) {
            
        } else if (isEqual(currentWord, "INVENTORY")) {
            
        } else if (isEqual(currentWord, "HELP")) {
            
        } else if (isEqual(currentWord, "SAVE_GAME")) {
            
        } else if (isEqual(currentWord, "RETURN")) {
            
        } else {
            printf("Command salah\n");
        }
        resetWord();
        printf("ENTER COMMAND: ");
        startWord();
        // endgame -> running = false

    }

    printf("\nKELUAR"); // sementara
    return 0;
}
