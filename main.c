#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    int option;
    do {
        printf("Bem-vindo ao Restaurante!\n");
        printf("Opções:\n");
        printf("1 - Criar Pedido\n");
        printf("2 - Adicionar Prato ao Pedido\n");
        printf("3 - Remover Prato do Pedido\n");
        printf("4 - Listar pedidos pendentes\n");
        printf("5 - Listar pedidos em processamento\n");
        printf("6 - Processar pedido\n");
        printf("7 - Sair\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                createOrder();
                break;
            case 2: {
                int orderNumber, dishType, dishId;
                printf("Número do pedido: ");
                scanf("%d", &orderNumber);
                printf("Tipo de prato (1-Entrada, 2-Prato Principal, 3-Sobremesa): ");
                scanf("%d", &dishType);
                printf("ID do prato: ");
                scanf("%d", &dishId);

                Dish *selectedDish = NULL;
                switch (dishType) {
                    case 1:
                        selectedDish = &entries[dishId - 1];
                        break;
                    case 2:
                        selectedDish = &mains[dishId - 1];
                        break;
                    case 3:
                        selectedDish = &desserts[dishId - 1];
                        break;
                }

                Order *current = head;
                int currentOrderNumber = 1;
                while (current != NULL) {
                    if (currentOrderNumber == orderNumber) {
                        addDishToOrder(current, *selectedDish);
                        printf("Prato adicionado ao pedido.\n");
                        break;
                    }
                    current = current->next;
                    currentOrderNumber++;
                }
                break;
            }
            case 3: {
                int orderNumber, dishId;
                printf("Número do pedido: ");
                scanf("%d", &orderNumber);
                printf("ID do prato: ");
                scanf("%d", &dishId);

                Order *current = head;
                int currentOrderNumber = 1;
                while (current != NULL) {
                    if (currentOrderNumber == orderNumber) {
                        removeDishFromOrder(current, dishId);
                        printf("Prato removido do pedido.\n");
                        break;
                    }
                    current = current->next;
                    currentOrderNumber++;
                }
                break;
            }
            case 4:
                listPendingOrders();
                break;
            case 5:
                listProcessingOrders();
                break;
            case 6: {
                int orderNumber;
                printf("Número do pedido: ");
                scanf("%d", &orderNumber);
                processOrder(orderNumber);
                printf("Pedido processado.\n");
                break;
            }
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (option != 7);

    Order *current = head;
    while (current != NULL) {
        Order *next = current->next;
        free(current->dishes);
        free(current);
        current = next;
    }

    return 0;
}