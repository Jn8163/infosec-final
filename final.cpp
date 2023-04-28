#include <iostream>
#include <string>

using namespace std;



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

                        cout << "Encrypt or decrypt? (e/d)" << endl;
                        cin >> option;
                        cout << endl;

                        cout << "Enter message (no spaces): ";
                        cin >> message;
                        cout << endl;

                        if(option == "e" || option == "E"){
                                cout << " e ";
                        } else if(option == "d" || option == "D"){
                                cout << " d ";
                        } else{
                                cout << "ERROR: NOT A VALID OPTION";
                        }
                }
        }
        return 0;
}
