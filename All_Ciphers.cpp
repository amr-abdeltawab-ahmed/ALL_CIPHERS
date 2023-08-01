// Program Name: Ciphers.cpp
// Program Description: c++ program to encrypt or decrypt in 10 Ciphers
// Last Modification Date: 01/08/2023
// Author : Amr Abdeltawab Ahmed

#include<cmath>
#include<iostream>
#include<string>
#include<cctype>
#include<map>
#include<unordered_map>
using namespace std;


// Function to repeat the keyword to match the message length
string repeatKeyword(const string& keyword, int length) {
    string repeatedKey;
    for (int i = 0, j = 0; i < length; i++) {
        if (j >= keyword.length()) {
            j = 0;
        }
        repeatedKey += keyword[j++];
    }
    return repeatedKey;
}


// Function to convert the input text to uppercase
string toUpperCase(const string& text) {
    string result = text;
    for (char &c: result)
        c = toupper(c);

    return result;
}


// Function to perform modular arithmetic for negative numbers
int mod(int x, int m) {
    return (x % m + m) % m;
}






////////////// Affine Cipher //////////////

//Encryption
string affineCipherEncrypt(const string& text, int keyA, int keyB) {
    string encryptedText;
    for (char c : text) {
        if (isalpha(c)) {
            char encryptedChar = mod(keyA * (toupper(c) - 'A') + keyB, 26) + 'A';
            encryptedText += encryptedChar;
        } else {
            encryptedText += c;
        }
    }
    return encryptedText;
}

//Decryption
string affineCipherDecrypt(const string& text, int keyA, int keyB) {
    int aInverse = 0;
    for (int i = 0; i < 26; i++) {
        if ((keyA * i) % 26 == 1) {
            aInverse = i;
            break;
        }
    }

    string decryptedText = "";
    for (char c : text) {
        if (isalpha(c)) {
            char decryptedChar = mod(aInverse * (toupper(c) - 'A' - keyB), 26) + 'A';
            decryptedText += decryptedChar;
        } else {
            decryptedText += c;
        }
    }
    return decryptedText;
}



////////////// Caesar Cipher //////////////

//encryption
void caesarCipherEncrypt(char* message, int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // lowercase letter
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
            // uppercase letter
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}
//decryption
void caesarCipherDecrypt(char* message, int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // lowercase letter
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
            // uppercase letter
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}

////////////// Atbash Cipher //////////////
//Encryption
string atbashCipherEncrypt(const string& message) {
    string encryptedMessage = message;
    for (char& c : encryptedMessage) {
        if (isalpha(c)) {
            c = toupper(c);
            c = 'Z' - (c - 'A'); // Reverse letter in the alphabet
        }
    }
    return encryptedMessage;
}
//Decryption (Same as encryption, as Atbash is its own inverse)
string atbashCipherDecrypt(const string& message) {
    return atbashCipherEncrypt(message);
}

////////////// Vigenere Cipher //////////////
//Encryption
string vigenereCipherEncrypt(const string& message, const string& key) {
    string encryptedMessage = "";
    string repeatedKey = repeatKeyword(key, message.length());

    for (size_t i = 0; i < message.length(); i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            int keyShift = repeatedKey[i] - 'A';
            ch = ((ch - 'A') + keyShift) % 26 + 'A';
        }
        encryptedMessage += ch;
    }

    return encryptedMessage;
}

//Decryption
string vigenereCipherDecrypt(const string& message, const string& key) {
    string decryptedMessage = "";
    string repeatedKey = repeatKeyword(key, message.length());

    for (size_t i = 0; i < message.length(); i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            int keyShift = repeatedKey[i] - 'A';
            ch = ((ch - 'A' - keyShift + 26) % 26) + 'A';
        }
        decryptedMessage += ch;
    }

    return decryptedMessage;
}



