#include <stdio.h>


int main(){
	
	
	char dniEntry[9];
	
	char letterDni[24] ="TRWAGMYFPDXBNJZSQVHLCKE";
	
	unsigned int resto;
	
	unsigned int numberDni = 00000000;
	
	unsigned int cipherDni = 10000000;
	
		
	printf("A continuación introduce un DNI. \n");
	
	scanf("%s", dniEntry);
	
	for(int i = 0; i < 9; i++){
		
		numberDni += (dniEntry[i] - 48) * cipherDni;
		
		cipherDni /= 10;
		
	}

	
	resto = numberDni % 23;

	if(letterDni[resto] == dniEntry[8]){
	
		printf("El DNI es correcto. \n");
		
	}else{
		
		printf("El DNI es incorrecto, su letra debería ser %c. \n", letterDni[resto]);
		
	}
	
}
