#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This method advances the letters by 'k', the size of the shift */
char encryptShift(int k, char c) {
	char character;
	int temp = (int) c;
	temp += k;
	//This wraps the letter if it goes beyond 'Z' value of 90, to restart at 'A'
	if(temp > 90) {
		int i = temp - 90;
		i += 64;
		temp = i;
	}
	character = (char) temp;
	//Returns the encrypted character
	return character;
}
/* This method converts the encrypted letters back to the original letter */
char decryptShift(int k, char c) {
	char character;
	int temp = (int) c;
	temp -= k;
	//If the shifted letter is below 'A' value of 65, then wraps to 'Z'
	if(temp < 65) {
		int i = 65 - temp;
		i = 91 - i;
		temp = i;
	}
	character = (char) temp;
	//Returns the unencrypted 
	return character;
}
/*The encrypt method takes in the amount of the shift (key) and the user string
and encrypts the message */
void encrypt(int key, char userString[]) {
	//Gets the length of the user string
	int x = strlen(userString);
	int i;
	for(i = 0; i < x; i++) {
		//Gets the character at index 'i' in the user string array
		char character = userString[i];
		//Prints the unencrypted letter
		printf("unencrypted letter: %c | ", character); 
		if (character != ' ') {
			//If the character is not a whitespace, then call the encryptShift method
			//The encrypted letter is returned and stored in variable 'character'
			character = encryptShift(key, character);
			//The unencrypted letter is replaced with the encrypted letter in the array
			userString[i] = character;
			//Prints the encrypted letter
			printf("encrypted to letter: %c\n", character);
		}else{
			//If the letter was a whitespace, then simply print it verbatim
			printf("encrypted to letter: %c\n", character);
		}
	}
	//Prints the encrypted message
	printf("Output text: %s\n", userString);
}
/*The decrypt method takes in the amount of the shift (key) and the user string
and unencrypts the message */
void decrypt(int key, char userString[]) {
	//Gets the length of the user string
	int x = strlen(userString);
	int i;
	for(i = 0; i < x; i++) {
		//Gets the character at index 'i' in the user string array
		char character = userString[i];
		//Prints the encrypted letter
		printf("encrypted letter: %c | ", character);
		if (character != ' ') {
			//If the character is not a whitespace, then call the decryptShift method
			//The unencrypted letter is returned and stored in variable 'character'
			character = decryptShift(key, character);
			//The encrypted letter is replaced with the unencrypted letter in the array
			userString[i] = character;
			//Prints the unencrypted letter
			printf("unencrypted to letter: %c\n", character);
		}else{
			//If the letter was a whitespace, then simply print it verbatim
			printf("unencrypted to letter: %c\n", character);
		}
	}
	//Prints the unencrypted message
	printf("Output text: %s\n", userString);
}



int main( int argc, char *argv[] ) {
	//If the number of command line arguments isn't 3, then print error 
	if(argc != 3) {
		printf("Error, wrong number of input arguments.\n");

		return -1;
	}
	//Converts the string of the amount of shift (key) to integer type 
	int key = atoi(argv[1]);
	//The third element in the argv array is either 'd' or 'e' and is stored in mode
	char mode = *argv[2];
	//Prints the substitution key value
	printf("Substitution key is set to %d\n", key);
	//Creates an array to store the user string
	char userString[100];
	//The fgets method stores the entire line of user input...
	//into the userString array, (including whitespaces)
	fgets(userString, 100, stdin);
	//The strtok method is used to remove the \n character at end of string
	strtok(userString, "\n"); 
	printf("Input text supplied is: %s\n", userString);

	//If user entered 'e', then call the encrypt method and pass in the arguments
	if(mode == 'e') {
		encrypt(key, userString);
	}
	//If the user entered 'd', then call the decrypt method and pass in the arguments
	else if(mode == 'd') {
		decrypt(key, userString);
	}
	//If the user entered some other input other than 'd' or 'e', terminate program
	else {
		printf("Error: Please enter 'd' or 'e' for the key.\n");
		return -1;
	}

	return 0;

}
