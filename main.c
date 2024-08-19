#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main() {
    int option;
    printf("Bem-vindo ao Restaurante!\n");
    do {
        printf("====================================\n");
        printf("Opções:\n");
        printf("1 - Criar Pedido\n");
        printf("2 - Remover Prato do Pedido\n");
        printf("3 - Listar pedidos pendentes\n");
        printf("4 - Listar pedidos em processamento\n");
        printf("5 - Processar pedido\n");
        printf("6 - Sair\n");
        printf("====================================\n");
        
        if (scanf("%d", &option) != 1) { //Caso o usuário digite um caractere inválido
            printf("Opção inválida.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (option) { 
            case 1: //Cria um pedido
                createOrder();
                break;
            case 2: { //Remove um prato do pedido
                removeDishFromOrder();
                break;
            }
            case 3: //Lista os pedidos pendentes
                listPendingOrders();
                break;
            case 4: //Lista os pedidos em processamento
                listProcessingOrders();
                break;
            case 5: { //Processa o próximo pedido
                processNextOrder();
                break;
            }
            case 6: //Sai do programa
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (option != 6);

    Order *current = pendingHead; //Libera a memória alocada para os pedidos
    while (current != NULL) {
        Order *next = current->next;
        free(current->dishes);
        free(current);
        current = next;
    }

    current = processingHead; 
    while (current != NULL) {
        Order *next = current->next;
        free(current->dishes);
        free(current);
        current = next;
    }

    return 0;
}