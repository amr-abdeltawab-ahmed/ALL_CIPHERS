// Program Name: All_Ciphers.cpp
// Program Description: c++ program to encrypt or decrypt in 10 Ciphers
// Last Modification Date: 24/03/2022
// Author : Amr Abdeltawab Ahmed
// Purpose: Learn and master c++ 

#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

//part from morse code 
string Morse_enc(char16_t Morse_enc_input) {
    
    switch(Morse_enc_input) {
        case 'a': case 'A':
        return ".-"; break;
        case 'b': case 'B':
        return "-..."; break;
        case 'c': case 'C':
        return "-.-."; break;
        case 'd': case 'D':
        return "-.."; break;
        case 'e': case 'E':
        return "."; break;
        case 'f': case 'F':
        return "..-."; break;
        case 'g': case 'G':
        return "--."; break;
        case 'h': case 'H':
        return "...."; break;
        case 'i': case 'I':
        return ".."; break;
        case 'j': case 'J':
        return ".---"; break;
        case 'k': case 'K':
        return "-.-"; break;
        case 'l': case 'L':
        return ".-.."; break;
        case 'm': case 'M':
        return "--"; break;
        case 'n': case 'N':
        return "-."; break;
        case 'o': case 'O':
        return "---"; break;
        case 'p': case 'P':
        return ".--."; break;
        case 'q': case 'Q':
        return "--.-"; break;
        case 'r': case 'R':
        return ".-."; break;
        case 's': case 'S':
        return "..."; break;
        case 't': case 'T':
        return "-"; break;
        case 'u': case 'U':
        return "..-"; break;
        case 'v': case 'V':
        return "...-"; break;
        case 'w': case 'W':
        return ".--"; break;
        case 'x': case 'X':
        return "-..-"; break;
        case 'y': case 'Y':
        return "-.--"; break;
        case 'z': case 'Z':
        return "--.."; break;
        default:
        return " "; break;
    }
}
string Morse_dec(string Morse_dec_input) {

        if(Morse_dec_input == ".-")
        {return "a";}
        else if(Morse_dec_input == "-...")
        {return "b";}
        else if(Morse_dec_input == "-.-.")
        {return "c";}
        else if(Morse_dec_input == "-..")
        {return "d";}
        else if(Morse_dec_input == ".")
        {return "e";}
        else if(Morse_dec_input == "..-.")
        {return "f";}
        else if(Morse_dec_input == "--.")
        {return "g";}
        else if(Morse_dec_input == "....")
        {return "h";}
        else if(Morse_dec_input == "..")
        {return "i";}
        else if(Morse_dec_input == ".---")
        {return "j";}
        else if(Morse_dec_input == "-.-")
        {return "k";}
        else if(Morse_dec_input == ".-..")
        {return "l";}
        else if(Morse_dec_input == "--")
        {return "m";}
        else if(Morse_dec_input == "-.")
        {return "n";}
        else if(Morse_dec_input == "---")
        {return "o";}
        else if(Morse_dec_input == ".--.")
        {return "p";}
        else if(Morse_dec_input == "--.-")
        {return "q";}
        else if(Morse_dec_input == ".-.")
        {return "r";}
        else if(Morse_dec_input == "...")
        {return "s";}
        else if(Morse_dec_input == "-")
        {return "t";}
        else if(Morse_dec_input == "..-")
        {return "u";}
        else if(Morse_dec_input == "...-")
        {return "v";}
        else if(Morse_dec_input == ".--")
        {return "w";}
        else if(Morse_dec_input == "-..-")
        {return "x";}
        else if(Morse_dec_input == "-.--")
        {return "y";}
        else if(Morse_dec_input == "--..")
        {return "z";}
}




//part from Vignere Cipher

string message;
string mappedkey;

