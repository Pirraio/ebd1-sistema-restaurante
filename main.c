#include <stdio.h>
#include <stdlib.h>

typedef struct dish {
    int id;
    char name[50];
} Dish;


typedef struct {
    Dish *dishes;
    int count;
    int isProcessing;
} Order;


int main() {

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
        {4, "Mousse de Chocolate"},
        {3, "Pudim de Leite"},
        {5, "Sorvete de Baunilha com Calda de Morango"}
    };

    printf("Bem-vindo ao Restaurante!\n");
    printf("Opções:\n");
    printf("1 - Criar Pedido\n");
    printf("2 - Remover Pedido\n");
    printf("3 - Listar pedidos pendentes\n");
    printf("4 - Listar pedidos em processamento\n");
    printf("5 - Processar pedido\n");
    printf("6 - Sair\n");

    int option;
    scanf("%d", &option);




   

    return 0;
}