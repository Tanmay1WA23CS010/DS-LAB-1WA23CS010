#include <stdio.h>

#define MAX 10
int arr[MAX];
int top = -1;

int isfull() {
    if (top == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isempty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push() {
    int ele;
    if (isfull()) {
        printf("stack overflow");
    } else {
        printf("enter what you want to add to the stack: ");
        scanf("%d", &ele);
        ++top;
        arr[top] = ele;
        printf("item added");
    }
}

void pop() {
    if (isempty()) {
        printf("underflow");
    } else {
        printf("the item removed was %d", arr[top]);
        top--;
        printf("item removed");
    }
}

int peek() {
    if (isempty()) {
        printf("STACK EMPTY !!");
    } else {
        return arr[top];
    }
}

void display() {
    if (isempty()) {
        printf("UNDERFLOW, STACK IS EMPTY");
    } else {
        printf("STACK :: \n");
        for (int i = top; i>=0; i--) {
                
            printf("%d ", arr[i]);
            printf("\n");
        }
        
    }
}

int main() {
    while (1) {
        int choice;
        printf("1: push\n");
        printf("2: pop\n");
        printf("3: top element\n");
        printf("4: display the stack\n");
        printf("5: exit from the program\n");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            continue;
        }
        switch (choice) {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: printf("the top element is %d\n", peek());
                    break;
            case 4: display();
                    break;
            case 5: break;
            default: printf("invalid input\n");
                    break;
        }
        if (choice == 5) {
            break;
        }
    }
    return 0;
}