void Vignere(){
    
    //Enter the message you want to encrypt
    string message1;
    string key;

    cout<<"Enter the message (The Maximum Number of Characters is 80) :";
    getline(cin,message1);
    
    if (message1.length() > 80){
        cout<<"Wrong\n";
        Vignere();
    }

    //message to upper
    for(int i = 0; i < message1.length() ; i++){
        message1[i] = toupper(message1[i]);
    }

    //Enter the key word
    cout<<"Enter the key word (The Maximum Number of Characters is 80) :";
    getline(cin,key);
    
    if (key.length() > 8){
        cout<<"Wrong\n";
        Vignere();
    }

    //key word to upper
    for(int i = 0; i < key.length() ; i++){
        key[i] = toupper(key[i]);
    }
    
    // repeated message
    string key1 = "";
    for (int i = 0,j = 0; i < message1.length() ; i++){
        if(j<key.length()){
            key1 += key[j];
            j++;
        }
        
        else {
            j = 0;
            key1 += key[j];
            j++;
        }
    }
    
    cout<<"message: "<<message1<<"\n"<<"repeated keyword: "<<key1<<"\n";
    message = message1;
    mappedkey = key1;

}

void Vignere_enc(){
//convert the message and the key to ASCII
    int input1 , input2;
    char input3;
    
    cout<<"encrypted message: ";
    for (int i = 0 ; i < message.length() ; i++){
        //convert the message to ASCII
        int ascii_message = message[i];
        
        //convert the keyword to ASCII
        int ascii_key = mappedkey[i];
        
        //if there are space or symbols or numbers , it keeps it
        if (message[i] > 90 || message[i] < 65){
            mappedkey[i] == 0;
            input3 = char(message[i]);
            cout<<input3;
        }
        
        else {
            input1 = message[i]+mappedkey[i];
            input1 = input1 % 26;
            input1 = input1 + 65;
            input3 = char(input1);
            cout<<input3;
        }
    }
}

void Vignere_dec(){
    string key;
    string enc;
    int ascii_message;
    char message1;

    cout<<"Enter the encrypted message (The Maximum Number of Characters is 80) :";
    getline(cin,enc);

    if (enc.length() > 80){
        cout<<"Wrong\n";
        Vignere_dec();
    }

    cout<<"Enter the keyword (The Maximum Number of Characters is 80) :";
    getline(cin,key);
    if (key.length() > 8){
        cout<<"Wrong\n";
        Vignere_dec();
    }
    
    //encrypt message to upper
    for(int i = 0; i < enc.length() ; i++){
        enc[i] = toupper(enc[i]);
    }
    
    //keyword to upper
    for(int i = 0; i < key.length() ; i++){
        key[i] = toupper(key[i]);
    }
    
    //repeat the keyword
    string keymap = "";
    for (int i = 0,j = 0; i < enc.length() ; i++){
        if(j<key.length()){
            keymap += key[j];
            j++;
        }else {
            j = 0;
            keymap += key[j];
            j++;
        }
        
    }
    
    //end the repeating
    cout<<"encrypt message:"<<enc<<"\n"<<"repeated keyword:"<<keymap<<"\n";
    
     for (int i = 0 ; i < enc.length() ; i++){
        
        //convert the message to ASCII
        int asciienc = enc[i];
        
        //convert the keyword to ASCII
        int asciikey = keymap[i];
        
        //if there are numbers , it keeps it
        if (enc[i] < 57 && enc[i] > 48){
            cout<<char(enc[i]);
        }
        
        //if there are spaces , it keeps it
        else if (enc[i] == 32 ){
            cout<<char(enc[i]);
        }
        
        else{
            enc[i] = enc[i] - 65;
            for (int j = 130 ; j < 180 ; j++ ){
                if( j % 26 == enc[i]){
                    ascii_message = j - keymap[i];
                    
                    //if the word is symbol , it remove it
                    if (ascii_message > 90 || ascii_message < 65){
                        continue;
                    }
                    
                    message1 = char(ascii_message) ;
                    cout<<message1;
                }
            }
        }
    }
}



//part from simple substution Cipher

string keyword();
string encryption(string alpha, string key);
string decryption(string alpha, string key);

