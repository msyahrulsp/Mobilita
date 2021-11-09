#include <stdio.h>
#include "loadsave.h"

void load() {
    FILE *loadFile;
    int a;

    loadFile = fopen("./save/Test.txt", "r");

    fscanf(loadFile, "%d", &a);
    printf("%d", a);
}

void save() {
    FILE *saveFile;

    saveFile = fopen("./save/Test.txt", "w");
    fprintf(saveFile, "1 2\n5");
}