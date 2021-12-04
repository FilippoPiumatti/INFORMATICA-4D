#ifndef INC_01_NODO_LISTALIB_H
#define INC_01_NODO_LISTALIB_H

#define TRUE 1 /* Per attribuzione var. boolean */
#define FALSE 0 /* Per attribuzione var. boolean */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int bool; /* Per dichiarazione var. boolean */

typedef struct atleta{
    int codice;
    char nome[30];
    float giroA, giroB, giroC;
    float punteggio;
    struct atleta *next;
}Atleta;
Atleta* ricercaPiloti(Atleta *head, float tempoCostante);
Atleta* loadFromFile(Atleta *head, char* file_name_atleti, char* file_name_esiti);
Atleta* addOnHead(Atleta *head); // Add nodo in testa alla lista
Atleta* addOnTail(Atleta *head, Atleta *newSt); // Add nodo in coda alla lista
Atleta* calcolaTempo(Atleta *head);
Atleta* nuovoAtleta();
void showList(Atleta *head);
int contaNodi(Atleta *head);
Atleta* nuovoAtletaDaFile(int cod, char *nome, float giroA, float giroB, float giroC);

void freeLista(Atleta **head);
float genFloat(float min, float max);

Atleta* addOnHead(Atleta *head){
    Atleta *pAtl; // Puntatore al nuovo nodo
    pAtl = nuovoAtleta();
    /* Completa il codice */
    pAtl->punteggio  = pAtl->giroA + pAtl->giroB , pAtl->giroC;
     pAtl->next = head;
    return pAtl;
}



float genFloat(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;  // [0, 1.0]
    return min + scale * ( max - min );       // [min, max]
}
Atleta* addOnTail(Atleta *head, Atleta *newSt){
    Atleta *pLista;
    Atleta *pAtl;
    if (newSt == NULL)
    {
        pAtl = nuovoAtleta();
        pAtl->punteggio  = pAtl->giroA + pAtl->giroB + pAtl->giroC;
    }
    else{
      pAtl = newSt;
    }


    if (head == NULL){
         head = pAtl;
    }
    else{
        pLista = head;
        while(pLista->next != NULL)
            pLista = pLista->next;
        pLista->next = pAtl;
    }
    return head;
}
void showList(Atleta *head){
    Atleta *pLista;

    if (head == NULL)
        printf("Lista Vuota\n");
    else{
        pLista = head;
        printf("Lista Atleti\n");
        printf("\nCodice\t\tgiroA\tgiroB\tgiroC\tPunteggio\t\tNome\n");
        do{
            printf("%d\t\t%.2f\t%.2f\t%.2f\t%.2f\t\t%s\n", pLista->codice, pLista->giroA, pLista->giroB, pLista->giroC,pLista->punteggio, pLista->nome);
            pLista = pLista->next;
        }
        while(pLista != NULL);

    }
}
Atleta* nuovoAtleta(){
    Atleta *pNew;
    int codice;
    float g1 = genFloat(0.0, 200.00),g2 = genFloat(0.0, 200.00),g3=genFloat(0.0, 200.00);
    char cogn[20];
    printf("Nuovo Pilota! ");
    printf("Inserisci Cognome: ");
    scanf("%s", cogn);
    do{
        printf("Inserisci codice identificativo: ");
        scanf("%d", &codice);
    }while(codice < 0);

    pNew = (Atleta*) malloc(sizeof(Atleta)); //alloco spazio per il nuovo pilota

    pNew->giroA = g1;// genero float da 0,0 a 200,00 per ogni giro
    pNew->giroB = g2;
    pNew->giroC = g3;


    pNew->codice = codice;

    strcpy(pNew->nome, cogn);
    pNew->next = NULL;
    return pNew;
}
Atleta* nuovoAtletaDaFile(int cod, char *nome, float giroA, float giroB, float giroC){
    Atleta *pNew;

    pNew = (Atleta*) malloc(sizeof(Atleta));
    pNew->codice = cod;
    strcpy(pNew->nome, nome);
    pNew->giroA = giroA;
    pNew->giroB = giroB;
    pNew->giroC = giroC;
    pNew->punteggio = giroA + giroB + giroC;
    pNew->next = NULL;
    return pNew;
}
int contaNodi(Atleta *head){
    int cont = 0;
    Atleta *p;
    p = head;

    while(p != NULL){
        cont++;
        p = p -> next;
    }

    return cont;
}
Atleta* loadFromFile(Atleta *head, char* file_name_atleti, char* file_name_esiti){
    FILE *fpA, *fpE;
    Atleta *pNew;
    bool trovato;
    char row_file[30+1];
    int cod, codE;
    char codStr[5], codEStr[5], giroAStr[6], giroBStr[6], giroCStr[6];
    char nome[20+1], n[20+1];
    float giroA, giroB, giroC;
    int i=0, j=0;
    fpA = fopen(file_name_atleti, "r"); // Apertura file in modalità read

    if (fpA == NULL && fpE == NULL)
        printf("Apertura files non riuscita\n");
    else{
        while(!feof(fpA)){ // Scorro il file, riga per riga, fino a quando non raggiungo EOF
            fscanf(fpA, "%s %s", codStr, nome);
            strcpy(n, nome); /* Ridondante ma, onde evitare problemi, memorizzo in altro vettore char [n] il nome */
            cod = atoi(codStr);
            trovato = FALSE;
            fpE = fopen(file_name_esiti, "r"); // Apertura file in modalità read
            while((!feof(fpE)) && trovato==FALSE){
                fscanf(fpE, "%s %s %s %s", codEStr, giroAStr, giroBStr, giroCStr);
                codE = atoi(codEStr);
                if (cod == codE)
                    trovato = TRUE;
            }
            fclose(fpE); // Chiusura del file
            if (trovato == TRUE){
                giroA = atof(giroAStr);
                giroB = atof(giroBStr);
                giroC = atof(giroCStr);
                pNew = nuovoAtletaDaFile(cod, n, giroA, giroB, giroC);
                head = addOnTail(head, pNew);
            }
        }
    }
    fclose(fpA); // Chiusura del file
    return head;
}

