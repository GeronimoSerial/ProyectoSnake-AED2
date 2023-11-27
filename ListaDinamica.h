#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define USUARIOS 10

typedef char tString[20]; 

typedef struct {
	tString nombre;
	int puntuacionUsuario;
}tUser;

typedef struct nodo {
	tUser user;
	struct nodo * siguiente;
} tListaDinamica;

void inicializarLista();
bool listaVacia( tListaDinamica * );

void insertarPrimero( tUser );
void insertarAdelante( tUser );
void insertarElemento( tUser );

void eliminarPrimero();
void eliminarK( int k );
void eliminarUsuario();

tListaDinamica * puntuacionNivelIntermedio;
tUser usuario;
int p;

void inicializarLista() {	

	puntuacionNivelIntermedio = NULL;
	
}

bool  listaVacia( tListaDinamica * pLista ) {
	
	return ( pLista == NULL );
	
}

void insertarPrimero( tUser pUsuario ) {
	
	tListaDinamica * nuevoUsuario;
	
	nuevoUsuario = ( tListaDinamica * ) malloc( sizeof( tListaDinamica ) );	
	nuevoUsuario->user = pUsuario;
	nuevoUsuario->siguiente = NULL;
	puntuacionNivelIntermedio = nuevoUsuario;
	
}

void insertarAdelante( tUser pUsuario ) {
	
	tListaDinamica * nuevoUsuario;
	
	nuevoUsuario = ( tListaDinamica * ) malloc( sizeof( tListaDinamica ) );	
	nuevoUsuario->user= pUsuario;
	nuevoUsuario->siguiente = puntuacionNivelIntermedio;
	puntuacionNivelIntermedio = nuevoUsuario;
	
}

void insertarElemento( tUser pUsuario ) {
	
	if ( listaVacia( puntuacionNivelIntermedio ) ) {
		insertarPrimero( pUsuario );
	}else {
		insertarAdelante( pUsuario );
	}
	
}

void eliminarPrimero(){
	
	tListaDinamica * nodoSuprimir;
	nodoSuprimir = puntuacionNivelIntermedio;
	
	puntuacionNivelIntermedio = puntuacionNivelIntermedio->siguiente;
	printf("\t\t\t\tPrimer usuario eliminado %s\n\n", nodoSuprimir->user.nombre);
	Sleep(1000); 
	free( nodoSuprimir );
	nodoSuprimir = NULL;
	
}

void eliminarK( int k ) {
	
	tListaDinamica * aux;
	tListaDinamica * nodoSuprimir;
	int i;
	
	aux = puntuacionNivelIntermedio;

	for ( i=1; i < k-1; i++) {
		aux = aux->siguiente;
	}
	
	nodoSuprimir = aux->siguiente;
	aux->siguiente = nodoSuprimir->siguiente;
	printf( "\t\t\t\tUsuario eliminado: %s\n\n", nodoSuprimir->user.nombre );
	Sleep(1000);	
	free( nodoSuprimir );
	nodoSuprimir = NULL;
	
}

void visualizarPuntuaciones( tListaDinamica * pLista ) {
	
	tListaDinamica * aux;
	aux = pLista;
	int i;
	
	printf("\t\t\t\tTABLA DE POSICIONES\n");
	printf ("\t\t\t ====================================\n");
	if( listaVacia(aux) ) {
			printf("\t\t\t |----------------------------------|\n");
			printf("\t\t\t | 0 Usuario: vacio\t ");
			printf("PUNTUACION: --- ");
			printf("|\n");
	}else {
		i = 0;
		while ( aux != NULL) {
			printf("\t\t\t | %d Usuario: %s\t ",i ,aux->user.nombre);
			printf("PUNTUACION: %d ",aux->user.puntuacionUsuario);
			printf(" |\n");
			aux = aux->siguiente;
			i = i + 1;
		}
	}
	printf ("\t\t\t ====================================\n");
	
}

void eliminarUsuarioNivelIntermedio(){
	
	int opcion;
	
	printf("\t\t\t\tDesea eliminar un Usuario?\n\t\t\t\t ( 1 - Si || 0 - No )\n\n \t\t\t\t");
			scanf("%d", &opcion);
			if (opcion == 1) {
				printf("\t\t\t      Desea eliminar el primero u otro?\n\t\t\t\t ( 1 - Primero || 0 - Otro )\n\n \t\t\t\t");
				scanf("%d", &opcion );
				if (opcion == 1) {
					eliminarPrimero();
					system("cls");
					visualizarPuntuaciones(puntuacionNivelIntermedio);
				} else {
					printf("\t\t\t    Que elemento de la lista quiere eliminar?\n\t\t\t\t ( Ingrese el numero de Usuario ) \n\n \t\t\t\t");
					scanf("%d", &p );
					eliminarK( p );
					system("cls");
					visualizarPuntuaciones(puntuacionNivelIntermedio);
				}
			}
			
}
