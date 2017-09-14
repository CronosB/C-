#include <stdio.h>


int imp (int* number, int numbersLength);

int main(){
	
	const int NUMBERS_LENGTH = 10;
	
	int number[NUMBERS_LENGTH];
	
	int numberMintomax[NUMBERS_LENGTH];

	int numberMaxtomin[NUMBERS_LENGTH];

	int numbercontrol = 0;

/*
 * Escanea 10 números introducidos por el usuario.
 */ 	
	
	for(int i = 0; i < NUMBERS_LENGTH; i++){
		
		scanf("%d", &number[i]);
		
		numberMintomax[i] = number[i];
		numberMaxtomin[i] = number[i];

	}
	
/*
 * Ordena mediante el metodo de la burbuja el array, asignando a la variable numberasign el primer 	valor de la matriz a comparar para poder asignarlo a la siguiente posicion correspondiente. Además mediante numbercontrol se comprueba que los numeros se están intercambiando para reiniciar la sentencia.
 *
 */

	for(int j = 1; j < NUMBERS_LENGTH; j++){
		
		int n = j - 1;
		
		int numberasign = 0;
		
		if(numberMintomax[n] > numberMintomax[j]){
			
			numberasign = numberMintomax[n];
			
			numberMintomax[n] = numberMintomax[j];
			
			numberMintomax[j] = numberasign;

			numbercontrol++;

		}

		if(numbercontrol != 0){
			j = 0;
			numbercontrol = 0;
		}
	} 
	
/*
 * Ordena mediante el metodo de la burbuja de mayor a menor, asigna a numberasign el primer valor de la comparación y luego lo reasigna al posterior previa asignación del posterior al anterior. Además con numbercontrol se comprueba si hay intercambio de valores y asi reinicia la sentencia desde el principio.
 * 
 */	
	
	for(int h = 1; h < NUMBERS_LENGTH; h++){
		
		int numberasign = 0;
		
		int n = h - 1;
		
		if(numberMaxtomin[n] < numberMaxtomin[h]){
			
			numberasign = numberMaxtomin[n];
			numberMaxtomin[n] = numberMaxtomin[h];
			numberMaxtomin[h] = numberasign;
			numbercontrol++;
		}
		if(numbercontrol !=0){
			h = 0;
			numbercontrol = 0;
		}
	}


	imp (number, NUMBERS_LENGTH);
	
	imp (numberMintomax, NUMBERS_LENGTH);

	imp (numberMaxtomin, NUMBERS_LENGTH);

return 0;

}
/*
 * Imprime la secuencia contenida en la matriz
 */
int imp (int* number, int numbersLength)
{ 
	for(int i = 0; i < numbersLength; i++){
	
		printf("%d.\n", number[i]);
	}
}

