#include <stdio.h>
#include <string.h>


int main () {

	const int PHONEBOOK_LENGTH = 2;

	const int NAME_LENGTH = 15;

	char option;


	struct phonebook {

		char name[15];

		unsigned int numberTelephone;

	};


	phonebook test_Phonebook[PHONEBOOK_LENGTH];



	printf ( "Bienvenido a la agenda, a continuación introducirás los datos correspondientes para operar. \n" );


	for ( int i = 0; i < PHONEBOOK_LENGTH; i++ ) {

		printf ( "Introduce un nombre. \n" );


		scanf ( "%15s", test_Phonebook[i].name );


		printf ( "Introduce su número de teléfono. \n" );


		scanf ( "%9d", &test_Phonebook[i].numberTelephone );


		}


	printf ( "Menú: Elige una de las siguientes opciones. \n a) Buscar por nombre. \n b) Buscar por número de teléfono. \n c) Salir. \n" );


	scanf ( "%1s", &option );


	switch ( option ) {

		case 'a':

		{

			char nameIndex[NAME_LENGTH];


			printf ( "Introduce un nombre: \n" );


			scanf ( "%15s", nameIndex );


			for ( int j = 0; j < PHONEBOOK_LENGTH; j++ ) {


				if ( strcmp ( nameIndex, test_Phonebook[j].name ) == 0 ) {

					printf ( "El número de teléfono de %s, es %d. \n", nameIndex, test_Phonebook[j].numberTelephone );

					break;

				}

			}

		break;

		}

		case 'b':

		{

		unsigned	int numberTelephoneIndex;


			printf ( "Introduce un número de teléfono: \n" );


			scanf ( "%9d", &numberTelephoneIndex );


			for ( int k = 0; k < PHONEBOOK_LENGTH; k++ ) {


				if ( numberTelephoneIndex == test_Phonebook[k].numberTelephone ) {

					printf( "El nombre a quien pertenece el número %d, es %s. \n", numberTelephoneIndex, test_Phonebook[k].name );

					break;

				}

			}

		break;

		}

		case 'c':

			printf( "Gracias por utilizarme.\n" );

	}

	return 0;

}
