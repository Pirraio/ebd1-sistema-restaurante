#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct dish {
    int id;
    char name[50];
} Dish;

typedef struct order {
    Dish *dishes;
    int count;
    int isProcessing;
    struct order *next;
} Order;

extern Order *head;
extern Dish entries[5];
extern Dish mains[5];
extern Dish desserts[5];

void addDishToOrder(Order *order, Dish dish);

void removeDishFromOrder(Order *order, int id);

void createOrder();

void listPendingOrders();

void processOrder(int orderNumber);

void listProcessingOrders();

#endif
