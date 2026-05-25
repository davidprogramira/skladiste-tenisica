#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include "tenisica.h"
#include "funkcije.h"
#include "datoteka.h"

extern int brojOperacija;

int main() {
    int izbor;
    int n = 0;
    int kapacitet = 10;
    Tenisica* tenisice = (Tenisica*)malloc(kapacitet * sizeof(Tenisica));

    if (tenisice == NULL) {
        perror("Greska pri alokaciji memorije");
        return 1;
    }

    do {
        printf("\n SKLADISTE TENISICA \n");
        printf("1. Dodaj tenisicu\n");
        printf("2. Ispis svih tenisica\n");
        printf("3. Uredi tenisicu\n");
        printf("4. Obrisi tenisicu\n");
        printf("5. Pretrazi tenisice\n");
        printf("6. Sortiraj tenisice\n");
        printf("7. Spremi u datoteku\n");
        printf("8. Ucitaj iz datoteke\n");
        printf("0. Izlaz\n");
        printf("Odabir: ");
        scanf("%d", &izbor);

        switch ((OpcijaProg)izbor) {
        case DODAJ:    dodajTenisicu(&tenisice, &n, &kapacitet);    break;
        case ISPIS:    ispisTenisica(tenisice, n);                  break;
        case UREDI:    urediTenisicu(tenisice, n);                  break;
        case OBRISI:   obrisiTenisicu(&tenisice, &n);               break;
        case PRETRAZI: pretraziTenisice(tenisice, n);               break;
        case SORTIRAJ: sortirajTenisice(tenisice, n);               break;
        case SPREMI:   spremiUDatoteku(tenisice, n);                break;
        case UCITAJ:   ucitajIzDatoteke(&tenisice, &n, &kapacitet); break;
        case IZLAZ:    printf("Izlaz...\n");                        break;
        default:       printf("Nepostojeca opcija!\n");
        }
    } while (izbor != 0);

    printf("Ukupno izvrsenih operacija: %d\n", brojOperacija);
    free(tenisice);
    tenisice = NULL;
    return 0;
}