void freeLista(Atleta **head){
    Atleta *pLista;
    while(*head != NULL){
        pLista = (*head) -> next;
        free(*head);
        *head = pLista;
    }
}

void ordPerPunteggio(Atleta *head){
 Atleta *l1 = NULL; //uso al posto di i e j, puntano di nodi
    Atleta *l2 = NULL;
    int ausCod;
    char ausNome[20+1];
    float ausPunteggio;
    int rifare = 1; //lo portiamo a 1 tutte le volte cha facciamo uno swap
    while(rifare == 1){
        rifare = 0;
        //ciclo per puntare al nodo successivo e ordinarli
        for(l1 = head; l1->next != NULL; l1 = l1->next){
            for(l2 = l1->next; l2 != NULL; l2 = l2->next){
                if(l1->punteggio>l2->punteggio){ //strcmp compara due stringhe, restiutuisce intero, maggiore di 0 stringa1 maggiore di stringa2, se minore di zero discporso opposto, se restitusce 0 le stringhe sono ugualei
                    /*Codice*/
                    ausCod = l1->codice;
                    l1->codice = l2->codice;
                    l2->codice = ausCod;
                    /*Cognome*/
                    strcpy(ausNome, l1->nome); //strcpy copia un astringa e la incolla su un altra
                    strcpy(l1->nome, l2->nome);
                    strcpy(l2->nome,ausNome);
                    /*Media*/
                    ausPunteggio = l1->punteggio;
                    l1->punteggio = l2->punteggio;
                    l2->punteggio = ausPunteggio;
                    rifare = 1;
                }
            }
        }
    }
}
#endif
