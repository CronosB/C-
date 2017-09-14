#include <iostream>
#include <string.h>

using namespace std;

int main ( int argc, char *argv [] ) {

//Declaración de variable y puntero: la primera indica la cantidad de argumentos pasados por el usuario, el segundo crea un array para almacenar la longitud de las cadenas de caracteres del usuario. El tercero y cuarto crea punteros a char para las cadenas al derecho y al reves.
  int numberArguments = argc - 1;

  int *lengthChains = new int [numberArguments];

  char **strings = new char *[numberArguments];

  char **reversedStrings = new char *[numberArguments];


//Esta sentencia asigna a lam atriz de int la longitud de cada cadena pasada por el usuario.

  for ( int i = 1; i <= numberArguments; i++ ) {

    lengthChains [i - 1] = strlen ( argv [i] );

  }

//Esta sentencia asigna una nueva dimension a ambas matrices de la cantidad correspondiente a la longitud de caracteres del usuario.

  for ( int i = 0; i < numberArguments; i++ ) {

    strings [i] = new char [lengthChains [i] + 1];

    reversedStrings [i] = new char [lengthChains [i] + 1];

  }


//Asigna cada argumento pasado por el usuario a la matriz strings

  for ( int i = 1; i <= numberArguments; i++ ) {

    strings [i - 1] = argv [i];

  }


//Esta sentencia asigna a reversedStrings los caracteres dados la vuelta de strings.

  for ( int i = 0; i < numberArguments; i++ ) {

    int h = 0;

    for ( int j = lengthChains [i] - 1; j >= 0; j-- ) {

      reversedStrings [i][h] = strings [i][j];

      h++;

    }

  }


//Esta sentencia muestra en pantallasss las cadenas de caracteres dadas ya la vuelta.

 for ( int i = 0; i < numberArguments; i++ ) {

   for (int j = 0; j < lengthChains [i]; j++ ) {

     cout << reversedStrings [i][j];

  }

  cout << endl;

 }


 for ( int i = 0; i < numberArguments; i++ ) {

   delete [] strings [i];

   delete [] reversedStrings [i];

 }

 delete [] strings;

 delete [] reversedStrings;

 delete [] lengthChains;

return 0;

}
