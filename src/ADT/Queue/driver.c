#include <stdio.h>
#include "queue.h"

int main() {
    Queue queue;

    Q_CreateQueue(&queue);

    if(Q_isEmpty(queue)) {
        printf("Queue kosong\n");
    }

    if(Q_isFull(queue)) {
        printf("Qeueu penuh\n");
    }
    
    // enqueue(&queue, pesanan); Pesanan dianggap ada
    // dequeue(&queue, &pesanan); Pesanan dianggap valid

    printf("%d\n", Q_length(queue));
    return 0;
}