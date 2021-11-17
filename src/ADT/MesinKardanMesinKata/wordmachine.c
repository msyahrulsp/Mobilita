#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;
Scn Scanner;

static int retval;

void startScan() {
    advFile();
    while (currentChar == BLANK) advFile();
    endWord = (currentChar == MARK);
    if (!endWord) advScan(); // ini udah bener
}

void advScan() {
    while (currentChar == BLANK || currentChar == MARK) advFile();
    getScan();
}

void getScan() {
    int temp, num = 0;
    if (((int)currentChar >= 65 && (int)currentChar <= 90) || (int)currentChar == 110) {
        Scanner.let = currentChar;
        Scanner.num = 0;
        advFile();
    } else {
        while ((currentChar != BLANK) && (currentChar != MARK)) {
            switch (currentChar) {
                case '0':
                    temp = 0;
                    break;
                case '1':
                    temp = 1;
                    break;
                case '2':
                    temp = 2;
                    break;
                case '3':
                    temp = 3;
                    break;
                case '4':
                    temp = 4;
                    break;
                case '5':
                    temp = 5;
                    break;
                case '6':
                    temp = 6;
                    break;
                case '7':
                    temp = 7;
                    break;
                case '8':
                    temp = 8;
                    break;
                case '9':
                    temp = 9;
                    break;
            }
            num = (num * 10) + temp;
            advFile();
        }
        Scanner.num = num;
        Scanner.let = ' ';
    }
}

void ignoreBlank() {
    while (currentChar == BLANK) adv();
}

void startWord() {
    start();
    ignoreBlank();
    endWord = (currentChar == MARK);
    if (!endWord) advWord();
}

void advWord() {
    ignoreBlank();
    if (currentChar == MARK && !endWord) {
        endWord = true;
    } else {
        copyWord();
    }
}

void copyWord() {
    int i = 0;
    while ((currentChar != MARK) && (i != CAPACITY)) {
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    currentWord.length = (i < CAPACITY) ? i : CAPACITY;
}

void resetWord() {
    int i;
    for(i = 0; i < currentWord.length; i++) {
        currentWord.contents[i] = BLANK;
    } 
    currentWord.length = 0;
    currentChar = BLANK;
}

boolean isEqual(Word input, char command[]) {
    int i, len;

    for (i = 0; command[i] != '\0'; ++i);
    len = i;

    if (input.length != len) return false;
    for (i = 0; i < len; i++) {
        if (input.contents[i] != command[i]) return false;
    }

    return true;
}

// boolean isEqualInt(Word input, int number) {
//     char str[10];
	
//     number = atoi(input);
//     sprintf(str,"&d",number);
	
//     return isEqual(input,str);
// }

void toPath() {
    int i;
    for (i = currentWord.length - 1; i >= 0; i--) {
        currentWord.contents[i+7] = currentWord.contents[i];
    }

    currentWord.contents[0] = '.';
    currentWord.contents[1] = '/';
    currentWord.contents[2] = 's';
    currentWord.contents[3] = 'a';
    currentWord.contents[4] = 'v';
    currentWord.contents[5] = 'e';
    currentWord.contents[6] = '/';

    currentWord.length += 7;
}