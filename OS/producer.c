#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 10

int mutex = 1;
int full = 0;
int empty = BUF_SIZE;
int buf[BUF_SIZE];
int in = 0, out = 0;

void producer() {
    --mutex;
    if (full < BUF_SIZE) {
        int item;
        printf("Enter the item to produce: ");
        scanf("%d", &item);
        
        buf[in] = item;
        in = (in + 1) % BUF_SIZE;
        
        ++full;
        --empty;
        printf("Produced item %d\n", item);
    } else {
        printf("Buffer is full!\n");
    }
    ++mutex;
}

void consumer() {
    --mutex;
    if (full > 0) {
        int item = buf[out];
        out = (out + 1) % BUF_SIZE;
        
        --full;
        ++empty;
        printf("Consumed item %d\n", item);
    } else {
        printf("Buffer is empty!\n");
    }
    ++mutex;
}

int main() {
    int choice;
    
    printf("\n1. Press 1 for Producer");
    printf("\n2. Press 2 for Consumer");
    printf("\n3. Press 3 for Exit");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (mutex == 1) {
                    producer();
                } else {
                    printf("Mutex not available!\n");
                }
                break;
                
            case 2:
                if (mutex == 1) {
                    consumer();
                } else {
                    printf("Mutex not available!\n");
                }
                break;
                
            case 3:
                exit(0);
                break;
                
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    
    return 0;
}
