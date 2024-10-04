#include <stdio.h>

#define MAX 10

int arr[MAX];
int top = -1;

int is_full(){
    return top == MAX - 1;
}

int is_empty(){
    return top == -1;
}

void push(int item){
    if (!is_full()){
        arr[++top] = item;
    }else{
        printf("Stack is full\n");
    }
}

void pop(){
    if (!is_empty()){
        int item = arr[top--];
        printf("Popped item is %d\n", item);
    }else{
        printf("Stack is empty\n");
    }
}

void display(){
    for (int i=0;i<=top;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(10);
    push(20);
    push(10);
    push(20);
    push(10);
    push(20);
    
    pop();
    display();

    return 0;
}