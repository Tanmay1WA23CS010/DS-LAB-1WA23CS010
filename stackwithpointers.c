//ALL VARIABLE ARE PASSED BY REFERNCES AS ASKED BY THE FACULTY

#include <stdio.h>

#define MAX 10

int isfull(int top) {
    return top == MAX - 1;
}

int isempty(int top) {
    return top == -1;
}
// PUSH FUNCTION
void push(int (*arr)[MAX], int *top, int item) {
    if (!isfull(*top)) {
        (*arr)[(*top)++] = item;
        printf("Item %d added successfully!\n", item);
    } else {
        printf("STACK IS FULL / OVERFLOW\n");
    }
}
//POP FUNCTION
void pop(int (*arr)[MAX], int *top) {
    if (!isempty(*top)) {
        printf("Item %d has been removed\n", (*arr)[--(*top)]);
    } else {
        printf("STACK IS EMPTY / UNDERFLOW\n");
    }
}
// DISPLAY FUNCTION
void display(int (*arr)[MAX], int top) {
    for (int i = 0; i < top; i++) {
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX];
    int top = -1;

    push(&arr, &top, 1);
    push(&arr, &top, 2);
    push(&arr, &top, 3);
    push(&arr, &top, 4);

    display(&arr, top + 1);

    pop(&arr, &top);
    display(&arr, top + 1);

    return 0;
}
