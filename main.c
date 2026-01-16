#include <stdio.h>

// İSİM SOYİSİM: Güven Arda Yılmaz
// ÖĞRENCİ NUMARASI: 2420161021
// BTK AKADEMİ SERTİFİKA BAĞLANTISI: sertifika linkimi bulamadım

void dizi_yazdir(float dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf(" %.2f", dizi[i]);
    }
    printf("\n");
}

void takas(float *ap, float *bp) {
    float gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

// Ders 08: Baloncuk Sıralama - Küçükten Büyüğe
void baloncuk_sirala(float dizi[], int BOYUT) {
    int i, j, takas_oldu;
    for (i = 1; i < BOYUT; i++) {
        takas_oldu = 0;
        for (j = 0; j < BOYUT - 1; j++) {
            if (dizi[j] > dizi[j + 1]) { 
                takas(&dizi[j], &dizi[j + 1]);
                takas_oldu = 1;
            }
        }
        if (takas_oldu == 0) break;
    }
}

// Ders 07: İkili Arama (Binary Search)
int ikili_arama(float dizi[], int n, float aranan) {
    int ilk = 0, son = n - 1, orta;
    while (ilk <= son) {
        orta = (ilk + son) / 2; //
        if (dizi[orta] == aranan) return orta; // SONUÇ = BULUNDU
        else if (aranan > dizi[orta]) ilk = orta + 1; //
        else son = orta - 1; //
    }
    return -1; // SONUÇ = BULUNAMADI
}

int main() {
    // Dizi elemanları güncellendi
    float A[] = {1.75, 1.82, 1.68, 1.94, 1.60, 1.88, 1.70};
    int N = sizeof(A) / sizeof(A[0]);
    float aranan_deger;
    int sonuc;

    baloncuk_sirala(A, N);

    printf("Siralanmis Dizi: ");
    dizi_yazdir(A, N);

    printf("\nAranacak degeri giriniz (Orn: 1.82): ");
    scanf("%f", &aranan_deger);

    sonuc = ikili_arama(A, N, aranan_deger);

    if (sonuc != -1) printf("SONUC = BULUNDU (Indis: %d)\n", sonuc); //
    else printf("SONUC = BULUNAMADI\n"); //

    return 0;
}