////////////// Baconian Cipher //////////////
//Encryption
string baconianCipherEncrypt(const string& message) {
    string encryptedMessage = "";
    string baconianArray[27] = {
            "AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB", "AABBA", "AABBB", "ABAAA", "ABAAA", "ABAAB", "ABABA",
            "ABABB", "ABBAA", "ABBAB", "ABBBB", "BAAAA", "BAAAB", "BAABA", "BAABB", "BABAA", "BABAB", "BABBA", "BABBB",
            "BBAAA", "BBAAB"
    };

    for (char ch : message) {
        if (isalpha(ch)) {
            int index = ch - 'A';
            encryptedMessage += baconianArray[index];
        }
    }

    return encryptedMessage;
}

//Decryption
string baconianCipherDecrypt(const string& message) {
    string decryptedMessage = "";
    string baconianArray[27] = {
            "AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB", "AABBA", "AABBB", "ABAAA", "ABAAA", "ABAAB", "ABABA",
            "ABABB", "ABBAA", "ABBAB", "ABBBB", "BAAAA", "BAAAB", "BAABA", "BAABB", "BABAA", "BABAB", "BABBA", "BABBB",
            "BBAAA", "BBAAB"
    };

    for (size_t i = 0; i < message.length(); i += 5) {
        string code = message.substr(i, 5);

        for (int j = 0; j < 27; j++) {
            if (code == baconianArray[j]) {
                decryptedMessage += static_cast<char>('A' + j);
                break;
            }
        }
    }

    return decryptedMessage;
}




////////////// Simple Substitution Cipher //////////////
//Encryption
string simpleEncryption(const string& alpha, const string& key) {
    string message;
    cout << "Enter the message to encrypt (please enter a space before it): ";
    cin.ignore();
    getline(cin, message);
    string text = "";
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ' ') {
            text += " ";
        } else {
            for (int j = 0; j < alpha.length(); j++) {
                if (message[i] == key[j]) {
                    text += alpha[j];
                    break;
                }
            }
        }
    }
    return text;
}
//Decryption
string simpleDecryption(const string& alpha, const string& key) {
    string message;
    cout << "Enter the message to decrypt (please enter a space before it): ";
    cin.ignore();
    getline(cin, message);
    string text = "";
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ' ') {
            text += " ";
        } else {
            for (int j = 0; j < alpha.length(); j++) {
                if (message[i] == alpha[j]) {
                    text += key[j];
                    break;
                }
            }
        }
    }
    return text;
}





////////////// Polybius Square Cipher //////////////
// Table definition
char table[5][5];

// Function to initialize the Polybius Square table
void initializeTable() {
    int num = 65, i = 0;
    while (num <= 90) {
        if (num != 74) {
            int j = i / 5;
            char ch = num;
            table[j][i % 5] = ch;
            i++;
        }
        num++;
    }
}

//Encryption
string polybiusEncryption(const string& message) {
    string encryptedMessage;
    int row, column;

    for (int i = 0; i < message.length(); i++) {
        char ch = tolower(message[i]);

        if (ch >= 'a' && ch <= 'z') {
            // finding the row and column in the grid
            row = ceil((ch - 'a') / 5) + 1;
            column = ((ch - 'a') % 5) + 1;

            if (ch == 'j') {
                // if character is 'j'
                row = row - 1;
                column = 5 - column + 1;
            }
            else if (ch >= 'i') {
                // if character is greater than 'i'
                if (column == 1) {
                    column = 6;
                    row = row - 1;
                }
                column = column - 1;
            }

            encryptedMessage += to_string(row) + to_string(column);
        }
        else {
            // If it's not a letter, keep the original character
            encryptedMessage += ch;
        }
    }

    return encryptedMessage;
}

//Decryption
string polybiusDecryption(const string& encryptedMessage) {
    string decryptedMessage;
    for (int i = 0; i < encryptedMessage.length(); i += 2) {
        if (isdigit(encryptedMessage[i]) && isdigit(encryptedMessage[i + 1])) {
            int row = encryptedMessage[i] - '0';
            int col = encryptedMessage[i + 1] - '0';

            if (row >= 1 && row <= 5 && col >= 1 && col <= 5) {
                char ch = table[row - 1][col - 1];
                decryptedMessage += ch;
            }
        }
        else {
            // If it's not a pair of digits, keep the original character
            decryptedMessage += encryptedMessage[i];
        }
    }

    return decryptedMessage;
}


