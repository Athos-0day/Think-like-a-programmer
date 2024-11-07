#include <iostream>
#include <string>

//tentative de vérifer si un entier vérifie la formule de Luhn sans utiliser le type charactère
//la complexité temporelle sera cependant probablement plus important 

int ajout_double_chiffre(int entier);
//permet de taiter les cas d'entier plus grand que 10 
//par exemple ajout_double_chiffre(13) => 1 + 3 = 4
int ajout_double_chiffre(int entier) 
{
    int somme = 0;
    somme = 1 + (entier%10) ;
    return somme ;
}

int longueur_entier(int entier);
//permet de calculer la longueur de l'entier 
//par exemple longueur_entier(513) => 3
int longueur_entier(int entier) 
{
    int somme = 1 ;
    while (entier/10>0) 
    {
        somme += 1 ;
        entier = entier/10 ;
    }
    return somme ;
    
}

bool Luhn_sumcheck(int entier) ;
//la fonction renvoie si l'entier demandé respecte la formule de Luhn ou non
bool Luhn_sumcheck(int entier) 
{
    int taille_entier = longueur_entier(entier) ;
    bool multiplie = true ;
    int chiffre_courant = 0 ;
    int resultat = 0 ;

    //on regarde si on doit commencer par multiplier par deux ou non 
    if (entier%2==0)
    {
        multiplie = true ;
    }
    else 
    {
        multiplie = false ;
    }

    //on va maintenant parcourir l'entier de droite à gauche par division par 10 
    while (entier>=1)
    {
       chiffre_courant = entier%10 ;
       entier = entier/10 ;
       if (multiplie)
       {
        chiffre_courant = chiffre_courant*2 ;
        multiplie = false ;
        
        //on vérifie s'il est plus grand que 10
        if (chiffre_courant>=10)
        {
            resultat += ajout_double_chiffre(chiffre_courant) ;
        }
        else 
        {
            resultat += chiffre_courant ;
        }
       } 
       else 
       {
        resultat += chiffre_courant ;
        multiplie = true ;
       }



    }
    return (resultat%10==0) ;  
}

int main() 
{
    int entier = 0 ;
    std::cout << "Entrer la valeur d'un entier naturel : " ;
    std::cin >> entier ;
    std::cin.ignore() ;
    
    //on vérifie des préconditions sur l'entier 
    while (entier<0)
    {
        std::cout << "L'entier doit être plus grand que 0" << std::endl ;
        std::cout << "Entrer la valeur d'un entier naturel : " ;
        std::cin >> entier ;
        std::cin.ignore() ;   
    }

    //on va maintenant vérifier si l'entier en question vérifie la formule de Luhn
    if (Luhn_sumcheck(entier)) 
    {
        std::cout << "L'entier vérifie la formule de Luhn"<< std::endl ;
    } 
    else 
    {
        std::cout << "L'entier ne vérifie pas la formule de Luhn"  << std::endl ;
    }
    return 0 ;
}