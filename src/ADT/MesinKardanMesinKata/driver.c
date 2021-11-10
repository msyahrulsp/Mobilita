#include <stdio.h>
#include "wordmachine.h"

int main(){
    printf("ENTER COMMAND: ");
    startWord();
    while(!isEqual(currentWord, "KELUAR")) {
        while(true) {
            printf("COMMAND: ");
            int i = 0;
            while (i < currentWord.length) {
                printf("%c", currentWord.contents[i]);
                i++;
            }
            if(isEqual(currentWord, "TEST123")) printf("\nINI SAMA 1");
            if(isEqual(currentWord, "TEST12")) printf("\nINI SAMA 2");
            printf("\n");
            break;
        }
        toPath();
        printf("%s\n", currentWord.contents);
        resetWord();
        printf("ENTER COMMAND: ");
        startWord();
    }

    FILE *saveFile;

    saveFile = fopen("./save/Test.txt", "w");
    if (saveFile == NULL) {
        printf("404");
        return 0;
    }
    fprintf(saveFile, "1245");
    return 0;
}