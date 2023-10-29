#include <stdio.h>
#include <stdlib.h>

void sayilariEkle() {
    int sayi, *liste, boyut = 0, i;
    int tekToplam = 0, ciftToplam = 0;
    
    // Bellekte listeyi olustur
    liste = (int *)malloc(boyut * sizeof(int));

    while (1) {
        printf("Bir sayi girin (-1 cikis icin): ");
        scanf("%d", &sayi);

        if (sayi == -1) {
            break;
        }

        // Sayi tek mi cift mi kontrol eden islem
        if (sayi % 2 != 0) {
            // Tek sayi ise basina ekle
            boyut++;
            liste = (int *)realloc(liste, boyut * sizeof(int));
            for (i = boyut - 1; i > 0; i--) {
                liste[i] = liste[i - 1];
            }
            liste[0] = sayi;
            tekToplam += sayi;
        } else {
            // Cift sayi ise sonuna ekle
            boyut++;
            liste = (int *)realloc(liste, boyut * sizeof(int));
            liste[boyut - 1] = sayi;
            ciftToplam += sayi;
        }
    }

    // Liste elemanlarını yazdıran yer
    printf("Tek Sayilarin Toplami: %d\n", tekToplam);
    printf("Cift Sayilarin Toplami: %d\n", ciftToplam);
    printf("Liste: ");
    for (i = 0; i < boyut; i++) {
        printf("%d ", liste[i]);
    }
    
    
    free(liste);
}

int main() {
    sayilariEkle();
    return 0;
}
