#include <iostream>
#include <string.h>



using namespace std;



struct stringsEntry {

  int lenghtString;

  char *originalString;

  char *finalString;

};


struct strings {

  int userUsefullArguments;

  stringsEntry *userStringsEntry;

};



strings memoryRequest ( int argumentsCount, char **arguments );

void memoryRelease ( strings userStrings );

strings reverseString ( strings userStrings );

void printScreen ( strings userStrings );



int main ( int argc, char *argv[] ) {

  if ( argc == 1 ) {

    cout << "No has introducido ningún argumento" << endl;

    return 0;

  }

  strings userStrings;


  userStrings = reverseString ( memoryRequest ( argc , argv ) );

  printScreen ( userStrings );

  memoryRelease ( userStrings );



  return 0;

}



/*
  Esta función pide memoria al sistema y asigna al array dentro del struct los
  valores introducidos por el usuario.
*/


strings memoryRequest ( int argumentsCount, char **arguments ) {

  strings userStrings;

  userStrings.userUsefullArguments = argumentsCount - 1;

  userStrings.userStringsEntry = new stringsEntry [ userStrings.userUsefullArguments ];


  for ( int i = 0; i < userStrings.userUsefullArguments; i++ ) {

    userStrings.userStringsEntry[i].lenghtString = strlen ( arguments[i + 1] );

  }

  for ( int i = 0; i < userStrings.userUsefullArguments; i++ ) {

    userStrings.userStringsEntry[i].originalString = new char [ userStrings.userStringsEntry[i].lenghtString + 1 ];

    userStrings.userStringsEntry[i].finalString = new char [ userStrings.userStringsEntry[i].lenghtString + 1 ];

  }

  for ( int i = 0; i < userStrings.userUsefullArguments; i++ ) {

    strcpy ( userStrings.userStringsEntry[i].originalString, arguments[i + 1] );

  }

  return userStrings;

}



/*
Esta función libera la memoria pedida al sistema.
*/

void memoryRelease ( strings userStrings ) {

  for ( int i = 0; i < userStrings.userUsefullArguments; i++ ) {

    delete [] userStrings.userStringsEntry[i].originalString;

    delete [] userStrings.userStringsEntry[i].finalString;

  }

  delete [] userStrings.userStringsEntry;

}



/*
Esta función asigna a la inversa las cadenas de caracteres introducidas por el usuario
a finalString.
*/

strings reverseString ( strings userStrings ) {

  for ( int i = 0; i < userStrings.userUsefullArguments; i++ ) {

    for ( int j = 0; j < userStrings.userStringsEntry[i].lenghtString; j++ ) {

      if ( j + 1 == userStrings.userStringsEntry[i].lenghtString ) {

        userStrings.userStringsEntry[i].finalString[j + 1] = '\000';

      }

      userStrings.userStringsEntry[i].finalString[j] =
        userStrings.userStringsEntry[i].originalString[ userStrings.userStringsEntry[i].lenghtString - 1 - j];

    }

  }

  return userStrings;

}



/*
Esta función imprime en pantalla los arrays que contienen las las cadenas de caracteres
originales del usuario y las que estan ya dadas la vuelta.
*/


void printScreen ( strings userStrings ) {

  for ( int i = 0; i < userStrings.userUsefullArguments; i++ ) {

    cout << userStrings.userStringsEntry[i].originalString << endl;

    cout << userStrings.userStringsEntry[i].finalString << endl;

  }

}
