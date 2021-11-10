#include <stdio.h>
#include "loadsave.h"

void load() {
    FILE *loadFile;

    resetWord();
    printf("Masukkan nama save file permainan: ");
    startWord();
    toPath();
    loadFile = fopen(currentWord.contents, "r");

    while(loadFile == NULL) {
        printf("File save tersebut tidak ada!\n");
        resetWord();
        printf("Masukkan nama save file permainan: ");
        startWord();
        toPath();
        loadFile = fopen(currentWord.contents, "r");
    }
    
}

void save() {
    FILE *saveFile;

    resetWord();
    printf("Masukkan nama save file permainan: ");
    startWord();
    toPath();
    saveFile = fopen(currentWord.contents, "w");

    fprintf(saveFile, "1 2\n5");
}