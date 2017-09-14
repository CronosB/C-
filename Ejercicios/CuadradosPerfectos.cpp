#include <stdio.h>


int main(){
	
	
	unsigned int numberEntry = 0;
	
	
	printf("A continuacion introduce un número de máximo 8 cifras para comprobar si es natural o no. \n");
	
	scanf("%8u", &numberEntry);
	
	
	if(numberEntry == 0){
		
		printf("El número que has introducido no es un número natural. \n");
		
	}
	
	for(int i = 0; i < 10000; i++){
		
		if(numberEntry == i * i){
			
			printf("El número que has introducido es un número natural. \n");
			
			return 0;
			
		}
	}
	
	
	printf("El número que has introducido no es un número natural. \n");

	return 0;
	
}
