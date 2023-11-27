#include<iostream>
#include<windows.h>
#include<conio.h>

#include "ListaEstatica.h"
#include "ListaDinamica.h"
#include "Corte.h"

#define ARRIBA    72
#define IZQUIERDA 75
#define DERECHA   77
#define ABAJO     80
#define ESC       27

#define USUARIOS 10

void inicializarPrograma();

int cuerpo [400][2];
int n;
int tam;
int x,y;
int dir;
int xc,yc;
int velocidad,h;
int puntuacion;
int w1;
int w2;

char tecla;

void gotoxy (int, int);
void guardar_posicion();
void dibujar_cuerpo();
void borrar_cuerpo();
void teclear();
void cambiar_velocidad();
void puntos();
void titulo();
void menu();
void opciones();

//Nivel 1

void pintar ();
void comida();
bool game_over();
void game();
bool win1();

//Nivel 2
void pintar2();
void comida2();
bool game_over2();
void game2();
bool win2();

int main(){
	titulo();
	inicializarPrograma();
	menu();
	system("pause>NULL");
	return 0;
}

void inicializarPrograma(){
	
	inicializarListaEstatica(puntuacionesNivelInicial);
	inicializarLista();
	abrirArchivoEscribir();
	
}

/* Funciones Principales */

void guardar_posicion(){  //guarda la posicion en coordenadas
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++;
	if(n==tam)n=1;//si no come , no incrementa su tamaño
}

void reiniciarJuego(){ 
	borrar_cuerpo();
	guardar_posicion();
	n=1;
	tam=5;
	x=10,y=12;
	dir=3;
	xc=30,yc=15;
	velocidad=150,h=1;
	puntuacion=0;
	w1=200;
	w2=280;
}

void dibujar_cuerpo(){
	for(int i=1;i<tam;i++){
		gotoxy(cuerpo[i][0],cuerpo[i][1]);printf("%c",254);
	}
}

void borrar_cuerpo(){
		gotoxy(cuerpo[n][0],cuerpo[n][1]);printf(" ");
	
}

void teclear(){
	if(kbhit()){ // funcion que sirve para guardar la tecla que pulsamos , si no pulsamos nimguna retorna 0
		tecla=getch(); 
		switch(tecla){// switch para elegir la tecla que presionemos
			case ARRIBA:
				if(dir!=2) //si se mueve para arriba no se puede mover a abajo
				   dir=1;
				   break;
		    case ABAJO://si se mueve para abajo no se puede mover a abajo
		    	if(dir!=1)
			       dir=2;
				   break;
			case DERECHA: //si se mueve para derecha no se puede mover a izquierda
				if(dir!=4)
				   dir=3;
				   break;
			case IZQUIERDA://si se mueve para izquierda no se puede mover a derecha
				if(dir!=3)
				   dir=4;
				   break;	   	
		}
	}
	
}

void cambiar_velocidad(){           //incrementacion de velocidad a medida que come
	if(puntuacion==h*20){
		velocidad-=10;
		h++;
	}
}

void puntos(){
	gotoxy(3,1);printf("Puntos 00%d",puntuacion);
}

