#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define USUARIOSTOTALES 20

typedef char tString[20];

typedef struct {
	int nivel;
	tString usuario;
	int puntuacionUsuario;
}tDatosUsuario;

typedef tDatosUsuario listaOrdenar[USUARIOSTOTALES];

void abrirArchivoEscribir();
void grabarDatos( tDatosUsuario );
void cerrarArchivoEscribir();

void abrirArchivoLeer();
void cerrarArchivoLeer();
void procesoCorte();
void principioCorte();
void unUsuario();
void finCorte();
void leerRegistro();
	
int buscarLugarArray(listaOrdenar);
void ordenarListaEstatica(listaOrdenar);

tDatosUsuario regUsuario;
FILE * archivoJugadores;
listaOrdenar listaUsuariosTotales;
int nivelAnterior;
tDatosUsuario datosUsuario;
FILE * archivo;

int totalJugadores;
int totalPuntuacion;

int acumuladorPuntuaciones;
int contadorJugadores;

void inicializarListaEstatica(listaOrdenar pLista){
	
	int i;
	for (i=0; i <= USUARIOSTOTALES-1; i++){
		pLista[i].nivel = 0;
		strcpy(pLista[i].usuario, "vacio");
		pLista[i].puntuacionUsuario= 0;
	}
	
}

void abrirArchivoEscribir(){
	
	archivoJugadores = fopen("Usuarios.dat", "wb");
	inicializarListaEstatica(listaUsuariosTotales);
	
}

int buscarLugarArray(listaOrdenar pLista){
	int i = 0 ;
	int lugarLibre1 = 0;
	
	while((lugarLibre1 == 0 ) && (i<=USUARIOSTOTALES-1)){
		if (pLista[i].nivel == 0){
			lugarLibre1=i;
			return lugarLibre1;
		}
		i = i + 1;
	}
	
	return lugarLibre1;
}

 void grabarDatos(tDatosUsuario pUsuario){
 	
 	int posicionLibre = buscarLugarArray( listaUsuariosTotales );
 	listaUsuariosTotales[posicionLibre].nivel = pUsuario.nivel;
 	strcpy ( listaUsuariosTotales[posicionLibre].usuario, pUsuario.usuario );
 	listaUsuariosTotales[posicionLibre].puntuacionUsuario = pUsuario.puntuacionUsuario;
 	
 }
 
  void ordenarListaEstatica(listaOrdenar pLista){
	int i, j;
	tDatosUsuario auxUsuario;
	bool bandera;

	bandera = false;
	i = 0;
	while ((bandera == false) && (i < USUARIOSTOTALES))	{
		bandera = true;	
		for (j = 0; j < USUARIOSTOTALES-1; j++)	{
			if (pLista[j].nivel > pLista[j+1].nivel){
				auxUsuario.nivel = pLista[j].nivel;
				auxUsuario.puntuacionUsuario = pLista[j].puntuacionUsuario;
				strcpy(auxUsuario.usuario, pLista[j].usuario);
				pLista[j].nivel = pLista[j+1].nivel;
				pLista[j].puntuacionUsuario = pLista[j+1].puntuacionUsuario;
				strcpy(pLista[j].usuario, pLista[j+1].usuario);
				pLista[j+1].nivel = auxUsuario.nivel;
				pLista[j+1].puntuacionUsuario = auxUsuario.puntuacionUsuario;
				strcpy(pLista[j+1].usuario, auxUsuario.usuario);
				bandera = false;
			}
		}
		i = i+1;				
	}
}
 
 void ordenarArchivo(){
 	
 	tDatosUsuario aux;
 	int i;
 	
	for (i=0 ; i <= USUARIOSTOTALES ; i++) {
		
		if ( listaUsuariosTotales[i].nivel != 0) {
			aux.nivel = listaUsuariosTotales[i].nivel;
			aux.puntuacionUsuario = listaUsuariosTotales[i].puntuacionUsuario;
			strcpy ( aux.usuario, listaUsuariosTotales[i].usuario );
			fwrite(&aux, sizeof(tDatosUsuario), 1, archivoJugadores);
		}
		
	}
 	
 }
 
 void cerrarArchivoEscribir(){
 	
 	fclose(archivoJugadores);
 	
 }
 
 void visualizarPuntuacionTotales (listaOrdenar pLista){
	int i;
	printf("\t\t\t\tTABLA DE POSICIONES\n");
	printf ("\t\t\t ==================================\n");
	for (i=0; i<=USUARIOSTOTALES-1;i++){
		printf("\t\t\t |--------------------------------|\n");
		printf("\t\t\t | %d Usuario: %s\t ", pLista[i].nivel ,pLista[i].usuario);
		printf("PUNTUACION: %d ",pLista[i].puntuacionUsuario);
		printf("|\n");
	}
	printf ("\t\t\t ==================================\n\n");
}
 
 void cargarDatos(){
 	
 	ordenarListaEstatica ( listaUsuariosTotales );
 	ordenarArchivo();
 	cerrarArchivoEscribir();
 	
 }
 
 void leerRegistro(){
 	
 	fread(&regUsuario, sizeof(tDatosUsuario),1, archivo);
 	
 }
 
 void abrirArchivoLeer(){
 	
 	archivo = fopen("Usuarios.dat", "rb");
	leerRegistro();
	totalJugadores = 0;
	totalPuntuacion = 0;

 }
 
 void procesoCorte(){
	while (!feof(archivo)){
		principioCorte();
		while (!feof(archivo) && nivelAnterior == regUsuario.nivel){
			unUsuario();
			leerRegistro();
		}
		finCorte();
	}
}

void finPrograma(){
	
	float promedioTotal = totalPuntuacion / totalJugadores;
	
	printf("\t\t\t Cantidad total de jugadores: %d\n", totalJugadores);
	printf("\t\t\t Puntuacion total de jugadores: %d\n", totalPuntuacion);
	printf("\t\t\t Promedio general de puntuaciones: %.2f\n", promedioTotal);
	
	fclose(archivo);
}

void principioCorte(){
	
	acumuladorPuntuaciones = 0;
	contadorJugadores = 0;
	nivelAnterior = regUsuario.nivel;
	
}

void unUsuario(){
	
	acumuladorPuntuaciones = acumuladorPuntuaciones + regUsuario.puntuacionUsuario;
	contadorJugadores = contadorJugadores + 1;
		
}

void finCorte(){
	
	float promedio = acumuladorPuntuaciones/contadorJugadores;
	printf("\t\t\t |------------------------------------------------|\n");
	printf("\t\t\t |Promedio de puntuacion en todo el Nivel %d: %.2f|\n", nivelAnterior , promedio);
	printf("\t\t\t |Cantidad de jugadores en el Nivel %d: %d          |\n", nivelAnterior, contadorJugadores);
	printf ("\t\t\t *================================================*\n");
	totalPuntuacion = totalPuntuacion + acumuladorPuntuaciones;
	totalJugadores = totalJugadores + contadorJugadores;
	
}

void realizarCorte(){
	
	abrirArchivoLeer();
	procesoCorte();
	finPrograma();
	
}
