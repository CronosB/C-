#include <iostream>
#include <stdlib.h>


using namespace std;


unsigned long long factorial ( unsigned int userNumber );


int main ( int argc, const char **argv ){

  unsigned int userNumber = 0;

  unsigned long long userFactorial = 0;


  cin >> userNumber;

  userFactorial = factorial ( userNumber );

  cout << userFactorial << endl;


  return 0;

}



unsigned long long factorial ( unsigned int userNumber ) {


  if ( userNumber == 0 ) {

    return 1;

  } else {

    return userNumber * factorial ( userNumber - 1 );

  }

}
