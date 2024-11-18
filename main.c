#include <stdio.h>
#include "double_list.h"

int main() {
	DoubleList* list = create_list();
	if (list == NULL) {
		printf("No se pudo crear la lista.\n");
		return 1;
	}

	//Insertar valores iniciales a la lista
	insert_at_end(list, 3);
	insert_at_end(list, 8);
	insert_at_end(list, 14);
	insert_at_end(list, 21);
	insert_at_end(list, 28);

	printf("Lista inicial:\n");
	print_list_forward(list);

	//Prueba de las funciones para editar la lista
	
	insert_at_beginning(list, 1); //Agrega al inicio
	printf("\nSe agrego el nodo 1 al inicio.");
	insert_at_end(list, 35); //Agrega al final
	printf("\nSe agrego el nodo 35 al final de la lista.");
	insert_at_index(list, 10, 3); //Agrega en la posicion 3
	printf("\nSe agrego el nodo 10 en la posicion 3");
	insert_at_index(list, 51, 5); //Agrega en la posicion 5
	printf("\nSe agrego el nodo 51 en la posicion 5.\n");
	//Imprime la nueva lista con los cambios
	
	printf("\nLista despues de los cambios realizados:\n");
	print_list_forward(list);
	
	//Eliminar dos nodos
	delete_node(list, 1);//Elimina el primer nodo
	printf("\nSe elimino el nodo 1.");
	delete_node(list, 10);//Elimina el tercer nodo con valor de 10
	printf("\nSe elimino el nodo 10.\n");
	
	//Mostrar la lista con los nodos eliminados
	printf("\nLista despues de eliminar los nodos:\n");
        print_list_forward(list);
	
	//Buscar nodos en la list
	int node_to_find = 21;
	printf("\nBuscando nodo %d ...", node_to_find);
	int node_index  = find_node(list, node_to_find);
	if (node_index != -1) {
		printf("Nodo con el valor %d encontrado en la posicion %d\n", node_to_find, node_index);
	} else {
		printf("Nodo con el valor %d no encontrado. \n", node_to_find);
	}


	//Imprimir lista en diferente orden
	printf("\nLista de inicio a fin:\n");
	print_list_forward(list); 

	printf("\nLista desde el final hasta el inicio:\n");
	print_list_backward(list);

	//Liberar nodos y lista
	free_list(list);
	free(list);
	printf("\nLos nodos y la lista se liberaron con exito\n");

	return 0;
}