////////////// Morse Cipher //////////////
//Encryption
string morseEncrypt(char input) {
    static unordered_map<char, string> morseTable = {
            {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."},
            {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."},
            {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"},
            {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."},
            {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."},
            {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."},
            {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"},
            {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}
    };

    auto it = morseTable.find(input);
    return (it != morseTable.end()) ? it->second : " ";
}
//Decryption
char morseDecryption(string input) {
    static unordered_map<string, char> reverseMorseTable = {
            {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'}, {"--.", 'g'},
            {"....", 'h'}, {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'},
            {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'}, {"..-", 'u'},
            {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'}, {"--..", 'z'}
    };

    auto it = reverseMorseTable.find(input);
    return (it != reverseMorseTable.end()) ? it->second : ' ';
}


////////////// X-OR Cipher //////////////
//Encryption and Decryption
string XOR(string data, char key) {
    string xor_message = data;
    for (int i = 0; i < xor_message.length(); i++) {
        xor_message[i] ^= key;
    }
    return xor_message;
}


////////////// RailFence Cipher //////////////
//Encryption
string railFenceEncrypt(string message, int key_RailFence) {
    char array_RailFence[key_RailFence][(message.length())];
    for (int i=0; i < key_RailFence; i++)
        for (int j = 0; j < message.length(); j++)
            array_RailFence[i][j] = '\n';
    bool dir_down = false;
    int row = 0, col = 0;
    for (int i=0; i < message.length(); i++){
        if (row == 0 || row == key_RailFence-1)
            dir_down = !dir_down;
        array_RailFence[row][col++] = message[i];
        dir_down?row++ : row--;
    }
    string OutPut;
    for (int i=0; i < key_RailFence; i++)
        for (int j=0; j < message.length(); j++)
            if (array_RailFence[i][j]!='\n')
                OutPut.push_back(array_RailFence[i][j]);
    return OutPut;
}
//Decryption
string railFenceDecrypt(string cipher, int key_RailFence) {
    char array_RailFence[key_RailFence][cipher.length()];
    for (int i=0; i < key_RailFence; i++)
        for (int j=0; j < cipher.length(); j++)
            array_RailFence[i][j] = '\n';
    bool dir_down;
    int row = 0, col = 0;
    for (int i=0; i < cipher.length(); i++) {
        if (row == 0)
            dir_down = true;
        if (row == key_RailFence-1)
            dir_down = false;
        array_RailFence[row][col++] = '*';
        dir_down?row++ : row--;
    }
    int index = 0;
    for (int i=0; i<key_RailFence; i++)
        for (int j=0; j<cipher.length(); j++)
            if (array_RailFence[i][j] == '*' && index<cipher.length())
                array_RailFence[i][j] = cipher[index++];
    string OutPut;
    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++) {
        if (row == 0)
            dir_down = true;
        if (row == key_RailFence-1)
            dir_down = false;
        if (array_RailFence[row][col] != '*')
            OutPut.push_back(array_RailFence[row][col++]);
        dir_down?row++: row--;
    }
    return OutPut;
}






                                     //////////////////////////////////
                                   ////////////// Main //////////////
                                 //////////////////////////////////
int main() {

    cout<<"Which Cipher do you wants to use?\n0- Affine Cipher\n1- Caesar Cipher\n2-Atbash Cipher\n3-Vignere Cipher\n4-Baconian Cipher\n5-Simple Substitution Cipher\n6-Polybius Square Cipher\n7-Morse Cipher\n8-XOR Cipher\n9-Rail-fence Cipher\n10- End\nEnter your choice : ";

    //The Cipher choice
    int Cipher_choice;
    cin >> Cipher_choice;

    //Affine Cipher
    if (Cipher_choice == 0) {
        cout <<"Welcome to the Affine Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";
        int operation_num;
        cin >> operation_num;

        if (operation_num == 1) {
            int keyA, keyB;
            string message;

            cout << "E(x) = (a x + b) mod 26 where x is the letter to cipher." << endl;
            cout << "Enter the message: ";
            getline(cin, message);

            cout << "Enter 'a' value: ";
            cin >> keyA;
            cout << "Enter 'b' value: ";
            cin >> keyB;

            // Convert the message to uppercase
            string uppercaseMessage = toUpperCase(message);

            // Encrypt the message
            string encryptedMessage = affineCipherEncrypt(uppercaseMessage, keyA, keyB);

            cout << "The Encrypted Message: " << encryptedMessage << endl;
        }
        else if (operation_num == 2) {
            int keyA, keyB;
            string encryptedMessage;

            cout << "D(y) = c (y - b) mod 26 where y is the letter to decipher" << endl;
            cout << "Enter the message you want to decrypt: ";
            getline(cin, encryptedMessage);

            cout << "Enter 'a' value: ";
            cin >> keyA;
            cout << "Enter 'b' value: ";
            cin >> keyB;

            // Convert the encrypted message to uppercase
            string uppercaseEncryptedMessage = toUpperCase(encryptedMessage);

            // Decrypt the message
            string decryptedMessage = affineCipherDecrypt(uppercaseEncryptedMessage, keyA, keyB);

            cout << "The Decrypted Message: " << decryptedMessage << endl;
        }
        else if (operation_num == 3) {
            cout << "The Program Is Ending. Thanks For Using Our Program!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }


    //Caesar Cipher
    else if (Cipher_choice == 1) {
        cout <<"Welcome to the Caesar Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";
        int operation_num;
        cin >> operation_num;
        cin.ignore();

        char Message[100];
        int key;

        if (operation_num == 1) {
            cout << "Enter The Message: ";
            cin.getline(Message, sizeof(Message));
            cout << "Enter The key: ";
            cin >> key;

            // Encrypt the message
            caesarCipherEncrypt(Message, key);

            cout << "Your Cipher Is: " << Message << endl;
        }
        else if (operation_num == 2) {
            cout << "Enter The Message: ";
            cin.getline(Message, sizeof(Message));
            cout << "Enter The key: ";
            cin >> key;

            // Decrypt the message
            caesarCipherDecrypt(Message, key);

            cout << "Your Message Is: " << Message << endl;
        }
        else if (operation_num == 3) {
            cout << "The Program Is End, Thanks For Using Our Program" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    }


    //Atbash Cipher
    else if (Cipher_choice == 2) {
        cout <<"Welcome to the Atbash Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";

        int operation_num;
        cin >> operation_num;
        cin.ignore(); // Clear input buffer

        string message;

        if (operation_num == 1) {
            cout << "Enter Your Message: ";
            getline(cin, message);

            // Encrypt the message
            string encryptedMessage = atbashCipherEncrypt(message);

            cout << "The Encrypted message is: " << encryptedMessage << endl;
        }
        else if (operation_num == 2) {
            cout << "Enter Your Message: ";
            getline(cin, message);

            // Decrypt the message
            string decryptedMessage = atbashCipherDecrypt(message);

            cout << "The Decrypted message is: " << decryptedMessage << endl;
        }
        else if (operation_num == 3) {
            cout << "The Program Is End, Thanks For Using Our Program" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    }


    //Vignere Cipher
    else if (Cipher_choice == 3) {
        cout <<"Welcome to the Vignere Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";

        int operation_num;
        cin >> operation_num;
        cin.ignore(); // Clear input buffer

        if (operation_num == 1) {
            cout << "Encryption\n";
            string message, key;
            cout << "Enter Your Message: ";
            getline(cin, message);
            cout << "Enter the keyword: ";
            getline(cin, key);

            // Convert both message and keyword to uppercase
            for (char& c : message) {
                c = toupper(c);
            }
            for (char& c : key) {
                c = toupper(c);
            }

            // Encrypt the message using the Vigenere Cipher
            string encryptedMessage = vigenereCipherEncrypt(message, key);

            cout << "The Encrypted message is: " << encryptedMessage << endl;
        }
        else if (operation_num == 2) {
            cout << "Decryption\n";
            string message, key;
            cout << "Enter the encrypted message: ";
            getline(cin, message);
            cout << "Enter the keyword: ";
            getline(cin, key);

            // Convert both encrypted message and keyword to uppercase
            for (char& c : message) {
                c = toupper(c);
            }
            for (char& c : key) {
                c = toupper(c);
            }

            // Decrypt the message using the Vigenere Cipher
            string decryptedMessage = vigenereCipherDecrypt(message, key);

            cout << "The Decrypted message is: " << decryptedMessage << endl;
        }
        else if (operation_num == 3) {
            cout << "The Program Is End, Thanks For Using Our Program" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    }


    //Baconian Cipher
    else if (Cipher_choice == 4) {
        cout <<"Welcome to the Baconian Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";

        int operation_num;
        cin >> operation_num;
        cin.ignore(); // Clear input buffer

        if (operation_num == 1) {
            cout << "Encryption\n";
            string message;
            cout << "Enter the Text you want to encrypt: ";
            getline(cin, message);

            // Convert the message to uppercase
            for (char& c : message) {
                c = toupper(c);
            }

            // Encrypt the message using the Baconian Cipher
            string encryptedMessage = baconianCipherEncrypt(message);

            cout << "The Cipher Message is: " << encryptedMessage << endl;
        }
        else if (operation_num == 2) {
            cout << "Decryption\n";
            string message;
            cout << "Enter the Message you want to decrypt: ";
            getline(cin, message);

            // Decrypt the message using the Baconian Cipher
            string decryptedMessage = baconianCipherDecrypt(message);

            cout << "The Decipher Message is: " << decryptedMessage << endl;
        }
        else if (operation_num == 3) {
            cout << "The Program Is End, Thanks For Using Our Program" << endl;
            return 0;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    }


    //Simple Substitution Cipher
    else if (Cipher_choice == 5) {
        cout <<"Welcome to the Simple Substitution Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";

        int operation_num;
        cin >> operation_num;
        cin.ignore();

        string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string key;

        // Get the keyword from the user
        cout << "Enter the keyword (26 unique letters): ";
        getline(cin, key);

        if (operation_num == 1) {
            string output1 = simpleEncryption(alpha, key);
            cout << "Encrypted message is: " << output1 << endl;
        }
        else if (operation_num == 2) {
            string output2 = simpleDecryption(alpha, key);
            cout << "Decrypted message is: " << output2 << endl;
        }
        else if (operation_num == 3) {
            cout << "The Program is end" << endl;
            return 0;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    }


    //Polybius Square Cipher
    else if (Cipher_choice == 6) {
        cout <<"Welcome to the Polybius Square Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";

        // Initialize the Polybius Square table
        initializeTable();

        int operation_num;
        cin >> operation_num;
        cin.ignore();

        if (operation_num == 1) {
            cout << "Enter Your Message: ";
            string message;
            getline(cin, message);
            string encryptedMessage = polybiusEncryption(message);
            cout << "\nYour Encrypted Message: " << encryptedMessage << endl;
        }
        else if (operation_num == 2) {
            cout << "Enter Your Encrypted Message: ";
            string encryptedMessage;
            getline(cin, encryptedMessage);
            string decryptedMessage = polybiusDecryption(encryptedMessage);
            cout << "\nYour Decrypted Message: " << decryptedMessage << endl;
        }
        else if (operation_num == 3) {
            cout << "The Program Is End, Thanks For Using Our Program" << endl;
        }

    }


    //Morse Cipher
    else if (Cipher_choice == 7) {
        cout <<"Welcome to the Morse Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";

        int operation_num;
        cin >> operation_num;
        cin.ignore();

        if (operation_num == 1) {
            cout << "Enter the message: ";
            string input;
            getline(cin, input);

            string output;
            for (char ch : input) {
                output += morseEncrypt(ch);
                output += ' '; // Add space between letters
            }
            cout << "The encrypted message: " << output << endl;
        } else if (operation_num == 2) {
            cout << "Enter the morse code: ";
            string input;
            getline(cin, input);

            string output;
            int node = 0;
            for (int i = 0; i <= input.length(); i++) {
                if (input[i] == ' ' || i == input.length()) {
                    string sub = input.substr(node, i - node);
                    output += morseDecryption(sub);
                    node = i + 1;
                }
            }
            cout << "The decrypted message: " << output << endl;
        } else if (operation_num == 3) {
            cout << "The Program Is End, Thanks For Using Our Program" << endl;
        } else {
            cout << "Invalid input! Please choose a valid operation." << endl;
        }

    }


    //XOR Cipher
    else if (Cipher_choice == 8) {
        cout <<"Welcome to the X-OR Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice: ";

        int operation_num;
        string message;
        char key = 'A';

        // Take the message from the user
        cout << "Enter message: ";
        getline(cin, message);

        cin >> operation_num;

        if (operation_num == 1) {
            string ciphered = XOR(message, key);
            cout << "Ciphered message is: " << ciphered << endl;
            cout << "Hexadecimal value: ";
            for (const auto& item : ciphered) {
                cout << hex << int(item);
            }
            cout << "\n";
        }

        else if (operation_num == 2) {
            string deciphered = XOR(message, key);
            cout << "Deciphered message is: " << deciphered << endl;
            cout << "Hexadecimal value: ";
            for (const auto& item : deciphered) {
                cout << hex << int(item);
            }
            cout << "\n";
        }

        else if (operation_num == 3) {
            cout << "Thanks for using our program" << endl;
        } else {
            cout << "Invalid input! Please choose a valid operation." << endl;
        }


    }


    //Rail-fence Cipher
    else if (Cipher_choice == 9) {
        cout <<"Welcome to the Rail-fence Cipher\nWhat do you like to do?\n1- Encrypt a message\n2- Decrypt a message\n3- End\nEnter your choice : ";
        int operation_num;
        cin >> operation_num;

        if (operation_num == 1) {
            string message1;
            int key_RailFence1;
            cout << "Enter The Message: ";
            cin.ignore();
            getline(cin, message1);
            cout << "Enter The Key: ";
            cin >> key_RailFence1;
            cout << "Encrypted Message: " << railFenceEncrypt(message1, key_RailFence1) << endl;
        }

        else if (operation_num == 2) {
            string message2;
            int key_RailFence2;
            cout << "Enter The Message: ";
            cin.ignore();
            getline(cin, message2);
            cout << "Enter The Key: ";
            cin >> key_RailFence2;
            cout << "Decrypted Message: " << railFenceDecrypt(message2, key_RailFence2) << endl;
        }

        else if (operation_num == 3) {
            cout << "The Program Is End, Thanks For Using Our Program" << endl;
        }
        else {
            cout << "Invalid input! Please choose a valid operation." << endl;
        }

    }


    //End the program
    else if (Cipher_choice == 10) {
        cout << "Thanks for using our program";
        return 0;
    }


    // Defensive program in case the user enters the wrong choice
    else {
        cout << "Invalid number, please try again"<<endl;
        // Let the user choose again
        main();
    }


    // Show a message to the user to choose to continue with another process or end the program
    int inp;
    cout << "Do you want to do another thing?\n1-Yes.\n2-No, End The program.\nplease, Enter (1 or 2):\n";
    cin >>inp;
    //if he said yes, back to the program again
    if (inp == 1) {
        main();
    }
    //if he said no,End the program again
    else if (inp == 2) {
        cout << "\nThank you for using our program.";
        return 0;
    }
    else {
        //Defensive program in case of entering the wrong number
        cout << "Invalid number.Thank you for using our program.";
        return 0;
    }

}
