#include <stdio.h>

int main(){
	
	const int NUMBERS_LENGTH1 = 5;
	
	const int NUMBERS_LENGTH2 = 5;
	
	int table[NUMBERS_LENGTH1][NUMBERS_LENGTH2];
	
	printf("Por favor introduce 5 valores por columna. \n Estos se representarán en columnas y se sumarán las mismas así como las filas \n");

/*
 * Esta sentencia recoge los 25 valores repartidos en columnas para el array.
 * 
 */

	for(int i = 0; i < NUMBERS_LENGTH1; i++){
		
		int numbercolumn = i + 1;
		
		printf("Columna %d. \n", numbercolumn);
		
		for(int j = 0; j < NUMBERS_LENGTH2; j++){
			
			scanf("%d", &table[i][j]);
		}
	}
	
/*
 * Esta sentencia imprime los valores correspondientes al array repartidos en columnas.
 * 
 */

	for(int k = 0; k < NUMBERS_LENGTH1; k++){
		
		int numbercolumn = k + 1;
		printf("Columna %d. \n", numbercolumn);
		
		for(int l = 0; l < NUMBERS_LENGTH2; l++){
			
			printf("%d. \n", table[k][l]);
		}
	}

/*
 * Esta sentencia suma los valores correspondientes a cada columna e imprime los resultados.
 * 
 */
	
	for(int m = 0; m < NUMBERS_LENGTH1; m++){
		
		int numbercolumn = m + 1;
		
		int sumcolumn = 0;
		
		printf("La suma de la columna %d. es ", numbercolumn);
		
		for(int n = 0; n < NUMBERS_LENGTH2; n++){
			
			sumcolumn += table[m][n];
		}
		
		printf("%d. \n", sumcolumn);
	}

/*
 * Esta sentencia suma las filas correspondientes e imprime dichas sumas.
 * 
 */
	
	for(int o = 0; o < NUMBERS_LENGTH2; o++){
		
		int numberarrow = o + 1;
		
		int sumarrow = 0;
		
		printf("La suma de la fila %d. es ",numberarrow);
		
		for(int p = 0; p < NUMBERS_LENGTH1; p++){
			
			sumarrow += table[p][o];
		}
		
		printf("%d. \n", sumarrow);
	}
	return 0;
}
