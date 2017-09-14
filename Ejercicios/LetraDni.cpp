#include <stdio.h>

int main (){
	
	char letterDni[24] ="TRWAGMYFPDXBNJZSQVHLCKE";
	
	unsigned int numberDni = 0;
	
	unsigned int resto = 0;
	
	printf("A continuación introduce un DNI valido. \n");
	
	scanf("%8u", &numberDni);
	
	resto = numberDni % 23;
	
	printf("La letra correspondiente es %c. \n", letterDni[resto]);
	
	return 0;
	
}
