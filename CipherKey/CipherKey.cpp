//
//  main.cpp
//  CipherKey
//
//  Created by Gabriel Push on 2/1/24.
//

#include <iostream>
using namespace std;

void genCipher(char alphabet[], char cipherKey[], int shift, int length) {
    for (int i = 0; i < length; i++) {
        cipherKey[i] = alphabet[(i + shift) % 52];
    }
    cipherKey[length] = '\0';
}

void takeString(string &input, char cipherKey[]) {
    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) {
            char base = isupper(input[i]) ? 'A' : 'a';
            input[i] = cipherKey[input[i] - base];
        }
    }
}

int main() {
    char alphabet[53] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    char cipherKey[53];
    string plainText;
    string cipherText;
    int shift;
    int length = 52;
    string input;
    
    cout << "Enter a shift value(1-51): " << endl;
    cin >> shift;
    if (shift < 1 || shift > 51) {
        return -1;
    }
    
    genCipher(alphabet, cipherKey, shift, length);
    
    cout << "Enter a string: " << endl;
    cin.ignore();
    getline(cin, input);
    
    
    takeString(input, cipherKey);
    
    
    cout << "Alphabet: " << alphabet << endl << endl;
    cout << "Cipher Key: " << cipherKey << endl << endl;
    cout << "String entered converted to Cipher Key: " << input << endl << endl;
    
    
}
