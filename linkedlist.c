#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* CreateNew(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Correct allocation
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void AddBeginning(Node** head, int value) {
    Node* newNode = CreateNew(value);
    newNode->next = *head;
    *head = newNode;
}

void AddEnd(Node** head, int value) {
    Node* newNode = CreateNew(value);
    if (*head == NULL) { // For no element
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode; // Add new node at the end
}

void AddAny(Node** head, int value, int targetpos) {
    Node* newNode = CreateNew(value);
    if (targetpos == 0) { // At the beginning
        AddBeginning(head, value);
        return;
    }

    Node* current = *head;
    int i = 0; // Initialize i to 0
    while (current != NULL && i < targetpos - 1) {
        current = current->next;
        i++;
    }

    if (current != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {

        printf("Position out of bounds\n");
        free(newNode);
    }
}


void Display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main() {
    Node* head = NULL;

    AddBeginning(&head, 10);
    AddEnd(&head, 20);
    AddEnd(&head, 30);
    AddAny(&head, 11, 1);



    Display(head);



    return 0;
}
