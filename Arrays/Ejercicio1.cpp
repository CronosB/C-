#include <stdio.h>

#include <limits.h>

int main(){

	int number[10];
	
	int totalsum = 0;
	
	int avg = 0; 
	
	int max = INT_MIN;
	
	int min = INT_MAX;
	
	/*
	 * Recoge 10 números del usuario y los va sumando a la variable totalsum, despúes compara individualmente cada elemento para sacar el máximo y el mínim, asignandolos a max, y min.
	 */
	
	for(int i = 0; i < 10; i++){
		
		scanf("%d",&number[i]); 
		totalsum += number[i];
		
		if(max < number[i]){
			
			max = number[i];
		
		}
				
			
		if(min > number[i]){
			
			min = number [i];
		}
	}
	
	avg = totalsum / 10;

	printf("La suma es %d.\n", totalsum);
	
	printf("La media es %d.\n", avg);
	
	printf("El máximo es %d.\n", max);
	
	printf("El mínimo es %d.\n", min);
}
