#include <stdio.h>


int coordinates [2] = { 0, 0 };

char possibleMoves [28][3];

bool control = true ;


void asignCoordinates ( char *dataEntry );

void pawn ();


int main () {


	char pieceOrigin [4] = {0, 0, 0, 0};

	char coordinatesChess [3];


	printf ("Bienvenido a mi pequeño programa de ajedrez, a continuación introduciras el nombre de una pieza y su posición en el tablero. \n Después en el menú podras elegir si introducir un movimiento para comprobar si es correcto o ver todos los posibles. \n");

	printf ("Introduce la pieza con la celda de origen en notación algebraica. \n");

	scanf ( "%3s", pieceOrigin );


	if ( pieceOrigin [2] == 0 ) {

		coordinatesChess [0] = pieceOrigin [0];

		coordinatesChess [1] = pieceOrigin [1];
		
		pieceOrigin [0] = 'P';

	} else {
		coordinatesChess [0] = pieceOrigin [1];

		coordinatesChess [1] = pieceOrigin [2];

	}


	asignCoordinates ( coordinatesChess );


	if ( coordinates [0] == 0 || coordinates [1] == 0 ) {

		printf("No has introducido una notación correcta. \n");

		return 1;

	}

	switch ( pieceOrigin ) {
		
		case 'P' : 
		
			pawn ();
			
		
		default :
		
			printf("No has introducido una notación correcta. \n");
		
	}

}


void asignCoordinates ( char *dataEntry ) {

/* Está función si la variable "control" es verdad, recoge la notación algebraica
 * y en un array previamente creado asigna coordenadas numericas para el eje X y el eje Y.
 *
 */

 	char letter [9] = "abcdefgh";

 	char number [9] = "12345678";

	char letterPiece = dataEntry [0];

	if ( control ) {

		for ( int i = 0; i < 9; i++ ) {

			if ( dataEntry [0] == letter [i] ) {

				coordinates [0] = i + 1;

			}

			if ( dataEntry [1] == number [i] ) {

				coordinates [1] = i + 1;

			}

		}

	} else {

		for ( int j = 0; j < 29; j++ ) {
			
			if ( possibleMoves [j][1] == 0 ) {
				
				break;
			
			}
			
			for ( int k = 0; k < 9; k++) {
				
				if ( ( possibleMoves [j][0] - 1 ) == letter [k] ) {
					
					if ( letterPiece == 'P' ) {
						
						printf ( "%c%c", letterPiece, letter [k] );
					
					} else {
						
						printf ( "%c", letter [k] );

				}
				
			}
			
			for ( int l = 0; l < 9; l++ ) {
							
				if ( ( possibleMoves [j][1] - 1 ) == number [k] ) {
					
					printf ( "%c. \n", number[k] );
					
				}
				
			}
			
		}
	
	}

}

}


void pawn () {

	char choisePiece [8];
	
	control = false;

	switch ( coordinates [0] ) {
		
		case 8 :
		
			printf ( "Esta posición no es posible, ya que en esta casilla el peón corona por otra pieza. \n");
			
			break;
			
		case 7 :
		
			printf ( "Elige por que pieza quieres coronar el peón. \n" );
			
			scanf ( "%7s", choisePiece );
			
			asignCoordinates ( choisePiece );
			
		default :
		
			coordinates [0] += 1;
			
			choisePiece [0] = 'P';
			
			asignCoordinates ( choisePiece );
			
		}

}
