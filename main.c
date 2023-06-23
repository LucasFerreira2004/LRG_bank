#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main() {
    int cont = 1; //variavel responsavel por garantir a possibilidade de repetição
    unsigned int n_contas;
    int conta_index = 0;
    unsigned int conta_id = 1;
    unsigned int id_pesquisa;

    Conta* vet_contas = NULL; // Inicialize o vetor com NULL

    int operacao;
    do{
        printf("============BEM VINDO AO BANCO LRG============\n\n");
        printf("Operacoes:\n");
        printf("1 -> Criar conta\n");
        printf("2 -> Pesquisar conta\n");
        printf("3 -> Sacar ou Depositar\n");
        printf("4 -> Deletar conta\n");
        printf("0 -> Sair do Banco\n");

        scanf("%d", &operacao);
        switch (operacao){
            case 1: //creat
                do {
                    Conta account;

                    printf("Insira os dados para a criação de uma nova conta!\n");
                    printf("Nome do proprietario: "); scanf(" %[^\n]", account.n_proprietario);
                    printf("Sado inicial da conta: "); scanf("%lf", &account.saldo);
                    scanf("%c", &account.tipo); //esse scanf armazena o \n do scan acima. É uma gambiarra.
                    printf("Tipo da conta (c/p): "); scanf("%c", &account.tipo);

                    vet_contas = createAccount(vet_contas, account, &conta_index, &conta_id);
                    printf("conta com os dados a seguir acaba de ser criada!: \n");
                    describeAccount(vet_contas[conta_index - 1]);

                    printf("deseja adicinar nova conta? (1/0): ");
                    scanf("%d", &cont);
                } while (cont);
                break;         
                
            case 2: //pesquisar
                cont = 1;
                do{
                    printf("Insira os dados para a pesquisa de uma conta!\n");
                    printf("Id: "); scanf("%u", &id_pesquisa);

                    unsigned int index_pesquisa = getAccount(vet_contas, id_pesquisa, conta_index);

                    if(index_pesquisa == -1){
                        printf("Conta nao encontrada!\n");
                    }else{
                        printf("Encontrado: \n");
                        describeAccount(vet_contas[index_pesquisa]);
                    }

                    printf("deseja pesquisar outra conta? (1/0): ");
                    scanf("%d", &cont); 
                }while (cont);
                break;
            case 3:
                printf("Insira os dados para depositar ou sacar de uma conta!\n");
                    printf("Id: "); scanf("%u", &id_pesquisa);

                 unsigned int index_pesquisa = getAccount(vet_contas, id_pesquisa, conta_index);

                 if(index_pesquisa != -1){
                        char opc;
                        print("Deseja sacar ou depositar (d/s): ");
                 }else{
                    (printf("ID nao encontrado\n"));
                 }

                break;
            case 4:
                cont = 1;
                do{
                    printf("Insira os dados para a remoção de uma conta!\n");
                    printf("Id: "); scanf("%u", &id_pesquisa);

                    unsigned int index_pesquisa = getAccount(vet_contas, id_pesquisa, conta_index);

                    if(index_pesquisa != -1){
                        vet_contas = newDeleteAccount(vet_contas, id_pesquisa, &conta_index);
                        printf("Conta deletada com sucesso!\n");
                    }else{
                        (printf("ID nao encontrado\n"));
                    } 
                    
                    printf("deseja remover outra conta? (1/0): ");
                    scanf("%d", &cont); 
                }while (cont);
                break;
            case 0:
                break;
                
            default:
            break;
        }
    }while(operacao);

  //  printf("Conta indice %u\n", conta_index);

    for (int i = 0; i < conta_index; i++) { //aqui temos o < pois o índice, depois de tantas operações, está reprentando o tamanho, ou seja, uma possição 
        describeAccount(vet_contas[i]);    //propicia para uma gravação futura no vetor. 
        printf("\n");
    }

    free(vet_contas);

    return 0;
}
