#include <stdio.h>

int main (){
	
	unsigned short int sideA = 0;
	unsigned short int sideB = 0;
	unsigned short int sideC = 0;
	
	printf("A continuación introduce los lados del triangulo para saber si es Equilatero, Escaleno o Isosceles. \n");
	
	scanf("%hu", &sideA);
	scanf("%hu", &sideB);
	scanf("%hu", &sideC);
	
	if(sideA == sideB && sideA == sideC){
		
		printf("Es un triangulo equilatero. \n");
		
		return 0;
		
	}
	if(sideA == sideB || sideA == sideC || sideB == sideC){
		
		printf("Es un triangulo isosceles. \n");
		
	}else{
		
		printf("Es un triangulo escaleno. \n");
		
	}
	
	return 0;

}
