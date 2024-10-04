#include <stdio.h>

#define MAX 10

int arr[MAX];
int *top = &arr[0] - 1;

int is_full(int *top){
    return *top == MAX - 1;
}

int is_empty(int *top){
    return *top == -1;
}

void push(int *top, int *arr, int item){
    if (!is_full(top)){
        arr[++(*top)] = item;
    }else{
        printf("Stack is full\n");
    }
}

void pop(int *top, int *arr){
    if (!is_empty(top)){
        int item = arr[(*top)--];
        printf("Popped item is %d\n", item);
    }else{
        printf("Stack is empty\n");
    }
}

void display(int *top, int *arr){
    for (int i=0;i<=*top;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    push(&top, arr, 10);
    push(&top, arr, 20);
    push(&top, arr, 10);
    push(&top, arr, 20);
    push(&top, arr, 10);
    push(&top, arr, 20);
    push(&top, arr, 10);
    push(&top, arr, 20);
    
    pop(&top, arr);
    display(&top, arr);

    return 0;
}