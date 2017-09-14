#include <stdio.h>

bool increment (char* number, int number_length);

int main(){
	
	const int NUMBER_LENGTH = 10;
	
	char numberEntry[NUMBER_LENGTH];

/*
 * Esta sentencia asigna como valor por defecto al array la secuencia de escape.
 * 
 */

	for(int i = NUMBER_LENGTH; i >= 0; i--){
	
		numberEntry[i] = '\000';
	
	}
	
	printf("Introduce un número con un máximo de 9 dígitos para que el mismo se incremente. \n");
	
	scanf("%10s", numberEntry);

	//printf("NumberPosition %d \n", numberPosition);
	
	increment(numberEntry, NUMBER_LENGTH);
	
	return 0;
	
}

bool increment (char* number, int number_length){
	
	int numberEnd = number_length;

/*
 * Esta sentencia recoge en la variable numberPosition la posicion del caracter de fin de cadena.
 * 
 */

	for(int j = 0; j < number_length; j++){
		
		if(number[j] == '\000'){
			
			numberEnd = j;
			
			break;
		}
	}
	
	int controlType = 0;
	
	int numberPosition = numberEnd - 1;
	
/*	
	for(int l = numberPosition; l >= 0; l--){
		
		for(char m = '0'; m <= '0'; m++){
			
			if(number[l] == m ){
				
				controlType = 1;
			}
			else{
				
				controlType = 0;
			}
		}
	}
	
	if(controlType == 1){ */

		int array_control = 0;
		
		int control_escape = 0;
	
	/*
	 * Esta sentencia inicia desde el final del array hasta el principio del mismo. Mientras realiza el recorrido cuenta los 9 que hay en él, para detectar que si el máximo permitido de carácteres a ingresar son todos 9 de como valor 0 al "incrementarlo".
	 * 
	 * Así mismo también comprueba que si no se introdujo el máximo de carácteres permitidos como "9" y cada uno se convierte en cero y asigna al principio de la cadena un "1" si todo son "9" o incrementa en una unidad el anterior.
	 * 
	 * También si el número introducido es cualquier otro lo incrementa simplemente en una unidad.
	 * 
	 */
	 
		for(int k = numberPosition; k >= 0; k--){
			
			array_control++;
			
			if(number[k] == '9'){
			
				if(array_control == number_length){
					
					for(int l = number_length; l >= 0 ; l--){
						
						if(l == 0){
							
							number[l] = '0';
						}
						else{
							
							number[l] = '\000';
						}
					}					
				}
				else{
					if(k == 0 && number[k] == '9'){
						
						number[k] = '1';
						
						number[numberPosition + numberEnd] = '0';
					}
					else{
						
						number[k] = '0';
						
					}
				}
			}
			else{
					
				number[k]++;
				
				break;
			}
		}
		
		printf("%s. \n", number);
		
/*	}
	else{
		
		
	}*/
}


