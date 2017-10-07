#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


void printScreen ( const char **argument );
bool checkArgument ( const char **argument );
bool **square ( int size );
void deleteSquare ( int size, bool **square );


int main(int argc, char const *argv[]) {


  if ( !( argc == 2 ) ) {

    cout << "Introduce un tamaño." << endl;

    return 0;

  }

  if ( checkArgument ( argv ) ) {

    printScreen ( argv );

  } else {

    cout << "No has introducido un número" << endl;

  }


  return 0;

}



void printScreen ( const char **argument ) {

  int size = atoi ( argument[1] );

  bool **polygon = square ( size );


  for ( int i = 0; i < size; i++ ) {

    for (int j = 0; j < size; j++) {

      if ( polygon[i][j] ) {

        cout << "o ";

      } else {

        cout << "  ";

      }

    }

    cout << endl;

  }

  deleteSquare ( size, polygon );

}



bool checkArgument ( const char **argument ){

  bool check = true;

  for ( unsigned int i = 0; i < strlen ( argument[1] ); i++) {

    if ( !isdigit ( argument[1][i] ) ){

      check = false;

      break;

    }

  }

  return check;

}



bool **square ( int size ) {

  bool **check = new bool*[size];

  for (int i = 0; i < size; i++) {

    check[i] = new bool[size];

  }

  for ( int i = 0; i < size; i++) {

    for ( int j = 0; j < size; j++) {

      if ( i == 0 || ( i + 1 ) == size ) {

        check[i][j] = true;

      } else {

        if ( j == 0 || ( j + 1 ) == size ) {

          check[i][j] = true;

        } else {

          check[i][j] = false;

        }

      }

    }

  }

  return check;

}



void deleteSquare ( int size, bool **square ) {

  for ( int i = 0; i < size; i++) {

    delete [] square[i];

  }

  delete [] square;

}
