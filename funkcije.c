#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcije.h"
#include "tenisica.h"

int brojOperacija = 0;

void dodajTenisicu(Tenisica** tenisice, int* n, int* kapacitet) {
    if (*n >= *kapacitet) {
        *kapacitet *= 2;
        Tenisica* temp = (Tenisica*)realloc(*tenisice, *kapacitet * sizeof(Tenisica));
        if (temp == NULL) {
            perror("Greska pri realokaciji memorije");
            return;
        }
        *tenisice = temp;
    }
    Tenisica t;
    t.id = *n + 1;
    printf("Brend: ");
    scanf("%49s", t.brend);
    printf("Model: ");
    scanf("%49s", t.model);
    printf("Velicina: ");
    scanf("%f", &t.velicina);
    printf("Cijena: ");
    scanf("%f", &t.cijena);
    printf("Kolicina: ");
    scanf("%d", &t.kolicina);
    (*tenisice)[*n] = t;
    (*n)++;
    brojOperacija++;
    printf("Tenisica uspjesno dodana!\n");
}

void ispisTenisica(Tenisica* tenisice, int n) {
    if (n == 0) {
        printf("Skladiste je prazno!\n");
        return;
    }
    printf("\n--- POPIS TENISICA ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", tenisice[i].id);
        printf("Brend: %s\n", tenisice[i].brend);
        printf("Model: %s\n", tenisice[i].model);
        printf("Velicina: %.1f\n", tenisice[i].velicina);
        printf("Cijena: %.2f\n", tenisice[i].cijena);
        printf("Kolicina: %d\n", tenisice[i].kolicina);
        ispisLinije();
    }
}

void urediTenisicu(Tenisica* tenisice, int n) {
    if (n == 0) {
        printf("Skladiste je prazno!\n");
        return;
    }
    int id;
    printf("Unesite ID tenisice koju zelite urediti: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (tenisice[i].id == id) {
            printf("Novi brend: ");
            scanf("%49s", tenisice[i].brend);
            printf("Novi model: ");
            scanf("%49s", tenisice[i].model);
            printf("Nova velicina: ");
            scanf("%f", &tenisice[i].velicina);
            printf("Nova cijena: ");
            scanf("%f", &tenisice[i].cijena);
            printf("Nova kolicina: ");
            scanf("%d", &tenisice[i].kolicina);
            brojOperacija++;
            printf("Tenisica uspjesno uredena!\n");
            return;
        }
    }
    printf("Tenisica s ID-om %d nije pronadena!\n", id);
}

void obrisiTenisicu(Tenisica** tenisice, int* n) {
    if (*n == 0) {
        printf("Skladiste je prazno!\n");
        return;
    }
    int id;
    printf("Unesite ID tenisice koju zelite obrisati: ");
    scanf("%d", &id);
    for (int i = 0; i < *n; i++) {
        if ((*tenisice)[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                (*tenisice)[j] = (*tenisice)[j + 1];
            }
            (*n)--;
            brojOperacija++;
            printf("Tenisica uspjesno obrisana!\n");
            return;
        }
    }
    printf("Tenisica s ID-om %d nije pronadena!\n", id);
}

void pretraziTenisice(Tenisica* tenisice, int n) {
    if (n == 0) {
        printf("Skladiste je prazno!\n");
        return;
    }
    int izbor;
    printf("\n--- PRETRAGA ---\n");
    printf("1. Po brendu\n");
    printf("2. Po velicini\n");
    printf("3. Po cijeni\n");
    printf("Odabir: ");
    scanf("%d", &izbor);
    char brend[50];
    float velicina, cijena;
    int pronadeno = 0;
    switch (izbor) {
    case 1:
        printf("Unesite brend: ");
        scanf("%49s", brend);
        for (int i = 0; i < n; i++) {
            if (strcmp(tenisice[i].brend, brend) == 0) {
                printf("ID: %d | Brend: %s | Model: %s | Velicina: %.1f | Cijena: %.2f | Kolicina: %d\n",
                    tenisice[i].id, tenisice[i].brend, tenisice[i].model,
                    tenisice[i].velicina, tenisice[i].cijena, tenisice[i].kolicina);
                pronadeno = 1;
            }
        }
        break;
    case 2:
        printf("Unesite velicinu: ");
        scanf("%f", &velicina);
        for (int i = 0; i < n; i++) {
            if (tenisice[i].velicina == velicina) {
                printf("ID: %d | Brend: %s | Model: %s | Velicina: %.1f | Cijena: %.2f | Kolicina: %d\n",
                    tenisice[i].id, tenisice[i].brend, tenisice[i].model,
                    tenisice[i].velicina, tenisice[i].cijena, tenisice[i].kolicina);
                pronadeno = 1;
            }
        }
        break;
    case 3:
        printf("Unesite cijenu: ");
        scanf("%f", &cijena);
        for (int i = 0; i < n; i++) {
            if (tenisice[i].cijena == cijena) {
                printf("ID: %d | Brend: %s | Model: %s | Velicina: %.1f | Cijena: %.2f | Kolicina: %d\n",
                    tenisice[i].id, tenisice[i].brend, tenisice[i].model,
                    tenisice[i].velicina, tenisice[i].cijena, tenisice[i].kolicina);
                pronadeno = 1;
            }
        }
        break;
    default:
        printf("Nepostojeca opcija!\n");
        return;
    }
    if (!pronadeno) {
        printf("Nije pronadena nijedna tenisica!\n");
    }
}

static int usporediBrend(const void* a, const void* b) {
    const Tenisica* ta = (const Tenisica*)a;
    const Tenisica* tb = (const Tenisica*)b;
    return strcmp(ta->brend, tb->brend);
}

static int usporediCijenu(const void* a, const void* b) {
    const Tenisica* ta = (const Tenisica*)a;
    const Tenisica* tb = (const Tenisica*)b;
    if (ta->cijena < tb->cijena) return -1;
    if (ta->cijena > tb->cijena) return 1;
    return 0;
}

static int usporediVelicinu(const void* a, const void* b) {
    const Tenisica* ta = (const Tenisica*)a;
    const Tenisica* tb = (const Tenisica*)b;
    if (ta->velicina < tb->velicina) return -1;
    if (ta->velicina > tb->velicina) return 1;
    return 0;
}

static int usporediKolicinu(const void* a, const void* b) {
    const Tenisica* ta = (const Tenisica*)a;
    const Tenisica* tb = (const Tenisica*)b;
    return ta->kolicina - tb->kolicina;
}

void sortirajTenisice(Tenisica* tenisice, int n) {
    if (n == 0) {
        printf("Skladiste je prazno!\n");
        return;
    }
    int izbor;
    printf("\n--- SORTIRANJE ---\n");
    printf("1. Po brendu\n");
    printf("2. Po cijeni\n");
    printf("3. Po velicini\n");
    printf("4. Po kolicini\n");
    printf("Odabir: ");
    scanf("%d", &izbor);
    switch (izbor) {
    case 1: qsort(tenisice, n, sizeof(Tenisica), usporediBrend);    break;
    case 2: qsort(tenisice, n, sizeof(Tenisica), usporediCijenu);   break;
    case 3: qsort(tenisice, n, sizeof(Tenisica), usporediVelicinu); break;
    case 4: qsort(tenisice, n, sizeof(Tenisica), usporediKolicinu); break;
    default: printf("Nepostojeca opcija!\n"); return;
    }
    printf("Tenisice uspjesno sortirane!\n");
    ispisTenisica(tenisice, n);
}