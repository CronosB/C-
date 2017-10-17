#include <iostream>


using namespace std;


int main ( int argc, const char **argv ){
	
	
	unsigned long long numberResult = 1;
	
	unsigned int numberControl = 0;
	
	int i = 1;
	
	
	cout << "Introduce un número." << endl;
	
	
	cin >> numberControl;
	
	
	while ( numberControl != 0 ) {
		
		numberResult = numberResult * i++;
		
		numberControl--;
		
	}
	
	
	cout << numberResult << endl;
		
	
	return 0;
	
}

