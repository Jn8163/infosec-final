//#include <iostream>
//#include <string>
//#include <map>
#include<bits/stdc++.h>

using namespace std;

map<int, int> keyMap;

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

	int len = message.length();

	int index1 = 0;
	int index2 = 0;
	char new_message[len];

	cout << "Encrypted text: ";

	for (int i = 0; i < len; i++){
		index1 = message[i] - 97;
		index2 = key[i] - 97;

		new_message[i] = arr[index1][index2];
		cout << new_message[i];
	}

	cout << endl << endl;

}

void vigenere_decrypt(string message, string key, char arr[][26]){

	int len = message.length();

	int index1 = 0;
	int index2 = 0;
	char new_message[len];

	cout << "Decrypted text: ";

	for (int i = 0; i < len; i++){
		index1 = key[i] - 97;
		index2 = message[i] - 97;

		for(int j = 0; j < 26; j++){
			if(arr[index1][j] == message[i])
				cout << arr[0][j];
		}
	}

	cout << endl << endl;

}

void keyAssign(string key){

}

void columnar_encrypt(string message, string key){

	for(int i = 0; i < key.length(); i++){
		keyMap[key[i]] = i; // permutates key map
	}

	string text = "";
	int len = message.length();
	int width = key.length();
	int height = len/width;
	int j;

	if(len % width != 0)
		height++;

	char arr[height][width];
	int counter = 0;

	// creates grid
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(counter >= len){
				arr[i][j] = 'X';
				cout << arr[i][j] << " ";
			}
			else{
				arr[i][j] = message[counter];
				cout << arr[i][j] << " ";
			}

			counter++;
		}
		cout << endl << endl;
	}

	for(map<int,int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii){
		j=ii->second;
		for(int i = 0; i < height; i++){
	//		cout << arr[i][j];
			text += arr[i][j];
		}
		cout << endl;
	}
	cout << text;

	// encryption loop (goes from bottom left to top right of grid)
/*	for(int j = 0; j < width; j++){
		for(int i = height - 1; i >= 0; i--){
			if(arr[i][j] != ' ')
				cout << arr[i][j];

		}
	}*/
	cout << endl;
}

void columnar_decrypt(string message, string key){

	for(int i = 0; i < key.length(); i++){
		keyMap[key[i]] = i; // permutates key map
	}

	int len = message.length();
	int width = key.length();
	int height = len/width;
	int tmp = 0;

	if(len % width != 0)
		height++;

	char arr[height][width];
	int counter = 0;

	// creates grid
	for(int j = 0; j < width; j++){
		for(int i = 0; i < height; i++){
			if(counter >= len){
				arr[i][j] = ' ';
				cout << arr[i][j] << " ";
			}
			else{
				arr[i][j] = message[counter];
				cout << arr[i][j] << " ";
			}

			counter++;
		}
		cout << endl << endl;
	}

	for(map<int,int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii){
		ii->second = tmp++;
	}

	char matrix[height][width];
	map<int,int>::iterator ii = keyMap.begin();
	tmp = 0;
	for(int l = 0, j = 0; key[l] != '\0'; tmp++){
		j = keyMap[key[l++]];
		for(int i = 0; i < height; i++){
			matrix[i][tmp] = arr[i][j];
		}
	}

	// printer
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			cout << matrix[i][j];
		}
	}
	cout << endl;
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

//			cout << vigenere_arr[i][j] << " ";
		}
//		cout << endl;
	}


        while(input != 0){

                cout << "     CHOOSE A CIPHER     " << endl;
                cout << "-------------------------" << endl;
                cout << "1. Caesar" << endl;
                cout << "2. Vigenere" << endl;
		cout << "3. Columnar Transposition" << endl;
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
				for (int i = 0; i < key.length(); i++){
					key[i] = tolower(key[i]);
				}
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

		// Columnar Transposition
		if(input == 3){
			cout << "Enter key: ";
			cin >> key;
			cout << endl;

			cout << "Encrypt or decrypt? (e/d)" << endl;
                        cin >> option;
                        cout << endl;

			cout << "Enter message (no spaces): ";
			cin >> message;
			cout << endl;

                        if(option == "e" || option == "E"){
                                columnar_encrypt(message, key);
                        } else if(option == "d" || option == "D"){
                                columnar_decrypt(message, key);
                        } else{
                                cout << "ERROR: NOT A VALID OPTION" << endl << endl;
                        }

		}

        }
        return 0;
}