void gotoxy(int x, int y)  {     //declaracion de funcion
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

//Nivel 1

void pintar(){
     // Líneas horizontales
     for(int i=2; i < 78; i++){
        gotoxy (i, 3); printf ("%c", 205);  // los números hacen referencia al código acsii
        gotoxy(i, 23); printf ("%c", 205);
     }
     //Líneas verticales
     for(int v=4; v < 23; v++){
        gotoxy (2,v);  printf ("%c", 186);
        gotoxy(77,v);  printf ("%c", 186);
     }
     // Esquinas
     gotoxy  (2,3);    printf ("%c", 201);
     gotoxy (2,23);    printf ("%c", 200);
     gotoxy (77,3);    printf ("%c", 187);
     gotoxy(77,23);    printf ("%c", 188);
	 gotoxy(3,25);printf("Puntos para ganar 00%d",w1);
	 gotoxy(3,27);printf("ACLARACION: A veces tu viborita puede pisar la comida y no aparece ninguna nueva, si eso pasa, REINICIA");
	 gotoxy(60,25);printf("NIVEL INICIAL");
}

void comida() {
    if (x == xc && y == yc) {
        xc = (rand() % 73) + 4;
        yc = (rand() % 19) + 4;
        tam++;
        puntuacion += 10;
    }
    gotoxy(xc, yc);
    printf("%c", 'O');
}


bool game_over(){
	if(y==3||y==23||x==2||x==77){
	return false;
	}//cordenadas marco del juego
	for(int j=tam-1;j>0;j--){                                   //for game over si choca con su mismo cuerpo 
		if(cuerpo[j][0]==x&&cuerpo[j][1]==y)
		return false;
	}
	return true;
}

bool win(){
	if(w1==puntuacion)return false; 
	return true;		
}


void game(){
	while(tecla!=ESC&&game_over()&& win()){
	puntos();
	borrar_cuerpo();
	guardar_posicion();
	dibujar_cuerpo();
	comida();
	
	teclear();
	teclear();

	if(dir==1)y--;
	if(dir==2)y++;
	if(dir==3)x++;
	if(dir==4)x--;
	Sleep(velocidad);
	
if ( !game_over()){
	MessageBox(NULL,"PERDISTE","  JUEGO TERMINADO", MB_OK);
	system("cls");
	puntuacionesNivelInicial[lugarLibre].puntuacionUsuario = puntuacion;
	datosUsuario.puntuacionUsuario = puntuacion;
	grabarDatos(datosUsuario);
}
if ( !win()){
	MessageBox(NULL,"GANASTE"," JUEGO TERMINADO", MB_OK);
	system("cls");
	puntuacionesNivelInicial[lugarLibre].puntuacionUsuario = puntuacion;
	datosUsuario.puntuacionUsuario = puntuacion;
	grabarDatos(datosUsuario);
}
}
}

//Nivel 2/

void pintar2(){
     // Líneas horizontales
     for(int i=2; i < 78; i++){
        gotoxy (i, 3); printf ("%c", 205);  // los números hacen referencia al código acsii
        gotoxy(i, 23); printf ("%c", 205);
     }
     //Líneas verticales
     for(int v=4; v < 23; v++){
        gotoxy (2,v);  printf ("%c", 186);
        gotoxy(77,v);  printf ("%c", 186);
     }
     // Esquinas
     gotoxy  (2,3);    printf ("%c", 201);
     gotoxy (2,23);    printf ("%c", 200);
     gotoxy (77,3);    printf ("%c", 187);
     gotoxy(77,23);    printf ("%c", 188);
	 gotoxy(3,25);printf("Puntos para ganar 00%d",w2);
	 gotoxy(3,27);printf("ACLARACION: A veces tu viborita puede pisar la comida y no aparece ninguna nueva, si eso pasa, REINICIA");
	 gotoxy(60,25);printf("NIVEL INTERMEDIO");
}

void comida2(){
	if (x == xc && y == yc) {
    	xc = (rand() % 73) + 4;
    	yc = (rand() % 19) + 4;
        tam++;
        puntuacion += 10;
        cambiar_velocidad;
    }
    gotoxy(xc, yc);
    printf("%c", 'O');
}

bool game_over2(){
	if(y==3||y==23||x==2||x==77){
		return false;	
	}
	for(int j=tam-1;j>0;j--){
		if(cuerpo[j][0]==x&&cuerpo[j][1]==y)
		return false;
	}
 return true;
}

bool win2(){
	if(w2==puntuacion)return false;
	return true;		
}

void game2(){
	while(tecla!=ESC&&game_over2()&& win2()){
	puntos();
	borrar_cuerpo();
	guardar_posicion();
	dibujar_cuerpo();
	comida2();
	
	teclear();
	teclear();

	if(dir==1)y--;
	if(dir==2)y++;
	if(dir==3)x++;
	if(dir==4)x--;
	Sleep(velocidad);
	
if ( !game_over2()){
	MessageBox(NULL,"  PERDISTE","  FIN DEL JUEGO", MB_OK);
	system("cls");
	usuario.puntuacionUsuario = puntuacion;
	datosUsuario.puntuacionUsuario = puntuacion;
	
	insertarElemento(usuario);
	grabarDatos(datosUsuario);
	
}
if ( !win2()){
	MessageBox(NULL,"  GANASTE","  ENHORABUENA!", MB_OK);
	system("cls");
	usuario.puntuacionUsuario = puntuacion;
	datosUsuario.puntuacionUsuario = puntuacion;
	
	insertarElemento(usuario);
	grabarDatos(datosUsuario);
	
}
}
}

void titulo(){

    
	
	printf("\t\t\t  PROYECTO INTEGRADOR-AEDI2-COMISION C\n\n");

    printf("\t\t\t\t\t   INSTRUCCIONES\n\n");
    printf("\t\t\t  El juego termina al alcanzar los puntos indicados en cada nivel \n");
    printf("\t\t\t  Debera recolectar la comida para acumular puntos: %c\n",4);
    printf("\t\t\t  Pierdes al chocar con el limite del marco o con tu propio cuerpo!\n");
    printf("\n");
    printf("\t\t\t  Para moverte debes utilizar las flechas del teclado\n\n");
    printf("\t\t\t  Precione enter para iniciar!!\n\n");
        
    system("pause>NULL");
    system("cls");
}

void menu(){
	system("cls");
	int opcion;
	opciones();
	scanf ("%d", &opcion);
		switch (opcion){
		case 1: {
			system("cls");
			printf("\n\n\n\t\t\t\t Ingrese nombre del jugador: ");
			fflush(stdin);
			lugarLibre = buscarLugarArray(puntuacionesNivelInicial);
			gets(puntuacionesNivelInicial[lugarLibre].usuario);
			puntuacionesNivelInicial[lugarLibre].puntuacionUsuario = -1;
			strcpy ( datosUsuario.usuario, puntuacionesNivelInicial[lugarLibre].usuario );
			datosUsuario.nivel = 1 ;
			system("cls");
			printf("\t\t\t JUGADOR: %s",puntuacionesNivelInicial[lugarLibre].usuario);
			reiniciarJuego();
			pintar();
			gotoxy(xc,yc);printf("%c",4);
			game();
			menu();
			break;
		}
		case 2: {
			system("cls");
			printf("\n\n\n\t\t\t\t Ingrese nombre del jugador: ");
			fflush(stdin);
			gets(usuario.nombre);
			strcpy ( datosUsuario.usuario, usuario.nombre);
			datosUsuario.nivel = 2 ;
			system("cls");
			printf("\t\t\t JUGADOR: %s",usuario.nombre);
			reiniciarJuego();
			pintar2();
			gotoxy(xc,yc);printf("%c",4);
			game2();
			menu();
			break;
		}
		case 3: {
  			system("cls");
   			printf("\t\t\t\tTABLA DE POSICIONES\n");
   			printf("\t\t\t ==================================\n");
    		ordenarListaEstatica(puntuacionesNivelInicial); // Ordenar la lista antes de mostrarla
    		mostrarListaEstaticaRecur(puntuacionesNivelInicial, 0);
    		printf("\t\t\t ==================================\n\n");
   			eliminarUsuarioNivelInicial();
    		gotoxy(25, 25); printf("Presione enter para volver al MENU");
    		system("pause>NULL");
    		menu();
    		break;
		}
		case 4: {
			system("cls");
			strcpy (usuario.nombre, "nada");
			usuario.puntuacionUsuario = 00;
			visualizarPuntuaciones(puntuacionNivelIntermedio);
			eliminarUsuarioNivelIntermedio();
			gotoxy(26,25); printf ("Presione enter para volver al MENU");
			system("pause>NULL");
			menu();
			break;
		}
		case 5: {
			system("cls");
			cargarDatos();
			printf("\t\t\t\t\tINFORME POR NIVEL\n");
			printf ("\t\t\t *================================================*\n");
			realizarCorte();
			gotoxy(26,25); printf ("Presione enter para volver al MENU");
			system("pause>NULL");
			menu();
			break;
		}
		default: {
			system("cls");
			printf("\n\n\t\t\t\t\t\tFIN PROGRAMA ...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		} 
	
	}
}

void opciones(){
	system("cls");
	printf("\n\n\n");
	printf("\t\t\t\t  *====================================================*\n");
	printf("\t\t\t\t  |                                                    |\n");
	printf("\t\t\t\t  | Ingrese la opcion que desea realizar               |\n");
	printf("\t\t\t\t  |                                                    |\n");
	printf("\t\t\t\t  | 1 - Iniciar partida nivel inicial                  |\n");
	printf("\t\t\t\t  |                                                    |\n");
	printf("\t\t\t\t  | 2 - Iniciar partida nivel intermedio               |\n");
	printf("\t\t\t\t  |                                                    |\n");
	printf("\t\t\t\t  | 3 - Mostrar tablero de puntuacion nivel inicial    |\n");
	printf("\t\t\t\t  |                                                    |\n");
	printf("\t\t\t\t  | 4 - Mostrar tablero de puntuacion nivel intermedio |\n");
	printf("\t\t\t\t  |                                                    |\n");
	printf("\t\t\t\t  | 5 - Emitir informe por nivel                       |\n");
	printf("\t\t\t\t  |                                                    |\n");
	printf("\t\t\t\t  | Otro numero - Salir                                |\n");
	printf("\t\t\t\t  |                                                    |\n");
	printf("\t\t\t\t  *====================================================*");
    gotoxy(1,18);printf("\n\n\t\t\t\t   Eleccion: ");
}