string keyword() {
	cout << "Enter key (alphabet letters) with no repeat letter :";
	string key;
	cin.ignore();
	getline(cin, key);

	for (int i = 0; i < key.length(); i++) {
			for (int j = 0; j < key.length(); j++) {
				if (i == j) {
					continue;
				}
				else if (key[i] == key[j]) {
					cout << "repeatd letter ";
					exit(EXIT_FAILURE);
				}
			}
	}
	
	string temp = "";
	for (int i = 0; i < key.length(); i++) {
	    temp += key;
	}
	
	for (int i = 0; i < 26; i++) {
	    temp += (char)(i + 97);
	}

	for (int i = 0; i < temp.length(); i++) {
		bool found = false;
		for (int j = 0; j < key.length(); j++) {
			if (temp[i] == key[j]) {
				found = true;
				break;
			}
		}
		if (found == false)
			key += temp[i];
	}
	return key;
}

string simple_decryption(string alpha, string key) {
	string message;
	cout << "Enter message 'please enter a space before it': ";
	cin.ignore();
	getline(cin, message);
	string text = "";
	for (int i = 0; i < message.length(); i++) {
		if (message[i] == (char)32) {
			text += " ";
		}
		else {
			for (int j = 0; j < alpha.length(); j++) {
				if (message[i] == alpha[j])  {
					text += key[j];
					break;
				}
			}
		}
	}
	return text;
}

string simple_encryption(string alpha, string key) {
	string message;
	cout << "Enter message 'please enter a space before it':";
	cin.ignore();
	getline(cin, message);
	string text = "";
	for (int i = 0; i < message.length(); i++) {
		if (message[i] == (char)32) {
			text += " ";
		}
		else {
			for (int j = 0; j < alpha.length(); j++) {
				if (message[i] == key[j])
				{
					text += alpha[j];
					break;
				}
			}
		}
	}
	return text;
}



// part from XOR Cipher

string XOR(string data, char key);
//function of encryption and decryption
string XOR(string data, char key) {
	string xor_message = data;
	for (int i = 0; i < xor_message.length(); i++)
	{
		xor_message[i] ^= key;
	}
	return xor_message;
}



//part from Rail-fence

string E_RailFence(string message, int key_RailFence) {
	//create the array to cipher the message
	char array_RailFence[key_RailFence][(message.length())];
	//filling the array 
	for (int i=0; i < key_RailFence; i++)
		for (int j = 0; j < message.length(); j++)
			array_RailFence[i][j] = '\n';
	//find the direction
	bool dir_down = false;
	int row = 0, col = 0;

	for (int i=0; i < message.length(); i++)
	{
		if (row == 0 || row == key_RailFence-1)
			dir_down = !dir_down;
			
		// fill the corresponding alphabet
		array_RailFence[row][col++] = message[i];
		
		// find the next row 
		dir_down?row++ : row--;
	}

	//construct the cipher using the array
	string OutPut;
	for (int i=0; i < key_RailFence; i++)
		for (int j=0; j < message.length(); j++)
			if (array_RailFence[i][j]!='\n')
				OutPut.push_back(array_RailFence[i][j]);
	return OutPut;
}


string D_RailFence(string cipher, int key_RailFence) {
	// create the array to Decipher a message
	char array_RailFence[key_RailFence][cipher.length()]; 
	// filling the array
	for (int i=0; i < key_RailFence; i++)
		for (int j=0; j < cipher.length(); j++)
			array_RailFence[i][j] = '\n';
			
	// to find the direction
	bool dir_down;
	int row = 0, col = 0;

	//mark the places with '*'
	for (int i=0; i < cipher.length(); i++) {
		//check the direction of flow
		if (row == 0)
			dir_down = true;
		if (row == key_RailFence-1)
			dir_down = false;
			
		//place the marker
		array_RailFence[row][col++] = '*';
		
		//find the next row 
		dir_down?row++ : row--;
	}

	//construct the fill the array
	int index = 0;
	for (int i=0; i<key_RailFence; i++)
		for (int j=0; j<cipher.length(); j++)
			if (array_RailFence[i][j] == '*' && index<cipher.length())
				array_RailFence[i][j] = cipher[index++];

	//read the array in zig-zag manner to construct
	string OutPut;
	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++) {
		//check the direction
		if (row == 0)
			dir_down = true;
		if (row == key_RailFence-1)
			dir_down = false; 
		//place the marker
		if (array_RailFence[row][col] != '*')
			OutPut.push_back(array_RailFence[row][col++]);
		//find the next row 
		dir_down?row++: row--;
	}
	return OutPut;
}



