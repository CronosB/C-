#include <stdio.h>

int main (){
	
		float number_progresive = 0; //Variable para representar la progresion numerica
		int number_division = 0; //Divisor para la media numerica
		float number_sum = 0; //Suma de todos los numeros de la progresion
		float number_med = 0; //Media de todos los numeros de la progresion
		
		for(int a = 0; a < 10; a++){
			
			number_progresive++;
			number_division++;
			number_sum +=number_progresive;
			
			printf("%f \n" ,number_progresive); //Imprime en pantalla la progresion numerica
			
		}
		
		number_med = number_sum/number_division; //Calcula la media
				
		printf("La media es %f \n" ,number_med); //Imprime en pantalla la media
		printf("La suma de todos es %f \n" ,number_sum); //Imprime en pantalla la suma de todos los elementos
	
		return 0;
}
