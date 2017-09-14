#include <iostream>
#include <string.h>


using namespace std;

void screenOut ( int argumentsCount, char **string );

void reversedArguments ( int argumentsCount, char **string );


int main ( int argc, char *argv[] ) {


  screenOut ( argc, argv );

  reversedArguments ( argc, argv );


  return 0;

}



void screenOut ( int argumentsCount, char **string ) {

  for ( int i = 1; i < argumentsCount; i++ ) {

    cout << string[i] << endl;

  }

}


void reversedArguments ( int argumentsCount, char **string ) {

  char **reversedString = new char *[argumentsCount];

  int *lenghtString = new int [argumentsCount];


  for( int i = 0; i < argumentsCount; i++ ) {

    lenghtString [i] = strlen ( string [i] );

  }

  for ( int i = 0; i < argumentsCount; i++ ) {

    reversedString [i] = new char [lenghtString[i]];

  }


  for ( int i = 0; i < argumentsCount; i++ ) {

    for ( int j = 0; j < lenghtString [i]; j++ ) {

      reversedString [i][j] = string [i][lenghtString [i] - ( j + 1 )];

    }

  }

  screenOut ( argumentsCount, reversedString );


  for( int i = 0; i < argumentsCount; i++ ) {

    delete [] reversedString [i];

  }

  delete [] lenghtString;

  delete [] reversedString;

}
