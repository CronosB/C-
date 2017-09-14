#include <stdio.h>

/*
 * Muestra línea a línea los números del 1 al 10, para a
 * continuación mostrar la suma y la media.
 */
int main () {
	
	/*
	 * Representa la progresión numerica.
	 */
	int number_progresive = 1;
		
	/*
	 * Suma de todos los números de la progresión.
	 */
	int number_sum = 0;
	
	/*
	 * Media de todos los números de la progresión.
	 */
	int number_avg = 0;
	
	/*
	 * Variable que contendrá el mayor número de la progresión.
	 */
	int number_max = 0;
	
	/* 
	 * Variable que contendrá el menor número de la progresión.
	 */	
	int number_min = 1;
	
	for (; number_progresive <= 10; number_progresive++) {
		
		number_sum += number_progresive;
		
		printf("%i.\n", number_progresive);
		
		/* 
		 * Comprueba si number_max contiene el mayor de la progresión, si no se lo asigna.
		 */
		if(number_max < number_progresive) number_max = number_progresive;
		
		/*
		 * Comprueba si number_min contiene el menor de la progresión, si no se lo asigna.
		 */
		if(number_min > number_progresive) number_min = number_progresive;
	}
	
	/*
	 * Cálculo de la media.
	 */
	number_avg = number_sum / number_progresive;
			
	printf("La media es %i.\n", number_avg);
	printf("La suma de todos es %i.\n", number_sum);
	printf("El mayor es %i.\n",number_max);
	printf("El menor es %i.\n",number_min);
	
	return 0;
	
}
