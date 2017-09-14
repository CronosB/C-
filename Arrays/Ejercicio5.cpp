#include <stdio.h>
#include <string.h>

bool palindrome(char* word);

int main(){
	
	const int NUMBER_LENGTH = 40;
	
	char wordEntry[NUMBER_LENGTH];
	
	bool isPalindrome;
	
	printf("Introduce una palabra, por favor. \n");
	
	scanf("%40s", wordEntry);
	
	isPalindrome = palindrome(wordEntry);

	if(isPalindrome){
		
		printf("Es un palíndromo");
	
	}
	else{
		
		printf("No es un palíndromo");
		
	}
		
	return 0;
	
}

bool palindrome(char* word){
	
	if (!word)
		return false;
	
	int wordLength = strlen(word);
	
	for(int i = 0, j = wordLength - 1; i < wordLength - 1; i++, j--){
		
		if (word[i] != word[j]) {
			
			return false;
			
		}
		
		if(i >= j){
			
			return true;
		}
		
	}
}
