#include "listalib.h"

/*
float genFloat(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;  // [0, 1.0]
    return min + scale * ( max - min );       // [min, max]
}
*/
int main()
{
    int scelta;
    Atleta *testa = NULL; // Puntatore al primo nodo

    testa = loadFromFile(testa, "piloti.csv", "esiti.csv");
    showList(testa);

    do{
        printf("MENU'\n");
        printf("1. Calcola e Stampa Punteggio Atleti (somma dei 3 giri)\n");
        /* (tempo giro casuale 57<=t<=62) */
        printf("2. Nuovo Pilota (in testa)\n");
        printf("3. Nuovo Pilota (in coda)\n");
        printf("4. Ricerca e Stampa Nomi Atleti con ALMENO un giro sotto X secondi\n");
        printf("5. Stampa Classifica (ordinata per punteggio)\n");
        printf("0. Esci");
        printf("Scelta: ");
        scanf("%d", &scelta);
    }while(scelta != 0);

    /* DEALLOCA LISTA ATLETI */
    /* Codice qui */
    /* ------------- */
    printf("PROGRAMMA TERMINATO...\n");
    return 0;
}
