#include <iostream>
#include <string>
#include <algorithm>
using namespace std ;

//on va créer une à une les fonctions de traductions en système de numérotation 
//binaire décimal et héxadécimal
//on essaiera ensuite de trouver une fonction général pour les écritures en base

string decimal_vers_bin(int entier) ; //la fonction de décimal vers binaire 
int bin_vers_decimal(string binaire) ; //la fonction inverse
int hexa_vers_decimal(string hexa) ; //la fonction de l'héxadécimal vers décimal
string decimal_vers_hexa(int entier) ; //l'opération inverse
int puissance_entiere(int entier, int puissance) ; //la fonction qui renvoie x**n et qui sera impérative


//permet d'inverser les éléments d'une chaine de caractère
void reverse(string &s)
{
	int n = s.length();
	for (int i = 0; i < n/2; i++) {
		std::swap(s[i], s[n-i-1]);
	}
}

//fonction x**n qui ne sera utilisé qu'avec x entier 
int puissance_entiere(int entier, int puissance)
{
    int resultat = 1 ;
    int i ;
    for (i=1 ; i<=puissance ; i++)
    {
        resultat = resultat*entier ; 
    }
    return resultat ;

}

//la fonction de passage de décimal à binaire
string decimal_vers_bin(int entier) 
{
    string resultat = "" ;
    while (entier>0)
    {
        if (entier%2==0)
        {
            resultat += '0' ;
            entier = entier/2 ;
        }
        else 
        {
            resultat += '1' ;
            entier = entier/2 ;
        }

    }
    reverse(resultat) ;
    return resultat ;
}

//la fonction de passage de binaire à décimal
int bin_vers_decimal(string dec) 
{
    int resultat = 0 ;
    int i, taille = dec.size() ;

    for (i=0 ; i<taille ; i++)
    {
        if (dec.at(i)=='1')
        {
            resultat+= puissance_entiere(2 , taille - 1 - i) ;
        }
    }
    return resultat ;
}

//la fonction de passage d'héxadécimal à décimal
int hexa_vers_decimal(string hexa) 
{
    //initialisation des variables
    int taille_hexa = hexa.size() ;
    int i ;
    int resultat = 0 ;

    //on va parcourir la chaine de caractère
    for (i=0 ; i<taille_hexa ; i++)
    {
        switch (hexa.at(i))
        {
            case '0':
                resultat = resultat ;
                break ;
            case '1':
                resultat += puissance_entiere(16,taille_hexa-i-1) ;
                break ;
            case '2':
                resultat += 2*puissance_entiere(16,taille_hexa-i-1) ;
                break;
            case '3':
                resultat += 3*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
            case '4':
                resultat += 4*puissance_entiere(16,taille_hexa-i-1) ;
                break;
            case '5':
                resultat += 5*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
            case '6':
                resultat += 6*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
             case '7':
                resultat += 7*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
            case '8':
                resultat += 8*puissance_entiere(16,taille_hexa-i-1) ;
                break;
            case '9':
                resultat += 9*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
            case 'A':
                resultat += 10*puissance_entiere(16,taille_hexa-i-1) ;
                break;
            case 'B':
                resultat += 11*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
            case 'C':
                resultat += 12*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
            case 'D':
                resultat += 13*puissance_entiere(16,taille_hexa-i-1) ;
                break;
            case 'E':
                resultat += 14*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
            case 'F':
                resultat += 15*puissance_entiere(16,taille_hexa-i-1) ;
                break ;
        }

    }
    return resultat ;
}

//la fonction de passage de décimal à héxadécimal
string decimal_vers_hexa(int entier)
{
    string ecriture_hexa = "" ;
    char caractere ;
    while (entier>0)
    {
        if ((entier%16)<10) 
        {
            caractere = '0' + (entier%16) ;
            ecriture_hexa += caractere ;
            entier = entier/16 ;
        } 
        else 
        {
            ecriture_hexa += static_cast<char>(55+(entier%16)) ;
            entier = entier/16 ;
        }
    }
    reverse(ecriture_hexa) ;
    return ecriture_hexa ;
}



//on va maintenant mettre en place une interaction entre l'ordinateur et l'utilisateur
int main() 
{
    char Mode_entree ;
    cout << "Votre entree est-elle en systeme (D)ecimal, (H)exadecimal ? " ;
    cin >> Mode_entree ;

    if (Mode_entree=='D')
    {
        int valeur ;
        int i ;
        cout << "Veuillez entrer la valeur : " ;
        cin >> valeur ;
        cin.ignore() ;
        cout << "Decimal : " << valeur << endl ;
        cout << "Hexadecimal : " << decimal_vers_hexa(valeur) << endl ;

    }

    if (Mode_entree =='H')
    {
        string hexa ="" ;
        int i ;
        int valeur_dec ;
        cout << "Veuillez entrer la valeur : " ;
        cin >> hexa ;
        cin.ignore() ;
        valeur_dec = hexa_vers_decimal(hexa) ;
        cout << "Decimal : " << valeur_dec << endl ;
        cout << "Hexadecimal : " << hexa << endl ;
        
    }



    return 0 ;

}