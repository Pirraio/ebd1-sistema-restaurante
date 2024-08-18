#include <stdio.h>
#include <stdlib.h>


typedef struct dish{
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
}


int main() {
 Menu entries = {NULL};
 Menu mains = {NULL};
 Menu desserts = {NULL};


int entriesCounter = 0;
int mainsCounter = 0;
int dessertsCounter = 0;


    addDish(&entries, &entriesCounter, "Sopa de Cebola");
    addDish(&entries, &entriesCounter, "Salada Caesar");
    addDish(&mains, &mainsCounter, "Lasanha à Bolonhesa");
    addDish(&mains, &mainsCounter, "Filé Mignon com Fritas");
    addDish(&desserts, &dessertsCounter, "Tiramisu");
    addDish(&desserts, &dessertsCounter, "Cheesecake de Frutas Vermelhas");
 
    for(int i = 0; i < entriesCounter; i++){
        printf("Entrada %d: %s\n", i+1, entries.dishes[i].name);
    }

    free(entries.dishes);
    free(mains.dishes);
    free(desserts.dishes);

    return 1;
}