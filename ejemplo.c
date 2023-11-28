#include<stdlib.h>  // Inclusión de la librería estándar para funciones de utilidad
#include<stdio.h>   // Inclusión de la librería estándar para operaciones de entrada y salida
#include<string.h>  // Inclusión de la librería estándar para operaciones con cadenas de caracteres
#include<stdbool.h> // Inclusión de la librería estándar para tipos booleanos

#define USUARIOS 10 // Definición de una constante USUARIOS con valor 10

// Definición de tipos de datos personalizados

typedef char tString[20]; // Tipo de dato para representar una cadena de caracteres

typedef struct {          // Definición de una estructura tUsuario
    tString usuario;      // Campo para almacenar el nombre del usuario
    int puntuacionUsuario; // Campo para almacenar la puntuación del usuario
} tUsuario;

typedef tUsuario listaEstatica[USUARIOS]; // Tipo de dato para representar una lista estática de tUsuario con tamaño USUARIOS

// Declaración de variables globales

listaEstatica puntuacionesNivelInicial; // Declaración de una lista estática puntuacionesNivelInicial
tUsuario auxUsuario; // Declaración de una variable auxiliar de tipo tUsuario

// Prototipos de funciones

void inicializarListaEstatica(listaEstatica); // Prototipo de la función para inicializar la lista estática
void ordenarListaEstatica(listaEstatica);     // Prototipo de la función para ordenar la lista estática
void mostrarListaEstatica(listaEstatica);     // Prototipo de la función para mostrar la lista estática
void mostrarListaEstaticaRecur(listaEstatica, int); // Prototipo de la función para mostrar la lista estática de manera recursiva

void eliminarUsuarioNivelInicial(); // Prototipo de la función para eliminar un usuario del nivel inicial
void eliminarUsuario(int);         // Prototipo de la función para eliminar un usuario específico

int buscarLugarArray(listaEstatica); // Prototipo de la función para buscar un lugar vacío en la lista estática
int lugarLibre; // Declaración de una variable para almacenar un lugar libre en la lista
int k; // Declaración de una variable para operaciones diversas

// Función para inicializar la lista estática
void inicializarListaEstatica(listaEstatica pLista) {
    int i;
    for (i = 0; i <= USUARIOS - 1; i++) {
        strcpy(pLista[i].usuario, "vacio"); // Inicializa el nombre de usuario como "vacio"
        pLista[i].puntuacionUsuario = 0;    // Inicializa la puntuación del usuario como 0
    }
}

/* 
Función para ordenar la lista estática basada en la puntuación del usuario.
Se utiliza el algoritmo de ordenación de burbuja para este propósito.
*/

void ordenarListaEstatica(listaEstatica pLista) {
    // (Código de la función de ordenación de burbuja, explicación detallada en el comentario arriba del código)
}

// Función para mostrar la lista estática
void mostrarListaEstatica(listaEstatica pLista) {
    // (Código para mostrar la lista estática en formato tabular, detallado en el comentario arriba del código)
}

/*
Función para mostrar la lista estática de manera recursiva.
Esta función muestra la lista de usuarios hasta encontrar un usuario con puntuación 0.
*/

void mostrarListaEstaticaRecur(listaEstatica pLista, int i) {
    // (Código recursivo para mostrar la lista estática, detallado en el comentario arriba del código)
}

// Función para buscar un lugar vacío en la lista estática
int buscarLugarArray(listaEstatica pLista) {
    // (Código para buscar un lugar vacío en la lista estática, detallado en el comentario arriba del código)
}

// Función principal para eliminar un usuario del nivel inicial
void eliminarUsuarioNivelInicial() {
    // (Código para eliminar un usuario del nivel inicial, detallado en el comentario arriba del código)
}

// Función para eliminar un usuario específico
void eliminarUsuario(int k) {
    // (Código para eliminar un usuario específico y actualizar la lista, detallado en el comentario arriba del código)
}
