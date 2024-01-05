#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct MinHeap {
    int arr[MAX_HEAP_SIZE];
    int size;
};


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void minHeapify(struct MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->arr[left] < minHeap->arr[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->arr[right] < minHeap->arr[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->arr[idx], &minHeap->arr[smallest]);
        minHeapify(minHeap, smallest);
    }
}


void insert(struct MinHeap *minHeap, int key) {
    if (minHeap->size == MAX_HEAP_SIZE) {
        printf("Heap is full, cannot insert\n");
        return;
    }

    
    minHeap->arr[minHeap->size] = key;
    int i = minHeap->size;
    minHeap->size++;

    while (i > 0 && minHeap->arr[(i - 1) / 2] > minHeap->arr[i]) {
        swap(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMin(struct MinHeap *minHeap) {
    if (minHeap->size <= 0) {
        printf("Heap is empty, cannot delete\n");
        return -1;
    }


    int root = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;


    minHeapify(minHeap, 0);

    return root;
}

void display(struct MinHeap *minHeap) {
    printf("Min Heap: ");
    for (int i = 0; i < minHeap->size; i++) {
        printf("%d ", minHeap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MinHeap minHeap = {{}, 0};
    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Delete Min\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(&minHeap, key);
                break;
            case 2:
                printf("Minimum element deleted: %d\n", deleteMin(&minHeap));
                break;
            case 3:
                display(&minHeap);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }


}
