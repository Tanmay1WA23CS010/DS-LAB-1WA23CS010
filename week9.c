#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void DeletionOfFirst(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void DeleteSpecified(Node** head, int target) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->data == target) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        Node* temp = *head;
        while (temp->next != NULL && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Target not found\n");
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
    }
}

void Display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicate the end of the list
}

int main() {
    Node* head = NULL;

    // Creating nodes and adding them to the list
    head = CreateNode(10);
    head->next = CreateNode(20);
    head->next->next = CreateNode(30);

    // Display the list
    printf("Initial list: ");
    Display(head);

    // Deleting the first node
    DeletionOfFirst(&head);
    printf("After deleting the first node: ");
    Display(head);

    // Deleting a specified node
    DeleteSpecified(&head, 20);
    printf("After deleting node with value 20: ");
    Display(head);

    // Attempt to delete a non-existent node
    DeleteSpecified(&head, 40);

    // Final state of the list
    printf("Final list: ");
    Display(head);

    // Cleanup remaining nodes
    while (head != NULL) {
        DeletionOfFirst(&head);
    }

    return 0;
}
