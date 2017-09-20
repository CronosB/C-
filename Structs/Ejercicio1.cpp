#include <stdio.h>
#include <string.h>


struct phonebook {

	int numberEntries;

	char name [15];

	int number;

};



void menu ();

bool checkOption ( char option );

void texts ( char choiceText );

void releaseBufferInput ();

struct phonebook *dataEntry ();

void searchNumber ( struct phonebook *userPhonebook );

void searchName ( struct phonebook *userPhonebook );



int main () {

	menu ();

	return 0;

}


//Esta función genera el menú y permite al usuario elegir la opción que corresponda.

void menu () {

	char userOption = 0;

	bool checkUserOption = false;

	phonebook *userPhonebook = 0;

	bool checkUsed = false;


	while ( userOption != 'q' ) {

		texts ( 'm' );

		userOption = getchar ();

		releaseBufferInput ();

		checkUserOption = checkOption ( userOption );


	//Este bucle comprueba el valor introducido por el usuario mediante el valor ansi de cada caracter.

		while ( checkUserOption ) {

			texts ( 'e' );

			userOption = getchar ();

			releaseBufferInput ();

			checkUserOption = checkOption ( userOption );

		}


		switch ( userOption ) {

			case 'a':

				if ( checkUsed == false ) {

					userPhonebook = dataEntry ();

					checkUsed = true;

					break;

			}

			else {

				texts ( 'u' );

				break;

			}


			case 'b':

				if ( checkUsed ) {

					searchNumber ( userPhonebook );

					break;

				}

				else {

					texts ( 'z' );

					break;

				}


			case 'c':

				if ( checkUsed ) {

					searchName ( userPhonebook );

					break;
				}

				else {

					texts ( 'z' );

					break;

				}


			case 'q':

				texts ( 'g' );

				if ( checkUsed ) {

					delete [] userPhonebook;

				}

				break;

		}

	}

}

//Comprueba que la variable pasada a la función sea: "a", "b", "c" o "q" con sus valores correspondientes en ANSI.

bool checkOption ( char option ) {

	bool check = false;

	check = (

			option != 97 &&
			option != 98 &&
			option != 99 &&
			option != 113

		);

	return check;

}


/*Esta función imprime en pantalla el texto elegido:
"m" para el menú,
"e" para el mensaje de error al introducir mal un caracter,
"g" para la despedida,
"d" para el mensaje de cantidad de argumentos para la agenda,
"l" para el mensaje de introducción de nombre,
"n" para el mensaje de introducción de número,
"u" para indicar que ya se introdujeron datos al struct phonebook y
"z" para informar que no se han introducido datos.
*/

void texts ( char choiceText ) {


	switch ( choiceText ) {

		case 'm' :

			printf ( "Elige una de las siguientes opciones: \n a) Agregar números. \n b) Busca por nombre. \n c) Busca por número. \n q) Salir. \n \n" );

			break;


		case 'e' :

			printf ( "Has introducido una opción incorrecta, por favor vuelve a intentarlo. \n" );

			break;


		case 'g' :

			printf ( "Gracias por utilizarme. \n" );

			break;


		case 'd' :

			printf ( "Indica la cantidad de nombres y números que quieres añadir, por favor. \n" );

			break;


		case 'l' :

			printf ( "Introduce un nombre. \n" );

			break;


		case 'n' :

			printf ( "Introduce un número. \n" );

			break;


		case 'u' :

			printf ( "Ya has introducido los datos. \n" );

			break;


		case 'z' :

			printf ( "No has introducido ningún dato. \n" );

			break;

	}

}


//Esta función vacía el buffer de entrada de posibles caracteres que añada el usuario a mayores y del salto de linea.

void releaseBufferInput () {

	char checkGetChar = 0;

	do

		checkGetChar = getchar();

	while ( checkGetChar != '\n' && checkGetChar != EOF );

}


//Esta función recoge la cantidad de datos que introducirá el usuario y los correspondientes nombres y números.

struct phonebook *dataEntry () {

	int numberEntries = 0;



	texts ( 'd' );

	scanf ( "%d", &numberEntries);

	releaseBufferInput ();


	phonebook *userPhonebook = 0;

	userPhonebook = new phonebook [numberEntries];


	userPhonebook[0].numberEntries = numberEntries;


	for ( int i = 0; i < numberEntries; i++ ) {

		texts ( 'l' );

		scanf ( "%15s", userPhonebook[i].name );

		releaseBufferInput ();


		texts ( 'n' );

		scanf ( "%9d", &userPhonebook[i].number );

		releaseBufferInput ();

	}

	return userPhonebook;

}



//Esta función compara dentro del array del struct el campo del nombre con el nombre que introduce el usuario e imprime el número de la misma posición dentro de ese array.

void searchNumber ( struct phonebook *userPhonebook ) {

	int numberEntries = userPhonebook[0].numberEntries;

	char name[15];


	texts ( 'l' );


	scanf ( "%15s", name );

	releaseBufferInput ();


	for ( int i = 0; i < numberEntries; i++ ) {

	 if ( strcmp ( name, userPhonebook[i].name ) == 0 ) {

		 printf ( "El número correspondiente a %s es el %d. \n", userPhonebook[i].name, userPhonebook[i].number );

	 }

	}

}



//Esta función compara dentro del array del struct el campo del número con el número que introduce el usuario e imprime el nombre de la misma posición dentro de ese array.

void searchName ( struct phonebook *userPhonebook ) {

	int numberEntries = userPhonebook[0].numberEntries;

	int number;


	texts ( 'n' );


	scanf ( "%d", &number );

	releaseBufferInput ();


	for ( int i = 0; i < numberEntries; i++ ) {

		if ( number == userPhonebook[i].number ) {

			printf ( "El nombre correspondiente al número %d, es de %s. \n", number, userPhonebook[i].name );

		}

	}

}
