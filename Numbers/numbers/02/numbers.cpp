#include <stdio.h>

/*
 * Muestra línea a línea los números del 1 al 10, para a
 * continuación mostrar la suma y la media.
 */
int main () {
	
	/*
	 * Representa la progresión numerica.
	 */
	float number_progresive = 0;
	
	/*
	 * Divisor para la media numérica.
	 */
	int number_division = 0;
	
	/*
	 * Suma de todos los números de la progresión.
	 */
	float number_sum = 0;
	
	/*
	 * Media de todos los números de la progresión.
	 */
	float number_avg = 0;
	
	/*
	 * Variable que contendrá el mayor número de la progresión.
	 */
	float number_max = 0;
	
	/* 
	 * Variable que contendrá el menor número de la progresión.
	 */	
	float number_min = 0;
	
	for (int i = 0; i < 10; i++) {
		
		number_progresive++;
		number_division++;
		number_sum += number_progresive;
		
		printf("%g.\n", number_progresive);
		
		/* 
		 * Comprueba si number_max contiene el mayor de la progresión, si no se lo asigna.
		 */
		if(number_max < number_progresive) number_max = number_progresive;
		
		/*
		 * Comprueba si number_min contiene el menor de la progresión, si no se lo asigna.
		 */
		if(number_min > number_progresive || number_progresive == 1) number_min = number_progresive;
	}
	
	/*
	 * Cálculo de la media.
	 */
	number_avg = number_sum / number_division;
			
	printf("La media es %g.\n", number_avg);
	printf("La suma de todos es %g.\n", number_sum);
	printf("El mayor es %g.\n",number_max);
	printf("El menor es %g.\n",number_min);
	
	return 0;
	
}
