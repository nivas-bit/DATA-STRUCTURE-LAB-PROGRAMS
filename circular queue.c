
 #include <stdio.h>
#include <stdlib.h>



void insert(int q[], int *rear, int *count, int item,int Qsize){
    if (*count >= Qsize)
        printf("queue overflow\n");
    else {
        *rear = (*rear + 1) % Qsize;
        q[*rear] = item;
        (*count)++;
    }
}

int delete(int q[], int *front, int *count,int Qsize){
    int deleted_item;
    if (*count == 0) {
        printf("queue underflow\n");
        return -1;
    } else {
        deleted_item = q[*front];
        *front = (*front + 1) % Qsize;
        (*count)--;
        return deleted_item;
    }
}

void display(int q[], int *front, int *count,int Qsize){
    int i, j;
    if (*count == 0) {
        printf("queue underflow\n");
    } else {
        i = *front;
        for (j = 0; j < *count; j++) {
            printf(" %d ", q[i]);
            i = (i + 1) % Qsize;
        }
        printf("\n");
    }
}

int main() {
    int choice, rear = -1, front = 0, deleted_item, count = 0,item;
    int Qsize=3;
    int q[Qsize];

    while (1) {
        printf("\nEnter the choice\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int item;
                printf("Enter the item\n");
                scanf("%d", &item);
                insert(q, &rear, &count, item, Qsize);
                break;
            }
            case 2: {
                deleted_item = delete(q, &front, &count, Qsize);
                printf("The item deleted is %d\n", deleted_item);

                break;
            }
            case 3: {
                display(q, &front, &count, Qsize);
                break;
            }


            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }
    return 0;
}


