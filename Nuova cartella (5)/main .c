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
    float tempoCostante;

    testa = loadFromFile(testa, "piloti.csv", "esiti.csv");


    do{
        printf("1. Calcola e Stampa tempo piloti (somma dei 3 giri)\n");
        /* (tempo giro casuale 57<=t<=62) */
        printf("2. Nuovo Pilota (in testa)\n");
        printf("3. Nuovo Pilota (in coda)\n");
        printf("4. Ricerca e Stampa Nomi Piloti con ALMENO un giro sotto X secondi\n");
        printf("5. Stampa Classifica (ordinata per punteggio)\n");
        printf("0. Esci");
        printf("Scelta: ");
        scanf("%d", &scelta);
        switch(scelta){
             case 1: // calcolo punteggio
               showList(testa);
            break;
        case 2: // Add in testa
           testa = addOnHead(testa);
            showList(testa);
            break;
        case 3: // add in coda
             testa = addOnTail(testa,NULL);
             showList(testa);
            break;
        case 4: //ricerca nomi piloti con giro sotto x secondi
            printf("inserisci il tempo: ");
            scanf("%.2f",&tempoCostante);

            break;
        case 5: //stampa classifica
                ordPerPunteggio(testa);
                showList(testa);
            break;

        }

    }while(scelta != 0);

    /* DEALLOCA LISTA ATLETI */
     freeLista(testa);
    /* ------------- */
    printf("PROGRAMMA TERMINATO...\n");
    return 0;
}
