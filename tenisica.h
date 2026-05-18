#ifndef TENISICA_H
#define TENISICA_H

typedef struct {
    int id;
    char brend[50];
    char model[50];
    float velicina;
    float cijena;
    int kolicina;
} Tenisica;

typedef enum {
    IZLAZ = 0,
    DODAJ = 1,
    ISPIS = 2,
    UREDI = 3,
    OBRISI = 4,
    PRETRAZI = 5,
    SORTIRAJ = 6,
    SPREMI = 7,
    UCITAJ = 8
} OpcijaProg;

#endif