#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

typedef struct {
    char n_proprietario[100];
    unsigned int id;
    double saldo;
    char tipo;
} Conta;

//create
Conta* createAccount(Conta* vet, Conta new_account, unsigned int* index, unsigned int* id);

//read
int getAccountIndex(Conta* vet, unsigned int id, unsigned int index);
int searchAccount(Conta* vet, unsigned int id, unsigned int index);

//update
int deposit(Conta* vet, unsigned int index_required, double amount);
int withdraw(Conta* vet, unsigned int index_required, double amount);

//delete
Conta* deleteAccount(Conta* vet, unsigned int id, unsigned int* index);

//outras
void describeAccount(Conta account);

#endif // OPERATIONS_H_INCLUDED
