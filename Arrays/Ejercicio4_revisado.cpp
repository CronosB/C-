#include <stdio.h>

const int NUMBER_LENGTH = 10;

bool increment (char* number);

int main (){

	char numberEntry[NUMBER_LENGTH];
	
	for(int h = 0; h <= NUMBER_LENGTH; h++){
		
		numberEntry[h] = '\000';
		
	}
		
	printf("Introduce un numero de máximo 10 cifras. \n");
		
	scanf("%9s", numberEntry);

	if(increment(numberEntry)){
	
		printf("%s. \n", numberEntry);
	
	}
	else{
		
		printf("No es un número lo que has introducido. \n");
	}

	return 0;
}

bool increment (char* number){
	
	int numberControl = 0;
	
	for(int j = 0; j < NUMBER_LENGTH; j++){
		
		if(number[j] == '\000'){
			
			continue;
					
		}
		
		if(number[j] < '0' || number[j] > '9'){
				
			return false;
				
		}
	}
	
	for(int i = NUMBER_LENGTH; i >= 0; i--){
	
		if(number[i] == '\000'){
			
			continue;
					
		}
			
		if(number[i] == '9'){
			
			number[i] = '0';
			
			numberControl++;
			
			if(i == 0){
				
				number[0] = '1';
				
				number[numberControl] = '0';
				
				if(number[NUMBER_LENGTH - 1] == '0'){
				
					number[0] = '0';
					
					number[1] = '\000';
					
				}
			}
		}
		else{
			
			number[i]++;			
			break;
			
		}

	}
		
	return true;
	
}