//part from Polybius Square Cipher 

void Cipher(string message1) {           
    int row, column;
    
    // convert each character to code
    for (int i = 0; message1[i]; i++) {  
        
        // finding the row and col
	    row = ceil((message1[i] - 'a') / 5) + 1;         
	    column = ((message1[i] - 'a') % 5) + 1;       
	    if (message1[i] == 'k') {   
	        
	        // if character is 'k'
	        row = row - 1;
	        column = 5 - column + 1;
	    }
	    else if (message1[i] >= 'j') {
	        
	        // if character is greater than 'j'
	        if (column == 1) {
		        column = 6;
		        row = row - 1;
	        }
	        column = column - 1;
	    }
	    cout << row << column;
    }
    cout << endl;
}

// Table definition
char table[5][5];  

// Define the code function
string coding(string message2) {              
        string input1;
        
        //know the length
        int l1 = message2.length();           
        char input2[l1+1];
        
        for(int i=0;i<l1;i++)
            for(int j=0;j<5;j++)
                for(int k=0;k<5;k++) {
                    if(input2[i]==table[j][k]) {
                        char ch = j+48+1;
                        string row(1,ch);
                        input1=input1+row;
                        ch = k+48+1;
                        string col(1,ch);
                        input1=input1+col;
                    }
                }
        return input1;
}

string decoding(string input1) {                  
    string input3;
    
    //know the length
    int l1 = input1.length();             
    char input4[l1+1];
    strcpy(input4,input1.c_str());
    for(int i=0;i<l1;i=i+2) {
        int row, col;
        row=input4[i];
        row-=48;
        col=input4[i+1];
        col-=48;
        string s(1,table[row-1][col-1]);
        // Add the Cipher consecutively in the form of string
        input3=input3+s;                  
    }
    return input3;
}




