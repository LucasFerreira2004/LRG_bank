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
int getAccount(Conta* vet, unsigned int id, unsigned int index);
int searchAccount(Conta* vet, unsigned int id, unsigned int index);

//update
void deposit(unsigned int id, double amount);
void withdraw(unsigned int id, double amount);

//delete
int deleteAccount(unsigned int id, unsigned int* index, Conta *conta);
Conta* newDeleteAccount(Conta* vet, unsigned int id, unsigned int* index);


//outras
void describeAccount(Conta account);
void menuCreate();


#endif // OPERATIONS_H_INCLUDED
