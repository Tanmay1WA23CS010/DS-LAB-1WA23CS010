#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int isfull(int rear) {
    return rear == SIZE - 1; // Check if the queue is full
}

int isempty(int front, int rear) {
    return front > rear; // Check if the queue is empty
}

void insert(int item, int *queue, int *rear) {
    if (isfull(*rear)) {
        printf("OVERFLOW !!\n");
        return;
    } else {
        (*rear)++;
        queue[*rear] = item;
        printf("%d inserted successfully\n", item);
    }
}

int delete(int *queue, int *front, int *rear) {
    if (isempty(*front, *rear)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[(*front)++];
}

void display(int *queue, int front, int rear) {
    if (isempty(front, rear)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, f = 0, r = -1, item;
    int q[SIZE];
    while (1) {
        printf("1: Insert  2: Delete  3: Display    Any other key: exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to insert:\n");
                scanf("%d", &item);
                insert(item, q, &r);
                break;

            case 2:
                item = delete(q, &f, &r);
                if (item == -1) {
                    // Already handled in delete function
                } else {
                    printf("%d deleted successfully\n", item);
                }
                break;

            case 3:
                display(q, f, r);
                break;

            default:
                exit(0);
                break;
        }
    }
    return 0;
}
