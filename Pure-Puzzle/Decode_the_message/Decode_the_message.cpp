#include <iostream>
#include <string>
using namespace std ;
//l'objectif est de décoder un message selon les règles expliquées dans le livre
//voir le fichier pdf associé 

char mode_majuscule(int entier) ;
//cette première fonction renverra la majuscule associé à l'entier 

char mode_minuscule(int entier) ;
//cette deuxième fonction fait la même chose pour les minuscules

char mode_accentuation(int entier) ;
//idem pour l'accentuation


char mode_majuscule(int entier) 
{
    return static_cast<char>(64+entier) ;
}

char mode_minuscule(int entier) 
{
    return static_cast<char>(96+entier) ;
}

char mode_accentuation(int entier) 
{
    if (entier==1) {return '!' ;}
    if (entier==2) {return '?' ;}
    if (entier==3) {return ',' ;}
    if (entier==4) {return '.' ;}
    if (entier==5) {return ' ' ;}
    if (entier==6) {return ';' ;}
    if (entier==7) {return static_cast<char>(34) ;}
    else {return static_cast<char>(42) ;}

}

int main() 
{

    int message = 0 ;
    int mode = 0 ; 
    string resultat = "" ;

    cout << "Veuillez rentrer votre message nombre par nombre" << endl ;
    cout << "Entrez un nombre negatif lorsque que votre message est termine" << endl ;

    while (message>=0) 
    {
        cout << "Entrez la valeur d'un entier : " ;
        cin >> message ;
        cin.ignore() ;

        //on traite les cas d'exception de l'utilisateur 
        if (message < 0)
        {
            break ;
        }


        //on traite le cas du mode majuscule
        if (mode == 0 ) 
        {
            if (message%27==0) 
            {
                mode = 1 ;
                continue;
               
            }
            else 
            {
                resultat += mode_majuscule(message%27) ;
                continue;
                
            }
        } 

        //on traite le cas du mode minuscule
        if (mode == 1 ) 
        {
            if (message%27==0) 
            {
                mode = 2 ;
                continue;
                
            }
            else 
            {
                resultat += mode_minuscule(message%27) ;
                continue;
                
            }
        }

        //on traite le cas du mode accentuation 
        else 
        {
            if (message%9==0)
            {
                mode = 0 ;
                continue;
                
            }
            else 
            {
                resultat += mode_accentuation(message%9) ;
                continue;
               
            }
        } 


    } 
    cout << "Voici le message decode : " << resultat << endl ;

    return 0 ;
}


