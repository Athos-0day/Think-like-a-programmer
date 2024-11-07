#include <iostream>
#include <string>
#include <algorithm>
using namespace std ;


//Ce programme consiste a generaliser le programme Dec_Bin_Hex
//On pourra afficher les valeurs dans n'importe quelles bases avec une limite à la base 16

int codage_base_N_vers_int(string codage_N, int base) ; //la fonction de passage de codage en base N à décimal 
string int_vers_codage_base_N(int entier, int base) ; //la fonction de passage de décimal à codage en base N
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




string int_vers_codage_base_N(int entier, int base) 
{
    string resultat = "" ;
    char inter ;
    while (entier>0)
    {
        if ((entier%base)<10)
        {
            inter = '0' + (entier%base) ;
            resultat += inter ;
            entier = entier/base ;
        } 
        else 
        {
            resultat += static_cast<char>(55+(entier%base)) ;
            entier = entier/base ;  
        }
    }
    reverse(resultat) ;
    return resultat ;
}

//la fonction de passage de codage en base N à décimal 
int codage_base_N_vers_int(string codage, int base) 
{
    //initialisation des variables
    int taille_string = codage.size() ;
    int i ;
    int resultat = 0 ;

    //on va parcourir la chaine de caractère
    for (i=0 ; i<taille_string ; i++)
    {
        switch (codage.at(i))
        {
            case '0':
                resultat = resultat ;
                break ;
            case '1':
                resultat += puissance_entiere(base,taille_string-i-1) ;
                break ;
            case '2':
                resultat += 2*puissance_entiere(base,taille_string-i-1) ;
                break;
            case '3':
                resultat += 3*puissance_entiere(base,taille_string-i-1) ;
                break ;
            case '4':
                resultat += 4*puissance_entiere(base,taille_string-i-1) ;
                break;
            case '5':
                resultat += 5*puissance_entiere(base,taille_string-i-1) ;
                break ;
            case '6':
                resultat += 6*puissance_entiere(base,taille_string-i-1) ;
                break ;
             case '7':
                resultat += 7*puissance_entiere(base,taille_string-i-1) ;
                break ;
            case '8':
                resultat += 8*puissance_entiere(base,taille_string-i-1) ;
                break;
            case '9':
                resultat += 9*puissance_entiere(base,taille_string-i-1) ;
                break ;
            case 'A':
                resultat += 10*puissance_entiere(base,taille_string-i-1) ;
                break;
            case 'B':
                resultat += 11*puissance_entiere(base,taille_string-i-1) ;
                break ;
            case 'C':
                resultat += 12*puissance_entiere(base,taille_string-i-1) ;
                break ;
            case 'D':
                resultat += 13*puissance_entiere(base,taille_string-i-1) ;
                break;
            case 'E':
                resultat += 14*puissance_entiere(base,taille_string-i-1) ;
                break ;
            case 'F':
                resultat += 15*puissance_entiere(base,taille_string-i-1) ;
                break ;
        }

    }
    return resultat ;
}



int main() 
{
    int type ;
    cout << "Votre valeur est-elle un decimal (0) ou en base N (1) ? " ;
    cin >> type ;
    
    //gestion des erreurs de l'utilisateur
    while (type>1 || type<0)
    {
        cout << "Cette valeur n'est pas possible" << endl ;
        cout << "Votre valeur est-elle un (D)ecimal ou en (B)ase N ?" ;
        cin >> type ; 
        cin.ignore() ; 
    }

    //le cas d'une valeur decimal
    if (type==0)
    {
        int valeur ;
        int i ;
        cout << "Veuillez entrer la valeur : " ;
        cin >> valeur ;
        cout << "Decimal : " << valeur << endl ;

        for (i=2 ; i<=16 ; i++)
        {
            cout << "Base " << i << " : " << int_vers_codage_base_N(valeur,i) << endl ; 
        }
    }

    //le cas en base N 
    else 
    {
        string codage_N = "" ;
        int i ;
        int valeur_dec ;
        int base ;
        cout << "Veuillez entrer la valeur : " ;
        cin >> codage_N ;
        cin.ignore() ;
        cout << "Veuillez entrer la base dans laquelle est code cette valeur : " ;
        cin >> base ;
        cin.ignore() ;
        valeur_dec = codage_base_N_vers_int(codage_N,base) ;
        cout << "Decimal : " << valeur_dec << endl ;
        for (i=2 ; i<=16 ; i++)
        {
            cout << "Base " << i << " : " << int_vers_codage_base_N(valeur_dec, i) << endl ; 
        }


    }
    return 0 ;
}