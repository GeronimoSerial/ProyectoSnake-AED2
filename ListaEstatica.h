#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define USUARIOS 10


//TIPOS DE DATOS

typedef char tString[20];

typedef struct {
	tString usuario;
	int puntuacionUsuario;
}tUsuario;

typedef tUsuario listaEstatica[USUARIOS];


//DECLARACION DE LISTA Y AUXILIAR
listaEstatica puntuacionesNivelInicial;
tUsuario auxUsuario;


//PROTOTIPADO
void inicializarListaEstatica(listaEstatica);
void ordenarListaEstatica(listaEstatica);
void mostrarListaEstatica(listaEstatica);
void mostrarListaEstaticaRecur(listaEstatica , int);

void eliminarUsuarioNivelInicial();
void eliminarUsuario(int);


int buscarLugarArray(listaEstatica);
int lugarLibre;
int k;


//FUNCIONES
void inicializarListaEstatica(listaEstatica pLista){
	int i;
	for (i=0; i <= USUARIOS-1; i++){
		strcpy(pLista[i].usuario, "vacio");
		pLista[i].puntuacionUsuario= 0;
	}
}


//FUNCION PARA ORDENAR LA LISTA
void ordenarListaEstatica(listaEstatica pLista){
	int i, j;
	tUsuario auxUser;
	bool bandera;

	bandera = false;
	i = 0;
	while ((bandera == false) && (i < USUARIOS))	{
		bandera = true;	
		for (j = 0; j < USUARIOS-1; j++)	{
			if (pLista[j].puntuacionUsuario < pLista[j+1].puntuacionUsuario){
				auxUser.puntuacionUsuario = pLista[j].puntuacionUsuario;
				strcpy(auxUser.usuario, pLista[j].usuario);
				pLista[j].puntuacionUsuario = pLista[j+1].puntuacionUsuario;
				strcpy(pLista[j].usuario, pLista[j+1].usuario);
				pLista[j+1].puntuacionUsuario = auxUser.puntuacionUsuario;
				strcpy(pLista[j+1].usuario, auxUser.usuario);
				bandera = false;
			}
		}
		i = i+1;				
	}
}
//MOSTRAR LISTA
void mostrarListaEstatica(listaEstatica pLista){
	int i;
	printf("\t\t\t\tTABLA DE POSICIONES\n");
	printf ("\t\t\t ==================================\n");
	for (i=0; i<=USUARIOS-1;i++){
		printf("\t\t\t |--------------------------------|\n");
		printf("\t\t\t | %d Usuario: %s\t ", i ,pLista[i].usuario);
		printf("PUNTUACION: %d ",pLista[i].puntuacionUsuario);
		printf("|\n");
	}
	printf ("\t\t\t ==================================\n\n");
}
//FUNCION PARA MOSTRAR LA LISTA DE MANERA RECURSIVA
void mostrarListaEstaticaRecur(listaEstatica pLista, int i){

	if (pLista[i].puntuacionUsuario == 0) {
		printf("\t\t\t |--------------------------------|\n");
	} else {
		printf("\t\t\t |--------------------------------|\n");
		printf("\t\t\t | %d Usuario: %s\t ", i ,pLista[i].usuario);
		printf("PUNTUACION: %d ",pLista[i].puntuacionUsuario);
		printf("|\n");
		mostrarListaEstaticaRecur(pLista, i + 1);
	}
	
}
//BUSCAR UN LUGAR VACIO

int buscarLugarArray(listaEstatica pLista){
	int i = 0 ;
	int lugarLibre = 0;
	
	while((lugarLibre ==0 ) && (i<=USUARIOS-1)){
		if (pLista[i].puntuacionUsuario == 0){
			lugarLibre=i;
			return lugarLibre;
		}
		i = i + 1;
	}
	
	return lugarLibre;
}
//ELIMINAR UN USUARIO DEL NIVEL INICIAL
void eliminarUsuarioNivelInicial(){
    int opcion;
    
    printf("\t\t\t    Desea eliminar un usuario?\n\t\t\t   ( 1 - Si || 0 - No )\n\n\t\t\t");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("\t\t\t   Ingrese el numero de Usuario: \n\n");
        scanf("%d", &k);

        if (k >= 0 && k < USUARIOS && puntuacionesNivelInicial[k].puntuacionUsuario != 0) {
            eliminarUsuario(k);
            // Actualizar la lista después de eliminar un usuario
            inicializarListaEstatica(puntuacionesNivelInicial);
        } else {
            printf("\t\t\t   Numero de usuario no valido o usuario no existe.\n\n");
        }
    }
}

void eliminarUsuario(int k){
	
	printf("\t\t\t    Usuario eliminado: %s", puntuacionesNivelInicial[k].usuario );
	strcpy(puntuacionesNivelInicial[k].usuario, "vacio");
	puntuacionesNivelInicial[k].puntuacionUsuario = 0;
	Sleep(1000);
	system("cls");
	printf("\t\t\t\tTABLA DE POSICIONES\n");
	printf ("\t\t\t ==================================\n");
	ordenarListaEstatica(puntuacionesNivelInicial);
	mostrarListaEstaticaRecur(puntuacionesNivelInicial, 0 );
	printf ("\t\t\t ==================================\n\n");

}
