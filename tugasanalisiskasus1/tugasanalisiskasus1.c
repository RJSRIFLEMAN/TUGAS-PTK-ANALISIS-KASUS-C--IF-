
#include <stdio.h>

int main() {
    int tujuan, tempat;
    int hargaTiket, hargaMenginap, totalHarga;
    char *namaTujuan;
    char *namaTempat;

    printf("=== PROGRAM PAKET WISATA ===\n");
    printf("1. Gunung\n");
    printf("2. Pantai\n");
    printf("3. Taman Hiburan\n");

    printf("Pilih tujuan wisata (1-3): ");
    scanf("%d", &tujuan);

    if (tujuan == 1) {
        namaTujuan = "Gunung";
        hargaTiket = 50000;
        namaTempat = "Penginapan";
        hargaMenginap = 200000;
    }
    else if (tujuan == 2) {
        namaTujuan = "Pantai";
        hargaTiket = 40000;
        namaTempat = "Penginapan";
        hargaMenginap = 200000;
    }
    else if (tujuan == 3) {
        namaTujuan = "Taman Hiburan";
        hargaTiket = 80000;

        printf("\nPilih tempat menginap:\n");
        printf("1. Hotel\n");
        printf("2. Penginapan\n");
        printf("Pilihan: ");
        scanf("%d", &tempat);

        if (tempat == 1) {
            namaTempat = "Hotel";
            hargaMenginap = 500000;
        }
        else if (tempat == 2) {
            namaTempat = "Penginapan";
            hargaMenginap = 250000;
        }
        else {
            printf("Pilihan tempat menginap tidak valid!\n");
            return 0;
        }
    }
    else {
        printf("Pilihan tujuan wisata tidak valid!\n");
        return 0;
    }

    totalHarga = hargaTiket + hargaMenginap;

    printf("\n=== HASIL PEMESANAN ===\n");
    printf("Tujuan Wisata    : %s\n", namaTujuan);
    printf("Tempat Menginap  : %s\n", namaTempat);
    printf("Harga Tiket      : Rp%d\n", hargaTiket);
    printf("Harga Menginap   : Rp%d\n", hargaMenginap);
    printf("Total Harga      : Rp%d\n", totalHarga);

    return 0;
}
