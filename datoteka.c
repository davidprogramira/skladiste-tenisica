#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "datoteka.h"

void spremiUDatoteku(Tenisica* tenisice, int n) {
    FILE* fp = fopen("skladiste.bin", "wb");
    if (fp == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(tenisice, sizeof(Tenisica), n, fp);
    fclose(fp);
    printf("Podaci uspjesno spremljeni!\n");
}

void ucitajIzDatoteke(Tenisica** tenisice, int* n, int* kapacitet) {
    FILE* fp = fopen("skladiste.bin", "rb");
    if (fp == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }
    fread(n, sizeof(int), 1, fp);
    if (*n > *kapacitet) {
        *kapacitet = *n;
        Tenisica* temp = (Tenisica*)realloc(*tenisice, *kapacitet * sizeof(Tenisica));
        if (temp == NULL) {
            perror("Greska pri alokaciji memorije");
            fclose(fp);
            return;
        }
        *tenisice = temp;
    }
    fread(*tenisice, sizeof(Tenisica), *n, fp);
    fclose(fp);
    printf("Podaci uspjesno ucitani!\n");
}