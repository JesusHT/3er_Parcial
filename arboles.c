
#include <stdlib.h>
#include <stdio.h>

struct node {
	struct node* hijo_izq;
	struct node* hijo_der;
	int nivel;
	int dato;
};


struct node* nuevo_nodo(int dato) {
	struct node* node = NULL;
	node = malloc(sizeof(struct node));
	node -> hijo_izq = NULL;
	node -> hijo_der = NULL;
	node -> nivel    = 1;
	node -> dato     = dato;
	return node;
}

void insertar_nodo(struct node* raiz, struct node* nd) {
	if (raiz != NULL && nd != NULL) {
		nd->nivel = raiz->nivel + 1;
		if (nd->dato > raiz->dato) {
			if (raiz -> hijo_der == NULL)
				raiz -> hijo_der = nd;
			else
				insertar_nodo(raiz->hijo_der, nd);
		} else {
			if (raiz->hijo_izq == NULL)
				raiz->hijo_izq = nd;
			else
				insertar_nodo(raiz->hijo_izq, nd);
		}
	}
}

int buscarEnArbol(struct node* nd, int dato) {
	int calNivel = 0;
    
	if (nd != NULL) {

        if (nd->dato == dato)
		    return nd->nivel;

	    calNivel = buscarEnArbol(nd->hijo_izq, dato);

	    if (calNivel > 0)
		    return calNivel;
	
        calNivel = buscarEnArbol(nd->hijo_der, dato);

	    if (calNivel > 0)
		    return calNivel;

        return 0;
    }
	
    return 0;
}

int main() {
	int n = 0, nivel = 0;

	struct node* nd = nuevo_nodo(6);
    
	insertar_nodo(nd, nuevo_nodo(5));
	insertar_nodo(nd, nuevo_nodo(11));
	insertar_nodo(nd, nuevo_nodo(4));
	insertar_nodo(nd, nuevo_nodo(3));
	insertar_nodo(nd, nuevo_nodo(8));
	insertar_nodo(nd, nuevo_nodo(12));
	insertar_nodo(nd, nuevo_nodo(9));
	insertar_nodo(nd, nuevo_nodo(21));
	
	printf("Ingrese el número a buscar: ");
	scanf("%d", &n);
	
    nivel = buscarEnArbol(nd, n);

	if (nivel > 0)
		printf("\nEl número %d esta en el nivel: %d  \n",n, nivel);
	else 
		printf("El número %d no ha sido encontrado.\n",n);

	return 0;
}