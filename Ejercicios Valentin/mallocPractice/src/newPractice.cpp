#include <iostream>
#include <cstring>
#include <stdlib.h>


using namespace std;


bool checkData ( int argc );
char *reserveMemory ( char const *argument );
void freeMemory ( char *pChar );


int main ( int argc, char const *argv[] ) {

  if ( !checkData ( argc ) ) {

    return 0;

  }


  char *pChar = reserveMemory ( argv[1] );


  strcpy ( pChar, argv[1] );


  cout << pChar << endl;


  delete pChar;

  return 0;

}



bool checkData ( int argc ) {

  if ( argc != 2 ) {

    cout << "Introduce un único argumento" << endl;

    return false;

  }

  return true;

}



char *reserveMemory ( char const *argument ) {

  char *pChar = new char;

  return pChar;

}
