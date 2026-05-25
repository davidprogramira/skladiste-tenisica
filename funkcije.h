#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#include "tenisica.h"

static inline void ispisLinije() {
    printf("----------------------\n");
}

void dodajTenisicu(Tenisica** tenisice, int* n, int* kapacitet);
void ispisTenisica(Tenisica* tenisice, int n);
void urediTenisicu(Tenisica* tenisice, int n);
void obrisiTenisicu(Tenisica** tenisice, int* n);
void pretraziTenisice(Tenisica* tenisice, int n);
void sortirajTenisice(Tenisica* tenisice, int n);

#endif