int main() {
    
    // Welcome the user and know which Cipher he wants to use
    cout<<"Ahlan ya user ya habibi\nThis program has 10 ciphers which can help you to encrypt or decrypt any text\n";
    cout<<"Which Cipher do you wants to use?\n0- Affine Cipher\n1- Caesar Cipher\n2-Atbash Cipher\n3-Vignere Cipher\n4-Baconian Cipher\n5-Simple Substitution Cipher\n6-Polybius Square Cipher\n7-Morse Cipher\n8-XOR Cipher\n9-Rail-fence Cipher\n10- End\nEnter your choice : ";

    
    //The Cipher choice
    int Cipher_choice;
    cin >> Cipher_choice;
    
    
    
    //Affine Cipher
    if (Cipher_choice == 0) {
        cout << "welcome to the Affine Cipher\n";
        
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
        cin>>operation_num;
        
        
        //encrypt
        if (operation_num == 1){
            string Affine_msg;
            int Affine_inp1;
            int Affine_inp2;
            int Affine_inp3;
            char enc;
            cout<<"E(x) = (a x + b) mod 26 where x is the letter to cipher."<<endl;
            cout<<"enter the message :" ;
            cin.ignore();
            getline(cin,Affine_msg);
        
        
            cout<<"Enter 'a' value : ";
            cin>>Affine_inp1;
            cout<<"Enter 'b' value : ";
            cin>>Affine_inp2;
        
        
            //convert the message to upper
            for(int i = 0; i < Affine_msg.length() ; i++){
                Affine_msg[i] = toupper(Affine_msg[i]);
            }
        
            cout<<"The Encrypted Message : ";
        
            for (int i = 0 ; i < Affine_msg.length() ; i++){
                int asciimsg = Affine_msg[i];//convert the message to ASCII
            
                if (Affine_msg[i] == 32  ){
                    cout<<" ";
                }
                
                else if (Affine_msg[i] < 57 && Affine_msg[i] > 48){
                    cout<<Affine_msg[i];
                }
                
                else {
                    Affine_msg[i] = Affine_msg[i] - 65;
                    Affine_inp3 = Affine_inp1 * Affine_msg[i];
                    Affine_inp3 = Affine_inp3 + Affine_inp2;
                    Affine_inp3 = Affine_inp3 % 26;
                    Affine_inp3 = Affine_inp3 + 65;
                    enc = (Affine_inp3);
                    cout<<enc;
                }
            }
        }
        
        //decrypt
        else if (operation_num == 2){
            int Affine_inp4;
            int Affine_inp2;
            int Affine_inp3;
            string Affine_msg;
            char dec;
            
            cout<<"D(y) = c (y - b) mod 26 where y is the letter to decipher"<<endl;
            cout<<"Enter the message you want decrypt : ";
            cin.ignore();
            getline(cin,Affine_msg);
            
            cout<<"Enter c value : ";
            cin>>Affine_inp4;
            cout<<"Enter b value  : ";
            cin>>Affine_inp2;
            
            //convert the message to upper
            for(int i = 0; i < Affine_msg.length() ; i++){
                Affine_msg[i] = toupper(Affine_msg[i]);
            }
            
            cout<<"the decrypted message : "<<endl;;
            
            for (int i = 0 ; i < Affine_msg.length() ; i++){
                int Affine_asciimsg = Affine_msg[i];//convert the message to ASCII
                
                if (Affine_msg[i] == 32  ){
                    cout<<" ";
                }
                
                else if (Affine_msg[i] < 57 && Affine_msg[i] > 48){
                    cout<<Affine_msg[i];
                }
                
                else {
                    Affine_msg[i] = Affine_msg[i] - 65;
                    Affine_inp3 = Affine_msg[i] - Affine_inp2;
                    Affine_inp3 = Affine_inp3 * Affine_inp4;
                    Affine_inp3 = (Affine_inp3%26+26)%26;
                    Affine_inp3 += 65;
                    dec = (Affine_inp3);
                    cout<<dec;
                }
            }
        }
        
        //End
        else if (operation_num == 3){
            
            cout << "The Program Is End, Thanks For Using Our Program";
            return 0;
            
        }
    }
    
    
    
    //Caesar Cipher
    else if (Cipher_choice == 1) {
        cout << "welcome to the Caesar Cipher\n";
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
        cin>>operation_num;
        char Message[100];
        int i, j, length, key;
        
        //encryption
        if (operation_num == 1) {
            cout<<"Enter The Message:";
            cin >> Message;
            cout << "Enter The key: ";
            cin >> key; 
            length = strlen(Message);
            char ch;
            for(int i = 0; Message[i] != '\0'; ++i) {
                
                ch = Message[i];
                //lowercase letter
                if (ch >= 'a' && ch <= 'z'){
                
                    ch = ch + key;
                    if (ch > 'z') {
                        ch = ch - 'z' + 'a' - 1;
                    }  
                    Message[i] = ch;
                }
                //uppercase letter
                else if (ch >= 'A' && ch <= 'Z'){
                    ch = ch + key;
                    if (ch > 'Z'){
                        ch = ch - 'Z' + 'A' - 1;
                    }
                    Message[i] = ch;
                }
            }
            cout << "Your Cipher Is: " << Message << endl;
        }
        
        //decryption   
        else if (operation_num == 2) {
            cout<<"Enter The essage:";
            cin >> Message;
            cout << "Enter The key: ";
            cin >> key; 
            length = strlen(Message);
            char ch;
            for(int i = 0; Message[i] != '\0'; ++i) {
                ch = Message[i];
                //lowercase letter
                if(ch >= 'a' && ch <= 'z') {
                    ch = ch - key;
                    if(ch < 'a'){
                        ch = ch + 'z' - 'a' + 1;
                    }
                    Message[i] = ch;
                }
                //uppercase letter
                else if(ch >= 'A' && ch <= 'Z') {
                    ch = ch - key;
                    if(ch < 'A') {
                        ch = ch + 'Z' - 'A' + 1;
                    }
                    Message[i] = ch;
                }
            }
            cout << "Your Message Is: " << Message << endl;
        }
        else if (operation_num == 3) {              
            cout << "The Program Is End, Thanks For Using Our Program";
            return 0;
        }
    }
    
    
    
    
    //Atbash Cipher
    else if (Cipher_choice == 2) {
        cout << "welcome to the Atbash Cipher\n";
        
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        string message;
        int operation_num ,n ;
        cin>>operation_num;
        
        char first_array[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
        char second_array[27] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A',' '};
        
        //Encrypt
        if (operation_num == 1) {
            
            //the input of the compiler to Encrypt
            cout<<"Enter Your Message :";
            cin.ignore();
            getline(cin,message);
            n = message.length();
            for (int l = 0; l < n; l++) {
                message[l] = toupper(message[l]);
            }
            
            //the encrypted message
            cout<<"The Encrypted message is :";
            
            for (int i = 0; i < n; i++) {
                
                for (int j = 0; j < 27 ; j++) {
                    
                    if (message[i] == first_array[j]) {
                        
                        cout<<second_array[j];
                    }
                }
            }
            
        }
        
        
        
        //Decrypt
        else if (operation_num == 2) {
            // the input of the compiler to Decrypt 
            cout<<"Enter Your Message :";
            cin.ignore();
            getline(cin,message);
            n = message.length();
            for (int l = 0; l < n; l++) {
                
                message[l] = toupper(message[l]);
            }
            //the Decrypted massage
            cout<<"The Decrypted massege is :";
            for (int i = 0; i < n; i++) {
                
                for (int j = 0; j < 27; j++) {
                    
                    if (message[i] == second_array[j]) {
                        cout<<first_array[j];
                    }
                }
            }
            
        }
    
    
        //End
        else if (operation_num == 3) {
            
            cout << "The Program Is End, Thanks For Using Our Program";
            return 0;
            
        }
    }
    
    
    
    
    //Vignere Cipher
    else if (Cipher_choice == 3) {
        cout << "welcome to the Vignere Cipher\n";
        
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
        cin >> operation_num;
        
        cin.ignore();
        
        if (operation_num == 1 ) {
            cout<<"Encryption"<<endl;
            Vignere();
            Vignere_enc();
        }
        
        else if (operation_num == 2) {
            cout<<"Decryption\n";
            Vignere_dec();
        }
        
        else if (operation_num == 3) {
            cout << "The Program Is End, Thanks For Using Our Program";
            return 0;
        }
        
    } 
    
    
    
    
    //Baconian Cipher
    else if (Cipher_choice == 4) {
        cout << "welcome to the Baconian Cipher\n";
        
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
        cin >> operation_num;
        
        // Define variables
        string Baconian_message;
        int choice , n ;
        string Baconian_array[27] = {"aaaaa ","aaaab ","aaaba ","aaabb ","aabaa ","aabab ","aabba ","aabbb ","abaaa ","abaab ","ababa ","ababb ","abbaa ","abbab ","abbba ","abbbb ","baaaa ","baaab ","baaba ","baabb ","babaa ","babab ","babba ","babbb ","bbaaa ","bbaab "};
        string Baconian_array2 = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        
        if(operation_num == 1){
            
            //Enter the message you want to Encrypt
            cout <<"Enter the Text you want to  it :";
            cin.ignore();
            getline(cin,Baconian_message);
            
            //copy all the strings in the array
            n = Baconian_message.length();
            char Baconian_charArry[n];
            strcpy(Baconian_charArry, Baconian_message.c_str());
            
            for (int j = 0; j < n; j++) {
                Baconian_charArry[j] = toupper(Baconian_charArry[j]);
            }
            
            //print the Encrypt
            cout<< "The Cipher Message is :";
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < 27; j++) {
                    if(Baconian_charArry[i] == Baconian_array2[j]) {
                        cout<<Baconian_array[j];
                    }
                }       
            }
        }

        else if (operation_num == 2){
            //Enter the message you want to Decrypt 
            cout <<"Enter the Message you want to Decrypt :";
            cin.ignore();
            getline(cin,Baconian_message);
            
            cout<< "The Decipher Message is :";
            for (int k = 0; k < 500; k++) {
                
                if(Baconian_message[k] == 'a' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'a'){
                    cout<<'A';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'b'){
                    cout<<'B';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'a'){
                    cout<<'C';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'b'){
                    cout<<'D';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'a'){
                    cout<<'E';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'b'){
                    cout<<'F';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'a'){
                    cout<<'G';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'b'){
                    cout<<'H';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'a'){
                    cout<<'I';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'b'){
                    cout<<'J';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'a'){
                    cout<<'K';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'b'){
                    cout<<'L';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'a'){
                    cout<<'M';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'b'){
                    cout<<'N';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'a'){
                    cout<<'O';
                }
                else if (Baconian_message[k] == 'a' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'b'){
                    cout<<'P';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'a'){
                    cout<<'Q';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'b'){
                    cout<<'R';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'a'){
                    cout<<'S';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'b'){
                    cout<<'T';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'a'){
                    cout<<'U';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'b'){
                    cout<<'V';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'a'){
                    cout<<'W';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'a' && Baconian_message[k+2] == 'b' && Baconian_message[k+3] == 'b' && Baconian_message[k+4] == 'b'){
                    cout<<'X';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'a'){
                    cout<<'Y';
                }
                else if (Baconian_message[k] == 'b' && Baconian_message[k+1] == 'b' && Baconian_message[k+2] == 'a' && Baconian_message[k+3] == 'a' && Baconian_message[k+4] == 'b'){
                    cout<<'Z';
                }
                else {
                    Baconian_message = Baconian_message.substr(1,Baconian_message.length());
                    break;
                }
                Baconian_message = Baconian_message.substr(5,Baconian_message.length());
            }
        }
    
        else if (operation_num == 3){
            cout<<"The Program Is End, Thanks For Using Our Program";
            return 0;
        }
        
    }
    
    
    
    
    //Simple Substitution Cipher
    else if (Cipher_choice == 5) {
        cout << "welcome to the Simple Substitution Cipher\n";
        
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
        cin >> operation_num;
        cin.ignore();
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string key = keyword();
        
        if (operation_num == 1) {
            string output1 = simple_encryption(alpha, key);
            cout << "Encrypted message is: " << output1 << endl;
        }
        
        else if (operation_num == 2) {
            string output2 = simple_decryption(alpha, key);
		    cout << "Decrypted message is: " << output2 << endl;
            
        }
        
        else if (operation_num == 3) {
		    cout << "The Program is end";
		    return 0;
            
        }
        
    }
    
    
    
    
    //Polybius Square Cipher
    else if (Cipher_choice == 6) {
        
        // using ascii in code
        int num = 65, i=0;                        
        while(num<=90) {
            if(num!=74) {
                int j = i/5;
                char ch = num;
                table[j][i%5] = ch;
                i++;
            }
        num++;
        }
        
        //the begginning
        cout << "welcome to the Polybius Square Cipher\n";
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
        cin >> operation_num;
        
        //encrypt
        if (operation_num == 1) {        
            string message1;
            
            cout<<"Enter Your Message: ";              
            cin>>message1;
            
            cout<<"\nYour Message: ";
            Cipher(message1);
        }
        
        //decrypt
        else if (operation_num == 2) {             
            string message2,input3;
            
            cout<<"Enter Your Message: ";
            cin>>message2;
            
            input3 = decoding(message2);
            cout<<"\nYour Message: "<<input3;
        }
        
        //end the program
        else if (operation_num == 3) {               
            cout << "The Program Is End, Thanks For Using Our Program";
            return 0;
        }
    }
    
    
    
    
    //Morse Cipher
    else if (Cipher_choice == 7) {
        cout << "welcome to the Morse Cipher\n";
        
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
        cin >> operation_num;
        
        char key;
        bool loop = true;
        
        while(loop) {
            bool toMorse=true;
            string input;
            string output = "";
            int node = 0;
            string sub;
            
            
            // encrypt
            if(operation_num == 1) {
                cout<<"Enter the message: ";
                cin.ignore();
                getline(cin,input);
                
                for(int i = 0; i<input.length(); i++){
                    if(i!=0){
                        output+=" ";
                    }
                    output = output + Morse_enc(input[i]);
                }
                cout<<"the encrypted message : "<<output;
            }
            
            
            //decrypt
            else if(operation_num == 2){
                cout<<"Enter the morse code: ";
                cin.ignore();
                getline(cin,input);
                
                for(int i = 0;i<=input.length();i++) {
                    if (input[i]==' ') {
                        sub = input.substr(node,i-node);
                        output+=Morse_dec(sub);
                        node = i+1;
                    }
                    
                    else if (i==input.length()-1) {
                        sub = input.substr(node,i+1-node);
                        output+=Morse_dec(sub);
                        node = i+1;
                    }
                }
                cout<<"the decrypted message : "<<output;
            }
            
            //end
            else if (operation_num == 3){
                cout << "The Program Is End, Thanks For Using Our Program";
                return 0;
            }
        }
    }
    
    
    
    
    //XOR Cipher
    else if (Cipher_choice == 8) {
        cout << "welcome to the XOR Cipher\n";
        
        cout<<"What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
	    int choice;
	    string message;
	    char key = 'A';
	    
	    // take the massage from user
	    cout << "enter message: ";
	    getline(cin, message);
	    cout << "1-cipher: " << endl;
	    cout << "2-dicpher: " << endl;
	    cout << "3-end: " << endl;
	    cout << "enter 1 or 2 or 3: ";
	    cin >> operation_num;
	
    	// encryption
	    if (operation_num == 1) {
		    string ciphered = XOR(message, key);
		    cout << "ciphered message is: " << ciphered << endl;
		    cout << "hexa value : ";
		    for (const auto & item : ciphered) {
			    cout << hex << int(item);
     		}
	     	cout << "\n";
	    }
	    
	    //decryption
	    else if (operation_num == 2) {
		    string deciphered = XOR(message, key);
		    cout << "deciphered message is: " << deciphered << endl;
		    cout << "hexa value: ";
		    for (const auto& item : deciphered) {
			    cout << hex << int(item);
		    }
		    cout << "\n";
	    }
	
	    else if (operation_num == 3) {
	        cout << "thanks for using our program";
	        return 0;
	    }
	
    }
    
    
    
    
    //Rail-fence Cipher
    else if (Cipher_choice == 9) {
        
        cout << "welcome to the Rail-fence Cipher\n";
        cout<< "What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\nEnter your choice : ";
        
        int operation_num;
        cin>>operation_num;
        
        //encrypt
        if (operation_num == 1) {    
            string message1;
            int key_RailFence1;
            
            cout <<"Enter The Message :";
            cin >> message1;
            
            cout <<"Enter The Key :";
            cin >> key_RailFence1;
            
            cout << E_RailFence(message1, key_RailFence1) << endl;
        }
        
        //decrypt
        else if (operation_num == 2) {             
            string message2;
            int key_RailFence2;
            cout <<"Enter The Message :";
            cin >> message2;
            
            cout <<"Enter The Key :";
            cin >> key_RailFence2;
            
            cout << D_RailFence(message2, key_RailFence2) << endl;
        }
        
        //end 
        else if (operation_num == 3) {  
            
            cout << "The Program Is End, Thanks For Using Our Program";
            return 0;
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