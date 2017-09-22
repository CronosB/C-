#include <iostream>
#include <string.h>


using namespace std;


struct prototypeString {

  char *originalString;

  char *reversedString;

  int argumetsUsefullCount;

  int *lenghtString;

};


struct prototypeString *memoryRequest ( int argumentsCount );

void memoryRelease ( prototypeString *userString );



int main ( int argc, char *argv[] ) {


  prototypeString *userString = 0;

  userString = memoryRequest ( argc );

  memoryRelease ( userString );

  return 0;

}


struct prototypeString *memoryRequest ( int argumentsCount ) {

  prototypeString *userString = 0;

  int userUsefullArguments = argumentsCount - 1;


  userString = new prototypeString [ userUsefullArguments ];

  userString[0].argumetsUsefullCount = userUsefullArguments;


  return userString;

}


void memoryRelease ( prototypeString *userString ) {

//  int userUsefullArguments = userString[0].argumetsUsefullCount;

  delete [] userString;

}
