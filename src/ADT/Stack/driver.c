#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;
    // Pesanan pesanan;

    S_CreateStack(&stack);

    if(S_isEmpty(stack)) {
        printf("Stack kosong\n");
    }

    if(S_isFull(stack)) {
        printf("Stack full\n");
    }

    // S_push(&stack, 1) // S_ElType == Pesanan
    // S_pop(&stack, &pesanan)

    printf("%d\n", S_length(stack));
    return 0;
}