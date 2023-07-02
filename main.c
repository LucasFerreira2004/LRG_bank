#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");

    int cont = 1; //variavel responsavel por garantir a possibilidade de repetição
    int conta_tam = 0;
    unsigned int conta_id = 1;
    unsigned int id_pesquisa;

    Conta* vet_contas = NULL; // Inicialize o vetor com NULL

    int operacao;
    do{
        do{
        printf("============BEM VINDO AO BANCO LRG============\n\n");
        printf("Operacoes:\n");
        printf("1 -> Criar conta\n");
        printf("2 -> Pesquisar conta\n");
        printf("3 -> Sacar ou Depositar\n");
        printf("4 -> Deletar conta\n");
        printf("0 -> Sair do Banco\n");

        scanf("%d", &operacao);

        if(operacao >= 0 && operacao <= 4) break;
        else printf("Operacao invalida\n");
        }while (operacao != 1 || operacao != 2 || operacao != 3 || operacao != 4 || operacao != 0);
        

        if(operacao == 1 || operacao == 2 || operacao == 3 || operacao == 4 || operacao == 0){
        switch (operacao){
            case 1: //creat
                do {
                    Conta account;

                    printf("Insira os dados para a criação de uma nova conta!\n");
                    printf("Nome do proprietario: "); scanf(" %[^\n]", account.n_proprietario);
                    printf("Sado inicial da conta: "); scanf("%lf", &account.saldo);
                    scanf("%c", &account.tipo); //esse scanf armazena o \n do scan acima. É uma gambiarra.
                    
                    do{ // operacao invalida para char nao funciona
                    printf("Tipo da conta (c/p): "); scanf("%c", &account.tipo);
                    if(account.tipo == 'c' || account.tipo == 'p') break;
                    else printf("Conta invalida\n");
                    }while(account.tipo != 'c' || account.tipo != 'p');
                    
                    vet_contas = createAccount(vet_contas, account, &conta_tam, &conta_id);
                    printf("conta com os dados a seguir acaba de ser criada!: \n");
                    describeAccount(vet_contas[conta_tam - 1]);
                    
                    do{
                    printf("deseja adicinar nova conta? (1/0): ");
                    scanf("%d", &cont);
                     if(cont == 1 || cont == 0) break;
                    else printf("Operacao invalida\n");
                    }while (cont != 1 || cont != 0);
                    
                } while (cont);
                break;         
                
            case 2: //pesquisar
                cont = 1;
                do{
                    printf("Insira os dados para a pesquisa de uma conta!\n");
                    printf("Id: "); scanf("%u", &id_pesquisa);

                    unsigned int index_pesquisa = getAccountIndex(vet_contas, id_pesquisa, conta_tam);

                    if(index_pesquisa == -1){
                        printf("Conta nao encontrada!\n");
                    }else{
                        printf("Encontrado: \n");
                        describeAccount(vet_contas[index_pesquisa]);
                    }

                    do{
                    printf("deseja pesquisar uma nova conta? (1/0): ");
                    scanf("%d", &cont);
                    if(cont == 1 || cont == 0) break;
                    else printf("Operacao invalida\n");
                    }while (cont != 1 || cont != 0);

                }while (cont);
                break;
                
            case 3:
                cont = 1;
                do{
                    printf("Insira os dados para depositar ou sacar de uma conta!\n");
                    printf("Id: "); scanf("%u", &id_pesquisa);

                    unsigned int index_pesquisa = getAccountIndex(vet_contas, id_pesquisa, conta_tam);

                    if(index_pesquisa != -1){
                            char opc;
                            double amount;
                            printf("Deseja sacar ou depositar (s/d): "); scanf(" %c", &opc);
                            
                            if(opc == 'd'){
                                printf("Digite o valor que deseja depositar: "); scanf("%lf", &amount);
                                if(deposit(vet_contas, index_pesquisa, amount)){
                                    printf("deposito bem sucedido!\n");
                                    printf("Conta de id %u alterada com sucesso\n", id_pesquisa);
                                }else{
                                    printf("deposito mal sucedido\n");
                                }

                            }else if(opc == 's'){
                                printf("Digite o valor que deseja sacar: "); scanf("%lf", &amount);
                                if (withdraw(vet_contas, index_pesquisa, amount)){
                                    printf("saque bem sucedido!\n");
                                    printf("Conta de id %u alterada com sucesso\n", id_pesquisa);
                                }else 
                                    printf("saque mal sucedido\n");
                            }
                            
                    }else{
                        (printf("ID nao encontrado\n"));
                    }
                    
                    do{
                    printf("deseja sacar ou depositar em uma nova conta? (1/0): ");
                    scanf("%d", &cont);
                    if(cont == 1 || cont == 0) break;
                    else printf("Operacao invalida\n");
                    }while (cont != 1 || cont != 0);

                }while(cont);
                break;

            case 4:
                cont = 1;
                do{
                    printf("Insira os dados para a remoção de uma conta!\n");
                    printf("Id: "); scanf("%u", &id_pesquisa);

                    unsigned int index_pesquisa = getAccountIndex(vet_contas, id_pesquisa, conta_tam);

                    if(index_pesquisa != -1){
                        vet_contas = deleteAccount(vet_contas, id_pesquisa, &conta_tam);
                        printf("Conta deletada com sucesso!\n");
                    }else{
                        (printf("ID nao encontrado\n"));
                    } 
                    
                    do{
                    printf("deseja remover outra conta? (1/0): ");
                    scanf("%d", &cont);
                    if(cont == 1 || cont == 0) break;
                    else printf("Operacao invalida\n");
                    }while (cont != 1 || cont != 0); 
                }while (cont);
                break;
            case 0:
                break;
                
            default:
                printf("Opção inválida\n");
            break;
        }
        } else {
            printf("Esta operacaoo é invalida, por favor digite uma nova operacaoo\n\n");
            continue;
            }
    }while(operacao);

    printf("======== DADOS DE TODAS AS CONTAS APÓS A EXECUÇÃO DAS OPERAÇÕES ========\n");
    for (int i = 0; i < conta_tam; i++) { //aqui temos o < pois o índice, depois de tantas operações, está reprentando o tamanho, ou seja, uma possição 
        describeAccount(vet_contas[i]);    //propicia para uma gravação futura no vetor. 
        printf("\n");
    }

    free(vet_contas);

    return 0;
}