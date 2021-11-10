#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

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