#include <iostream>


using namespace std;


unsigned long long factorial ( unsigned int originalNumber );

unsigned int getNumber ();



int main ( int argc, const char **argv ){
	
	
	cout << "Introduce un número." << endl;

	
	cout << factorial ( getNumber () ) << endl;
		
	
	return 0;
	
}


unsigned long long factorial ( unsigned int originalNumber ) {


	unsigned long long result = 1;
	
	int i = 1;

		
	while ( originalNumber != 0 ) {
		
		result = result * i;
		
		i++;
		
		originalNumber--;
		
	}	
	
	return result;	
		
}


unsigned int getNumber () {
	
	unsigned int number = 0;
	
	cin >> number;
	
	return number;

}
