#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Create
//nesta função temos que *vet é um ponteiro para ponteiro pois o vetor original já em um ponteiro, pois é vetor dinâmico
 Conta* createAccount(Conta* vet, Conta new_account, unsigned int* tam, unsigned int* id) {
    new_account.id = *id;
    Conta* new_vet = (Conta*) malloc ((*tam + 1) * sizeof(Conta));
    for (int i = 0; i < *tam; i++) new_vet[i] = vet[i]; 
    
    if (new_vet == NULL) {
        // Verifica se a realocação falhou
        printf("Erro ao realocar memória para o vetor de contas.\n");
        return vet;
    }

    new_vet[*tam] = new_account;

    (*tam)++; //aumentando o tam principal;
    (*id)++;
    free(vet);
    return new_vet;
}

// Read 
// A função retorna o INDICE onde o determinado elemento está
int getAccountIndex(Conta* vet, unsigned int id, unsigned int tam){
    for (int i = 0; i < tam; i++){
        if (vet[i].id == id) return i;
    }

    return -1;
}
//retorna 1 ou 0, se foi encontrado ou não.
int searchAccount(Conta* vet, unsigned int id, unsigned int tam) {
    for (int i = 0; i < tam; i++){
        if (vet[i].id == id) return 1;
    }
    
    return 0;
}

// Update
void deposit(Conta* vet, unsigned int index, double amount) {
    vet[index].saldo += amount;
}

void withdraw(Conta* vet, unsigned int tam_required, double amount) {
    vet[tam_required].saldo -= amount;
}

// Delete
Conta* deleteAccount(Conta* vet, unsigned int id, unsigned int* tam){
    unsigned int k = 0;
    Conta* new_vet = (Conta*) malloc ((*tam - 1) * sizeof(Conta));
    for (int i = 0; i < *tam; i++){ 
        if (vet[i].id != id) new_vet[k++] =  vet[i];
    } 

    free(vet);
    (*tam)--;

    return new_vet;
}

void describeAccount(Conta account){
    printf("id: %u\n", account.id);
    printf("proprietario: %s\n", account.n_proprietario);
    printf("saldo: %.2lf\n", account.saldo);
    printf("tipo: %c\n", account.tipo);
}


