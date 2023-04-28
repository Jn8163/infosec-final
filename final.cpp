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

void vigenere_encrypt(string message, string key, char arr[][26]){

}

void vigenere_decrypt(string message, string key, char arr[][26]){

}

int main(){

        int input = -1;
        int shift = 0;
        string option = "";
        string message = "";

	char vigenere_arr[26][26];
	string key = "";

	// constructs array
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < 26; j++){
			vigenere_arr[i][j] = 'A' + i + j;
			while (vigenere_arr[i][j] > 90)
				vigenere_arr[i][j] -= 26;

			vigenere_arr[i][j] = tolower(vigenere_arr[i][j]);

			cout << vigenere_arr[i][j] << " ";
		}
		cout << endl;
	}

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

		// Vigenere
		if(input == 2){
			cout << "Enter your message (no spaces): ";
			cin >> message;
			for (int i = 0; i < message.length(); i++){
				message[i] = tolower(message[i]);
			}
                        cout << endl;

			while(key.length() != message.length()){
				cout << "Enter a key (must match the character length of the message): ";
				cin >> key;
				cout << endl << endl;

				if(key.length() != message.length())
					cout << "ERROR: KEY AND MESSAGE LENGTHS DO NOT MATCH" << endl << endl;
			}

			cout << "Encrypt or decrypt? (e/d)" << endl;
                        cin >> option;
                        cout << endl;

                        if(option == "e" || option == "E"){
                                vigenere_encrypt(message, key, vigenere_arr);
                        } else if(option == "d" || option == "D"){
                                vigenere_decrypt(message, key, vigenere_arr);
                        } else{
                                cout << "ERROR: NOT A VALID OPTION" << endl << endl;
                        }
		}


        }
        return 0;
}
