#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;



struct numbersEntry {

  long int originalNumber;

  long int squaredNumber;

  long int cubeNumber;

};


struct numbers {

	int userUsefullArguments;

	bool *check;

	numbersEntry *userNumbersEntry;

};


numbers assignArguments ( int argumentsCount, const char **arguments );

void releaseMemory ( numbers userNumbers );

long int square ( long int number );

long int cube ( long int number );

numbers operations ( numbers userNumbers );

void printScreen ( numbers userNumbers );

long int conversion ( char *argument );

bool *entryDataCheck ( int argumentsCount, const char **arguments );




int main ( int argc, char const *argv[] ) {

	
	if ( argc == 1 ) {

		cout << "No has introducido ningún argumento." << endl;

		return 0;

	}
  


	numbers userNumbers;


	userNumbers = operations ( assignArguments ( argc, argv ) );

	printScreen ( userNumbers );

	releaseMemory ( userNumbers );


	return 0;

}



/*
  Esta función pide memoria dinámica al sistema y asigna los argumentos
  introducidos por el usuario a originalNumber.
*/

numbers assignArguments ( int argumentsCount, const char **arguments ) {

	numbers userNumbers;
	
	userNumbers.userUsefullArguments = argumentsCount - 1;

	userNumbers.userNumbersEntry = new numbersEntry [userNumbers.userUsefullArguments];

	userNumbers.check = entryDataCheck ( argumentsCount, arguments );
	
	for ( int i = 0; i < userNumbers.userUsefullArguments; i++ ) {
	  
		if ( userNumbers.check ) {

			//Se le suma uno a arguments para obviar el nombre del programa.
		
			userNumbers.userNumbersEntry[i].originalNumber = atol (arguments[i + 1]);
			
		}
	
	}

  return userNumbers;

}



/*
  Esta función libera la memoria pedida al sistema.
*/

void releaseMemory ( numbers userNumbers ) {

	delete [] userNumbers.userNumbersEntry;

	delete [] userNumbers.check;
	
}



/*
  Esta función devuelve el cuadrado del número que se le pasa
*/

long int square ( long int number ) {

  return number * number;

}


/*
  Esta función devuelve el cubo del número que se le pasa
*/

long int cube ( long int number ) {

  return number * number * number;

}



/*
  Esta función asigna los números elevados al cuadrado y al cubo a sus respectivas variables.
*/

numbers operations ( numbers userNumbers ) {

  for ( int i = 0; i < userNumbers.userUsefullArguments; i++ ) {

	if ( userNumbers.check[i] ) {

		userNumbers.userNumbersEntry[i].squaredNumber =

		square ( userNumbers.userNumbersEntry[i].originalNumber );

		userNumbers.userNumbersEntry[i].cubeNumber =

		cube ( userNumbers.userNumbersEntry[i].originalNumber );

	}

  }

  return userNumbers;

}


/*
  Esta función imprime en pantalla los números originales y los elevados.
*/

void printScreen ( numbers userNumbers ) {

	for ( int i = 0; i < userNumbers.userUsefullArguments; i++ ) {

		if ( userNumbers.check[i] ) {
		
			cout << userNumbers.userNumbersEntry[i].originalNumber << endl;

			cout << userNumbers.userNumbersEntry[i].squaredNumber << endl;

			cout << userNumbers.userNumbersEntry[i].cubeNumber << endl;

		} else {
			
			cout << "Este número no es valido." << endl;
			
		}

		if ( i + 1 != userNumbers.userUsefullArguments ) cout << endl;

  }

}



/*
 * Esta función comprueba que se introducen números y no otros carácteres.
 * 
*/

bool *entryDataCheck ( int argumentsCount, const char **arguments ) {
	
	int usefullArguments = argumentsCount - 1;
	
	int *argumentLength = new int [usefullArguments]; 
	
	bool *check = new bool [usefullArguments];
	
	
	/*
	 * Inicio ambas iteraciones en 1 para ignorar el primer argumento que es el del
	 * propio programa. Además resto otro 1 a argumentLength y check para que inicien desde
	 * la posición cero.
	 */
	
	for ( int i = 1; i < argumentsCount; i++ ) {
		
		argumentLength[i - 1] = strlen ( arguments[i] );
		
	}
	
	
	for ( int i = 1; i < argumentsCount; i++ ) {
		
		for ( int j = 0; j < argumentLength[i - 1]; j++ ) {
			
			if ( arguments[i][j] < 48 || arguments[i][j] > 57 ) {
				
				check[i - 1] = false;
				
				break;
				
			} else {
				
				check[i - 1] = true;
				
			}
			
		}
		
	}
	

	delete [] argumentLength;


	return check;
	
}
