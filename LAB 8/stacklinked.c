#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head; // insert at beginning
    head = newNode;
    printf("Pushed %d\n", value);
}

void pop() {
    if (head == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Popped %d\n", temp->data);
    free(temp);
}

void enqueue(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) { // empty queue
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued %d\n", value);
}

void dequeue() {
    if (head == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Dequeued %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Enqueue\n4.Dequeue\n5.Display\n6.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: printf("Enter value: "); scanf("%d", &value); push(value); break;
        case 2: pop(); break;
        case 3: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
        case 4: dequeue(); break;
        case 5: display(); break;
        case 6: exit(0);
        default: printf("Invalid choice\n");
        }
    }
}
