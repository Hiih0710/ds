#include <stdio.h>
#include <stdlib.h>
#include <conio.h>      /* Turbo C ke liye; modern compiler me optional */

struct node {
    int data;
    struct node* next;
};

int value() {
    int val;
    printf("\nEnter the value you want to insert: ");
    scanf("%d", &val);
    return val;
}

/* Add at beginning */
void addatbegining(struct node **q) {
    struct node* newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }
    newnode->data = value();
    newnode->next = *q;
    *q = newnode;
}

/* Add at end */
void addattheend(struct node** q) {
    struct node* newnode;
    struct node* r;

    newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }

    newnode->data = value();
    newnode->next = NULL;

    if (*q == NULL) {
        *q = newnode;
    } else {
        r = *q;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = newnode;
    }
}

/* Display list */
void display(struct node *q) {
    if (q == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nLinked List:\n");
    while (q != NULL) {
        printf("%d\n", q->data);
        q = q->next;
    }
}

/* Delete at beginning */
void deleteatbeginning(struct node** q) {
    struct node* temp;

    if (*q == NULL) {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }

    temp = *q;
    *q = (*q)->next;
    printf("\nDeleted element: %d\n", temp->data);
    free(temp);
}

/* Delete at end */
void deleteattheend(struct node** q) {
    struct node* temp;
    struct node* prev;

    if (*q == NULL) {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }

    temp = *q;
    prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        /* Only one node in list */
        *q = NULL;
    } else {
        prev->next = NULL;
    }

    printf("\nDeleted element: %d\n", temp->data);
    free(temp);
}

/* Delete specific value */
void deletevalue(struct node** q) {
    struct node* temp;
    struct node* prev;
    int val;

    if (*q == NULL) {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }

    printf("\nEnter the value to delete: ");
    scanf("%d", &val);

    temp = *q;
    prev = NULL;

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nValue %d not found in the list.\n", val);
        return;
    }

    if (prev == NULL) {
        /* Deleting the first node */
        *q = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("\nDeleted element: %d\n", temp->data);
    free(temp);
}

int main() {
    int choice;
    int running = 1;
    struct node* p = NULL;

    while (running) {
        printf("\nEnter your choice:\n");
        printf("1: Display\n2: Add at beginning\n3: Add at the end\n");
        printf("4: Delete at beginning\n5: Delete at end\n6: Delete specific value\n7: Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            display(p);
            break;
        case 2:
            addatbegining(&p);
            break;
        case 3:
            addattheend(&p);
            break;
        case 4:
            deleteatbeginning(&p);
            break;
        case 5:
            deleteattheend(&p);
            break;
        case 6:
            deletevalue(&p);
            break;
        case 7:
            running = 0;   /* loop se bahar */
            break;
        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }

    printf("\nExiting program...\n");
    return 0;
}
