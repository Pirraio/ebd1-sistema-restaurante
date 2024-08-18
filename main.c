#include <stdio.h>
#include <stdlib.h>

typedef struct dish {
    int id;
    char name[50];
} Dish;

typedef struct {
    Dish *dishes;
    int count;
} Menu;

void addDish(Menu *menu, int *counter, const char *name) {
    if (*counter == 0) {
        menu->dishes = (Dish *)malloc(sizeof(Dish));
    } else {
        menu->dishes = (Dish *)realloc(menu->dishes, (*counter + 1) * sizeof(Dish));
    }
    menu->dishes[*counter].id = *counter + 1;
    snprintf(menu->dishes[*counter].name, sizeof(menu->dishes[*counter].name), "%s", name);
    (*counter)++;
    menu->count = *counter; 
}

void listMenu(Menu *menu) {
    for (int i = 0; i < menu->count; i++) {
        printf("Prato %d: %s\n", menu->dishes[i].id, menu->dishes[i].name);
    }
}

void removeDish(Menu *menu, int *counter, int id) {
    int found = 0;
    for (int i = 0; i < *counter; i++) {
        if (menu->dishes[i].id == id) {
            found = 1;
        }
        if (found && i < *counter - 1) {
            menu->dishes[i] = menu->dishes[i + 1];
        }
    }
    if (found) {
        (*counter)--;
        menu->dishes = (Dish *)realloc(menu->dishes, (*counter) * sizeof(Dish));
        menu->count = *counter; 
    }
}

int main() {
    Menu entries = {NULL, 0};
    Menu mains = {NULL, 0};
    Menu desserts = {NULL, 0};

    int entriesCounter = 0;
    int mainsCounter = 0;
    int dessertsCounter = 0;

    addDish(&entries, &entriesCounter, "Sopa de Cebola");
    addDish(&entries, &entriesCounter, "Salada Caesar");
    addDish(&mains, &mainsCounter, "Lasanha à Bolonhesa");
    addDish(&mains, &mainsCounter, "Filé Mignon com Fritas");
    addDish(&desserts, &dessertsCounter, "Tiramisu");
    addDish(&desserts, &dessertsCounter, "Cheesecake de Frutas Vermelhas");

    printf("Entradas:\n");
    listMenu(&entries);

    printf("\nRemovendo 'Salada Caesar'...\n");
    removeDish(&entries, &entriesCounter, 2);

    printf("Entradas após remoção:\n");
    listMenu(&entries);

    free(entries.dishes);
    free(mains.dishes);
    free(desserts.dishes);

    return 0;
}