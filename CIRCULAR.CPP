#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   /* Turbo C ke liye; modern compiler me optional */

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;
int counter = 0;

int isFull() {
    return counter == MAX_SIZE;
}

int isEmpty() {
    return counter == 0;
}

void enqueue() {
    int data;

    if (isFull()) {
        printf("\nQueue is Full");
        return;
    }

    printf("\nEnter an element to add: ");
    scanf("%d", &data);

    if (front == -1) {   /* first insertion */
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = data;
    counter++;

    printf("\n%d is added to queue", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is Empty");
        return;
    }

    printf("\n%d is dequeued", queue[front]);
    counter--;

    if (counter == 0) {   /* queue becomes empty */
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

void display() {
    int i, count;

    if (isEmpty()) {
        printf("\nQueue is Empty");
        return;
    }

    i = front;
    count = 0;

    printf("\nQueue elements:");
    while (count < counter) {
        printf(" %d", queue[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
}

int main() {
    int choice;
    int running = 1;

    while (running) {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            running = 0;   /* loop se bahar */
            break;

        default:
            printf("\nInvalid choice");
        }
    }

    printf("\nExiting program...\n");
    return 0;
}
