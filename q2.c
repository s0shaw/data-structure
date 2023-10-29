#include <stdio.h>
#include <stdlib.h>

// Bağlı liste düğüm yapısı
struct Node {
    int data;
    struct Node* next;
};

// Yeni düğüm oluşturma fonksiyonu
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Bağlı listeye eleman ekleme fonksiyonu
void ekle(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

// Bağlı listeyi büyükten küçüğe sıralama fonksiyonu
void sirala(struct Node** head) {
    struct Node* current = *head;
    struct Node* index = NULL;
    int temp;

    if (*head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data < index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// Bağlı listeyi yazdırma fonksiyonu
void yazdir(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Bağlı listeye 100 rastgele sayı ekleme
    for (int i = 0; i < 100; i++) {
        ekle(&head, rand() % 1000); // 0 ile 999 arasında rastgele sayılar eklenir
    }

    printf("Rastgele Sayilar:\n");
    yazdir(head);

    // Bağlı listeyi sıralama
    sirala(&head);

    printf("Siralama (Buyukten Kucuge):\n");
    yazdir(head);

    return 0;
}
