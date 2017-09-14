#include <stdio.h>

int chainLength (char* caractersChain, int number_length);

int main (){
	
	const int NUMBER_LENGTH = 30;
	
	char caractersChainEntry[NUMBER_LENGTH];
	

	printf("Bienvenido, introduce una cadena de carácteres y te el número total de ellos. \n");

	scanf("%s", caractersChainEntry);
	
	printf("El total son %d. \n", chainLength (caractersChainEntry, NUMBER_LENGTH));
	
	
	}

int chainLength (char* caractersChain, int number_length){
	
	int caracterMeter = 0;
	
	
	for(int i = 0; i < number_length; i++){
		
		if(caractersChain[i] == '\000') break;
		
		caracterMeter++;
		
	}
	
	return caracterMeter;
	
}
