#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H
#include <stdlib.h>

//Estructura para un nodo de la lista
typedef struct Node {
    int data; 		//Datos que se almacenan
    struct Node* next;	//Puntero al nodo anterior
    struct Node* prev;	//Puntero al nodo siguiente
} Node;

//Estructura para la lista doblemente enlazada
typedef struct DoubleList {
    Node* head;	//Puntero al primer nodo
    Node* tail;	//Puntero al ultimo nodo
} DoubleList;

// Funciones de la lista doblemente enlazada
DoubleList* create_list();
void insert_at_beginning(DoubleList* list, int data);
void insert_at_end(DoubleList* list, int data);
void insert_at_index(DoubleList* list, int data, int index);
void delete_node(DoubleList* list, int data);
int  find_node(DoubleList* list, int data);
void print_list_forward(DoubleList* list);
void print_list_backward(DoubleList* list);
void free_list(DoubleList* list);

#endif // DOUBLE_LIST_H
