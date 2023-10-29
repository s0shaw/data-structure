#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// data yapisi tanimlama
struct Ogrenci {
    int numara;
    char ad[50];
    int yas;
    struct Ogrenci* sonraki;
};

// listenin bas pointeri
struct Ogrenci* bas = NULL;

// Ogrenci ekleme fonksiyonu
void basaOgrenciEkle(int numara, char ad[50], int yas) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->numara = numara;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->yas = yas;
    yeniOgrenci->sonraki = bas;
    bas = yeniOgrenci;
}

// Ogrenci bilgilerini yazdiran fonksiyon
void ogrenciBilgileriniYazdir() {
    struct Ogrenci* temp = bas;
    int sayac = 1;

    printf("Ogrenci Bilgileri:\n");

    while (temp != NULL) {
        printf("%d- %s %d %d\n", sayac, temp->ad, temp->yas, temp->numara);
        temp = temp->sonraki;
        sayac++;
    }
}

// Ogrenci arama fonksiyonu
void ismeGoreAra(char arananAd[50]) {
    struct Ogrenci* temp = bas;
    int bulundu = 0;
    int sayac = 1;

    while (temp != NULL) {
        if (strcmp(temp->ad, arananAd) == 0) {
            printf("%d- %s %d %d\n", sayac, temp->ad, temp->yas, temp->numara);
            bulundu = 1;
            break;
        }
        temp = temp->sonraki;
        sayac++;
    }

    if (!bulundu) {
        printf("Ogrenci bulunamadi.\n");
    }
}

// Ogrenci silen fonksisyon
void isimSil(char arananAd[50]) {
    struct Ogrenci* temp = bas;
    int bulundu = 0;

    while (temp != NULL) {
        if (strcmp(temp->ad, arananAd) == 0 && temp->sonraki != NULL) {
            struct Ogrenci* silinecek = temp->sonraki;
            temp->sonraki = temp->sonraki->sonraki;
            free(silinecek);
            bulundu = 1;
            printf("Ogrenci silindi.\n");
            break;
        }
        temp = temp->sonraki;
    }

    if (!bulundu) {
        printf("Ogrenci bulunamadi veya listenin son elemani.\n");
    }
}

// En uzun ismi yazan fonksiyon.
void enUzunIsim() {
    struct Ogrenci* temp = bas;
    int maxUzunluk = 0;
    char enUzunIsim[50];

    while (temp != NULL) {
        int uzunluk = strlen(temp->ad);
        if (uzunluk > maxUzunluk) {
            maxUzunluk = uzunluk;
            strcpy(enUzunIsim, temp->ad);
        }
        temp = temp->sonraki;
    }

    printf("Listenin en uzun ismi: %s\n", enUzunIsim);
    printf("Uzunluk: %d\n", maxUzunluk);
}

int main() {
    int secim, numara, yas;
    char ad[50];

    while (1) {
        printf("\nOgrenci Yonetim Sistemi\n");
        printf("1- Ogrenci Ekle\n");
        printf("2- Tum Ogrenci Bilgilerini Goruntule ve Say\n");
        printf("3- Ogrenci Ara\n");
        printf("4- Ogrenci Sil\n");
        printf("5- En Uzun Ismi Bul\n");
        printf("6- Cikis\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Ogrenci numarasi girin: ");
                scanf("%d", &numara);
                printf("Ogrenci adini girin: ");
                scanf("%s", ad);
                printf("Ogrenci yasini girin: ");
                scanf("%d", &yas);
                basaOgrenciEkle(numara, ad, yas);
                break;
            case 2:
                ogrenciBilgileriniYazdir();
                break;
            case 3:
                printf("Aranan ogrenci adini girin: ");
                scanf("%s", ad);
                ismeGoreAra(ad);
                break;
            case 4:
                printf("Silinecek ogrenci adini girin: ");
                scanf("%s", ad);
                isimSil(ad);
                break;
            case 5:
                enUzunIsim();
                break;
            case 6:
                printf("Programdan cikiliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    }

    return 0;
}
