#include <stdio.h>

char increment (char* number, int numberlength);

int main(){
	
	const int NUMBER_LENGTH = 10;
	
	char numberEntry[NUMBER_LENGTH];

	printf("Introduce un número con un máximo de 9 dígitos para que el mismo se incremente. \n");
	
	scanf("%s", numberEntry);
	
	increment(numberEntry, NUMBER_LENGTH);
	
	return 0;
	
}

char increment (char* number, int number_length){

	
	int numberPosition = 0;
	
/*
 * Esta sentencia comprueba la cantidad de cifras introducidas.
 * 
 */
	
	for(int i = 0; i < number_length; i++){
		
		if(number[i] == 0){
			
			numberPosition = i;
		}
	}

/*
 * Esta sentencia comprueba la posicion dentro del array de la última cifra introducida y la incrementa en 1.
 * 
 */
	
	if(numberPosition == 0){
		
		number[number_length - 1]++;
	}
	else{
		
		number[numberPosition - 1]++;
	}
	
	printf("%s. \n", number);
	printf("%d", numberPosition);
}
