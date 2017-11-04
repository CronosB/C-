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



enum polygonList {

  squarePolygon,

  rectanglePolygon,

  trianglePolygon,

  error

};




bool isNumber ( const char **userArguments );

polygon *reserveMemory ( const char *polygonType, const char *base, const char *height );

void freeMemory ( polygon *userPolygon );

bool checkData ( int argumentsLenght, const char *base, const char *height );

void choicePolygon ( polygon *userPolygon );

void square ( polygon *userPolygon );

void drawPolygon ( polygon *userPolygon );

polygonList searchPolygon ( const char *typePolygon );

void triangle ( polygon *userPolygon );




int main ( int argc, char const *argv[] ) {

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

  userPolygon->polygon = new bool*[userPolygon->height];


  for ( int i = 0; i < userPolygon->height; i++ ) {

    userPolygon->polygon[i] = new bool [userPolygon->base];

  }


  return userPolygon;

}



/*
 * Esta función libera la memoria dinámica utilizada.
 */


void freeMemory ( polygon *userPolygon ) {

  for ( int i = 0; i < userPolygon->height; i++ ) {

    delete [] userPolygon->polygon[i];

  }

  delete [] userPolygon->polygon;

  delete userPolygon;

}



/*
 * Esta función comprueba que la cantidad de argumentos introducidos son correctos y que los que
 * corresponden a la base y altura son números.
 */


bool checkData ( int argumentsLenght, const char *base, const char *height ) {

  if ( !( argumentsLenght == 4 ) ) {

    cout << "Introduce el polígono a dibujar (square, rectangle, triangle), su base y altura para dibujarlo." << endl;

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


  switch ( searchPolygon ( userPolygon->polygonType ) ) {


    case squarePolygon:

      if ( userPolygon->base != userPolygon->height ) {

        cout << "Los dos lados deben ser iguales." << endl;

        square ( userPolygon );

        drawPolygon ( userPolygon );

        break;

      }

      square ( userPolygon );

      drawPolygon ( userPolygon );

      break;


    case rectanglePolygon:

      if ( userPolygon->base == userPolygon->height ) {

        cout << "Los datos son los de un cuadrado" << endl;

        square ( userPolygon );

        drawPolygon ( userPolygon );

        break;

      }

      square ( userPolygon );

      drawPolygon ( userPolygon );

      break;


    case trianglePolygon:

      if ( userPolygon->base != ( userPolygon->height * 2 ) ) {

        cout << "La base debe de ser el doble de la altura" << endl;

        break;

      }

      triangle ( userPolygon );

      drawPolygon ( userPolygon );

      break;


    case error:

      cout << "No has introducido una figura correcta." << endl;

      break;

  }

}



/*
 * Se adjudica a cada posición dentro del array un valor positivo o negativo para definir la figura
 * de un cuadrado.
 */


void square ( polygon *userPolygon ) {

  for ( int i = 0; i <  userPolygon->height; i++ ) {

    for ( int j = 0; j < userPolygon->base; j++ ) {

		userPolygon->polygon[i][j] = false;

      if ( i == 0 || ( i + 1 ) == userPolygon->height ) {

        userPolygon->polygon[i][j] = true;

      }

      if ( j == 0 || ( j + 1 ) == userPolygon->base ) {

        userPolygon->polygon[i][j] = true;

      }

    }

  }

}



/*
 * Dibuja el carácter elegido según los valores positivos recogidos en polygon.
 */


void drawPolygon ( polygon *userPolygon ) {

  for ( int i = 0; i < userPolygon->height; i++ ) {

    for ( int j = 0; j < userPolygon->base; j++ ) {

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



/*
 * Compara la cadena de carácteres que introdujo el usuario en el segundo argumento con la lista de
 * polígonos validos y devuelve su posición dentro del enum.
 */


polygonList searchPolygon ( const char *userPolygonChoice ) {

  if ( strcmp ( userPolygonChoice, "square" ) == 0 ) {

    return squarePolygon;

  }

  if ( strcmp ( userPolygonChoice, "rectangle" ) == 0 ) {

    return rectanglePolygon;

  }

  if ( strcmp ( userPolygonChoice, "triangle" ) == 0 ) {

    return trianglePolygon;

  }

  return error;

}


void triangle ( polygon *userPolygon ) {

  int vertex = userPolygon->base / 2;

  int j = 0;

  for ( int i = 0; i < userPolygon->height; i++ ) {

    if ( i == 0 ) {

      userPolygon->polygon[i][vertex] = true;

    } else {

      userPolygon->polygon[i][vertex + j] = true;

      userPolygon->polygon[i][vertex - j] = true;

    }

    if ( ( i + 1 ) == userPolygon->height ) {

      for ( int l = vertex - j; l < userPolygon->base; l++ ) {

        userPolygon->polygon[i][l] = true;

      }

    }

    j++;



  }

}
