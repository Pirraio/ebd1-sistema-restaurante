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
    struct order *next;
} Order;

extern Order *pendingHead;
extern Order *processingHead;
extern Dish entries[5];
extern Dish mains[5];
extern Dish desserts[5];

void addDishToOrder(Order *order, Dish dish);

void removeDish(Order *order, int id);

void removeDishFromOrder();

void createOrder();

void listPendingOrders();

void processNextOrder();

void listProcessingOrders();

#endif