#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Create
//nesta função temos que *vet é um ponteiro para ponteiro pois o vetor original já em um ponteiro, pois é vetor dinâmico
 Conta* createAccount(Conta* vet, Conta new_account, unsigned int* index, unsigned int* id) {
    new_account.id = *id;
    Conta* new_vet = (Conta*) malloc ((*index + 1) * sizeof(Conta));
    for (int i = 0; i < *index; i++) new_vet[i] = vet[i]; 
    
    if (new_vet == NULL) {
        // Verifica se a realocação falhou
        printf("Erro ao realocar memória para o vetor de contas.\n");
        return vet;
    }

    new_vet[*index] = new_account;

    (*index)++; //aumentando o index principal;
    (*id)++;
    free(vet);
    return new_vet;
}

// Read 
// A função retorna o INDICE onde o determinado elemento está
int getAccount(Conta* vet, unsigned int id, unsigned int index){
    for (int i = 0; i < index; i++){
      //  printf("estamos no index: %u. Estamos no id: %u\n", i, index);
        if (vet[i].id == id) return i;
    }
     //   printf("passou do for\n");
    return -1;
}
//retorna 1 ou 0, se foi encontrado ou não.
int searchAccount(Conta* vet, unsigned int id, unsigned int index) {
    for (int i = 0; i <= index; i++){
        if (vet[i].id == id) return 1;
    }
    
    return 0;
}

void deposit(unsigned int id, double amount) {}

void withdraw(unsigned int id, double amount) {}

int deleteAccount(unsigned int id, unsigned int* index, Conta *conta) {
    int tem_id = -1;

    for (unsigned int i = 0; i < *index; i++) {
        printf("estamos no index: %u. Estamos no id: %u\n", *index, i);
        if (conta[i].id == id) {
            tem_id = i;
            break;
        }
    }

    if (tem_id == -1)
        return 0;  // Conta com o ID fornecido não encontrada

    for (unsigned int i = tem_id; i < *index - 1; i++) {
        conta[i] = conta[i + 1];
    }
    (*index)--;
    return 1;  // Conta deletada com sucesso
}

Conta* newDeleteAccount(Conta* vet, unsigned int id, unsigned int* index){
    unsigned int k = 0;
    Conta* new_vet = (Conta*) malloc ((*index - 1) * sizeof(Conta));
    for (int i = 0; i < *index; i++){ 
        if (vet[i].id != id) new_vet[k++] =  vet[i];
    } 

    free(vet);
    (*index)--;

    return new_vet;
}

void describeAccount(Conta account){
    printf("id: %u\n", account.id);
    printf("proprietario: %s\n", account.n_proprietario);
    printf("saldo: %.2lf\n", account.saldo);
    printf("tipo: %c\n", account.tipo);
}


