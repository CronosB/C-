#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;



struct polygon {

  int base;

  int height;

  bool **polygon;

};



bool isNumber ( const char **userArguments );

polygon *reserveMemory ( const char **userArguments );

void freeMemory ( polygon *userPolygon );

bool checkData ( int argumentsLenght, const char **userArguments );

void choicePolygon ( const char **userArguments );

polygon *square ( polygon *userPolygon );

void drawPolygon ( polygon *userPolygon );




int main(int argc, char const *argv[]) {

  if ( !checkData ( argc, argv ) ) {

    return 0;

  }

  choicePolygon ( argv );



  return 0;

}



bool isNumber ( const char **userArguments ){

  for ( unsigned int i = 0; i < strlen ( userArguments[2] ); i++) {

    if ( !isdigit ( userArguments[2][i] ) ) {

      return false;

    }

  }


  for ( unsigned int i = 0; i < strlen ( userArguments[3] ); i++) {

      if ( !isdigit ( userArguments[3][i] ) ) {

        return false;

      }

    }

  return true;

}



polygon *reserveMemory ( const char **userArguments ) {

  polygon *userPolygon = NULL;

  userPolygon->base = atoi ( userArguments[2] );

  userPolygon->height = atoi ( userArguments[3] );

  userPolygon->polygon = new bool*[userPolygon->base];


  for ( int i = 0; i < userPolygon->base; i++ ) {

    userPolygon->polygon[i] = new bool [userPolygon->height];

  }


  return userPolygon;

}



void freeMemory ( polygon *userPolygon ) {

  for ( int i = 0; i < userPolygon->base; i++ ) {

    delete [] userPolygon->polygon[i];

  }

  delete[] userPolygon->polygon;

}



bool checkData ( int argumentsLenght, const char **userArguments ) {

  if ( !( argumentsLenght == 4 ) ) {

    cout << "No has introducido los argumentos correctos" << endl;

    return false;

  }

  if ( !isNumber ( userArguments ) ) {

    cout << "No has introducido números para calcular la figura." << endl;

    return false;

  }

  return true;

}



void choicePolygon ( const char **userArguments ) {

  char userPolygonType = 's';


  switch ( userPolygonType ) {


    case 's':

      polygon *userPolygon = NULL;

      userPolygon = reserveMemory ( userArguments );

    //  drawPolygon ( square ( userPolygon ) );

    //  freeMemory ( userPolygon );

    break;

  }


}



polygon *square ( polygon *userPolygon ) {

  if ( userPolygon->base != userPolygon->height ) {

    cout << "Los dos lados deben ser iguales." << endl;

  }

  for ( int i = 0; i <  userPolygon->base; i++ ) {

    for ( int j = 0; j < userPolygon->base; j++ ) {

      if ( i == 0 || ( i + 1 ) == userPolygon->base ) {

        userPolygon->polygon[i][j] = true;

      }

      if ( j == 0 || ( j + 1 ) == userPolygon->base ) {

        userPolygon->polygon[i][j] = true;

      }

    }

  }

  return userPolygon;

}



void drawPolygon ( polygon *userPolygon ) {

  for ( int i = 0; i < userPolygon->base; i++ ) {

    for ( int j = 0; j < userPolygon->height; j++ ) {

      if ( userPolygon->polygon[i][j] ) cout << "* ";

    }

    cout << endl;

  }

}
