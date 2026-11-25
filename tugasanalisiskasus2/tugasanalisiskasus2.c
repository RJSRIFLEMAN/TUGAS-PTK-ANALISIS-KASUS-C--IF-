
#include <stdio.h>

int main() {
    int pilihan;
    long long rupiah, jumlahUtuh, sisaValuta;
    long long lembar1000 = 0;
    long long lembar100 = 0;
    long long lembar50 = 0;
    long long lembar10 = 0;
    long long nilaiDiterima = 0;

    double kurs, jumlahValuta, kembalian;

    printf("=== PROGRAM MONEY CHANGER ===\n");
    printf("1. Yen (JPY)\n");
    printf("2. US Dollar (USD)\n");
    printf("3. Yuan (CNY)\n");

    printf("Pilih mata uang (1-3): ");
    scanf("%d", &pilihan);

    printf("Masukkan jumlah uang Rupiah: Rp");
    scanf("%lld", &rupiah);

    printf("Masukkan kurs mata uang: Rp");
    scanf("%lf", &kurs);

    if (rupiah <= 0 || kurs <= 0) {
        printf("Jumlah uang atau kurs tidak valid!\n");
        return 0;
    }

    jumlahValuta = rupiah / kurs;
    jumlahUtuh = (long long)jumlahValuta;
    sisaValuta = jumlahUtuh;

    if (pilihan == 1) {

        // Pecahan Yen 1000
        lembar1000 = sisaValuta / 1000;

        nilaiDiterima = lembar1000 * 1000;
    }

    else if (pilihan == 2) {

        // Pecahan USD 50 didahulukan
        if (sisaValuta >= 50) {
            lembar50 = 1;
            sisaValuta = sisaValuta - 50;
        }

        // Pecahan USD 100
        if (sisaValuta >= 100) {
            lembar100 = sisaValuta / 100;
            sisaValuta = sisaValuta % 100;
        }

        // Pecahan USD 50
        if (sisaValuta >= 50) {
            lembar50 = lembar50 + (sisaValuta / 50);
            sisaValuta = sisaValuta % 50;
        }

        // Pecahan USD 10
        if (sisaValuta >= 10) {
            lembar10 = sisaValuta / 10;
            sisaValuta = sisaValuta % 10;
        }

        nilaiDiterima = (lembar100 * 100)
                      + (lembar50 * 50)
                      + (lembar10 * 10);
    }

    else if (pilihan == 3) {

        // Pecahan Yuan 100
        if (sisaValuta >= 100) {
            lembar100 = sisaValuta / 100;
            sisaValuta = sisaValuta % 100;
        }

        // Pecahan Yuan 10
        if (sisaValuta >= 10) {
            lembar10 = sisaValuta / 10;
            sisaValuta = sisaValuta % 10;
        }

        nilaiDiterima = (lembar100 * 100)
                      + (lembar10 * 10);
    }

    else {
        printf("Pilihan mata uang tidak valid!\n");
        return 0;
    }

    kembalian = rupiah - (nilaiDiterima * kurs);

    printf("\n=== HASIL PENUKARAN ===\n");

    if (pilihan == 1) {
        printf("Mata Uang : Yen (JPY)\n");
        printf("Lembar 1000 Yen : %lld lembar\n", lembar1000);
    }

    else if (pilihan == 2) {
        printf("Mata Uang : US Dollar (USD)\n");
        printf("Lembar 100 USD : %lld lembar\n", lembar100);
        printf("Lembar 50 USD  : %lld lembar\n", lembar50);
        printf("Lembar 10 USD  : %lld lembar\n", lembar10);
    }

    else if (pilihan == 3) {
        printf("Mata Uang : Yuan (CNY)\n");
        printf("Lembar 100 Yuan : %lld lembar\n", lembar100);
        printf("Lembar 10 Yuan  : %lld lembar\n", lembar10);
    }

    printf("Jumlah Valuta : %.3f\n", jumlahValuta);
    printf("Uang Diterima : %lld\n", nilaiDiterima);
    printf("Kembalian     : Rp%.0f\n", kembalian);

    return 0;
}
