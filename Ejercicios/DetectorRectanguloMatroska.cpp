#include <stdio.h>


void vertexEntry(int vertex[][2], short int numberSquare);

bool checkSquare (int checkVertex[][2]);

bool insideSquare(int squareOut[][2], int squareIn[][2]);


int main(){
	
	int square1[4][2];
	
	int square2[4][2];
	
	
	printf("A continuación introduce los vertices de un rectangulo en orden de las agujas del reloj y después el que quieres comprobar si esta dentro del primero. \n");
	
	
	vertexEntry(square1, 1);
	
	if(checkSquare(square1) == false){
		
		printf("El primer cuadrilatero no es un cuadrado. \n");
		
		return 1;
		
	}
	
	
	vertexEntry(square2, 2);
		
	if(checkSquare(square2) == false){
		
		printf("El segundo cuadrilatero no es un cuadrado. \n");
		
		return 1;
		
	}
		
	if(insideSquare(square1, square2)){
		
		printf("El 2º cuadrado esta dentro del 1º. \n");
		
	}else{
		
		printf("El 2º cuadrado no está dentro del 1º. \n");
		
	}

	return 0;

}

void vertexEntry(int vertex[][2], short int numberSquare){
	
	/*
	 * En esta función se recogen los puntos de coordenadas introducidos por el usuario en un array de dos dimensiones.
	 * 
	 */
	
	short int numberVertex = 1;
	
	printf("Introduce los vertices del %dº. \n", numberSquare);
	
	for(int i = 0; i < 4; i++){
		
		printf("Introduce primero el valor de X y despues el valor de Y del vertice %hdº. \n", numberVertex);
		
		scanf("%d", &vertex[i][0]);
		
		scanf("%d", &vertex[i][1]);
		
		numberVertex++;
	}
}

bool checkSquare(int checkVertex[][2]){
	
	/*
	 * En esta función se comprueba que la figura introducida es un cuadrado.
	 * 
	 */
	 
	bool side[4];
	
	bool checkSide = true;
		
	
	side[0] = (checkVertex[0][0] == checkVertex[1][0]) && (checkVertex[0][1] < checkVertex[1][1]);
	
	side[1] = (checkVertex[1][1] == checkVertex[2][1]) && (checkVertex[1][0] < checkVertex[2][0]);
	
	side[2] = (checkVertex[2][0] == checkVertex[3][0]) && (checkVertex[2][1] > checkVertex[3][1]);
	
	side[3] = (checkVertex[3][1] == checkVertex[0][1]) && (checkVertex[3][0] > checkVertex[0][0]);
	
	
	for(int j = 1; j < 5; j++){
		
		if(side[j]){
			
			continue;
			
		}else{
			
			checkSide = false;
			
			break;
			
		}
	}
	
	
	if(checkSide == true){
	
		return true;
	 
	}else{
		
		return false;
		
	}
}
	
bool insideSquare(int squareOut[][2], int squareIn[][2]){
	
	/*
	 * En esta función se comprueba mediante los lados de los cuadrados si el segundo está dentro del primero.
	 * 
	 */
	
	bool side1 = squareOut[0][0] < squareIn[0][0];
	
	bool side2 = squareOut[1][1] > squareIn[1][1];
	
	bool side3 = squareOut[2][0] > squareIn[2][0];
	
	bool side4 = squareOut[3][1] < squareIn[3][1];
	
	bool checkInside = side1 == side2 == side3 == side4;
	
	if(checkInside){
		
		return true;
		
	}else{
		
		return false;
		
	}
}
