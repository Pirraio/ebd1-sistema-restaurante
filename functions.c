#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

Dish entries[5] = {
    {1, "Sopa de Cebola"},
    {2, "Salada Caesar"},
    {3, "Bruschetta"},
    {4, "Carpaccio de Carne"},
    {5, "Camarão ao Alho"}
};

Dish mains[5] = {
    {1, "Lasanha à Bolonhesa"},
    {2, "Filé Mignon com Fritas"},
    {3, "Frango Grelhado com Legumes"},
    {4, "Bacalhau à Gomes de Sá"},
    {5, "Risoto de Cogumelos"}
};

Dish desserts[5] = {
    {1, "Tiramisu"},
    {2, "Cheesecake de Frutas Vermelhas"},
    {3, "Pudim de Leite"},
    {4, "Mousse de Chocolate"},
    {5, "Sorvete de Baunilha com Calda de Morango"}
};

Order *head = NULL;

void addDishToOrder(Order *order, Dish dish) {
    if (order->count == 0) {
        order->dishes = (Dish *)malloc(sizeof(Dish));
    } else {
        order->dishes = (Dish *)realloc(order->dishes, (order->count + 1) * sizeof(Dish));
    }
    order->dishes[order->count] = dish;
    order->count++;
}

void removeDishFromOrder(Order *order, int id) {
    int found = 0;
    for (int i = 0; i < order->count; i++) {
        if (order->dishes[i].id == id) {
            found = 1;
        }
        if (found && i < order->count - 1) {
            order->dishes[i] = order->dishes[i + 1];
        }
    }
    if (found) {
        order->count--;
        order->dishes = (Dish *)realloc(order->dishes, order->count * sizeof(Dish));
    }
}

void createOrder() {
    Order *newOrder = (Order *)malloc(sizeof(Order));
    newOrder->dishes = NULL;
    newOrder->count = 0;
    newOrder->isProcessing = 0;
    newOrder->next = head;
    head = newOrder;

    printf("Pedido criado. Adicione pratos ao pedido.\n");

    int dishType, dishId;
    while (1) {
        printf("Tipo de prato (1-Entrada, 2-Prato Principal, 3-Sobremesa, 0-Para sair): ");
        scanf("%d", &dishType);
        if (dishType == 0) break;
        if (dishType < 0 || dishType > 3) {
            printf("Tipo de prato inválido.\n");
            continue;
        }


        printf("Pratos disponíveis:\n");
        switch (dishType) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    printf("  %d - %s\n", entries[i].id, entries[i].name);
                }
                break;
            case 2:
                for (int i = 0; i < 5; i++) {
                    printf("  %d - %s\n", mains[i].id, mains[i].name);
                }
                break;
            case 3:
                for (int i = 0; i < 5; i++) {
                    printf("  %d - %s\n", desserts[i].id, desserts[i].name);
                }
                break;
        }

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
            default:
                printf("Tipo de prato inválido.\n");
                continue;
        }

        addDishToOrder(newOrder, *selectedDish);
        printf("Prato adicionado ao pedido.\n");
    }
}

void listPendingOrders() {
    Order *current = head;
    int orderNumber = 1;
    while (current != NULL) {
        if (!current->isProcessing) {
            printf("Pedido %d pendente:\n", orderNumber);
            for (int i = 0; i < current->count; i++) {
                printf("  Prato %d: %s\n", current->dishes[i].id, current->dishes[i].name);
            }
        }
        current = current->next;
        orderNumber++;
    }
}

void processOrder(int orderNumber) {
    Order *current = head;
    int currentOrderNumber = 1;
    while (current != NULL) {
        if (currentOrderNumber == orderNumber) {
            current->isProcessing = 1;
            return;
        }
        current = current->next;
        currentOrderNumber++;
    }
}

void listProcessingOrders() {
    Order *current = head;
    int orderNumber = 1;
    while (current != NULL) {
        if (current->isProcessing) {
            printf("Pedido %d em processamento:\n", orderNumber);
            for (int i = 0; i < current->count; i++) {
                printf("  Prato %d: %s\n", current->dishes[i].id, current->dishes[i].name);
            }
        }
        current = current->next;
        orderNumber++;
    }
}
