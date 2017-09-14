#include <stdio.h>

char increment (char* number, int numberlength, int numberposition);

int main(){
	
	const int NUMBER_LENGTH = 10;
	
	char numberEntry[NUMBER_LENGTH];
	
	int numberPosition = NUMBER_LENGTH;

	printf("Introduce un número con un máximo de 9 dígitos para que el mismo se incremente. \n");
	
	scanf("%10s", numberEntry);

/*
 * Esta sentencia recoge en la variable numberPosition la posicion del caracter de fin de cadena.
 * 
 */

	for(int i = 0; i < NUMBER_LENGTH; i++){
		
		if(numberEntry[i] == '\000'){
			
			numberPosition = i;
		}
	}
	
	printf("NumberPosition %d \n", numberPosition);
	
	increment(numberEntry, NUMBER_LENGTH, numberPosition);
	
	return 0;
	
}

char increment (char* number, int number_length, int numberposition){

	int a = 0;

/*
 * Esta sentencia comprueba la posicion inicial: si es un 9 incrementa la unidad siguiente, si no la misma. Si ademas los numeros introducidos son todos 9 reinicia la cadena desde 0. Se usa a variable a como control para comprobar si la cifra anterior era un 9 y "se incremento" para así incrementarse en una unidad.
 * 
 */
	if(number[numberposition - 1] == '9'){
	
		for(int j = (numberposition - 1); j >= 0; j--){
		
			if (a == 0){
			
				if(number[j] == '9'){
				
					number[j] = '0';
					
					a = 0;
				}
				else{
					
					number[j]++;
									
					a = 1;
				}
			}
		}
	}
	else{		
		
		number[numberposition - 1]++;
	}
	
	printf("%s. \n", number);
}

