#include <stdio.h>

int searchCaracter (char* chainCaracter, char caracter, int number_lenght);

int main (){
	
	const int NUMBER_LENGTH = 40;
	
	char chainCaracterEntry[NUMBER_LENGTH];
	
	char caracterEntry;
	
	
	printf("¡Bienvenido!, introduce una cadena de caracteres a continuación. \n");
	
	scanf("%40s", chainCaracterEntry);
	
	printf("Ahora por favor introduce el caracter a buscar y te devolveré su posición en la cadena, salvo que no este. \n");
	
	scanf("%1s", &caracterEntry);
	
	
	int search = searchCaracter (chainCaracterEntry, caracterEntry, NUMBER_LENGTH);
	
	if(search == -1){
		
		printf("No se ha encontrado el caracter que has introducido. \n");
	}
	else{
		
		printf("La posición del caracter introducido es %d. \n", search);
	
	}
}

int searchCaracter (char* chainCaracter, char caracter, int number_lenght){
	
	int caracterPosition = 0;
	
	for(int i = 0; i < number_lenght; i++){
		
		if(chainCaracter[i] == '\000'){
			
			caracterPosition = -1;
			
			break;
			
		}
		
		if(chainCaracter[i] == caracter){
			
			caracterPosition = i + 1;
			
			break;
			
		}
	}
	
	return caracterPosition;
	
}
