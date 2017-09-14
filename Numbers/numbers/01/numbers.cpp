#include <stdio.h>

int main () {
	
	float number_progresive = 0; // Variable para representar la progresión numerica.
	int number_division = 0; // Divisor para la media numérica.
	float number_sum = 0; // Suma de todos los números de la progresión.
	float number_med = 0; // Media de todos los números de la progresión.
	
	for (int i = 0; i < 10; i++) {
		
		number_progresive++;
		number_division++;
		number_sum += number_progresive;
		
		printf("%f.\n", number_progresive); // Imprime en pantalla la progresión numérica.
		
	}
	
	number_med = number_sum / number_division; // Calcula la media.
			
	printf("La media es %f.\n", number_med); // Imprime en pantalla la media.
	printf("La suma de todos es %f.\n", number_sum); // Imprime en pantalla la suma de todos los elementos.
	
	return 0;
	
}
