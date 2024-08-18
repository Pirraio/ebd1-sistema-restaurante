#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main() {
    int option;
    printf("Bem-vindo ao Restaurante!\n");
    do {
        printf("Opções:\n");
        printf("1 - Criar Pedido\n");
        printf("2 - Remover Prato do Pedido\n");
        printf("3 - Listar pedidos pendentes\n");
        printf("4 - Listar pedidos em processamento\n");
        printf("5 - Processar pedido\n");
        printf("6 - Sair\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                createOrder();
                break;
            case 2: {
                removeDishFromOrder();
                break;
            }
            case 3:
                listPendingOrders();
                break;
            case 4:
                listProcessingOrders();
                break;
            case 5: {
                processNextOrder();
                break;
            }
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (option != 6);

    Order *current = pendingHead;
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