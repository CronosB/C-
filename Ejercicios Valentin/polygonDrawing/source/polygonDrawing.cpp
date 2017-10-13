#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;



struct polygon {

  int base;

  int height;

  const char *polygonType;

  bool **polygon;

};



bool isNumber ( const char **userArguments );

polygon *reserveMemory ( const char *typePolygon, const char *base, const char *height );

void freeMemory ( polygon *userPolygon );

bool checkData ( int argumentsLenght, const char *base, const char *height );

void choicePolygon ( polygon *userPolygon );

polygon *square ( polygon *userPolygon );

void drawPolygon ( polygon *userPolygon );




int main(int argc, char const *argv[]) {

  if ( checkData ( argc, argv[2], argv[3] ) ) {

    choicePolygon ( reserveMemory ( argv[1], argv[2], argv[3] ) );

  }

  return 0;

}



/*
 * Comprueba que el argumento pasado a al función sea un número.
 */


bool isNumber ( const char *word ){

  for ( unsigned int i = 0; i < strlen ( word ); i++) {

    if ( !isdigit ( word[i] ) ) {

      return false;

    }

  }

  return true;

}

/*
 * Pide memoria dinámica al sistema para crear la estructura. Una vez hecho eso asigna los arrays
 * correspondientes transformandolos en número, a las variables base y height. Después, con ellas, crear
 * crea un array de dos dimensiones para crear la figura elegida como typePolygon.
 */


polygon *reserveMemory ( const char *polygonType, const char *base, const char *height ) {

  polygon *userPolygon = NULL;

  userPolygon = new polygon;

  userPolygon->polygonType = polygonType;

  userPolygon->base = atoi ( base );

  userPolygon->height = atoi ( height );

  userPolygon->polygon = new bool*[userPolygon->base];


  for ( int i = 0; i < userPolygon->base; i++ ) {

    userPolygon->polygon[i] = new bool [userPolygon->height];

  }


  return userPolygon;

}



/*
 * Esta función libera la memoria dinámica utilizada.
 */


void freeMemory ( polygon *userPolygon ) {

  for ( int i = 0; i < userPolygon->base; i++ ) {

    delete [] userPolygon->polygon[i];

  }

  delete [] userPolygon->polygon;

  delete [] userPolygon;

}



/*
 * Esta función comprueba que la cantidad de argumentos introducidos son correctos y que los que
 * corresponden a la base y altura son números.
 */


bool checkData ( int argumentsLenght, const char *base, const char *height ) {

  if ( !( argumentsLenght == 4 ) ) {

    cout << "Has introducido más datos de los necesarios." << endl;

    return false;

  }

  if ( !isNumber ( base ) || !isNumber ( height ) ) {

    cout << "No has introducido números para calcular la figura." << endl;

    return false;

  }

  return true;

}



/*
 * Esta función realiza las operaciones con una función de polígono en concreto, según la opción elegida
 * por el usuario, la cual almacena en typePolygon.
 */


void choicePolygon ( polygon *userPolygon ) {

  char userPolygonType = 's';


  switch ( userPolygonType ) {


    case square:

      if ( userPolygon->base != userPolygon->height ) {

        cout << "Los dos lados deben ser iguales." << endl;

        break;

      }

      drawPolygon ( square ( userPolygon ) );

      break;


    case rectangle:

      if ( userPolygon->base == userPolygon->height ) {

        cout << "Los datos son los de un cuadrado, no de un rectángulo." << endl;

        break;

      }

      drawPolygon ( square ( userPolygon ) );

      break;


    case triangle:

      break;

  }

}



/*
 * Se adjudica a cada posición dentro del array un valor positivo o negativo para definir la figura
 * de un cuadrado.
 */


polygon *square ( polygon *userPolygon ) {

  for ( int i = 0; i <  userPolygon->base; i++ ) {

    for ( int j = 0; j < userPolygon->height; j++ ) {

		userPolygon->polygon[i][j] = false;

      if ( i == 0 || ( i + 1 ) == userPolygon->base ) {

        userPolygon->polygon[i][j] = true;

      }

      if ( j == 0 || ( j + 1 ) == userPolygon->height ) {

        userPolygon->polygon[i][j] = true;

      }

    }

  }

  return userPolygon;

}



/*
 * Dibuja el carácter elegido según los valores positivos recogidos en polygon.
 */



void drawPolygon ( polygon *userPolygon ) {

  for ( int i = 0; i < userPolygon->base; i++ ) {

    for ( int j = 0; j < userPolygon->height; j++ ) {

      if ( userPolygon->polygon[i][j] ) {

        cout << "* ";

      } else {

        cout << "  ";

      }

    }

    cout << endl;

  }

  freeMemory ( userPolygon );

}
