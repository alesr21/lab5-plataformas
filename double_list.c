#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

DoubleList* create_list() {
    DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

//Funcion para insertar nodo al inicio
void insert_at_beginning(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
	    return; //Si malloc falla se sale de la funcion
    }

    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
	list->tail = new_node;
    }
    list->head = new_node; 
}

//Funcion para insertar nodo al final
void insert_at_end(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
            return; //Si malloc falla se sale de la funcion
    }

    new_node->data = data;
    new_node->next = NULL;

    if (list->tail == NULL) { //Si la lista esta vacia
        new_node->prev = NULL; //no hay nodos anteriores
	list->head = list->tail = new_node; 
    } else {
	new_node->prev = list->tail;
	list->tail->next = new_node;
	list->tail = new_node; //Actualiza la cola de la lista al nuevo nodo
    }
}

//Funcion para insertar nodo en un lugar especifico
void insert_at_index(DoubleList* list, int data, int index) {
    if (index < 0) {
        return; // Index invalido
    }

    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        return; // Fallo de malloc
    }
    new_node->data = data;

    if (index == 0) { // Insertar al inicio
        insert_at_beginning(list, data);
        return;
    }

    Node* current = list->head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current == NULL) { // Index fuera de los limites, insertar al final
        insert_at_end(list, data);
    } else { // Insertar entre current y current->next
        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != NULL) {
            current->next->prev = new_node;
        }
        current->next = new_node;
        if (new_node->next == NULL) { // Actualizar la cola si es necesario
            list->tail = new_node;
        }
    }
}

//Funcion para eliminar nodo
void delete_node(DoubleList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

//Funcion para buscar un nodo con valor especifico
int find_node(DoubleList* list, int data) {
    Node* current = list->head;
    int index = 0; //Utilizar un indice para conocer la posicion del nodo

    while (current != NULL) {
        if (current->data == data) {
	    printf("\nElemento %d encontrado en la posicion %d\n", data, index);
            return index;
        }
        current = current->next;
	index++;
    }

    printf("\nElemento %d no encontrado en la lista.\n", data);
    return -1;//Retorna -uno si el valor no se encuentra en la lista
}

//Funcion para recorrer la lista de inicio a fin

void print_list_forward(DoubleList* list) {
    Node* current = list->head; //Comienza al inicio de la lista
    
    while (current != NULL) { //Recorre hasta que no hayan mas nodos
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

//Funcion para recorrer la lista del final al incio
void print_list_backward(DoubleList* list) {
    Node* current = list->tail; //Comienza al final de la lista
    
    while (current != NULL) { //Recorre hasta que no hayan mas nodos
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("\n");
}

//Funcion para liberar la lista
void free_list(DoubleList* list) {
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next; // Guarda el siguiente nodo
        free(current); // Libera el nodo actual
        current = next;
    }
    list->head = NULL; //Inicio de la lista es NULL
    list->tail = NULL; //Final de la lista es NULL
}










