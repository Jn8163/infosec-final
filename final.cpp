#include <iostream>
#include <string>

using namespace std;

void caesar_encrypt(string message, int shift){

	int len = message.length();

	for (int i = 0; i < len; i++){
		message[i] += shift;
		// ensures letters wrap back around
		if (message[i] > 122)
			message[i] -= 26;
	}

	cout << "Encoded text: " << message;
	cout << endl << endl;
}

void caesar_decrypt(string message, int shift){

	int len = message.length();

	for (int i = 0; i < len; i++){
		message[i] -= shift;

		if (message[i] < 97)
			message[i] += 26;
	}

	cout << "Decoded text: " << message;
	cout << endl << endl;
}

int main(){

        int input = -1;
        int shift = 0;
        string option = "";
        string message = "";

        while(input != 0){

                cout << "     CHOOSE A CIPHER     " << endl;
                cout << "-------------------------" << endl;
                cout << "1. Caesar" << endl;
                cout << "2. Vigenere" << endl;
                cout << "0. Exit" << endl << endl;

                cout << "Enter value here: ";

                cin >> input;
                cout << endl;

                // Caesar
                if(input == 1){
                        cout << "How many spaces do you want to shift by?" << endl;
                        cin >> shift;
                        cout << endl;

                        cout << "Enter message (no spaces): ";
                        cin >> message;
			for (int i = 0; i < message.length(); i++){
				message[i] = tolower(message[i]);
			}
                        cout << endl;

                        cout << "Encrypt or decrypt? (e/d)" << endl;
                        cin >> option;
                        cout << endl;

                        if(option == "e" || option == "E"){
                                caesar_encrypt(message, shift);
                        } else if(option == "d" || option == "D"){
                                caesar_decrypt(message, shift);
                        } else{
                                cout << "ERROR: NOT A VALID OPTION" << endl << endl;
                        }
                }
        }
        return 0;
}
