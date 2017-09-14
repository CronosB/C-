#include <stdio.h>


int main(){

	unsigned int numberEntry = 0;
	
	unsigned long int numberSquare = 0;
	
	
	printf("A continuación introduce un número de máximo 8 cifras y te daré el cuadrado perfecto más cercano sin que lo supere. \n");
	
	scanf("%8u", &numberEntry);
	
	
	if(numberEntry == 0){
		
		printf("El número que has introducido no es un número natural. \n");
		
	}
	
	for(int i = 0; i <= 10000; i++){
		
		if(numberEntry == i * i){
			
			printf("El número que has introducido ya es un cuadrado perfecto. \n");
			
			break;
			
		}else if(numberEntry < i * i){
			
			numberSquare = (i - 1) * (i - 1);
			
			printf("El cuadrado perfecto más cercano es %lu. \n", numberSquare);
			
			break;
			
		}
	}
	
	return 0;

}
