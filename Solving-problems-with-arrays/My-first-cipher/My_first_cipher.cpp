#include <iostream>
#include <string>
using namespace std ;

//I will implement my Cesar cipher with a shift of 3 
//The case of a ASCII value which is out of the uppercase letter will be replace by a space 
int char_to_ascii(char lettre) ;
char plain_to_cipher(char plain_char) ;
char cipher_to_plain(char cipher_char) ;
string plaintext_to_ciphertext(string plaintext) ;
string ciphertext_to_plaintext(string ciphertext) ;

//let to associate a char with his ASCII number
int char_to_ascci(char lettre) 
{
    return static_cast<int>(lettre) ;
}

//constant array to access with Char with ASCII code
const char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'} ;

//function which take a char in the plaintext string and return his value after the cipher
char plain_to_cipher(char plain_char)
{
    int ascii = char_to_ascci(plain_char) ;

    if (ascii>90 || ascii<65)
    {
        return ' ' ;
    }

    if ((ascii+3)>90)
    {
        return alpha[ascii-88] ;
    } 
    else
    {
        return alpha[ascii-62] ;
    }
}

//same but cipher to plain
char cipher_to_plain(char cipher_char)
{
    int ascii = char_to_ascci(cipher_char) ;

    if (ascii>90 || ascii<65)
    {
        return ' ' ;
    }

    if ((ascii-3)<65) 
    {
        return alpha[ascii-65-29] ;
    }
    else 
    {
        return alpha[ascii-68] ;
    }
}

//function to cipher the plaintext
string plaintext_to_ciphertext(string plaintext)
{
    string ciphertext = "" ; 
    int size = plaintext.size() ;
    
    for (int i = 0; i<size; i++)
    {
        if (plaintext.at(i)==' ')
        {
            ciphertext = ciphertext + ' ' ;
        }
        else 
        {
            ciphertext = ciphertext +  plain_to_cipher(plaintext.at(i)) ;
        }
        
    }

    return ciphertext ;
}

//the inverse function 
string ciphertext_to_plaintext(string ciphertext)
{
    string plaintext = "" ; 
    int size = ciphertext.size() ;
    
    for (int i=0; i<size; i++)
    {
        if (ciphertext.at(i)==' ')
        {
            plaintext = plaintext + ' ' ;
        }
        else 
        {
            plaintext = plaintext + cipher_to_plain(ciphertext.at(i)) ;
        }
    }

    return plaintext ;
}

int main() 
{
    int mode = 0 ;
    cout << "Which mode do you want to use ?" << endl ;
    cout << "1 : encode" << endl ;
    cout << "2 : decode" << endl ;
    cin >> mode ;
    cin.ignore() ;

    while (mode<1 || mode>2) 
    {
        cout << "There are only two modes, mode 1 and mode 2" << endl ;
        cout << "Please enter a valid value" << endl ;
        cin >> mode ;
    }

    string message ;
    cout << "Enter your message with only uppercase letter" << endl;
    cin >> message ;
    cin.ignore() ;

    if (mode==1) 
    {
        cout << "your message : " << message << endl ;
        cout << "your encode message : " << plaintext_to_ciphertext(message) << endl ;
    }

    else 
    {
        cout << "your encode message : " << message << endl ;
        cout << "your message : " << ciphertext_to_plaintext(message) << endl ;
    }
    return 0 ;
}






