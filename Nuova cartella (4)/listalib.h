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

Atleta* loadFromFile(Atleta *head, char* file_name_atleti, char* file_name_esiti);
Atleta* addOnHead(Atleta *head); // Add nodo in testa alla lista
Atleta* addOnTail(Atleta *head, Atleta *newSt); // Add nodo in coda alla lista
Atleta* nuovoAtleta();
void showList(Atleta *head);
int contaNodi(Atleta *head);
Atleta* nuovoAtletaDaFile(int cod, char *nome, float giroA, float giroB, float giroC);
void ordPerNome(Atleta *head);
void freeLista(Atleta **head);

Atleta* addOnHead(Atleta *head){
    Atleta *pAtl; // Puntatore al nuovo nodo
    pAtl = nuovoAtleta();
    /* Completa il codice */

    return pAtl;
}
Atleta* addOnTail(Atleta *head, Atleta *newSt){
    Atleta *pLista;
    Atleta *pAtl;
    if (newSt == NULL)
        pAtl = nuovoAtleta();
    else
        pAtl = newSt;

    if (head == NULL)
        head = pAtl;
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
        printf("\nCodice\t\tgiroA\tgiroB\tgiroC\t\tNome\n");
        do{
            printf("%d\t\t%.2f\t%.2f\t%.2f\t\t%s\n", pLista->codice, pLista->giroA, pLista->giroB, pLista->giroC, pLista->nome);
            pLista = pLista->next;
        }
        while(pLista != NULL);
    }
}
Atleta* nuovoAtleta(){
    Atleta *pNew;
    /* Completa il codice */
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
    pNew->punteggio = -1;
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
    char codStr[5], codEStr[5], giroAStr[5], giroBStr[5], giroCStr[5];
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
     /* Completa il codice */
}
#endif
